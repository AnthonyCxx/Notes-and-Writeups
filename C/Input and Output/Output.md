# Output in C

# Charcters

## putchar(__*char*__)

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
    puts(str);

    return 0;
}
```

## printf(__*str*__, __*formatting variables*__)
