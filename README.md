# MyQueue
## This is a repo with my realization of ring buffer queue data type
## My queue has functions:
### QPushB (Queue Push Back)
This function push value to the tail of the queue.
### QPushF (Queue Push Front)
This function push value to the head of the queue. 
### QPopF (Queue Pop Front)
This function pop value from the head of the queue.
### QPopB (Queue Pop Back)
This function pop value from the tail of the queue.
### QDump
This function fill logfile with the dump of the queue.
## Example of usage:
```c
#include <stdio.h>
#include <stdlib.h>
#include "queue/queue.h" // including queue in our program

int main ()
{
    Queue *que = (Queue*)calloc(1, sizeof(Queue)); //allocated buffer for queue poiner

    QCtor (que, 4, "first_que_logfile.txt"); //Initialisation and constructing queue structure of capacity 4 and logfile "first_que_logfile.txt"
    
    QPushB (que, 1);    // Push 1 to the tail
    QDump (que);        // Dump our queue in logfile 
    
    QPushB (que, 2);    
    QDump (que);        // pic *
    
    QPushF (que, 3);    // Push 3 to the head of queu (the buffer is ringed) 
    QDump (que);        // pic **
    
    QPushF (que, 4);
    QDump (que);        // pic ***
    
    QPushF (que, 5);    //cousing queue resize
    QDump (que);        // pic ****
    
    QPushF (que, 6);
    QDump (que);

    int x = 0;          
    QPopF (que, &x);    // Pop the number in the head of queue to the x
    QPopF (que, &x);
    QPopF (que, &x);

    QDtor (que);        // Destruction of queue

    return 0;
}
```
## Examples of logfile
*Dump after "QPushB (que, 2);":
<p align="center">
<img src="https://github.com/ajlekcahdp4/queue/blob/main/examples_of_logfile/bef_circ.png">
</p>
** Dump after "QPushF (que, 3);" (buffer ringed):
<p align="center">
<img src="https://github.com/ajlekcahdp4/queue/blob/main/examples_of_logfile/aft_circ.png">
</p>
*** Dump right befor resizing:
<p align="center">
<img src="https://github.com/ajlekcahdp4/queue/blob/main/examples_of_logfile/bef_resize.png">
</p>
*** Dump right after resize:
<p align="center">
<img src="https://github.com/ajlekcahdp4/queue/blob/main/examples_of_logfile/aft_resize.png">
</p>