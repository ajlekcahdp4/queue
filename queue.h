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


void QCtor(Queue* que, unsigned int capacity, char* Qname);
void QDtor (Queue* que);
void QPushB (Queue* que, int val);
void QPushF (Queue* que, int val);
void QPopF (Queue* que, int* dest);
void QPopB (Queue* que, int* dest);
int QCheck (Queue* que);
void QResize (Queue* que, int capacity);
void QBResize (Queue* que, unsigned int capacity);
void QFResize (Queue* que, unsigned int capacity);
void QDump (Queue* que);
