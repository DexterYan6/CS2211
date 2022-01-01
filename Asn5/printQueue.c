/* CS2211a 2021 */
/* Assignment 05 */
/* Dexter Yan */
/* 251155849 */
/* dyan53 */
/* December 01, 2021 */

#include "headers.h"

int printQ(LIST *queue) {        //taking the very first element of the queue
    int numPages = 0;
    if(queue->head != NULL) {
        numPages = ((doc*)queue->head->dataPtr)->pages;      //get number of pages document has
        LIST_NODE *temp;                 //the print job is being popped from queue, below is the popping process
        temp =  queue->head;
        queue->head = queue->head->next;
        free(temp);
    }
    return numPages;
    //printf("DocNum: %d,                   NumofPages   %d                    Prioritylevel   %d                  NumofCycles   %d\n", ((doc*)queue->head->dataPtr)->docNum, ((doc*)queue->head->dataPtr)->pages, ((doc*)queue->head->dataPtr)->priority, ((doc*)queue->head->dataPtr)->cycles);
    //queue->count--;
}

int getDocNum(LIST *queue) {        //getting the document number of the print job
    int docNum = 0;
    if(queue->head != NULL) {
        docNum = ((doc*)queue->head->dataPtr)->docNum;
    }
    return docNum;
}

int getPrioNum(LIST *queue) {       //getting the priority number of the print job
    int prioNum = 0;
    if(queue->head != NULL) {
        prioNum = ((doc*)queue->head->dataPtr)->priority;
    }
    return prioNum;
}
