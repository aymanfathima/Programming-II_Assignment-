#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Define Stack structure
typedef struct {
    int top;
    double items[MAX];
} Stack;

// Function prototypes
void push(Stack *s, double value);
double pop(Stack *s);
double calculate(char operator, double operand1, double operand2);






int main() {
    

    char input[100];
    double operand1, operand2, result;
    int num;

    Stack stack;
    stack.top = -1; // Initialize stack

    choices:

    system("COLOR B");
	system("cls");

    printf("\n\n\t\t\t==============================="
					 "===============================\n");
	printf(  "\t\t\t                  A REVERCE POLISH NOTATION (RPN) \n");
	printf(  "\t\t\t                         CALCULATOR\n");
			
	printf(    "\t\t\t==============================="
			         "===============================\n\n\n");

    printf("\n\t    Enter RPN expression  \n");
    printf("\t      (operators: +, -, *, /, operands: numbers):\n\n");
    while (fgets(input, sizeof(input), stdin) != NULL) {
        for (int i = 0; input[i] != '\0'; i++) {
            if (isdigit(input[i])) {
                push(&stack, atof(&input[i])); //The atof() function returns the floating-point value that it interprets from the input string.
                while (isdigit(input[i]) || input[i] == '.') // Skip to the end of the number
                    i++;
            }
            else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
                operand2 = pop(&stack);
                operand1 = pop(&stack);
                result = calculate(input[i], operand1, operand2);
                push(&stack, result);
            }
            
            else if (input[i] == '\n') {
                    printf("\tResult: %.2f\n", pop(&stack));
                }
            else if (input[i] == 'e'){
                    exit(1);
                }
            
        } 
        printf("\n\tIf you want to exit the program press 'e' or\n");
        printf("\n\tEnter RPN expression  : \n");
    }

    

    return 0;
}

// Perform operation based on operator
double calculate(char operator, double operand1, double operand2) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                printf("Error: Division by zero\n");
                exit(1);
            }
            return operand1 / operand2;
        default:
            printf("Invalid operator\n");
            exit(1);
    }
}
