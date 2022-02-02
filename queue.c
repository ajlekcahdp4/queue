#include "queue.h"


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
    if (que->bp == que->capacity)
        QResize (que, 2*que->capacity);
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
    if (que->fp > que->bp)
    {
        fprintf(que->logfile, "ERROR: queue underflow\n");
        return 1;
    }
    if (que->fp < 0 )
    {
        fprintf (que->logfile, "ERROR: wrong front pointer\n");
        return 2;
    }
    if (que->bp < 0)
    {
        fprintf (que->logfile, "ERROR: wrong back pointer\n");
        return 3;
    }
    return 0;
}

void QResize (Queue* que, unsigned int capacity)
{
    int* temp_data = (int*)calloc(que->capacity, sizeof(int));
    int old_capacity = que->capacity;
    memcpy (temp_data, que->data, old_capacity*sizeof(int));
    que->capacity = capacity;
    que->data = realloc (que->data, capacity * sizeof(int));
    int i = 0;
    while (i < capacity)
    {
        if (i < que->fp)
            que->data[i] = 0;
        else if (i >= que->bp)
            que->data[i] = 0;
        i++;
    }
    memcpy (que->data, temp_data, old_capacity*sizeof(int));
    free(temp_data);
}

void QDump (Queue* que)
{
    fprintf (que->logfile, "Dump: \n");
    fprintf(que->logfile, "capacity = %u\n", que->capacity);
    fprintf(que->logfile, "fp = %u\n", que->fp);
    fprintf(que->logfile, "bp = %u\n", que->bp);
    fprintf(que->logfile, "data = %p\n", que->data);
    for (int i = 0; i < que->capacity; i++)
    {
        fprintf(que->logfile, "[%d] = %d\n", i, que->data[i]);
    }
    fprintf(que->logfile, "\n\n");
}
