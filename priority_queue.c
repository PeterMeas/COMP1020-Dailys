#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "priority_queue.h"


typedef struct
{
    int priority;
    int data;
}Node;

typedef struct
{
    Node* heap;
    int capacity;
    int size;
}Queue;


//Precondition: Creates an empty priority queue that can store integer data items
// with different integer priority. Higher
// integer values indicate higher priority in the queue. For example, consider the // priority and the data value to be key-value pairs where the priority is the key // and the data is the value. The queue could hold 21,10 and 35, 5 so that the
// first item to be removed from the queue would be the data value 5 because
// it has higher priority (35) than the data value 10 which only has (21). //Postcondition: Returns the handle to an empty priority queue.
PRIORITY_QUEUE priority_queue_init_default(void)
{
    Queue *pQueue = (Queue*)malloc(sizeof(Queue));
    if (pQueue == NULL)
    {
        printf("failed allocation\n");
        exit(1);
    }
    pQueue->capacity = 10;
    pQueue->size = 0;
    pQueue->heap = (Node*)malloc(sizeof(Node) * pQueue->capacity);
    if (pQueue->heap == NULL)
    {
        free(pQueue->heap);
        return NULL;
    }
return pQueue;

}


// Postcondition: returns SUCCESS if the highest priority item was removed from the queue
// and FAILURE if the queue was empty.
Status priority_queue_service(PRIORITY_QUEUE hQueue)
{
    if (hQueue == NULL)
    {
        puts("INVALID HANDLE\n");
        return FAILURE;
    }
    Queue *pQueue = (Queue*)hQueue;
    if (pQueue->size == 0)
    {
        return FAILURE;
    }
    Node temp;

    temp = pQueue->heap[0];
    pQueue->heap[0] = pQueue->heap[pQueue->size-1];
    pQueue->heap[pQueue->size-1] = temp;
    pQueue->size--;
    //max heap fix down

    int index = 0; //root
    int index_leftChild = (2 * index )+ 1;
    int index_rightChild = (2* index) +2;
    int largest_index;

    while(index_leftChild < pQueue->size) {
        if (index_rightChild < pQueue->size &&
            pQueue->heap[index_rightChild].priority > pQueue->heap[index_leftChild].priority) {
            largest_index = index_rightChild;
        } else {
            largest_index = index_leftChild;
        }

        if (pQueue->heap[largest_index].priority > pQueue->heap[index].priority) {
            Node swap = pQueue->heap[largest_index];
            pQueue->heap[largest_index] = pQueue->heap[index];
            pQueue->heap[index] = swap;
            index = largest_index;
        }
        else
        {
            break;
        }
    }
    return SUCCESS;
}


//Precondition: hQueue is a handle to a valid priority queue opaque object.
// Higher priority_level values indicate higher priority in the queue.
// data_item is simply a value we are storing in the queue.
//Postcondition: returns SUCCESS if the item was successfully added to the queue
// and FAILURE otherwise.
Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item)
{
    if (hQueue == NULL)
    {
        printf("INVALID HANDLE\n");
        return FAILURE;
    }
    Queue* pQueue=(Queue*)hQueue;
    if (pQueue->size >= pQueue->capacity)
    {
        int new_capacity = pQueue->capacity * 2;
        Node* new_heap = (Node*)malloc(sizeof(Node) * new_capacity);
        if (new_heap == NULL)
        {
            printf("failed allocation\n");
            return FAILURE;
                }
                memcpy(new_heap, pQueue->heap, sizeof(Node) * pQueue->capacity);
                free(pQueue->heap);
                
                // Replace old heap with the new one
                pQueue->heap = new_heap;
                pQueue->capacity = new_capacity;
    }
    int index = pQueue->size;
   pQueue->heap[index].priority = priority_level;
   pQueue->heap[index].data = data_item;
   pQueue->size++;

   int index_of_parent = (index-1)/2;
   //perform fix up
   //maintain max heap property
   while (index > 0) //there is child..
   {
    if(pQueue->heap[index].priority > pQueue->heap[index_of_parent].priority)
        //if priority of heap[index] is greater than its parent,
        // indicates needs to be fixed up to maintain max heap properity
    {
        Node temp = pQueue->heap[index];
        pQueue->heap[index] = pQueue->heap[index_of_parent];
        pQueue->heap[index_of_parent] = temp;
        index = index_of_parent;
    }
    else
    {
        break;
    }
   }
   return SUCCESS;
}


// Postcondition: returns a copy of the data value for the
// highest priority item in the queue.
//
// Sets the variable at the address referred to in pStatus to SUCCESS if there is
// at least one item in the queue and FAILURE if no item.
// If pStatus is
//// passed in as NULL then the status value is ignored for this run of the
//  function.
int priority_queue_front(PRIORITY_QUEUE hQueue, Status* pStatus)
{
    if (hQueue == NULL)
    {
        printf("INVALID HANDLE\n");
        if (pStatus != NULL)
        {
            *pStatus = FAILURE;
        }
        return -1;
    }
    Queue *pQueue = (Queue*)hQueue;
    int index = pQueue->size;
    if (index == 0 && pStatus != NULL)
    {
        *pStatus = FAILURE;
    }
    else
    {
        *pStatus = SUCCESS;
    }
    return pQueue->heap[0].data;
}

//Precondition: hQueue is a handle to a valid priority queue opaque object. //Postcondition: returns TRUE if the priority_queue is empty and FALSE otherwise.

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue)
{
    if (hQueue == NULL) {
        printf("INVALID HANDLE\n");
        exit(1);
    }
    Queue *pQueue = (Queue *) hQueue;
    return (pQueue->size != 0) ? FALSE : TRUE;
}
//Precondition: phQueue is a pointer to the handle of a valid priority queue opaque object.
//Postcondition: The opaque object will be free'd from memory and the handle pointed to // by phQueue will be set to NULL.
void priority_queue_destroy(PRIORITY_QUEUE* phQueue)
{
    if (*phQueue == NULL)
    {
        puts("INVALID HANDLE\n");
        exit(1);
    }
    Queue *pQueue = (Queue*)*phQueue;
    free(pQueue->heap);
    free(pQueue);
    *phQueue = NULL;
}

void print_queue_test(PRIORITY_QUEUE* hQueue)
{
    if (hQueue == NULL)
    {
        printf("invalid handle\n");
        exit(1);
    }
    Queue* pQueue = (Queue*)hQueue;
    printf("Printing priority queue\n");
    for(int i=0; i<pQueue->size; i++)
    {
        printf("Priority [%d] Data [%d]\n", pQueue->heap[i].priority, pQueue->heap[i].data);
    }
    printf("\n");
}

void print_front_of_queue_test(PRIORITY_QUEUE* hQueue)
{
    if (hQueue == NULL)
    {
        printf("invalid handle\n");
        exit(1);
    }
    Queue* pQueue = (Queue*)hQueue;
    Status status;
    printf("Printing front of priority queue\n");
    int front = priority_queue_front(pQueue, &status);
    if (status == SUCCESS) {
        printf("Front of queue is %d\n", front);
    } else {
        printf("Empty queue\n");
    }
    printf("\n");
}
