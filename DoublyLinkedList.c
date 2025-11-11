Doubly Linked List:

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
 int data;
 struct Node* prev;
 struct Node* next;
} Node;

Node* createNode(int value) {
 Node* newNode = (Node*)malloc(sizeof(Node));
 newNode->data = value;
 newNode->prev = NULL;
 newNode->next = NULL;
 return newNode;
}

void displayList(Node* head) {
 Node* temp = head;
 printf("\nDoubly Linked List Structure:\n");
 printf("-------------------------------------------------------------\n");
 printf("| %-10s | %-10s | %-5s | %-10s |\n", "Node Addr", "Prev Addr", "Data", "Next Addr");
 printf("-------------------------------------------------------------\n");
 while (temp != NULL) {
 printf("| %-10p | %-10p | %-5d | %-10p |\n",
 (void*)temp,
 (void*)temp->prev,
 temp->data,
 (void*)temp->next);
 temp = temp->next;
 }
 printf("-------------------------------------------------------------\n");
}

int main() {
 // Step 1: Create 5 independent nodes
 Node* N1 = createNode(1);
 Node* N2 = createNode(2);
 Node* N3 = createNode(3);
 Node* N4 = createNode(4);
 Node* N5 = createNode(5);
 // Step 2: Link nodes to form the doubly linked list
 N1->next = N2;
 N2->prev = N1;
 N2->next = N3;
 N3->prev = N2;
 N3->next = N4;
 N4->prev = N3;
 N4->next = N5;
 N5->prev = N4;
 // Step 3: Display the list with pointer addresses
 displayList(N1);
 // Cleanup: Free allocated memory
 free(N1);
 free(N2);
 free(N3);
 free(N4);
 free(N5);
 return 0;
}

OUTPUT:
Doubly Linked List Structure:
-------------------------------------------------------------
| Node Addr  | Prev Addr  | Data  | Next Addr  |
-------------------------------------------------------------
| 00000000009E3B90 | 0000000000000000 | 1     | 00000000009E3BE0 |
| 00000000009E3BE0 | 00000000009E3B90 | 2     | 00000000009E3C30 |
| 00000000009E3C30 | 00000000009E3BE0 | 3     | 00000000009E3C80 |
| 00000000009E3C80 | 00000000009E3C30 | 4     | 00000000009E3CD0 |
| 00000000009E3CD0 | 00000000009E3C80 | 5     | 0000000000000000 |
-------------------------------------------------------------
