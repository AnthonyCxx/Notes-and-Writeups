# Output in C

# Charcters

## putchar(__*char*__)
Outputs a single character to stdout (the console, unless otherwise redirected). _putchar()_ works with escape sequences as well as ASCII text. <br />
This function does not add implicitly add a newline.
```C
#include <stdio.h>

int main(void)
{
    int end = 1000000;   // 1_000_000
    
    // A simple progress bar that races to 1 million
    for(int i=0; i < end; i++)
    {
        // Print current progress
        printf("Progress: %d / %d", i, end);

        // Reset the cursor to the beginning of the line
        putchar('\r');    // carriage return character
    }

    return 0;
}
```
> Best practice would just be to write 'printf("Progress: %d / %d\r", i, end);', combining the two functions.

# Strings (Character Streams)

## puts(__*str*__)
The _puts()_ function prints a string of text ([literals](https://thabo-ambrose.medium.com/what-is-a-literal-in-computer-programming-560eace90b5b) or variables).
Unlike _printf()_, the _puts()_ function cannot be formatted with variables for [string interpolation](https://en.wikipedia.org/wiki/String_interpolation). 
Because of its simpler implementation, [_puts()_ is faster and more efficient than _printf()_](https://www.quora.com/What-is-the-difference-between-puts-and-printf) and should be favored for simple output. In addition to being faster, its implementation is easier since it automatically appends a newline character (\n).
```C
#include <stdio.h>

int main(void)
{
    char* str = "testing the puts function";    //a char pointer is basically a read-only string
    puts(str);    //implicit '\n'

    return 0;
}
```

## printf(__*str*__, __*formatting variables*__)
_printf()_ is the generic C print function and is especially good for [formatting strings](https://www.geeksforgeeks.org/format-specifiers-in-c/) with values.
_printf()_ is slower than _puts()_ and does not automatically append a newline character (\n). Be very careful when using _printf()_ (especially when printing
strings provided by the user) as _printf()_ has a well-known [string formatting vulnerability](https://owasp.org/www-community/attacks/Format_string_attack).
```C
#include <stdio.h>

int main(void)
{
    float total = 10.50;

    printf("Your total comes out to $%.2f\n", total);  

    return 0;
}
```
> Prints: Your total comes out to $10.50 <br />
> Note: the '.2' between the standard _%f_ determines the amount of decimal places in the float. <br />
> 
> Extra reading: [here are some notes](https://web.ecs.syr.edu/~wedu/Teaching/cis643/LectureNotes_New/Format_String.pdf) from Syracruse University on the format string vulnerability. <br />
