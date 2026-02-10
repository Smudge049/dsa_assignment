# Documentation for Program 4: Doubly Linked List

## (a) Data Structure Definition
A **Doubly Linked List** is implemented using a structure where each node contains:
- `int data`: The value stored in the node.
- `struct Node* prev`: A pointer to the previous node.
- `struct Node* next`: A pointer to the next node.
This structure allows bidirectional traversal.

## (b) Functions Implemented
- `append(struct Node** head, int val)`: Adds a node at the very end of the list.
- `insertAfter(struct Node* prev_node, int val)`: Takes a pointer to an existing node and inserts a new node immediately after it, updating all four involved pointers.
- `deleteNode(struct Node** head, struct Node* del)`: Removes a specific node from the list and reconnects the neighboring nodes.
- `display(struct Node* head)`: Prints the list in both forward and backward directions to verify the integrity of the `prev` and `next` links.

## (c) main() Method Organization
The `main()` function serves as a driver program:
1. It initializes a list with values 10, 20, and 30.
2. It calls `insertAfter()` to place 25 between 20 and 30.
3. It calls `deleteNode()` to remove the node containing 20.
4. After each operation, it uses `display()` to show the current state of the list from both directions.

## (d) Sample Output
```
Initial List:
Traversal in forward direction: 10 20 30 
Traversal in reverse direction: 30 20 10 

Inserting 25 after 20...
Traversal in forward direction: 10 20 25 30 
Traversal in reverse direction: 30 25 20 10 

Deleting node 20...
Traversal in forward direction: 10 25 30 
Traversal in reverse direction: 30 25 10 
```
