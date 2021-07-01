#include <stdio.h>

int main(void)
{

    /*
                                  TL;DR
                                  =====
        Do not implicitly convert incompatible types WITHOUT typecasting:
        ================================================================
        - Integers to doubles or floats (they are stored fundamentally differently)
        - Negative numeric types (ints, floats...) to unsigned integers (ex. -1000 to an unsigned integer)
        ^^ Even if you typecast a negative number to an unsigned number, it will still cause integer overflow

        Note: converting between floats and doubles will give you the closest possible
        equivalent, which will likely not be exactly accurate.
        
        *** SEE BELOW FOR PROGRAM OUTPUT ***
    */

    //A simple integer, float, and double
    int int_number = 65;
    float float_number = 12.3456;
    double double_number = 12.34567891011;

    /*
        Typecasting in C is done by just putting the datatype in parentheses
        before the variable or expression.

        Ex: '(char) 65' would become 'A' because in ASCII, 'A' is 65.

        Some types, such as characters and integers, do not need to be explicitly
        converted because of their relationship. For example, characters and integers
        can be used interchangably because characters are an integral type at heart.
        Typecasting does not affect the original variable, just the expression
        it's being used in. Doing '(float) number' will not permanantly change
        the value of 'number'.
    */

    // Exmaple of format specifiers in C
    printf("The number 65 is: %d (duh)\n", int_number);   //the 'd' in '%d' stands for decimal (base 10)


    /* UNSIGNED INTEGERS AND INTEGERS */
    /* ============================== */
    printf("\nTypecasting with integers and chars...\n");
    printf("The number -1000 as an unsigned int is %u (blatant error)\n", -1000);


    /* INTEGERS AND CHARS */
    /* ================== */
    printf("\nTypecasting with integers and chars...\n");

    // Integer -> Char (with typecasting)
    printf("The number 65 as a character (with typecasting) is: %c\n", (char) int_number);

    // Integer -> Char (without typecasting)
    printf("The number 65 as a character (without typecasting) is: %c\n", int_number);


    /* INTEGERS AND FLOATS */
    /* =================== */
    printf("\nTypecasting with integers and floats...\n");

    // Integer -> Float (with typecasting)
    printf("The integer 65 as a float (with typecasting) is: %f\n", (float) int_number);

    // Integer -> Float (without typecasting)
    printf("The integer 65 as a float (without typecasting) is: %f\n", int_number);

    // Float -> Integer (with typecasting)
    printf("The float 12.3456 as an integer (with typecasting) is: %d\n", (int) float_number);

    // Float -> Integer (without typecasting)
    printf("The float 12.3456 as an integer (without typecasting) is: %d (blatant error)\n", float_number);


    /* INTEGERS AND FLOATS */
    /* =================== */
    printf("\nTypecasting with integers and doubles...\n");

    // Integer -> Double (with typecasting)
    printf("The integer 65 as a double (with typecasting) is: %lf\n", (double) int_number);

    // Integer -> Double (without typecasting)
    printf("The integer 65 as a double (without typecasting) is: %lf\n", int_number);

    // Double -> Integer (with typecasting)
    printf("The double 12.34567891011 as an integer (with typecasting) is: %d\n", (int) double_number);

    // Double -> Integer (without typecasting)
    printf("The double 12.34567891011 as an integer (without typecasting) is: %d (blatant error)\n", double_number);


    /* FLOATS AND DOUBLES */
    /* ================== */
    printf("\nTypecasting with floats and doubles...\n");

    // Float -> Double (with typecasting)
    printf("The float 12.3456 as a double (with typecasting) is: %lf (careful, implied zeros)\n", (double) float_number);

    // Float -> Double (without typecasting)
    printf("The float 12.3456 as a double (without typecasting) is: %lf (careful, implied zeros)\n", float_number);

    // Double -> Float (with typecasting)
    printf("The double 12.34567891011 as a float (with typecasting) is: %f (careful, notice the rounding .345679 instead of .345678)\n", (float) double_number);

    // Double -> Float (without typecasting)
    printf("The double 12.34567891011 as a float (without typecasting) is: %f (careful, notice the rounding .345679 instead of .345678)\n", double_number);

    return 0;
}


/*
              PRINTS:
              ======
The number 65 is: 65 (duh)

Typecasting with integers and chars...
The number -1000 as an unsigned int is 4294966296 (blatant error)

Typecasting with integers and chars...
The number 65 as a character (with typecasting) is: A
The number 65 as a character (without typecasting) is: A

Typecasting with integers and floats...
The integer 65 as a float (with typecasting) is: 65.000000
The integer 65 as a float (without typecasting) is: 65.000000
The float 12.3456 as an integer (with typecasting) is: 12
The float 12.3456 as an integer (without typecasting) is: -183045472 (blatant error)

Typecasting with integers and doubles...
The integer 65 as a double (with typecasting) is: 65.000000
The integer 65 as a double (without typecasting) is: 65.000000
The double 12.34567891011 as an integer (with typecasting) is: 12
The double 12.34567891011 as an integer (without typecasting) is: -183045472 (blatant error)

Typecasting with floats and doubles...
The float 12.3456 as a double (with typecasting) is: 12.345600 (careful, implied zeros)
The float 12.3456 as a double (without typecasting) is: 12.345600 (careful, implied zeros)
The double 12.34567891011 as a float (with typecasting) is: 12.345679 (careful, notice the rounding .345679 instead of .345678)
The double 12.34567891011 as a float (without typecasting) is: 12.345679 (careful, notice the rounding .345679 instead of .345678)              

*/
