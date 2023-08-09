#include <stdio.h>
#include <stdlib.h>
#define ss 1000 // Updated stack size constraint

int mstack[1000], top = -1;

void push(int ele) {
    if (top == ss - 1) {
        printf("\n   ***   Stack is full  ***     \n");
        return;
    }
    top++;
    mstack[top] = ele;
    printf("\nElement pushed inside is %d\n", mstack[top]);
}

int pop() {
    if (top == -1) {
        printf("\nStack is empty\n");
        return -1;
    }
    int ele = mstack[top];
    top--;
    printf("\nElement popped is %d\n", ele);
}

void size() {
    printf("\nSize of the stack is %d\n", top + 1);
}

void display() {
    int i;
    printf("\nElements are: ");
    for (i = 0; i <= top; i++) {
        printf("%d ", mstack[i]);
    }
    printf("\n");
}

void reverseStack(int index) {
    if (index == top) {
        return;
    }
    int temp = mstack[index];
    reverseStack(index + 1);
    push(temp);
}

int main() {
    int choice, ele, N;
    printf("Enter the number of elements in the stack: ");
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &ele);
        push(ele);
    }

    printf("\nOriginal stack: ");
    display();
    
    reverseStack(0);

    printf("\nReversed stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", mstack[i]);
    }
    printf("\n");

    return 0;
}
