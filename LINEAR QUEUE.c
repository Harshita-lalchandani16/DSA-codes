#include <stdio.h>
#include <stdlib.h>

#define MAX 1000 // upper bound, actual size will be user-defined

int main() {
    int queue[MAX];
    int front = -1, rear = -1, n, choice, item;

    printf("Enter the size of the queue: ");
    scanf("%d", &n);

    while (1) {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. ISEMPTY\n");
        printf("4. ISFULL\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            // ENQUEUE
            case 1:
                if (rear == n - 1) {
                    printf("Queue Overflow! Cannot insert element.\n");
                } else {
                    if (front == -1)
                        front = 0;
                    rear = rear + 1;

                    printf("Enter the element to enqueue: ");
                    scanf("%d", &item);
                    queue[rear] = item;

                    printf("Item %d inserted into queue.\n", item);
                }
                break;

            // DEQUEUE
            case 2:
                if (front == -1 || front > rear) {
                    printf("Queue Underflow! No element to delete.\n");
                } else {
                    item = queue[front];
                    front = front + 1;

                    if (front > rear) {
                        front = -1;
                        rear = -1;
                    }

                    printf("Deleted Item: %d\n", item);
                }
                break;

            // ISEMPTY
            case 3:
                if (front == -1 || front > rear) {
                    printf("Queue is EMPTY.\n");
                } else {
                    printf("Queue is NOT EMPTY.\n");
                }
                break;

            // ISFULL
            case 4:
                if (rear == n - 1) {
                    printf("Queue is FULL.\n");
                } else {
                    printf("Queue is NOT FULL.\n");
                }
                break;

            // EXIT
            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000 // upper bound, actual size will be user-defined

int main() {
    int queue[MAX];
    int front = -1, rear = -1, n, choice, item;

    printf("Enter the size of the queue: ");
    scanf("%d", &n);

    while (1) {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. ISEMPTY\n");
        printf("4. ISFULL\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            // ENQUEUE
            case 1:
                if (rear == n - 1) {
                    printf("Queue Overflow! Cannot insert element.\n");
                } else {
                    if (front == -1)
                        front = 0;
                    rear = rear + 1;

                    printf("Enter the element to enqueue: ");
                    scanf("%d", &item);
                    queue[rear] = item;

                    printf("Item %d inserted into queue.\n", item);
                }
                break;

            // DEQUEUE
            case 2:
                if (front == -1 || front > rear) {
                    printf("Queue Underflow! No element to delete.\n");
                } else {
                    item = queue[front];
                    front = front + 1;

                    if (front > rear) {
                        front = -1;
                        rear = -1;
                    }

                    printf("Deleted Item: %d\n", item);
                }
                break;

            // ISEMPTY
            case 3:
                if (front == -1 || front > rear) {
                    printf("Queue is EMPTY.\n");
                } else {
                    printf("Queue is NOT EMPTY.\n");
                }
                break;

            // ISFULL
            case 4:
                if (rear == n - 1) {
                    printf("Queue is FULL.\n");
                } else {
                    printf("Queue is NOT FULL.\n");
                }
                break;

            // EXIT
            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
