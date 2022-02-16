#include <stdio.h>
#include <stdlib.h>
#include "queue/queue.h"

int main ()
{
    Queue *que = (Queue*)calloc(1, sizeof(Queue));
    int x = 0;
    QCtor (que, 4, "first_que");
    QPushB (que, 1);
    QDump (que);
    QPushB (que, 2);
    QDump (que);
    QPushF (que, 3);
    QDump (que);
    QPushF (que, 4);
    QDump (que);
    QPushF (que, 5);
    QDump (que);
    QPushF (que, 6);
    QDump (que);
    QPushF (que, 666);
    QDump (que);
    
    QPopF (que, &x);
    QPopF (que, &x);
    QPopF (que, &x);
    
    QDtor (que);
    return 0;
}