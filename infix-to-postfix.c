#include <stdio.h>
#include <stdlib.h>  // for malloc(), free()
#include <string.h>  // for strlen(), strcat()
#include <ctype.h>   // for isalnum()

// ----------- GLOBAL VARIABLES -----------
char *stack;
int top = -1;
int SIZE;

// ----------- FUNCTION DECLARATIONS -----------
void push(char symbol);
char pop();
int precedence(char symbol);
int isOperator(char symbol);
void infixToPostfix(char infix[], char postfix[]);

// ----------- MAIN FUNCTION -----------
int main() {
    char infix[200], postfix[200];

    printf("Enter size of stack: ");
    scanf("%d", &SIZE);

    // Allocate stack dynamically
    stack = (char *)malloc(SIZE * sizeof(char));

    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter Infix Expression: ");
    scanf("%s", infix); // or use gets() if needed

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    free(stack); // Free memory
    return 0;
}

// ----------- FUNCTION DEFINITIONS -----------

// Push element onto stack
void push(char symbol) {
    if (top >= SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = symbol;
    }
}

// Pop element from stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return stack[top--];
    }
}

// Check if character is an operator
int isOperator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^');
}

// Define precedence of operators
int precedence(char symbol) {
    switch (symbol) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char symbol;

    // Step 1: Push '(' and append ')' at end
    push('(');
    strcat(infix, ")");

    // Step 2: Scan infix from left to right
    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        // Step 3: Operand -> add to postfix
        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        }

        // Step 4: '(' -> push to stack
        else if (symbol == '(') {
            push(symbol);
        }

        // Step 5: Operator encountered
        else if (isOperator(symbol)) {
            // Step 5.1: Pop while precedence high/equal
            while (isOperator(stack[top]) && precedence(stack[top]) >= precedence(symbol)) {
                postfix[j++] = pop();
            }
            // Step 5.2: Push current operator
            push(symbol);
        }

        // Step 6: ')' encountered
        else if (symbol == ')') {
            // Step 6.1: Pop until '('
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            // Step 6.2: Remove '('
            pop();
        }
    }

    postfix[j] = '\0'; // Step 7: Exit
}
