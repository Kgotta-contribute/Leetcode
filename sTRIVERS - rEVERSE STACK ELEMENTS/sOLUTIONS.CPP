#include <iostream>
#define ss 1000 // Updated stack size constraint

int mstack[1000], top = -1;

void push(int ele) {
    if (top == ss - 1) {
        cout << "\n   ***   Stack is full  ***     \n";
        return;
    }
    top++;
    mstack[top] = ele;
    cout << "\nElement pushed inside is " << mstack[top] << "\n";
}

int pop() {
    if (top == -1) {
        cout << "\nStack is empty\n";
        return -1;
    }
    int ele = mstack[top];
    top--;
    cout << "\nElement popped is " << ele << "\n";
    return ele;
}

void size() {
    cout << "\nSize of the stack is " << top + 1 << "\n";
}

void display() {
    int i;
    cout << "\nElements are: ";
    for (i = 0; i <= top; i++) {
        cout << mstack[i] << " ";
    }
    cout << "\n";
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
    cout << "Enter the number of elements in the stack: ";
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> ele;
        push(ele);
    }

    cout << "\nOriginal stack: ";
    display();
    
    reverseStack(0);

    cout << "\nReversed stack: ";
    for (int i = 0; i <= top; i++) {
        cout << mstack[i] << " ";
    }
    cout << "\n";

    return 0;
}




=======================================================================================




// JAVA CODE : - 

import java.util.Scanner;

public class StackExample {
    final int ss = 1000;
    int[] mstack = new int[ss];
    int top = -1;

    void push(int ele) {
        if (top == ss - 1) {
            System.out.println("\n   ***   Stack is full  ***     \n");
            return;
        }
        top++;
        mstack[top] = ele;
        System.out.println("\nElement pushed inside is " + mstack[top]);
    }

    int pop() {
        if (top == -1) {
            System.out.println("\nStack is empty\n");
            return -1;
        }
        int ele = mstack[top];
        top--;
        System.out.println("\nElement popped is " + ele);
        return ele;
    }

    void size() {
        System.out.println("\nSize of the stack is " + (top + 1) + "\n");
    }

    void display() {
        System.out.print("\nElements are: ");
        for (int i = 0; i <= top; i++) {
            System.out.print(mstack[i] + " ");
        }
        System.out.println("\n");
    }

    void reverseStack(int index) {
        if (index == top) {
            return;
        }
        int temp = mstack[index];
        reverseStack(index + 1);
        push(temp);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of elements in the stack: ");
        int N = scanner.nextInt();

        StackExample stackExample = new StackExample();

        for (int i = 0; i < N; i++) {
            System.out.print("Enter element " + (i + 1) + ": ");
            int ele = scanner.nextInt();
            stackExample.push(ele);
        }

        System.out.println("\nOriginal stack: ");
        stackExample.display();

        stackExample.reverseStack(0);

        System.out.println("\nReversed stack: ");
        for (int i = 0; i <= stackExample.top; i++) {
            System.out.print(stackExample.mstack[i] + " ");
        }
        System.out.println("\n");

        scanner.close();
    }
}
