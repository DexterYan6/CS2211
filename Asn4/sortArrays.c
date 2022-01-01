/* CS2211a 2021 */
/* Assignment 04 */
/* Dexter Yan */
/* 251155849 */
/* dyan53 */
/* November 10, 2021 */

#include "headers.h"

//sort final summed array in ascending order
void arraySort(int **array, int row, int column) {
    int allElem = row * column;
    int sortArr[allElem];          //create a 1d array to store all elements from 2d array
    
    int counter = 0;
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < column; ++j){
            sortArr[counter] = array[i][j];           //move each element from 2d array to 1d array
            ++counter;
        }
    }

    //perform insertion sort to sort array in ascending order
    int k,l;    // k is keeping track of sortArr's position
    for(int i = 1; i < allElem; i++) {
        int temp = sortArr[i];         //saving number to use for comparison
        k = i - 1;
        while(l >= 0 && sortArr[k] > temp) {         //compare number next to saved number 
            sortArr[k+1] = sortArr[k];          //swap the places of the compared numbers depending on which number is bigger or smaller
            k = k - 1;
        }
        sortArr[k + 1] = temp;
    }

    //put the newly sorted 1d array back into the 2d array
    counter = 0;
    for(int i = 0; i < row; i++) {            
        for(int j = 0; j < column; j++) {
            array[i][j] = sortArr[counter];
            ++counter;
        }
    }
}