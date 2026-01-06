#pragma once
#include "pitches.h"
//--------------Frequency Note Implementation----------------
inline void initializeMelodies(fNote &n){
    // Lower octave version (G4-C5: 392-523Hz) - Better for smaller buzzers
    n.addMelody("zeldaItemLow", "Zelda Item Get Low", {
        n.G4,8, n.A4,8, n.B4,8, n.C5,2
    });
    n.addMelody("start", "Zelda Item Get Low", {
        n.D5,8,n.D5,-8,n.CS5,8,n.B4,-2,
    });
    //One
    n.addMelody("one", "One Metallica", {
        n.E4,-4,n.FS4,8,n.A4,4,n.B4,-2,
        n.D5,-4,n.CS5,8,n.B4,-8,n.REST,16,
        n.D5,-4,n.CS5,8,n.A4,-8,n.REST,16,
        n.D5,8,n.D5,-8,n.CS5,8,n.B4,-2,
        //-----------------
        n.FS5,-4,n.E5,16, n.D5,-8,
        n.E5,8,n.D5,4,n.REST,16,
        n.D5,8,n.CS5,8,n.REST,16,
        n.CS5,-4,n.B4,16,n.G4,-8,
        n.D4,8,n.A4,16,n.B4,-2
    });
    // Higher octave version (G5-C6: 784-1047Hz) - Brighter sound
    n.addMelody("zeldaItemHigh", "Zelda Item Get High", {
        n.G5,8, n.A5,8, n.B5,8, n.C6,2
    });
    n.addMelody("nokiatune","Nokia tune",{
        n.E5,8, n.D5,8, n.FS4,4, n.GS4,4, 
        n.CS5,8, n.B4,8, n.D4,4, n.E4,4, 
        n.B4,8, n.A4,8, n.CS4,4, n.E4,4,
        n.A4,2
    });
    // Doom - Extended main theme
    n.addMelody("doom","Doom - Main theme",{
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8, //1
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, 8, n.E2, 8, n.E2, 8, n.B2, 8, n.C3, 8,
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8,
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, -2,
    
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8, //5
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, 8, n.E2, 8, n.E2, 8, n.B2, 8, n.C3, 8,
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8,
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, -2,
    
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8, //9
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, 8, n.E2, 8, n.E2, 8, n.B2, 8, n.C3, 8,
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8,
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, -2,
    
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8, //13
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, 8, n.E2, 8, n.E2, 8, n.B2, 8, n.C3, 8,
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8,
        n.FS3, -16, n.D3, -16, n.B2, -16, n.A3, -16, n.FS3, -16, n.B2, -16, n.D3, -16, n.FS3, -16, n.A3, -16, n.FS3, -16, n.D3, -16, n.B2, -16,
    
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8, //17
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, 8, n.E2, 8, n.E2, 8, n.B2, 8, n.C3, 8,
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8,
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, -2,
    
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8, //21
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, 8, n.E2, 8, n.E2, 8, n.B2, 8, n.C3, 8,
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8,
        n.B3, -16, n.G3, -16, n.E3, -16, n.G3, -16, n.B3, -16, n.E4, -16, n.G3, -16, n.B3, -16, n.E4, -16, n.B3, -16, n.G4, -16, n.B4, -16,
    
        n.A2, 8, n.A2, 8, n.A3, 8, n.A2, 8, n.A2, 8, n.G3, 8, n.A2, 8, n.A2, 8, //25
        n.F3, 8, n.A2, 8, n.A2, 8, n.DS3, 8, n.A2, 8, n.A2, 8, n.E3, 8, n.F3, 8,
        n.A2, 8, n.A2, 8, n.A3, 8, n.A2, 8, n.A2, 8, n.G3, 8, n.A2, 8, n.A2, 8,
        n.F3, 8, n.A2, 8, n.A2, 8, n.DS3, -2,
    
        n.A2, 8, n.A2, 8, n.A3, 8, n.A2, 8, n.A2, 8, n.G3, 8, n.A2, 8, n.A2, 8, //29
        n.F3, 8, n.A2, 8, n.A2, 8, n.DS3, 8, n.A2, 8, n.A2, 8, n.E3, 8, n.F3, 8,
        n.A2, 8, n.A2, 8, n.A3, 8, n.A2, 8, n.A2, 8, n.G3, 8, n.A2, 8, n.A2, 8,
        n.A3, -16, n.F3, -16, n.D3, -16, n.A3, -16, n.F3, -16, n.D3, -16, n.C4, -16, n.A3, -16, n.F3, -16, n.A3, -16, n.F3, -16, n.D3, -16,
    
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8, //33
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, 8, n.E2, 8, n.E2, 8, n.B2, 8, n.C3, 8,
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8,
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, -2,
    
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8, //37
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, 8, n.E2, 8, n.E2, 8, n.B2, 8, n.C3, 8,
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8,
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, -2,
    
        n.CS3, 8, n.CS3, 8, n.CS4, 8, n.CS3, 8, n.CS3, 8, n.B3, 8, n.CS3, 8, n.CS3, 8, //41
        n.A3, 8, n.CS3, 8, n.CS3, 8, n.G3, 8, n.CS3, 8, n.CS3, 8, n.GS3, 8, n.A3, 8,
        n.B2, 8, n.B2, 8, n.B3, 8, n.B2, 8, n.B2, 8, n.A3, 8, n.B2, 8, n.B2, 8,
        n.G3, 8, n.B2, 8, n.B2, 8, n.F3, -2,
    
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8, //45
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, 8, n.E2, 8, n.E2, 8, n.B2, 8, n.C3, 8,
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8,
        n.B3, -16, n.G3, -16, n.E3, -16, n.G3, -16, n.B3, -16, n.E4, -16, n.G3, -16, n.B3, -16, n.E4, -16, n.B3, -16, n.G4, -16, n.B4, -16,
    
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8, //49
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, 8, n.E2, 8, n.E2, 8, n.B2, 8, n.C3, 8,
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8,
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, -2,
    
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8, //53
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, 8, n.E2, 8, n.E2, 8, n.B2, 8, n.C3, 8,
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8,
        n.FS3, -16, n.DS3, -16, n.B2, -16, n.FS3, -16, n.DS3, -16, n.B2, -16, n.G3, -16, n.D3, -16, n.B2, -16, n.DS4, -16, n.DS3, -16, n.B2, -16,
    
        // -/-
    
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8, //57
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, 8, n.E2, 8, n.E2, 8, n.B2, 8, n.C3, 8,
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8,
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, -2,
    
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8, //61
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, 8, n.E2, 8, n.E2, 8, n.B2, 8, n.C3, 8,
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8,
        n.E4, -16, n.B3, -16, n.G3, -16, n.G4, -16, n.E4, -16, n.G3, -16, n.B3, -16, n.D4, -16, n.E4, -16, n.G4, -16, n.E4, -16, n.G3, -16,  
    
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8, //65
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, 8, n.E2, 8, n.E2, 8, n.B2, 8, n.C3, 8,
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8,
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, -2,
    
        n.A2, 8, n.A2, 8, n.A3, 8, n.A2, 8, n.A2, 8, n.G3, 8, n.A2, 8, n.A2, 8, //69
        n.F3, 8, n.A2, 8, n.A2, 8, n.DS3, 8, n.A2, 8, n.A2, 8, n.E3, 8, n.F3, 8,
        n.A2, 8, n.A2, 8, n.A3, 8, n.A2, 8, n.A2, 8, n.G3, 8, n.A2, 8, n.A2, 8,
        n.A3, -16, n.F3, -16, n.D3, -16, n.A3, -16, n.F3, -16, n.D3, -16, n.C4, -16, n.A3, -16, n.F3, -16, n.A3, -16, n.F3, -16, n.D3, -16,
    
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8, //73
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, 8, n.E2, 8, n.E2, 8, n.B2, 8, n.C3, 8,
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8,
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, -2,
    
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8, //77
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, 8, n.E2, 8, n.E2, 8, n.B2, 8, n.C3, 8,
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8,
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, -2,
    
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8, //81
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, 8, n.E2, 8, n.E2, 8, n.B2, 8, n.C3, 8,
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8,
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, -2,
    
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8, //73
        n.C3, 8, n.E2, 8, n.E2, 8, n.AS2, 8, n.E2, 8, n.E2, 8, n.B2, 8, n.C3, 8,
        n.E2, 8, n.E2, 8, n.E3, 8, n.E2, 8, n.E2, 8, n.D3, 8, n.E2, 8, n.E2, 8,
        n.B3, -16, n.G3, -16, n.E3, -16, n.B2, -16, n.E3, -16, n.G3, -16, n.C4, -16, n.B3, -16, n.G3, -16, n.B3, -16, n.G3, -16, n.E3, -16
    });
    n.addMelody("imperialMarch","Star Wars - Imperial March",{
        // Measure 1
        n.A4, n.A4, n.A4,
        n.F4, n.C5, n.A4,
        // Measure 2
        n.F4, n.C5, n.A4,
        // Measure 3
        n.E5, n.E5, n.E5,
        n.F5, n.C5, n.GS4,
        // Measure 4
        n.F4, n.C5, n.A4
    },{
        // Measure 1
        4, 4, 4,
        8, 8, 2,
        // Measure 2
        8, 8, 2,
        // Measure 3
        4, 4, 4,
        8, 8, 2,
        // Measure 4
        8, 8, 2
    });
    n.addMelody("zeldaGBA", "Zelda GBA Item", {
        n.A4, n.B4, n.CS5, n.D5  // Alternative starting pitch
    }, {
        12, 12, 12, 2  // Slightly faster triplet
    });
}
    