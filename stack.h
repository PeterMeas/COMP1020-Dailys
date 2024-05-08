#ifndef STACK_H
#define STACK_H

#define STACK_MAX_LEN 1000

typedef struct {
    char data[STACK_MAX_LEN];
    int top;
} CharStack;

// Function prototypes
void initStack(CharStack* stack);
int isEmpty(const CharStack* stack);
int isFull(const CharStack* stack);
int push(CharStack* stack, char item);
char pop(CharStack* stack);
int isCorrect(const char* s);


#endif /* STACK_H */