#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int queue_enqueue(queue_t *q, int i)
{
    queue_node_t *n;
    if(!(n = malloc(sizeof(*n)))) // or queue_node_t instead of n but if rename you have to change that name.
    {
        return 1; // if malloc fails, return 1.
    }
    // do what needs to be done if no fail
    n->data = i; // node data gets i.
    n->next = NULL;
    q->length++; // increase length of queue.

    if(q->back)
    {
        q->back->next = n;
    }
    else
    {
        q->front = n;
    }
    q->back = n;

    return 0; // worked

}
int queue_dequeue(queue_t *q, int *i)
{
    queue_node_t *tmp;

    if(!q->length) // q is empty.
    {
        return 1; // return fail.
    }
    // if q is not empty, dequeue item.

    *i = q->front->data; // save value to return.

    tmp = q-> front; // save node to free it.
    q->front = q->front->next; // point to next item.
    free(tmp); // free tmp.
    if(!--q->length) // if the list is already empty.
    {
        q->back = NULL; // make back null.
    }

    return 0;
}
int queue_front(queue_t *q, int *i)
{
    if(!q->length) // q is empty.
    {
        return 1; // return fail.
    }

    *i = q->front->data; // save value to return.

    return 0;
}
int queue_length(queue_t *q)
{
    return q->length;
}
int queue_is_empty(queue_t *q)
{
    return !q->length;
}
int queue_init(queue_t *q)
{
    q->front = q->back = NULL;
    q->length = 0;

    return 0;
}
int queue_destroy(queue_t *q)
{
/*    while(queue_length()) // put params
    {
        queue_dequeue(); / put params
    }*/
    // don't do this because function calls takes a lot of performance ^^

    queue_node_t  *tmp;
    while((tmp = q->front)) // will return a warning to make sure you didnt mean ==. put extra () around to suppress.
    {
        q->front = q->front->next; // move front to next thing
        free(tmp);
    }

    // these assignments are not necessary, because the queue is already destroyed. It is an error to use this queue again,
    // regardless of whether we do these assignments or not.
    q->back = NULL;
    q->length = 0;

    return 0; // worked!
}

