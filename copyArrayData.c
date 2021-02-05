#include "config.h"
#include "arrays.h"
void copyArrayData(uchar data, uchar rowx)
{
    uchar colx = 0;
    gameArray[rowx][colx] = gameArray[rowx][colx]|data;
   // printf("%d  %d    %d\n", data, row, gameArray[row][col]);
}
