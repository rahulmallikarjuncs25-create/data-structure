CIRCULARQUEUE:
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert(int value) {
    if ((front == 0 && rear == MAX - 1) || (rear + 1 == front)) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (front == -1) {
        front = rear = 0;
    }
    else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;
    printf("%d inserted into circular queue.\n", value);
}

// Delete element from circular queue
void deleteElement() {
    if (front == -1) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    printf("%d deleted from circular queue.\n", queue[front]);

    // Queue becomes empty
    if (front == rear) {
        front = rear = -1;
    }
    else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Circular Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }

    printf("\n");
}
int main() {
    int choice, value;

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                deleteElement();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

OUTPUT:

----- MENU -----
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter value to insert: 4
4 inserted into circular queue.

----- MENU -----
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter value to insert: 6
6 inserted into circular queue.

----- MENU -----
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 3
Circular Queue elements: 4 6

----- MENU -----
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 2
4 deleted from circular queue.

----- MENU -----
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 3
Circular Queue elements: 6
