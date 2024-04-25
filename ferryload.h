#ifndef FERRYLOAD_H
#define FERRYLOAD_H

typedef void* QUEUE;

int ferryLoad(QUEUE left, QUEUE right, int ferryLength);
int dequeue(QUEUE phQueue);
void enqueue(QUEUE phQueue, int length);
int isEmpty(QUEUE hQueue);
QUEUE initQueue(void);



#endif