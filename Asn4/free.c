/* CS2211a 2021 */
/* Assignment 04 */
/* Dexter Yan */
/* 251155849 */
/* dyan53 */
/* November 10, 2021 */

#include "headers.h"

//free up previously allocated memory for elements
void freeTable(int ***table, int row, int column, int nArrs) {
    for(int i = 0; i < nArrs + 1; i++){
        for(int j = 0; j < row; j++) {
            free(table[i][j]);    //work backwards; free up the allocated space for the row pointers
        }
        free(table[i]);        //free up allocated space for 2d array
    }
    free(table);         //free up allocated space for triple array
}