/* CS2211a 2021 */
/* Assignment 04 */
/* Dexter Yan */
/* 251155849 */
/* dyan53 */
/* November 10, 2021 */

#include "headers.h"

//function to initialize 2d arrays
void initArrays(int row, int column, int ***table, int nArrs) {
    srand(time(NULL));

    int totalElem = row * column;     //total elements in each 2d array

    for(int i = 0; i < nArrs; i++) {             //initialize each 2d array inside nArrs
        table[i] = malloc(sizeof(int*) * row);          //set space for each 2d array
        for(int j = 0; j < row; j++) {
            table[i][j] = malloc(sizeof(int) * column);           //initialize and set space for each row in 2d array
            for(int k = 0; k < column; k++) {
                int r = (rand() % ((10 * totalElem) - 10)) + 1;          //fill each cell in every array
                table[i][j][k] = r;
            }   
        }
        table[i][row - 1][column - 1] = 0;          //final element in each 2d array is set to 0
    }    
}