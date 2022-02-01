#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main ()
{
    Queue *que = (Queue*)calloc(1, sizeof(Queue));
    int x = 0;
    QCtor (que, 10, "first_que");
    QPushB (que, 1);
    QPushB (que, 2);
    QPushB (que, 3);

    QPopF (que, &x);
    printf ("%d\n", x);

    QPopF (que, &x);
    printf ("%d\n", x);

    QPopF (que, &x);
    printf ("%d\n", x);
    
    QDtor (que);
    return 0;
}