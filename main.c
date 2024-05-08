#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

int main(int argc, char** argv) {
    PRIORITY_QUEUE Queue = priority_queue_init_default();
    Status status;

    priority_queue_insert(Queue, 3, 10);
    priority_queue_insert(Queue, 2, 90);
    priority_queue_insert(Queue, 1, 11);

    print_queue_test(Queue);
    print_front_of_queue_test(Queue);
    printf("Servicing priority queue\n");
    //priority_queue_service(Queue);
    priority_queue_service(Queue);
    print_front_of_queue_test(Queue);

    if (priority_queue_is_empty(Queue) == FALSE) {
        printf("PRIORITY QUEUE IS NOT EMPTY\n");
    } else if (priority_queue_is_empty(Queue) == TRUE) {
        printf("PRIORITY QUEUE IS EMPTY\n");
    }

    priority_queue_destroy(&Queue);
    return 0;
}