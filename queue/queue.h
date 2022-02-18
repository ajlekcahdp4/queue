#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Queue 
{
    unsigned int capacity;
    unsigned int bp;
    unsigned int fp;
    int * data;
    FILE* logfile;
} Queue;


int QCtor(Queue* que, unsigned int capacity, char* Qname);
int QDtor (Queue* que);
int QPushB (Queue* que, int val);
int QPushF (Queue* que, int val);
int QPopF (Queue* que, int* dest);
int QPopB (Queue* que, int* dest);
int QResize (Queue* que, int capacity);
int QDump (Queue* que);
