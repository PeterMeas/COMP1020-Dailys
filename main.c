#include "stack.h"
#include <stdio.h>
#include "string.h"
#include <stdlib.h>

int main(int argc, char** argv) {
    int n;
    scanf("%d\n", &n);
    char s[STACK_MAX_LEN + 1];

    for (int i = 0; i < n; ++i) {
        fgets(s, sizeof(s), stdin);
        s[strcspn(s, "\n")] = '\0';

        if (isCorrect(s)) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}