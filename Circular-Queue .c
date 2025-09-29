#include <stdio.h>
#include <stdlib.h>

#define ERROR -9999

int *Queue;
int front = -1;
int rear = -1;
int MAX;   // size will be set by user

int enqueue(int x) {
    if ((front == 0 && rear == MAX - 1) || (rear == front - 1)) {
        printf("Queue is full\n");
        return ERROR;
    }
    if (front == -1) {
        front = rear = 0;
    }
    else if (rear == MAX - 1 && front != 0) {
        rear = 0;
    }
    else {
        rear++;
    }
    Queue[rear] = x;
    return 1;
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return ERROR;
    }
    int data = Queue[front];
    if (front == rear) {
        front = rear = -1;
    }
    else if (front == MAX - 1)
        front = 0;
    else
        front++;
    return data;
}

int checkfront() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return ERROR;
    }
    return Queue[front];
}

int checkrear() {
    if (rear == -1) {
        printf("Queue is Empty\n");
        return ERROR;
    }
    return Queue[rear];
}

int isfull() {
    if ((front == 0 && rear == MAX - 1) || (rear == front - 1))
        return 1;
    return 0;
}

int isEmpty() {
    return (front == -1);
}

int main() {
    int choice, x, op;

    // Ask user for queue size
    printf("Enter the size of the queue: ");
    scanf("%d", &MAX);

    Queue = (int *)malloc(MAX * sizeof(int));
    if (Queue == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    do {
        printf("\n**** MENU ****\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Check Front\n");
        printf("4. Check Rear\n");
        printf("5. IsFull\n");
        printf("6. IsEmpty\n");
        printf("7. Exit\n");
        printf("Enter your choice = ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter the number to be inserted = ");
                scanf("%d", &x);
                op = enqueue(x);
                if (op == ERROR)
                    printf("Element not inserted.\n");
                else
                    printf("Element inserted.\n");
                break;

            case 2: 
                op = dequeue();
                if (op == ERROR)
                    printf("Element not deleted.\n");
                else
                    printf("Deleted element = %d\n", op);
                break;

            case 3: 
                op = checkfront();
                if (op != ERROR)
                    printf("%d is at the front of the queue.\n", op);
                break;

            case 4: 
                op = checkrear();
                if (op != ERROR)
                    printf("%d is at the rear of the queue.\n", op);
                break;

            case 5: 
                if (isfull())
                    printf("Queue is full.\n");
                else
                    printf("Queue is NOT full.\n");
                break;

            case 6: 
                if (isEmpty())
                    printf("Queue is Empty.\n");
                else
                    printf("Queue is NOT Empty.\n");
                break;

            case 7: break;

            default: printf("Invalid Option...\n");
        }

    } while (choice != 7);

    free(Queue);  // cleanup memory
    return 0;
}