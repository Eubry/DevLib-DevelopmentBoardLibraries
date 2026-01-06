#include "pitches.h"
//--------------Frequency Note Implementation----------------
fNote::fNote(){}
void fNote::printNotes(){
    for(const auto& note : mNote){
        ESP_LOGI("FNote", "Note: %s, Frequency: %u Hz", note.first.c_str(), note.second);
    }
}
void fNote::addMelody(std::string name, std::string alias, const int melody[], size_t length){
    dtaMelody newMelody;
    newMelody.name = name;
    newMelody.alias = alias;
    newMelody.length = length/2; // Number of notes is half the array length
    newMelody.type=1;// interleaved arrays
    //extract duration from melody {255,8]: frecuency, duration
    int8_t *dur=new int8_t[length/2];
    int *mel=new int[length/2];
    for(size_t i=0;i<length;i+=2){ // Fixed: iterate to length, not length*2
        mel[i/2]=melody[i];
        dur[i/2]=melody[i+1];
    }
    newMelody.melody = mel;
    newMelody.duration = dur;
    _melodies[name] = newMelody;
}
void fNote::addMelody(std::string name, std::string alias, const int melody[], const int8_t duration[], size_t length){
    dtaMelody newMelody;
    newMelody.name = name;
    newMelody.alias = alias;
    newMelody.melody = melody;
    newMelody.duration = duration;
    newMelody.length = length;
    newMelody.type=0;// Separate arrays
    _melodies[name] = newMelody;
}
void fNote::addMelody(std::string name, std::string alias, const std::string melody[], const int8_t duration[], size_t length){
    dtaMelody newMelody;
    newMelody.name = name;
    newMelody.alias = alias;
    newMelody.duration = duration;
    newMelody.length = length;
    newMelody.type=0;// Separate arrays
    // Convert string notes to frequencies
    int *freqMelody = new int[length];
    for(size_t i = 0; i < length; ++i){
        std::string noteStr = melody[i];
        if(mNote.find(noteStr) != mNote.end()){
            freqMelody[i] = mNote.at(noteStr);
        }else{
            freqMelody[i] = REST; // Default to REST if note not found
        }
    }
    newMelody.melody = freqMelody;
    _melodies[name] = newMelody;
}
dtaMelody fNote::getMelody(std::string name){
    if(_melodies.find(name) != _melodies.end()){
        return _melodies[name];
    }else{
        return dtaMelody(); // Return empty melody if not found
    }
}
void fNote::deleteMelody(std::string name){_melodies.erase(name);}
void fNote::playMelody(std::string name, pinManager& pinMgr, std::string buzzerId,uint8_t volume,int16_t speed,bool reverse){
    if(_melodies.find(name) != _melodies.end()){
        dtaMelody melody = _melodies[name];
        cTime timer;
        int16_t tempo = (speed > 0) ? speed : melody.tempo;
        int wholenote = (60000 * 4) / tempo;
        int divider = 0; 
        int64_t noteDuration = 0;
        
        // Iterate forward or backward based on reverse parameter
        if(reverse){
            for(int i = melody.length - 1; i >= 0; --i){
                int note = melody.melody[i];
                int8_t dur = melody.duration[i];

                divider = dur;
                if (divider > 0) {
                    noteDuration = (wholenote) / divider;
                } else if (divider < 0) {
                    // dotted notes are represented with negative durations!!
                    noteDuration = (wholenote) / abs(divider);
                    noteDuration *= 1.5; // increases the duration in half for dotted notes
                }
                if(note == REST){
                    pinMgr.noTone(buzzerId);
                }else{
                    pinMgr.tone(buzzerId, note, volume);
                }

                do {timer.wait((noteDuration*0.9)*1000);} while(!timer.finish());
                // Wait for note duration (convert milliseconds to microseconds)
                pinMgr.noTone(buzzerId);
                timer.reset();// Short pause between notes
                do {timer.wait((noteDuration*0.1)*1000);} while(!timer.finish());
                timer.reset();
            }
        }else{
            for(size_t i = 0; i < melody.length; ++i){
            int note = melody.melody[i];
            int8_t dur = melody.duration[i];

            divider = dur;
            if (divider > 0) {
                noteDuration = (wholenote) / divider;
            } else if (divider < 0) {
                // dotted notes are represented with negative durations!!
                noteDuration = (wholenote) / abs(divider);
                noteDuration *= 1.5; // increases the duration in half for dotted notes
            }
            if(note == REST){
                pinMgr.noTone(buzzerId);
            }else{
                pinMgr.tone(buzzerId, note, volume);
            }

            do {timer.wait((noteDuration*0.9)*1000);} while(!timer.finish());
            // Wait for note duration (convert milliseconds to microseconds)
            pinMgr.noTone(buzzerId);
            timer.reset();// Short pause between notes
            do {timer.wait((noteDuration*0.1)*1000);} while(!timer.finish());
            timer.reset();
            }
        }
    }
}
fNote::~fNote(){}