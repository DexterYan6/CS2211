/* CS2211a 2021 */
/* Assignment 04 */
/* Dexter Yan */
/* 251155849 */
/* dyan53 */
/* November 10, 2021 */

#include "headers.h"

//function to combine all previous arrays and fill last nTables cell
void combineArrays(int row, int column, int ***table, int nArrs) {
    table[nArrs] = malloc(sizeof(int*) * row);          //allocate memory for final 2d array
    for(int i = 0; i < row; i++) {
        table[nArrs][i] = malloc(sizeof(int) * column);     //allocate memory for each row in the 1d array
        for(int j = 0; j < column; j++) {
            table[nArrs][i][j] = 0;             //set each cell equal to 0 
        } 
    }
    
    for(int i = 0; i < row; i++) {          
        for(int j = 0; j < column; j++) {
            for(int k = 0; k < nArrs; k++) {
                table[nArrs][i][j] = table[nArrs][i][j] + table[k][i][j];     //add up each position from each array and sum it into the new 2d array
            }
        }
    }
}