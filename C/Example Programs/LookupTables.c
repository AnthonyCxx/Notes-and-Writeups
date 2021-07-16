/*
Developer: Ethan Cox
Language: GNU Extended C
Compiler: GCC Compiler v9.3.0 for Ubuntu 20.04

Purpose: This is a short program that takes two integers and and arithmetic operation
         from the user and then calculates the result of the operation. This program
         is meant to show how lookup tables (LUTS) can be used to reduce code verbosity
         and increase code efficiency.

LICENSE: This program is free for anyone to use for any purpose by any person given that they
         do not hold the distributer liable for any results of code the use of this code.
*/
#include <stdio.h>
#include <stdlib.h>     // for 'exit()'

// A custom 'Tuple' of two ints
typedef struct Tuple
{
    int a;
    int b;
} Tuple;

// Arithmetic operations
int add(int, int);           // Add
int subtract(int, int);     // Subtract
int multiply(int, int);    // Multiply
int divide(int, int);     // Division
int mod(int, int);       // Modulus

// Calculator functions
Tuple getNums();
int displayMenu();
void calculate(int operation, int a, int b);    // Get two ints and calculate


// DRIVER CODE //
int main(void)
{
    // Get operation from user
    int oper = displayMenu();     // oper(ation)

    // Get the two numbers from the user
    Tuple nums = getNums();

    // Calculate the results of the numbers with the given operation
    calculate(oper, nums.a, nums.b);

    return 0;
}

// ****** FUNCTION IMPLEMENTATION ****** //

int displayMenu()
{
    int choice;

    do
    {
        // Display menu
        puts("\n// Choose an operation below //");
        puts("1. Addition");
        puts("2. Subtraction");
        puts("3. Multiplication");
        puts("4. Division");
        puts("5. Modulus");

        // Get choice
        printf("Operation: ");
        scanf("%d", &choice);

        // If error, display error
        if (choice < 1 || choice > 5)
            puts("Error: choose a number between 1 and 5");

    } while (choice < 1 || choice > 5);  // while (choice is less than 1 OR greater than 5)

    return choice - 1;   // Sub. 1 to align with the indicies of the LUT (lookup tables)
}

// Get user input
Tuple getNums()
{
    // tuple<int, int> to return the scanned values
    Tuple nums;

    // Get the numbers from the user
    printf("Enter two numbers: ");

    // Error handling, if not 2 numbers
    if (scanf("%d %d", &nums.a, &nums.b) == 1)   // 'scanf()' implicitly returns the amount of numbers scanned
    {
        puts("\n\nMinor fatal error: less than 2 numbers entered");
        puts("Exiting with status code 1");
        exit(1);
    }

    return nums;
}

/*
        COMMENTARY ON the 'calculate' FUNCTION:
        ---------------------------------------
        Notice how I was able to replace a huge switch statement, which would
        have included 5 different 'printf()' statements, each which would have also
        had their own hard-coded operator (+, -, etc.), with a single print statement
        by using lookup tables. The control of execution that the switch statement
        would have provided is integrated into the design of the lookup tables as
        each operation that the user could have chosen directly correlates with an index
        in both lookup tables. This way, we don't have to evaluate their choice and instead
        can use it directly, knowing that their choices, the arithmetic functions, and tokens
        all line up nicely.

*/

// 'calculate' implementation:
void calculate(int operation, int a, int b)
{
    //  A lookup table of 5 (int, int) function pointers -- one for each operation
    int (*calc[5])(int, int) = {&add, &subtract, &multiply, &divide, &mod};

    // A lookup table of the arithmetic operators for each operation
    char tokens[5] = {'+', '-', '*', '/', '%'};

    // Display the result of the operation (num1 [operator] num2 = [result])
    printf("\n%d %c %d = %d\n", a, tokens[operation], b, calc[operation](a, b));
}

// Arithmetic operator implementation
int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return a / b;
}

int mod(int a, int b)
{
    return a % b;
}
