#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct Stack {
    int size;
    int top;
    char *a;
} Stack;

// Create stack
Stack *create(int size) {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->size = size;
    s->top = -1;
    s->a = (char *)malloc(s->size * sizeof(char));
    return s;
}

// Stack operations
int isFull(Stack *s) {
    return s->top == s->size - 1;
}
int isEmpty(Stack *s) {
    return s->top == -1;
}
void push(Stack *s, char ch) {
    if (!isFull(s)) {
        s->a[++s->top] = ch;
    }
}
char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->a[s->top--];
    }
    return '\0';
}
char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->a[s->top];
    }
    return '\0';
}

// Precedence function
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Infix to Postfix conversion
void infixToPostfix(char *infix, char *postfix) {
    Stack *s = create(strlen(infix));
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if (isalnum(ch)) {
            postfix[j++] = ch;  // operand -> add to postfix
        }
        else if (ch == '(') {
            push(s, ch);
        }
        else if (ch == ')') {
            while (!isEmpty(s) && peek(s) != '(') {
                postfix[j++] = pop(s);
            }
            pop(s); // remove '('
        }
        else { // operator
            while (!isEmpty(s) && precedence(peek(s)) >= precedence(ch)) {
                postfix[j++] = pop(s);
            }
            push(s, ch);
        }
    }
    // Pop remaining operators
    while (!isEmpty(s)) {
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0'; // null terminate string
}

// Driver code
int main() {
    char infix[100], postfix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
