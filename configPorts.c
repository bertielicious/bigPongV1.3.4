#include "config.h"
void configPorts(void)
{
    TRISAbits.TRISA5 = LO;  // diagnostic LED pin 2
    TRISBbits.TRISB6 = LO;  // SCK is an output pin 11
    TRISCbits.TRISC7 = LO;  // SDO is an output pin 9
    TRISCbits.TRISC6 = LO; // select slave pin 8
    
    //********CLEAR ALL OUTPUTS**********************
    SDO = LO;
    SCK = LO;
    CS = LO;
   /***********************Pushbutton Inputs***********************/ 
    TRISCbits.TRISC5 = HI;  // Left pushbutton input pin 5
    TRISCbits.TRISC4 = HI;  // Right pushbutton input pin 6    
}
