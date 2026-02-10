#include <stdio.h>
#include <string.h>

#define MAX 100

// Stack structure
char stack[MAX];
int top = -1;

// Push element onto stack
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

// Pop element from stack
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

// Check if brackets match
int isMatching(char left, char right) {
    if (left == '(' && right == ')') return 1;
    if (left == '{' && right == '}') return 1;
    if (left == '[' && right == ']') return 1;
    return 0;
}

// Main logic to check if expression is balanced
int isBalanced(char* exp) {
    for (int i = 0; i < strlen(exp); i++) {
        // If opening bracket, push to stack
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        }
        // If closing bracket, check for match
        else if (exp[i] == ')' || exp[i] == '{' || exp[i] == ']' || exp[i] == '}') {
            if (top == -1 || !isMatching(pop(), exp[i])) {
                return 0;
            }
        }
    }
    // Final check: stack must be empty
    return (top == -1);
}

int main() {
    char exp[MAX];

    printf("Enter a mathematical expression: ");
    scanf("%[^\n]s", exp);

    if (isBalanced(exp)) {
        printf("Result: The parentheses are balanced.\n");
    } else {
        printf("Result: The parentheses are NOT balanced.\n");
    }

    return 0;
}
