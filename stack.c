#include <stdio.h>
#include <stdlib.h>

// Global variables
int stack[100];  // Maximum possible capacity
int top = -1;
int MAX;         // User-defined size

// Function declarations (optional but safe)
int isFull();
int isEmpty();
void push();
void pop();
void display();
void showMenu();

// ---------- USER-DEFINED FUNCTIONS ----------

// Check if stack is full
int isFull() {
    return top == MAX - 1;
}

// Check if stack is empty
int isEmpty() {
    return top == -1;
}

// Push element into stack
void push() {
    int item;
    if (isFull()) {
        printf("\nStack Overflow! Cannot push more elements.\n");
    } else {
        printf("Enter value to push: ");
        scanf("%d", &item);
        top++;
        stack[top] = item;
        printf("Element %d pushed successfully.\n", item);
    }
}

// Pop element from stack
void pop() {
    if (isEmpty()) {
        printf("\nStack Underflow! Nothing to pop.\n");
    } else {
        printf("Deleted element = %d\n", stack[top]);
        top--;
        printf("Element deleted successfully.\n");
    }
}

// Display stack contents
void display() {
    if (isEmpty()) {
        printf("\nStack is Empty.\n");
    } else {
        printf("\nCurrent Stack (Top to Bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

// Show menu options
void showMenu() {
    printf("\n-------STACK MENU-------\n");
    printf("1. PUSH (Insert)\n");
    printf("2. POP (Delete)\n");
    printf("3. DISPLAY (View Stack)\n");
    printf("4. EXIT\n");
    printf("Enter your choice: ");
}

// ---------- MAIN FUNCTION ----------
int main() {
    int choice;

  

    // Take user-defined stack size
    printf("\nEnter the maximum size of the stack : ");
    scanf("%d", &MAX);

    // Validate user input
    while (MAX <= 0 || MAX > 100) {
        printf("Invalid size! Enter again (1 to 100): ");
        scanf("%d", &MAX);
    }

    // Menu loop
    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
