#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void insertAtFirst(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void insertAtPosition(struct Node** head, int value, int position) {
    if (position == 1) {
        insertAtFirst(head, value);
        return;
    }

    struct Node* newNode = createNode(value);
    struct Node* temp = *head;

    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Position out of range!\n");
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Display list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    int choice, value, pos;
    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Insert at First\n");
        printf("2. Insert at Position\n");
        printf("3. Insert at End\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtFirst(&head, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(&head, value, pos);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;

            case 4:
                display(head);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}


output:

----- MENU -----
1. Insert at First
2. Insert at Position
3. Insert at End
4. Display List
5. Exit
Enter your choice: 1
Enter value: 5

----- MENU -----
1. Insert at First
2. Insert at Position
3. Insert at End
4. Display List
5. Exit
Enter your choice: 2
Enter value: 8
Enter position: 2

----- MENU -----
1. Insert at First
2. Insert at Position
3. Insert at End
4. Display List
5. Exit
Enter your choice: 1
Enter value: 3

----- MENU -----
1. Insert at First
2. Insert at Position
3. Insert at End
4. Display List
5. Exit
Enter your choice: 1
Enter value: 9

----- MENU -----
1. Insert at First
2. Insert at Position
3. Insert at End
4. Display List
5. Exit
Enter your choice: 3
Enter value: 6

----- MENU -----
1. Insert at First
2. Insert at Position
3. Insert at End
4. Display List
5. Exit
Enter your choice: 4
Linked List: 9 -> 3 -> 5 -> 8 -> 6 -> NULL

----- MENU -----
1. Insert at First
2. Insert at Position
3. Insert at End
4. Display List
5. Exit
Enter your choice: 4
