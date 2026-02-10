# Documentation for Program 3: Linked List Reverse Traversal

## (a) Data Structure Definition
The program uses a **Singly Linked List**. A `struct Node` is defined with:
- `int data`: To store the numerical value.
- `struct Node* next`: A pointer to the next node in the sequence.

## (b) Functions Implemented
- `insert(struct Node** head, int val)`: Creates a new node and appends it to the end of the existing list.
- `printList(struct Node* head)`: A helper function that traverses and prints the list in its original order.
- `reverseTraversal(struct Node* head)`: A recursive function that visits the `next` node first and prints the `data` after returning from the recursive call, effectively printing the list in reverse order.

## (c) main() Method Organization
The `main()` function:
1. Prompts the user for the number of elements to insert.
2. Uses a loop to get user input and build the linked list via `insert()`.
3. Displays the list in its original order for context.
4. Calls `reverseTraversal()` to demonstrate the reverse printing functionality.

## (d) Sample Output
**Complete Run:**
```
How many elements to insert? 4
Enter value 1: 10
Enter value 2: 20
Enter value 3: 30
Enter value 4: 40

Original Linked List:
10 -> 20 -> 30 -> 40 -> NULL

Reverse Traversal Output:
40 30 20 10 
```
