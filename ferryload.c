#include <stdio.h>
#include <stdlib.h>
#include "ferryload.h"

typedef struct
{
    int length;
    struct Car* next;
}Car;

typedef struct
{
    Car* front;
    Car* rear;
    int count;
}Queue;

QUEUE initQueue()
{
    Queue *pQueue = (Queue*)malloc(sizeof(Queue));
    if (pQueue == NULL)
    {
        return NULL;
    }
    pQueue->front = pQueue->rear = NULL;
    pQueue->count = 0;
    return pQueue;
}

int isEmpty(QUEUE pQueue)
{
    if(pQueue == NULL)
    {
        return 1;
    }
    Queue *phQueue = (Queue*)pQueue;
    return phQueue->count == 0;
}

void enqueue(QUEUE pQueue, int length)
{
    if (pQueue == NULL)
    {
        return;
    }
    Queue* phQueue = (Queue*)pQueue;
    Car* newCar = (Car*)malloc(sizeof(Car));
    if (newCar == NULL) return;
    newCar->length = length;
    newCar->next = NULL;
    if (phQueue->rear == NULL)
    {
        phQueue->front = phQueue->rear = newCar;
    }
    else {
        phQueue->rear->next = newCar;
        phQueue->rear = newCar;
    }
    phQueue->count++;
}

int dequeue(QUEUE pQueue)
{
    if (pQueue == NULL) return -1;
    Queue* phQueue = (Queue*)pQueue;
    if (isEmpty(pQueue))
    {
        return -1;
    }
    Car* temp = phQueue->front;
    int length = temp->length;
    phQueue->front = phQueue->front->next;
    if (phQueue->front == NULL)
    {
        phQueue->rear = NULL;
    }
    free(temp);
    phQueue->count--;
    return length;
}

int ferryLoad(QUEUE left, QUEUE right, int ferryLength)
{
    if (left == NULL || right == NULL) return -1;
    Queue* LEFT = (Queue*)left;
    Queue* RIGHT = (Queue*)right;
    int cross = 0;
    int currBank = 0;
    while (!isEmpty(LEFT) || !isEmpty(RIGHT))
    {
        int load = 0;
        if (currBank == 0)
        {
            while (!isEmpty(LEFT) && load + LEFT->front->length <= ferryLength)
            {
                load += dequeue(LEFT);
            }
        }
        else
        {
            while (!isEmpty(RIGHT) && load + RIGHT->front->length <= ferryLength)
            {
                load += dequeue(RIGHT);
            }
        }
        currBank = 1 - currBank;
        cross++;
    }
    return cross;
}
