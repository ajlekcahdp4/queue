#include "queue.h"

enum ERRORS {ERR_QUEUE_ZERO_POINTER};

int QCtor(Queue* que, unsigned int capacity, char* Qname)
{
    if (que == 0)
        return ERR_QUEUE_ZERO_POINTER;
    que->data = (int*)calloc (capacity, sizeof(int));
    que->capacity = capacity;
    que->bp = 0;
    que->fp = 0;
    que->logfile = fopen (Qname, "w");
    return 0;
}

int QPushB (Queue* que, int val)
{
    if (que == 0)
        return ERR_QUEUE_ZERO_POINTER;
    if ((que->bp - que->fp) % que->capacity == 0 && que->bp != 0)
    {
        QResize (que, 2*que->capacity);
    }
    que->data[que->bp] = val;
    que->bp = (que->bp + 1) % que->capacity;
    return 0;
}

int QPushF (Queue* que, int val)
{
    if (que == 0)
        return ERR_QUEUE_ZERO_POINTER;
    if ((que->bp - que->fp) % que->capacity == 0 && que->bp != 0)
    {
        QResize (que, 2*que->capacity);
    }
    que->fp = (que->fp - 1 + que->capacity) % que->capacity;
    que->data[que->fp] = val;
    return 0;
}

int QPopF (Queue* que, int* dest)
{
    if (que == 0)
        return ERR_QUEUE_ZERO_POINTER;
    *dest = que->data[que->fp];
    que->data[que->fp] = 0;
    que->fp += 1;
    return 0;
}

int QPopB (Queue* que, int* dest)
{
    if (que == 0)
        return ERR_QUEUE_ZERO_POINTER;
    *dest = que->data[que->bp];
    que->data[que->bp - 1] = 0;
    que->bp -= 1;
    return 0;
}

int QDtor (Queue* que)
{
    if (que == 0)
        return ERR_QUEUE_ZERO_POINTER;
    fclose (que->logfile);
    free (que->data);
    free (que);
    return 0;
}


int QResize (Queue* que, int capacity)
{
    //int old_capacity = que->capacity;
    if (que == 0)
        return ERR_QUEUE_ZERO_POINTER;
    if (que->bp > que->fp)
    {
        int* temp_data = (int*)calloc(que->capacity, sizeof(int));
        memcpy (temp_data, que->data, que->capacity*sizeof(int));
        
        que->data = realloc (que->data, capacity * sizeof(int));
        int i = 0;
        while (i < capacity)
        {
            que->data[i] = 0;
            i++;
        }

        memcpy (que->data, temp_data, que->capacity*sizeof(int));
        que->capacity = capacity;
        free(temp_data);
    }
    else if (que->bp == que->fp)
    {
        int* temp_data_b = (int*)calloc(que->capacity, sizeof(int));
        int* temp_data_f = (int*)calloc(que->capacity, sizeof(int));
        memcpy (temp_data_b, que->data, que->bp*sizeof(int));
        memcpy (temp_data_f, que->data + que->fp, (que->capacity - que->fp)*sizeof(int));
        
        que->data = realloc (que->data, capacity * sizeof(int));
        int i = 0;
        while (i < capacity)
        {
            que->data[i] = 0;
            i++;
        }

        memcpy (que->data, temp_data_b, que->bp*sizeof(int));
        memcpy (que->data + (capacity - (que->capacity - que->fp)), temp_data_f, (que->capacity - que->fp)*sizeof(int));
        que->fp = que->fp + capacity - que->capacity;
        que->capacity = capacity;
        free (temp_data_b);
        free (temp_data_f);
    }
    return 0;
}


int QDump (Queue* que)
{
    if (que == 0)
        return ERR_QUEUE_ZERO_POINTER;
    fprintf (que->logfile, "Dump: \n");
    fprintf(que->logfile, "capacity = %u\n", que->capacity);
    fprintf(que->logfile, "fp = %u\n", que->fp);
    fprintf(que->logfile, "bp = %u\n", que->bp);
    fprintf(que->logfile, "data = %p\n", que->data);
    for (unsigned int i = 0; i < que->capacity; i++)
    {
        if ((i >= que->fp && i < que->bp) || (i >= que->fp && que->bp <= que->fp) || (i < que->bp &&  que->bp <= que->fp))
            fprintf(que->logfile, "*[%d] = %d\n", i, que->data[i]);
        else
            fprintf(que->logfile, " [%d] = %d\n", i, que->data[i]);
        
    }
    fprintf(que->logfile, "\n\n");
    return 0;
}
