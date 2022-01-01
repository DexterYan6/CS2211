/* CS2211a 2021 */
/* Assignment 05 */
/* Dexter Yan */
/* 251155849 */
/* dyan53 */
/* December 01, 2021 */

#include "headers.h"
#include "definitions.h"

int main() {
    //variables
    srand(time(NULL));
    int newJob;
    int totalPages = 0;
    int docnum = 0;
    int currDocNum = 0;
    int currPrioNum = 0;
    int queueSize = 0;
    doc *docum;
    LIST *printQueue;

    printQueue = createList();    //create list

    for(int i = 0; i < ITERATIONS; i++) {    //looping based on number of iterations
        newJob = rand() % 10;        //random number generator
        if(newJob == 0) {            //10% chance of creating a new print job
            docnum++;
            docum = printJob(docnum);
        }
        else {
            docum = NULL;
        }
        //docum = printJob(); 
        //printf("%d,%d ", docum->priority, i);

        if(docum != NULL){             //if the document has been created
            insert(printQueue, docum);  //insert the document into the queue
            printf("Adding to Queue - Doc: %3d NoPages: %3d Priority: %3d\n", docum->docNum, docum->pages, docum->priority );
        }
        if(totalPages == 0) {        //if currently no print job, or if previous print job has been completed
            currDocNum = getDocNum(printQueue);
            currPrioNum = getPrioNum(printQueue);
            totalPages = printQ(printQueue);     //get new print job
        }
        else if(totalPages > 0){    //if print job is not completed
            totalPages--;
            printf("PRINTING - DOCUMENT: %3d  PAGE: %3d  priority:  %3d\n", currDocNum, totalPages, currPrioNum);   //keep printing current job
           
        }
        if(printQueue->head != NULL) {
            queueSize = totalElem(printQueue);
        }
        printStuff(printQueue);
        changeCycle(printQueue);
        printf("%d ", i);
    }
    printf("\nNumber of printer jobs left in queue: %d", queueSize);
    return 0;
}
