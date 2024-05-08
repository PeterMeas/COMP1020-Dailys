/**********************************************************************
Program: daily7
 Author:  peter meas
 Date:4/25/2024
Time spent: 3hrs
 Purpose: write a program that takes as input from the keyboard a series of strings that can be of any length, printing yes or no if given string correct else no
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void initStack(CharStack* stack) {
    stack->top = -1;
}

int isEmpty(const CharStack* stack) {
    return stack->top == -1;
}

int isFull(const CharStack* stack) {
    return stack->top == STACK_MAX_LEN - 1;
}

int push(CharStack* stack, char item) {
    if (isFull(stack)) {
        printf("Error: Stack is full.\n");
        return 0;
    }

    stack->data[++stack->top] = item;
    return 1;
}

char pop(CharStack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty.\n");
        return '\0';
    }

    return stack->data[stack->top--];
}
int isCorrect(const char* s) {
    CharStack stack;
    initStack(&stack);

    for (int i = 0; s[i] != '\0'; ++i) {
        char ch = s[i];
        if (ch == '(' || ch == '[') {
            if (!push(&stack, ch)) {
                return 0;
            }
        }
        else {
            if (isEmpty(&stack)) return 0;
            char top = pop(&stack);
            if (ch == ')' && top != '(') return 0;
            if (ch == ']' && top != '[') return 0;
        }
    }
    return isEmpty(&stack);
}
