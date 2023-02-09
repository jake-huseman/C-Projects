#include <stdio.h>
#include "queue.h"



int main(int argc, char *argv[])
{
    int i;
    queue_t q; // use this and pass the address bc the address is a pointer.
    // if you know how many you need you shouldn't be using malloc.
    queue_init(&q);
    // queue_t *q = malloc(...);
    //free(q);
    printf("%d ", queue_length(&q));
    for(i = 0; i < 100; i++)
    {
        queue_enqueue(&q, i);
    }
    //printf("%d ", queue_length(&q));
    printf("Queue is %s\n", queue_is_empty(&q) ? "empty" : "not empty"); //first one after ? is true and next is false

    queue_front(&q, &i);
    printf("Front: " "%d\n", i);

    while(!queue_dequeue(&q, &i))
    {
        printf("%d\n", i);
    }

    printf("Queue is %s\n", queue_is_empty(&q) ? "empty" : "not empty"); //first one after ? is true and next is false

    queue_destroy(&q);

}