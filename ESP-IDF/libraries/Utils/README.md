# Utils Library (ESP-IDF)

ESP-IDF specific utility library providing advanced FreeRTOS task management for ESP32 development.

## Description

This library provides ESP-IDF framework utilities that leverage FreeRTOS and ESP32-specific features. It includes a powerful task management system for creating, monitoring, and controlling FreeRTOS tasks.

## Features

### taskManager Class

A comprehensive FreeRTOS task management system with the following capabilities:

- **Task Creation**: Create tasks with custom parameters using `add()`
- **Core Affinity**: Pin tasks to specific CPU cores (0 or 1)
- **Priority Control**: Set task priorities (0-24)
- **Stack Management**: Configure stack size per task
- **Watchdog Integration**: Automatic watchdog timer registration and management
  - Tasks are automatically added to watchdog on creation via `esp_task_wdt_add()`
  - Global watchdog reset via `resetWatchdog()` using `esp_task_wdt_reset()`
  - Automatic watchdog cleanup on task deletion via `esp_task_wdt_delete()`
- **Task Lifecycle**: Safe task creation and deletion with proper cleanup
- **Task Registry**: Named task tracking via internal `std::map<std::string, taskStruct>`
- **Automatic Cleanup**: Destructor ensures all tasks are properly deleted

### Public Methods

- `add()` - Create and start a new task with watchdog registration
- `del()` - Delete a task with automatic watchdog unsubscription  
- `resetWatchdog()` - Reset global watchdog timer (validates task exists first)

### taskManager Destructor

The destructor automatically cleans up all managed tasks when the taskManager instance is destroyed.

**Behavior:**
- Iterates through all tasks in internal map
- Unsubscribes each task from watchdog timer
- Deletes all FreeRTOS tasks
- Clears internal task map
- Logs deletion of each task

### Helper Functions

- **inMap()**: Template function to check if a key exists in a std::map

## Installation

### ESP-IDF Project

1. Copy the Utils folder to your project's components directory:
   ```bash
   cp -r ESP-IDF/libraries/Utils your-project/components/
   ```

2. The component will be automatically detected by ESP-IDF build system

3. Include in your code:
   ```cpp
   #include "Utils.h"
   ```

## Usage

### Basic Task Creation

```cpp
#include "Utils.h"

Utils::taskManager tasks;

void ledTask(void* param) {
    while(1) {
        // Toggle LED
        gpio_set_level(GPIO_NUM_2, 1);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(GPIO_NUM_2, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
        
        // Reset watchdog for this task
        tasks.resetWatchdog("ledTask");
    }
}

void app_main() {
    // Create task: name, function, params, priority, core, stack size
    tasks.add("ledTask", ledTask, NULL, 1, 0, 2048);
}
```

### Advanced Task Management

```cpp
#include "Utils.h"

Utils::taskManager tasks;

void highPriorityTask(void* param) {
    int* counter = (int*)param;
    
    while(1) {
        (*counter)++;
        ESP_LOGI("HPTask", "Count: %d", *counter);
        
        tasks.resetWatchdog("highPriorityTask");
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void lowPriorityTask(void* param) {
    while(1) {
        ESP_LOGI("LPTask", "Running background task");
        
        tasks.resetWatchdog("lowPriorityTask");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void app_main() {
    int counter = 0;
    
    // High priority task on core 1
    tasks.add("highPriorityTask", highPriorityTask, &counter, 10, 1, 4096);
    
    // Low priority task on core 0
    tasks.add("lowPriorityTask", lowPriorityTask, NULL, 1, 0, 2048);
    
    // Later, delete a task if needed
    vTaskDelay(pdMS_TO_TICKS(10000));
    tasks.del("lowPriorityTask");
}
```

### Using inMap() Helper

```cpp
#include "Utils.h"
#include <map>

void checkConfig() {
    std::map<std::string, int> config = {
        {"maxConnections", 10},
        {"timeout", 5000},
        {"retries", 3}
    };
    
    if (Utils::inMap("timeout", config)) {
        ESP_LOGI("Config", "Timeout: %d", config["timeout"]);
    }
}
```

## API Reference

### taskManager::add()

```cpp
void add(const std::string& name, 
         TaskFunction_t taskFunc, 
         void* param = NULL, 
         UBaseType_t priority = 1, 
         BaseType_t core = 0, 
         uint32_t stackSize = 1024)
```

Creates and starts a new FreeRTOS task with automatic watchdog integration.

**Parameters:**
- `name` - Unique task identifier (used for task tracking and watchdog management)
- `taskFunc` - Task function pointer (must have signature `void taskFunc(void*)`)
- `param` - Optional parameter to pass to the task (default: NULL)
- `priority` - Task priority (0-24, higher = more priority, default: 1)
- `core` - CPU core to run on (0 or 1, default: 0)
- `stackSize` - Stack size in bytes (default: 1024, typical: 2048-4096)

**Behavior:**
- Creates task using `xTaskCreatePinnedToCore()`
- Automatically registers task with watchdog timer (`esp_task_wdt_add()`)
- Stores task information in internal map for management
- Logs creation status (success/failure) via ESP_LOG

**Example:**
```cpp
tasks.add("myTask", myTaskFunction, NULL, 5, 1, 4096);
```

### taskManager::del()

```cpp
void del(const std::string& name)
```

Safely deletes a task by name, including automatic watchdog cleanup.

**Parameters:**
- `name` - Name of the task to delete

**Behavior:**
- Checks if task exists in internal map
- Unsubscribes task from watchdog timer (`esp_task_wdt_delete()`)
- Deletes the FreeRTOS task (`vTaskDelete()`)
- Removes task from internal tracking map
- Logs deletion status or error if task not found

**Example:**
```cpp
tasks.del("myTask");
```

### taskManager::resetWatchdog()

```cpp
void resetWatchdog(const std::string& name)
```

Resets the watchdog timer for a specific task. Should be called periodically within the task's main loop to prevent watchdog timeout.

**Parameters:**
- `name` - Name of the task to reset watchdog for

**Behavior:**
- Verifies task exists in internal map
- Calls `esp_task_wdt_reset()` to reset the global watchdog timer
- Logs warning if reset fails
- Logs error if task not found

**Important:** This resets the global watchdog, so call it from within your task loop at regular intervals.

**Example:**
```cpp
void myTask(void* param) {
    while(1) {
inline bool inMap(const std::string& key, const std::map<std::string, T>& myMap)
```

Template helper function that checks if a key exists in a std::map.

**Parameters:**
- `key` - The key to search for
- `myMap` - The map to search in (const reference)

**Returns:** `true` if key exists, `false` otherwise

**Template Parameter:**
- `T` - The value type of the map (automatically deduced)

**Implementation:** Uses `find()` and compares against `end()` iterator

**Example:**
```cpp
std::map<std::string, int> data = {{"sensor1", 100}};
if (Utils::inMap("sensor1", data)) {
    // Key exists - safe to access data["sensor1"]
}

std::map<std::string, std::string> config = {{"wifi", "enabled"}};
if (Utils::inMap("mqtt", config)) {
    // This will be false - mqtt not in config
**Parameters:**
- `key` - The key to search for
- `myMap` - The map to search in

**Returns:** `true` if key exists, `false` otherwise

**Example:**
```cpp
std::map<std::string, int> data = {{"sensor1", 100}};
if (Utils::inMap("sensor1", data)) {
    // Key exists
}
```

## Task Priority Guidelines

| Priority | Use Case |
|----------|----------|
| 0-5 | Background tasks, logging, low-priority operations |
| 6-10 | Normal application tasks |
| 11-15 | Time-sensitive tasks, sensor reading |
| 16-20 | High-priority tasks, real-time control |
| 21-24 | Critical system tasks (use sparingly) |

## Stack Size Guidelines

| Task Type | Recommended Stack Size |
|-----------|----------------------|
| Simple LED blink | 1024 - 2048 bytes |
| Basic sensor reading | 2048 - 3072 bytes |
| WiFi/Network operations | 4096 - 8192 bytes |
| Complex processing | 8192+ bytes |

**Note:** Always monitor stack usage with `uxTaskGetStackHighWaterMark()` during development.

## Core Affinity

ESP32 has two cores (PRO_CPU and APP_CPU):
- **Core 0 (PRO_CPU)**: Usually runs WiFi/BT stack
- **Core 1 (APP_CPU)**: Available for user tasks

**Best Practices:**
- Pin computationally intensive tasks to Core 1
- Pin WiFi-related tasks to Core 0
- Use `tskNO_AFFINITY` for tasks that can run on either core

## Error Handling

The library uses ESP-IDF logging (ESP_LOG) to report status and errors:
- **ESP_LOGI**: Task creation success, task deletion confirmation
- **ESP_LOGE**: Task creation failure, task not found errors
- **ESP_LOGW**: Watchdog operation warnings (subscription/unsubscription failures)

All logs are tagged with "TASK_MANAGER" for easy filtering.

Monitor serial output with:
```bash
idf.py monitor
```

## Internal Implementation Details

### taskStruct

Internal structure used to track task information:
```cpp
struct taskStruct {
    TaskHandle_t handle;        // FreeRTOS task handle
    std::string name;           // Task name
    void* param;                // Task parameter (default: NULL)
    UBaseType_t priority;       // Task priority (default: 1)
    BaseType_t core;            // CPU core affinity (default: 0)
    uint32_t stackSize;         // Stack size in bytes (default: 1024)
};
```

### Private Members

- `_taskMap`: `std::map<std::string, taskStruct>` - Stores all managed tasks indexed by name
- `statusTask()`: Private method that logs task creation success/failure

## Requirements

- ESP-IDF 4.4 or later
- ESP32, ESP32-S2, ESP32-S3, or ESP32-C3
- FreeRTOS (included with ESP-IDF)

## Troubleshooting

**Task Won't Start:**
- Check stack size (increase if needed)
- Verify priority is valid (0-24)
- Ensure core is 0, 1, or tskNO_AFFINITY

**Watchdog Timeout:**
- Call `resetWatchdog()` more frequently in task loop
- Reduce processing time in task iterations
- Increase watchdog timeout in menuconfig

**Stack Overflow:**
- Increase stack size in `add()` call
- Reduce local variable usage in task
- Use dynamic allocation sparingly

## License

Open source - free to use and modify.
