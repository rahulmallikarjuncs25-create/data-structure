#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[20];
    int rollno;
    int age;
} Student;

typedef struct Node {
    Student data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(char name[], int rollno, int age) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data.name, name);
    newNode->data.rollno = rollno;
    newNode->data.age = age;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void displayNode(Node* node) {
    if (!node) {
        printf("Node is NULL!\n");
        return;
    }
    printf("\nNode Information:\n");
    printf(" Name    : %s\n", node->data.name);
    printf(" Roll No : %d\n", node->data.rollno);
    printf(" Age     : %d\n", node->data.age);
}

void traverseInteractive(Node* current) {
    char choice;
    while (1) {
        displayNode(current);
        printf("\nOptions: n = NEXT, p = PREV, e = EXIT\nEnter: ");
        scanf(" %c", &choice);

        if (choice == 'n') {
            if (current->next) current = current->next;
            else printf("At LAST node!\n");
        }
        else if (choice == 'p') {
            if (current->prev) current = current->prev;
            else printf("At FIRST node!\n");
        }
        else if (choice == 'e') break;
        else printf("Invalid input!\n");
    }
}

Node* searchByNodeNumber(Node* head, int position) {
    Node* temp = head;
    int count = 1;
    while (temp) {
        if (count == position) return temp;
        temp = temp->next;
        count++;
    }
    return NULL;
}

int main() {
    Node* N1 = createNode("aaa", 101, 20);
    Node* N2 = createNode("bbb", 102, 21);
    Node* N3 = createNode("ccc", 103, 19);
    Node* N4 = createNode("ddd", 104, 22);
    Node* N5 = createNode("eee", 105, 20);
    N1->next = N2;  N2->prev = N1;
    N2->next = N3;  N3->prev = N2;
    N3->next = N4;  N4->prev = N3;
    N4->next = N5;  N5->prev = N4;
    int pos;
    printf("Enter Node Number to Search (1-5): ");
    scanf("%d", &pos);
    Node* found = searchByNodeNumber(N1, pos);
    if (found) {
        printf("\nNode %d Found!\n", pos);
        displayNode(found);
        traverseInteractive(found);
    } else {
        printf("\nNode Not Found! Starting traversal from first node.\n");
        traverseInteractive(N1);
    }
    free(N1);
    free(N2);
    free(N3);
    free(N4);
    free(N5);
    return 0;
}

output:
Enter Node Number to Search (1-5): 2
Node 2 Found!
Node Information:
 Name    : bbb
 Roll No : 102
 Age     : 21

Node Information:
 Name    : bbb
 Roll No : 102
 Age     : 21

Options: n = NEXT, p = PREV, e = EXIT
Enter: p
Node Information:
 Name    : aaa
 Roll No : 101
 Age     : 20
