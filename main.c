#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main ()
{
    Queue *que = (Queue*)calloc(1, sizeof(Queue));
    int x = 0;
    QCtor (que, 3, "first_que");
    QPushB (que, 1);
    QPushB (que, 2);
    QPushB (que, 3);
    QPushB (que, 4);
    QPushF (que, 11);
    QDump (que);
    QPopF (que, &x);
    QPopF (que, &x);
    QPopF (que, &x);
    QPopF (que, &x);
    QPopF (que, &x);
    QDump (que);
    QPopF (que, &x);
    QDump (que);
    /*
    QPopF (que, &x);
    printf ("%d\n", x);

    QPopF (que, &x);
    printf ("%d\n", x);

    QPopF (que, &x);
    printf ("%d\n", x);
    
    QPopF (que, &x);
    printf ("%d\n", x);
    */
    
    QDtor (que);
    return 0;
}