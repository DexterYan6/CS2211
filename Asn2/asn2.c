/* CS2211a 2021 */
/* Assignment 02 */
/* Dexter Yan */
/* 251155849 */
/* dyan53 */
/* October 06, 2021 */

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define ITERATIONS 3

int main() {
    printf("Assignment Two\n");
    srand(time(NULL));
    int r, a;
    int input, compVar;
    int iterationCounter = ITERATIONS;
    int size = (rand() % ((50 * ITERATIONS) - 50)) + 50;
    int arr[size];
    int sizeOfArr = sizeof(arr);
    int iterNum = 1;
    int debug = 0;
    printf("Value of random size of array: %d\n", size);
    printf("Size of array: %d bytes\n", sizeOfArr);

    //run depending on number of iterations
    for(a = 0; a < ITERATIONS; a++) {
        //biggest number that can be generated
        int max = pow(10, iterationCounter);  
        printf("THIS IS ITERATION NUMBER: %d of %d", iterNum, ITERATIONS);
        if(debug == 1) {
            printf("\nUpper Range Value: %d", max);
        }
        printf("\nThis is the original array populated with values in the range of 1 and %d", max);
        printf("\nNumber of elements in the original array is: %d", size);
        printf("\n");

        //loop to fill array with random numbers
        for(int i = 0; i < size; i++) {
            r = 1 + (rand() % max);
            arr[i] = r;
        }

        //loop to print out original array with all values
        for(int i = 0; i < size; i++) {
            if(i && !(i%24)) {
                printf("\n");
            }
            printf("%6ld", arr[i]);
        }

        //loop to remove duplicates
        int size1 = size;  //counter from the end of the array
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size1; j++) {
                if(arr[i] == arr[j] && i != j) {
                    if(debug == 1) {
                        printf("\nThe value of %d at array index [%d] and the value of %d at array index [%d] are the same.", arr[i], i, arr[j], j);
                    }
                    for(int k = j; k < size; k++) {
                        if(k < size - 1) {
                            arr[k] = arr[k+1];    //if duplicate number is found, move all numbers to the left
                        }
                        else {
                            arr[size - 1] = 0;   //last element is replaced with a 0
                        }
                    }
                size1--;
                j--;
                }
            }
        }

        printf("\nThis is the current state of the array with all duplicate values removed");
        printf("\nNumber of unique (non-zero, non-duplicate) elements in the array is: %d", size1);
        printf("\n");

        //loop to print all unique numbers without modification
        for(int i = 0; i < size1; i++) {
            if(i && !(i%24)) {
                printf("\n");
            }
            printf("%6ld", arr[i]);
        }

        //sorting array from lowest to highest
        for(int i = 1; i < size; i++) {
            int compVar = arr[i];     //saving number to compare to every other number in the array
            int j = i - 1;

            while(compVar < arr[j] && j >=0) {
                arr[j+1] = arr[j];  //if compared number is smaller than number move it to the left 
                --j;
            }
            arr[j+1] = compVar;
        }

        printf("\nThese are the unique, non-zero elements in the array sorted in ascending order: ");
        printf("\n");

        //loop to print out final modified array
        int count = -1;
        for(int i = 0; i < size; i++) {
            if(arr[i] != 0) {
                count++;
                if(count && !(count%24)) {
                    printf("\n");
                }
                printf("%6ld", arr[i]);
            }
        }
        printf("\n\n");

        //decrease iteration number so max numbers for array becomes smaller
        iterationCounter = iterationCounter - 1;
        iterNum++;
    }    
}
