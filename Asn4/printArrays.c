/* CS2211a 2021 */
/* Assignment 04 */
/* Dexter Yan */
/* 251155849 */
/* dyan53 */
/* November 10, 2021 */

#include "headers.h"

//function to print out arrays
void printArrays(int ***table, int nArrs, int row, int column, int sorted) {
    if(sorted == 1) {     //once array has been sorted
        printf("\nFinal Sorted Array:\n");
        for(int i = 0; i < row; i++) {     //print out each element in a 2d array format
            for (int j = 0; j < column; j++) {
                printf("%5d", table[nArrs][i][j]);     
            }
            printf("\n");
        }
    }
    else {     //if array has not been sorted
        printf("Randomly initialized arrays:\n");
        for(int i = 0; i < nArrs; i++) {     //print out each element in a 2d array format
            for(int j = 0; j < row; j++){
                for(int k = 0; k < column; k++){
                    printf("%5d", table[i][j][k]);      
                }
                printf("\n");
            }
            printf("\n");
        } 
    }
    
   
}