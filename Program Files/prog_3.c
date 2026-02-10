#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node* next;
};

// Insert a node at the end
void insert(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Recursive function for reverse traversal
void reverseTraversal(struct Node* head) {
    if (head == NULL) return;

    // Traverse the rest of the list first
    reverseTraversal(head->next);

    // Print current node data after returning from recursion
    printf("%d ", head->data);
}

// Function to print list in normal order
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, val;

    printf("How many elements to insert? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        insert(&head, val);
    }

    printf("\nOriginal Linked List:\n");
    printList(head);

    printf("\nReverse Traversal Output:\n");
    reverseTraversal(head);
    printf("\n");

    return 0;
}
