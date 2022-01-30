typedef struct Queue 
{
    unsigned int capacity;
    unsigned int bp;
    unsigned int fp;
    int * data;
} Queue;

void QueCtor(Queue* que, unsigned int capacity);
void QueDtor (Queue* que);
void QuePushB (Queue* que, int val);
void QuePopF (Queue* que, int* dest);