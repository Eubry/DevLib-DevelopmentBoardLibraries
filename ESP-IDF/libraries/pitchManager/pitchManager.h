// -------------------------------------------------
// Copyright (c) 2021 HiBit <https://www.hibit.dev>
// -------------------------------------------------
#pragma once
#include "freertos/FreeRTOS.h"// Include FreeRTOS base
#include "freertos/task.h"// Include FreeRTOS task support
#include "freertos/timers.h"// Include FreeRTOS timers
#include "esp_err.h"// Include ESP error codes
#include "esp_log.h"// Add ESP logging support
#include <string>
#include <cstdint>
#include <map>
#include "counter.h"
#include "pinManagement.h"

// Note frequency definitions
const std::map<std::string, uint16_t> mNote = {
{"B0", 31},
{"C1", 33},{"CS1", 35},
{"D1", 37},{"DS1", 39},
{"E1", 41},
{"F1", 44},{"FS1", 46},
{"G1", 49},{"GS1", 52},
{"A1", 55},{"AS1", 58},
{"B1", 62},
{"C2", 65},{"CS2", 69},
{"D2", 73},{"DS2", 78},
{"E2", 82},
{"F2", 87},{"FS2", 93},
{"G2", 98},{"GS2", 104},
{"A2", 110},{"AS2", 117},
{"B2", 123},
{"C3", 131},{"CS3", 139},
{"DB3", 139},{"D3", 147},{"DS3", 156},
{"EB3", 156},{"E3", 165},
{"F3", 175},{"FS3", 185},
{"G3", 196},{"GS3", 208},
{"A3", 220},{"AS3", 233},
{"B3", 247},
{"C4", 262},{"CS4", 277},
{"D4", 294},{"DS4", 311},
{"E4", 330},
{"F4", 349},{"FS4", 370},
{"G4", 392},{"GS4", 415},
{"A4", 440},{"AS4", 466},
{"B4", 494},
{"C5", 523},{"CS5", 554},
{"D5", 587},{"DS5", 622},
{"E5", 659},
{"F5", 698},{"FS5", 740},
{"G5", 784},{"GS5", 831},
{"A5", 880},{"AS5", 932},
{"B5", 988},
{"C6", 1047},{"CS6", 1109},
{"D6", 1175},{"DS6", 1245},
{"E6", 1319},
{"F6", 1397},{"FS6", 1480},
{"G6", 1568},{"GS6", 1661},
{"A6", 1760},{"AS6", 1865},
{"B6", 1976},
{"C7", 2093},{"CS7", 2217},
{"D7", 2349},{"DS7", 2489},
{"E7", 2637},
{"F7", 2794},{"FS7", 2960},
{"G7", 3136},{"GS7", 3322},
{"A7", 3520},{"AS7", 3729},
{"B7", 3951},
{"C8", 4186},{"CS8", 4435},
{"D8", 4699},{"DS8", 4978},
{"REST", 0}
};
//Get the frecuency of a note
struct dtaMelody{
    std::string name="";
    std::string alias="";
    const int* melody=nullptr;
    const int8_t* duration=nullptr;
    size_t length=0;
    uint16_t tempo=200; // Default tempo
    uint8_t type=0;// 0-Separte arrays, 1-One array but: freq,dur interleaved
};
// template <typename T>
/*
Class to manage frequency notes and melodies.
Provides predefined note frequencies and methods to add, retrieve, and play melodies.

Volume levels:
10-20% = very quiet, good for indoor testing
30-40% = moderate volume
50%+ = louder, may sound harsh on cheap buzzers
*/
class fNote{
    private:
        std::map<std::string, dtaMelody> _melodies;
    public:
        static constexpr uint8_t REST=0,
        B0=31,
        A1=55,AS1=58,
        B1=62,
        C1=33,CS1=35,
        D1=37,DS1=39,
        E1=41,
        F1=44,FS1=46,
        G1=49,GS1=52,
        
        A2=110,AS2=117,
        B2=123,
        C2=65,CS2=69,
        D2=73,DS2=78,
        E2=82,
        F2=87,FS2=93,
        G2=98,GS2=104,
        
        A3=220,AS3=233,
        B3=247,
        C3=131,CS3=139,
        DB3=139,D3=147,DS3=156,
        EB3=156,E3=165,
        F3=175,FS3=185,
        G3=196,GS3=208;
        
        static constexpr uint16_t C4=262,CS4=277,
        A4=440,AS4=466,
        B4=494,
        D4=294,DS4=311,
        E4=330,
        F4=349,FS4=370,
        G4=392,GS4=415,
        
        A5=880,AS5=932,
        B5=988,
        C5=523,CS5=554,
        D5=587,DS5=622,
        E5=659,
        F5=698,FS5=740,
        G5=784,GS5=831,
        
        A6=1760,AS6=1865,
        B6=1976,
        C6=1047,CS6=1109,
        D6=1175,DS6=1245,
        E6=1319,
        F6=1397,FS6=1480,
        G6=1568,GS6=1661,
        
        A7=3520,AS7=3729,
        B7=3951,
        C7=2093,CS7=2217,
        D7=2349,DS7=2489,
        E7=2637,
        F7=2794,FS7=2960,
        G7=3136,GS7=3322,
        
        C8=4186,CS8=4435,
        D8=4699,DS8=4978;
        
    fNote();
    void printNotes();
    void addMelody(std::string name, std::string alias, const int melody[], size_t length);
    template<size_t N>
    void addMelody(std::string name, std::string alias, const int (&melody)[N]){
        addMelody(name, alias, melody, N);
    }
    //Methods to add melodies in string format
    void addMelody(std::string name, std::string alias, const std::string melody[], const int8_t duration[], size_t length);
    template<size_t N>
    void addMelody(std::string name, std::string alias, const std::string (&melody)[N], const int8_t (&duration)[N]){
        addMelody(name, alias, melody, duration, N);
    }
    //Methods to add melodies in int format
    void addMelody(std::string name, std::string alias, const int melody[], const int8_t duration[], size_t length);
    template<size_t N>
    void addMelody(std::string name, std::string alias, const int (&melody)[N], const int8_t (&duration)[N]){
        addMelody(name, alias, melody, duration, N);
    }
    void deleteMelody(std::string name);
    void playMelody(std::string name, pinManager& pinMgr, std::string buzzerId,uint8_t volume=50,int16_t speed=-1,bool reverse=false);
    dtaMelody getMelody(std::string name);
    //void addMelody(std::string name,int melody[], uint8_t duration[]);
    ~fNote();
};
// -------------------------------------------------