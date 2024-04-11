#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_STACK_SIZE 5

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int isEmpty() {
    return (top == -1);
}

int isFull() {
    return (top == MAX_STACK_SIZE - 1);
}

void push(element item) {
    if (isFull()) {
        fprintf(stderr, "Stack is full\n");
        return;
    }
    else {
        top = top + 1;
        stack[top] = item;
        printf("Push : %d\n", item);
        printf("Stack elements : ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int pop() {
    if (isEmpty()) {
        fprintf(stderr, "Stack is empty\n");
        return -1;
    }
    else {
        int popValue = stack[top];
        top = top - 1;
        printf("Popped : %d\n", popValue);
        printf("Stack elements : ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
        return popValue;
    }
}

int main(int argc, char* argv[]) {
    srand(time(NULL));

    int rand_num = 0;
    for (int i = 0; i < 30; ++i) {
        int rand_num = rand() % 100 + 1;
        printf("Current rand_num: %d | %s\n", rand_num, rand_num % 2 == 0 ? "Even" : "Odd");
        if (rand_num % 2 == 0) {
            push(rand_num);
        }
        else {
            pop();
        }
    }

    return 0;
}
