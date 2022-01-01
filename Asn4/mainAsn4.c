/* CS2211a 2021 */
/* Assignment 04 */
/* Dexter Yan */
/* 251155849 */
/* dyan53 */
/* November 10, 2021 */

#include "headers.h"

int main() {
    int nArrs, row, column;
    int ***nTables;

    printf("\nEnter the number of arrays (0 to quit): ");
    printf("\\");
    scanf("%d", &nArrs);
    
    while(nArrs != 0) {
        printf("\nEnter values for Rows Columns (e.g.2 3): ");
        scanf("%d %d", &row, &column);
        
        nTables = (int ***) calloc (nArrs + 1, sizeof(int **));     //allocate memory for triple pointer table
        
        initArrays(row, column, nTables, nArrs);
        
        combineArrays(row, column, nTables, nArrs);
        
        int PRINTTOTALSORTED = 0;          //variable to tell whether or not to print the final sorted array
        printArrays(nTables, nArrs, row, column, PRINTTOTALSORTED);

        arraySort(nTables[nArrs], row, column);
        PRINTTOTALSORTED = 1;
        printArrays(nTables, nArrs, row, column, PRINTTOTALSORTED);
        
        freeTable(nTables, row, column, nArrs);     //once all variables have been printed out, free memory

        printf("\nXXXXXX END OF SESSION XXXXXX\n\n");

        printf("Enter the number of arrays (0 to quit): ");
        scanf("%d", &nArrs);
        
    }
    return 0;
}