#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void QueCtor(Queue* que, unsigned int capacity)
{
    que->data = (int*)calloc (capacity, sizeof(int));
    que->capacity = capacity;
    que->bp = 0;
    que->fp = 0;
}

void QuePushB (Queue* que, int val)
{
    que->data[que->bp] = val;
    que->bp += 1;
}

void QuePopF (Queue* que, int* dest)
{
    *dest = que->data[que->fp];
    que->data[que->fp] = 0;
    que->fp += 1;
}

void QueDtor (Queue* que)
{
    free (que->data);
    free (que);
}