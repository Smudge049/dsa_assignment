#include <stdio.h>
#include <stdlib.h>

// Define Node structure for Doubly Linked List
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Insert a node at the end (for initial setup)
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) last = last->next;
    last->next = new_node;
    new_node->prev = last;
}

// Insert a node after a given node
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) return;

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
}

// Delete a given node
void deleteNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == NULL || del == NULL) return;

    if (*head_ref == del) *head_ref = del->next;
    if (del->next != NULL) del->next->prev = del->prev;
    if (del->prev != NULL) del->prev->next = del->next;

    free(del);
}

// Display list from beginning to end
void display(struct Node* node) {
    struct Node* last;
    printf("\nTraversal in forward direction: ");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\nTraversal in reverse direction: ");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Build initial list
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    printf("Initial List:");
    display(head);

    // Demonstration: Insert after given node
    printf("\nInserting 25 after 20...");
    insertAfter(head->next, 25); // head->next is 20
    display(head);

    // Demonstration: Delete a node
    printf("\nDeleting node 20...");
    deleteNode(&head, head->next); 
    display(head);

    return 0;
}
