






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

