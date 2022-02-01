#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void QCtor(Queue* que, unsigned int capacity, char* Qname)
{
    que->data = (int*)calloc (capacity, sizeof(int));
    que->capacity = capacity;
    que->bp = 0;
    que->fp = 0;
    que->logfile = fopen (Qname, "w");
}

void QPushB (Queue* que, int val)
{
    que->data[que->bp] = val;
    que->bp += 1;
    QCheck (que);
}

void QPopF (Queue* que, int* dest)
{
    *dest = que->data[que->fp];
    que->data[que->fp] = 0;
    que->fp += 1;
    QCheck (que);
}

void QDtor (Queue* que)
{
    fclose (que->logfile);
    free (que->data);
    free (que);
}

int QCheck (Queue* que)
{
    if (que->fp > que->bf)
        fprintf(que->logfile, "ERROR: queue underflow\n");
    if (que->fp < 0 )
        fprintf (que->logfile, "ERROR: wrong front pointer\n");
    if (que->bf < 0)
        fprintf (que->logfile, "ERROR: wrong back pointer\n");
        
}