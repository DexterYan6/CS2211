/* CS2211a 2021 */
/* Assignment 05 */
/* Dexter Yan */
/* 251155849 */
/* dyan53 */
/* December 01, 2021 */

#include "headers.h"

doc *printJob(int d) {           //creating the print job
    doc *docum;
    docum = (doc*)malloc(sizeof(doc));
    int createPrio = rand() % 10;   //random number generator

    docum->docNum = d;

    if(createPrio == 0) {   //10% chance of having job be priority 1
        docum->priority = 1;
    }
    else if(createPrio > 0 && createPrio < 7) {     //70% chance of having job be priority 2
        docum->priority = 2;
    }
    else {       //20% chance of having job be priority 3
        docum->priority = 3;
    }
    
    docum->pages = (rand() % MAXPAGES) + 1;    //document will have between 1 and MAXPAGES

    docum->cycles = 0;
    return docum;
}