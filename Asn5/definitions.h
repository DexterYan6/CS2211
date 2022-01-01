#ifndef DEFINITIONS_H_INCLUDED
#define DEFINITIONS_H_INCLUDED

typedef struct node
{
    void* dataPtr; // pointer to document structure
    struct node* next; // must be a singly linked list
} LIST_NODE;

typedef struct doc{
    int docNum;
    int priority;
    int pages;
    int cycles;
} doc;

typedef struct{
    LIST_NODE *head;
    int count;
} LIST;

#define PAGESPERMINUTE 1
#define MAXCYCLES 200
#define MAXPAGES 30
#define ITERATIONS 1000
#define DEBUG_SHOW_EXCEEDED 0

#include "printJob.c"
#include "list.c"
#include "printQueue.c"
#include "createList.c"

#endif
