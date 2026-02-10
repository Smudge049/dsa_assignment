#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// Convert Infix to Postfix
void infixToPostfix(char* infix, char* postfix) {
    int j = 0;
    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '('
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

// Evaluate Postfix Expression
int evaluatePostfix(char* postfix) {
    int evalStack[MAX];
    int eTop = -1;

    for (int i = 0; i < strlen(postfix); i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            evalStack[++eTop] = c - '0';
        } else {
            int val2 = evalStack[eTop--];
            int val1 = evalStack[eTop--];
            switch (c) {
                case '+': evalStack[++eTop] = val1 + val2; break;
                case '-': evalStack[++eTop] = val1 - val2; break;
                case '*': evalStack[++eTop] = val1 * val2; break;
                case '/': evalStack[++eTop] = val1 / val2; break;
            }
        }
    }
    return evalStack[0];
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    // Only evaluate if the expression contains numbers
    int hasDigit = 0;
    for(int i=0; i<strlen(postfix); i++) if(isdigit(postfix[i])) hasDigit = 1;
    
    if(hasDigit) {
        printf("Evaluation Result: %d\n", evaluatePostfix(postfix));
    } else {
        printf("Note: Evaluation skipped as expression contains variables instead of numbers.\n");
    }

    return 0;
}
