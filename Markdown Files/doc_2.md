# Documentation for Program 2: Infix to Postfix & Evaluation

## (a) Data Structure Definition
The program uses a **Stack** data structure implemented with a character array (`char stack[MAX]`) for operator handling during conversion, and an integer array (`int evalStack[MAX]`) for operand handling during evaluation.

## (b) Functions Implemented
- `push(char c)` and `pop()`: Standard stack operations.
- `precedence(char c)`: Returns an integer representing the priority of operators (`^` > `*`, `/` > `+`, `-`).
- `infixToPostfix(char* infix, char* postfix)`: Uses the stack to convert the input expression into postfix notation based on operator precedence.
- `evaluatePostfix(char* postfix)`: Scans the postfix expression and performs arithmetic operations using a numeric stack.

## (c) main() Method Organization
The `main()` function:
1. Inputs an infix expression from the user.
2. Calls `infixToPostfix()` to convert and display the expression.
3. Checks if the expression contains digits; if so, it calls `evaluatePostfix()` to calculate the result.
4. Outputs the final numerical result or a note if variables were used.

## (d) Sample Output
**Case 1: Evaluation**
```
Enter infix expression: 2+3*4
Postfix Expression: 234*+
Evaluation Result: 14
```

**Case 2: Complex Expression**
```
Enter infix expression: (1+2)*3
Postfix Expression: 12+3*
Evaluation Result: 9
```

**Case 3: Variables (No Evaluation)**
```
Enter infix expression: a+b*c
Postfix Expression: abc*+
Note: Evaluation skipped as expression contains variables instead of numbers.
```
