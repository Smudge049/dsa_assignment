# Documentation for Program 1: Balanced Parentheses

## (a) Data Structure Definition
The program uses a **Stack** data structure implemented using a fixed-size character array (`char stack[MAX]`). A variable `top` keeps track of the index of the last element added to the stack.

## (b) Functions Implemented
- `push(char c)`: Adds a character to the top of the stack.
- `pop()`: Removes and returns the character from the top of the stack.
- `isMatching(char left, char right)`: Checks if a pair of opening and closing characters form a valid set of parentheses (e.g., `(` and `)`).
- `isBalanced(char* exp)`: Iterates through the expression, pushes opening brackets onto the stack, and pops them when a closing bracket is encountered to check if they match.

## (c) main() Method Organization
The `main()` function:
1. Declares a character array to store the user input.
2. Prompts the user to enter a mathematical expression.
3. Calls the `isBalanced()` function to evaluate the expression.
4. Outputs whether the expression is balanced or not based on the return value.

## (d) Sample Output
**Run 1:**
```
Enter a mathematical expression: a + (b - c) * (d
Result: The parentheses are NOT balanced.
```

**Run 2:**
```
Enter a mathematical expression: m + [a - b * (c + d * {m)]
Result: The parentheses are NOT balanced.
```

**Run 3:**
```
Enter a mathematical expression: a + (b - c)
Result: The parentheses are balanced.
```
