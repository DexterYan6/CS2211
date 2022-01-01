/* CS2211a 2021 */
/* Assignment 05 */
/* Dexter Yan */
/* 251155849 */
/* dyan53 */
/* December 01, 2021 */

#include "headers.h"

LIST *createList(void) {     //creating empty linked list
    LIST* list;
    list = (LIST*)malloc(sizeof(LIST));
    list->count = 0;
    list->head = NULL;
    return list;
}