#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -------- Step 2: Define SongNode --------
struct SongNode {
    char *songName;               
    struct SongNode *next;
};

// -------- Step 3: Define MusicQueue --------
struct MusicQueue {
    struct SongNode *front;
    struct SongNode *rear;
    int repeat;     // 0 = OFF, 1 = ON
    int size;       // current number of songs
    int maxSize;    // user-defined maximum capacity
};

// -------- Function Prototypes --------
void initializeQueue(struct MusicQueue *q, int maxSize);
void enqueue(struct MusicQueue *q, char song[]);
void dequeue(struct MusicQueue *q);
void peek(struct MusicQueue *q);
void displayQueue(struct MusicQueue *q);
void toggleRepeat(struct MusicQueue *q);

// -------- Step 10: Menu-driven Program --------
int main() {
    struct MusicQueue q;
    int choice, maxSize;
    char temp[500];

    printf("Enter maximum number of songs in the queue: ");
    scanf("%d", &maxSize);
    getchar(); // consume newline

    initializeQueue(&q, maxSize);

    do {
        printf("\n--- MUSIC QUEUE MENU ---\n");
        printf("1. Add Song (Enqueue)\n");
        printf("2. Play Song (Dequeue)\n");
        printf("3. Show Next Song (Peek)\n");
        printf("4. Display Queue\n");
        printf("5. Toggle Repeat Mode\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter Song Name: ");
                fgets(temp, sizeof(temp), stdin);
                temp[strcspn(temp, "\n")] = '\0';
                enqueue(&q, temp);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                peek(&q);
                break;

            case 4:
                displayQueue(&q);
                break;

            case 5:
                toggleRepeat(&q);
                break;

            case 6:
                printf("Exiting Music Queue. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// -------- Step 4: Initialize Queue --------
void initializeQueue(struct MusicQueue *q, int maxSize) {
    q->front = NULL;
    q->rear = NULL;
    q->repeat = 0;
    q->size = 0;
    q->maxSize = maxSize;
}

// -------- Step 5: Enqueue (Add Song) --------
void enqueue(struct MusicQueue *q, char song[]) {
    if (q->size == q->maxSize) {
        printf("Queue is full. Cannot add more songs.\n");
        return;
    }

    struct SongNode *newNode = (struct SongNode *)malloc(sizeof(struct SongNode));
    newNode->songName = (char *)malloc((strlen(song) + 1) * sizeof(char));
    strcpy(newNode->songName, song);
    newNode->next = NULL;

    if (q->front == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->size++;
    printf("Song \"%s\" added to queue.\n", song);
}

// -------- Step 6: Dequeue (Play Song) --------
void dequeue(struct MusicQueue *q) {
    if (q->front == NULL) {
        printf("No songs in queue.\n");
        return;
    }

    struct SongNode *temp = q->front;
    printf("Now Playing: %s\n", temp->songName);

    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;

    q->size--;

    // Step 6.4: Repeat mode ON → enqueue again
    if (q->repeat == 1) {
        enqueue(q, temp->songName);
    }

    free(temp->songName);
    free(temp);
}

// -------- Step 7: Peek (Show Next Song) --------
void peek(struct MusicQueue *q) {
    if (q->front == NULL) {
        printf("No songs queued.\n");
    } else {
        printf("Next Song: %s\n", q->front->songName);
    }
}

// -------- Step 8: Display Queue --------
void displayQueue(struct MusicQueue *q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Songs in Queue:\n");
    struct SongNode *temp = q->front;
    int i = 1;
    while (temp != NULL) {
        printf("  %d. %s\n", i++, temp->songName);
        temp = temp->next;
    }
    printf("Total songs: %d / %d\n", q->size, q->maxSize);
}

// -------- Step 9: Toggle Repeat --------
void toggleRepeat(struct MusicQueue *q) {
    if (q->repeat == 0) {
        q->repeat = 1;
        printf("Repeat Mode: ON\n");
    } else {
        q->repeat = 0;
        printf("Repeat Mode: OFF\n");
    }
}
