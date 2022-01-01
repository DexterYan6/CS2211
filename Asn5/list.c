/* CS2211a 2021 */
/* Assignment 05 */
/* Dexter Yan */
/* 251155849 */
/* dyan53 */
/* December 01, 2021 */

#include "headers.h"

void insert(LIST *queue, doc *docum) {       //inserting based on priority of list
    int done = 0;
    LIST_NODE *temp = (LIST_NODE*)malloc(sizeof(LIST_NODE));     //creating "new" pointer
    LIST_NODE *head = queue->head;
    
    temp->dataPtr = docum;

    if(queue->head == NULL) {        //if the queue is empty add to queue
        queue->head = (LIST_NODE*)malloc(sizeof(LIST_NODE));
        temp->next = NULL;
        queue->head = temp;
        return;
    }

    else if(((doc*)head->dataPtr)->priority > docum->priority) {    //checking the priority of the very first node
        temp->next = queue->head;                 //if current node has higher priority than head node current node is new head node
        queue->head = temp;
        return;
    }

    else if (((doc*)head->dataPtr)->priority == docum->priority && ((doc*)head->dataPtr)->pages >= docum->pages){   //still checking the priority based on doc pages
        temp->next = queue->head;
        queue->head = temp;
        return;
    }

   else {          //checking for priority of all other nodes
        while(done == 0) {            
            if(head->next == NULL) {      //if end of list is reached
                head->next = temp;        //node belongs at very end of list
                temp->next = NULL;
                done = 1;                 //finish the loop as the node has been inserted
            }
            else if(((doc*)head->next->dataPtr)->priority > docum->priority) {    //if the node spot is found in the middle
                temp->next = head->next;          //inserting node
                head->next = temp;
                done = 1;                  //finish the loop as the node has been inserted
            }
            else if(((doc*)head->next->dataPtr)->priority == docum->priority) {   //if priority between documents is the same
                if(((doc*)head->next->dataPtr)->pages >= docum->pages){           //check for which document has less pages
                    temp->next = head->next;       //should the current document have more pages, it will have lower priority
                    head->next = temp;
                    done = 1;
                }
            }
            head = head->next;            //traverse the linked list as the node has not been inserted yet
        }
    }
}

void changeCycle(LIST *queue) {     //increment cycle
    LIST_NODE *head = queue->head;
    while(head) {
        (((doc*)head->dataPtr)->cycles)++;
        if(((doc*)head->dataPtr)->cycles == MAXCYCLES) {
            if(DEBUG_SHOW_EXCEEDED == 1) {
                printf("EXCEEDED CYCLE COUNT - Document: %3d,     Pages: %3d     Priority: %3d     Cycle Count: %3d\n", ((doc*)head->dataPtr)->docNum, ((doc*)head->dataPtr)->pages, ((doc*)head->dataPtr)->priority, ((doc*)head->dataPtr)->cycles);
            }
        }
        printf("Increment Cycle - Document: %3d     Pages: %3d     Priority: %3d     Cycle Count: %3d\n", ((doc*)head->dataPtr)->docNum, ((doc*)head->dataPtr)->pages, ((doc*)head->dataPtr)->priority, ((doc*)head->dataPtr)->cycles);
        head = head->next;
    }
}

int totalElem(LIST *queue) {      //get the total elements in the list
    int total = 0;
    LIST_NODE *head = queue->head;

    while(head) {
        total++;
        head = head->next;
    }
    printf("Current Printer Queue Size: %d\n", total);
    return total;
}

void printStuff(LIST *queue) {     //print all the elements in the queue
    int done  = 0;
    if(queue->head == NULL) {
        printf("EMPTY QUEUE - no print jobs currently in queue\n");
    }
    else {
        LIST_NODE *head = queue->head;
        while(head) {
            printf("Current Printer Queue: DocNum: %3d     NumofPages: %3d     Prioritylevel: %3d     NumofCycles   %d\n", ((doc*)head->dataPtr)->docNum, ((doc*)head->dataPtr)->pages, ((doc*)head->dataPtr)->priority, ((doc*)head->dataPtr)->cycles);
            head = head->next;
        }
        printf("END OF LIST\n\n");
    }   
}

