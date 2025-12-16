DOUBLY LINKED LIST WITH INSERTION FROM THE LEFT NODE DELETION FROM A SPECIFIC POSITION

#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;
void create() {
    int n, i, val;
    struct node *temp, *newnode;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &val);
        newnode->data = val;
        newnode->prev = newnode->next = NULL;
        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
}
void insert_left() {
    int key, val;
    struct node *temp = head, *newnode;
    printf("Enter value before which to insert: ");
    scanf("%d", &key);
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        printf("Value not found!\n");
        return;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter new data: ");
    scanf("%d", &val);

    newnode->data = val;
    newnode->next = temp;
    newnode->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = newnode;
    else
        head = newnode;
    temp->prev = newnode;
}
void delete_value() {
    int key;
    struct node *temp = head;
    printf("Enter value to delete: ");
    scanf("%d", &key);
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        printf("Value not found!\n");
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
    printf("Node deleted successfully.\n");
}
void display() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {`
    int choice;
    do {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create\n");
        printf("2. Insert to left of a node\n");
        printf("3. Delete a node by value\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1: create(); break;
        case 2: insert_left(); break;
        case 3: delete_value(); break;
        case 4: display(); break;
        case 5: exit(0);
        default: printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}
OUTPUT:

--- Doubly Linked List Menu ---
1. Create
2. Insert to left of a node
3. Delete a node by value
4. Display
5. Exit
Enter your choice: 1
Enter number of nodes: 3
Enter data: 4
Enter data: 5
Enter data: 6

--- Doubly Linked List Menu ---
1. Create
2. Insert to left of a node
3. Delete a node by value
4. Display
5. Exit
Enter your choice: 2
Enter value before which to insert: 5
Enter new data: 3

--- Doubly Linked List Menu ---
1. Create
2. Insert to left of a node
3. Delete a node by value
4. Display
5. Exit
Enter your choice: 4
Doubly Linked List: 4 <-> 3 <-> 5 <-> 6 <-> NULL

--- Doubly Linked List Menu ---
1. Create
2. Insert to left of a node
3. Delete a node by value
4. Display
5. Exit
Enter your choice: 3
Enter value to delete: 5
Node deleted successfully.

--- Doubly Linked List Menu ---
1. Create
2. Insert to left of a node
3. Delete a node by value
4. Display
5. Exit
Enter your choice: 4
Doubly Linked List: 4 <-> 3 <-> 6 <-> NULL
