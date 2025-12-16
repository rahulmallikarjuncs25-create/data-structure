QUEUE:
#include <stdio.h>
#include <stdlib.h>

#define MAX 5   

int queue[MAX];
int front = -1, rear = -1;

void insert(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }

    if (front == -1)
        front = 0;

    queue[++rear] = value;
    printf("%d inserted into queue.\n", value);
}

void deleteElement() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    printf("%d deleted from queue.\n", queue[front]);
    front++;

   
    if (front > rear)
        front = rear = -1;
}
void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
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
Enter value to insert: 5
5 inserted into queue.

----- MENU -----
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter value to insert: 9
9 inserted into queue.

----- MENU -----
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter value to insert: 6
6 inserted into queue.

----- MENU -----
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 2
5 deleted from queue.

----- MENU -----
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 3
Queue elements: 9 6

----- MENU -----
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice:
