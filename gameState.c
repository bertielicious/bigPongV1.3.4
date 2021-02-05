#include "config.h"
#include "clearScreen.h"
#include "clearGameArray.h"
#include "arrays.h"
#include "splashScreen.h"
#include "writeMatrix.h"
#include "printDigit.h"
#include "paddleMove.h"
#include <stdio.h>
uchar gameState(uchar state)
{                                           // PONG FSM
    uchar row, col = 0;
    uchar paddlePos = 3;// paddlePos can be 1-6, low lowest position, 6 highest position
    switch(state)
    {
        case 0:
            state = 1;// reset state
            break;
        case 1:
            clearScreen();
            splashScreen(splishR, splishL);// display "PONG" for 2 sec
            __delay_ms(2000);
             clearScreen();
            state = 2;
            break;
        case 2 :
            splashScreen(plyL, plyR);// display L 1 R 2 player
            while(LPB&&RPB==HI);     // wait for player selection button press
            if(LPB==LO&&RPB==HI)     // L = 1 plyr, R = 2 plyr
            {
                state = 3;
            }
            else if(LPB==HI&&RPB==LO)
            {
                state = 4;
            }
            break;
        case 3:
            
             clearScreen();
             writeMatrix();         // draw left paddle and right wall
             state = 5;
            
            
            break;
           
        case 4:
            col = 15;
            for(row=0; row<8;row++)
            {
                gameArray[row][col]=0;
            }
            col = 15;
            for(row=2; row<5;row++)
            {
                gameArray[row][col]=1;
            }
            writeMatrix();          // draw left paddle and right paddle
            state = 5;
            break;
        case 5:
            
            printDigit(6,8,tres);
            __delay_ms(1000);
            printDigit(6,8,dos);
            __delay_ms(1000);
            printDigit(6,8,uno);
            __delay_ms(1000);
            printDigit(6,8,cero);
            __delay_ms(1000);
            printDigit(6,8,null);
            state = 6;
            break;
        case 6:
             clearScreen();
             GIE = 1;
           
            break;
    }   
    return state;
}
