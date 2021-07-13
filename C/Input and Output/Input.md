# Input in C

# Characters

## getchar()
The _getchar()_ function returns a single character from [stdin](https://en.wikipedia.org/wiki/Standard_streams#Standard_input_(stdin)). Typically, stdin is the keyboard,
but could be other input if redirected.
```C
#include <stdio.h>

int main(void)
{
    char input;

    // Prompt the user for a character
    printf("Enter a character: ");
    input = getchar();      // Get the character

    putchar('\n');   // End the line

    // Display the entered character
    printf("Entered character: %c\n", input);

    return 0;
}
```
> Sources: <br />
> [_TutorialsPoint: C Library Funtion - getchar()_](https://www.tutorialspoint.com/c_standard_library/c_function_getchar.htm) <br />
> [_Javatpoint: getchar() function in C_](https://www.javatpoint.com/getchar-function-in-c) <br />

# Strings

## scanf()
The _scanf()_ function reads input until it reaches a whitespace. _scanf()_ is good for getting general user input like numbers and words. _scanf()_ takes two parameters:
the format of the input (as a [formatted string](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C/Input%20and%20Output/Formatting%20Input%20and%20Output.md), like with _printf()_) and the memory address of the variable to store the data read in. Remember that the name of an array is a pointer to the first element, so you do not need to
use the [_&_ (address-of) operator](https://www.educba.com/address-operator-in-c/) with buffers (character arrays). <br />

You can scan for '_%\[^\\n\]s_' to emulate the
[_gets()_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C/Input%20and%20Output/Input.md#gets) function, but you will run into the same problem of buffer overflows.
```C
#include <stdio.h>

int main(void)
{
    int number;
    char word[50];

    // Get input (an integer)
    printf("Enter an integer: ");
    scanf("%d", &number);       // '&' needed for non-pointers

    // Get input (a string)
    printf("Enter a word: ");
    scanf("%s", word);         // '&' NOT needed for pointers (char arrays)

    // Print input
    printf("You entered the number: %d\n", number);
    printf("You entered the word: %s\n", word);

    return 0;
}
```
> Sources: <br />
> [_Study Tonight: Input and Output in C_](https://www.studytonight.com/c/c-input-output-function.php) <br />
> [_Dummies.com: Basics of scanf() in C Programming_](https://www.dummies.com/programming/c/basics-of-the-scanf-function-in-c-programming/) <br />
> [_Quora: What is Scanf()_ with \[^n\]?](https://www.quora.com/What-is-scanf-n) <br />

## gets()
The _gets()_ function reads from [stdin](https://en.wikipedia.org/wiki/Standard_streams#Standard_input_(stdin)) until it encounters a newline (\n) or EOF character.
Though convenient, using the _gets()_ function is considered bad practice because it will continue to write characters even when your buffer runs out of memory 
(50 characters in this case). If _gets()_ writes more characters than the buffer can hold, the program will instantly crash because it will detect 
[stack smashing](https://stackoverflow.com/questions/40416516/what-is-stack-smashing-c). If you want to use _gets()_, use [_fgets()_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C/Input%20and%20Output/Input.md#fgets) instead. Just don't use _gets()_.
```C
#include <stdio.h>

int main(void)
{
    // A buffer to store the input
    char buffer[50];

    // Get input
    printf("Enter a sentence: ");   // Prompt
    gets(buffer);                  // Get the user input

    // Print input
    printf("Input: %s\n", buffer);

    return 0;
}
```
> Reference: [_C++ Reference: gets()_](https://www.cplusplus.com/reference/cstdio/gets/) <br />
> 
> Compile this program and then enter more than 50 characters. The program will automaticaly terminate with a fatal error: <br /> 
> \*\*\* stack smashing detected \*\*\*: terminated <br />
> Aborted (core dumped) <br />

## fscanf()
The _fscanf()_ function works as _scanf()_ for [_FILE*_](https://www.geeksforgeeks.org/data-type-file-c/) streams. _fscanf()_ takes three parameters: the _FILE\*_ pointer,
the format of the input, and the list of variables to store the input. Like _scanf()_, you have to use '&' for non-pointers.

```C
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char month[20];
    int day, year;

    // Open a file 'date.txt' in read mode
    FILE* readfile = fopen("date.txt", "r");

    // Scan the date from the file
    fscanf(readfile, "%s %d %d", month, &day, &year);

    // Print the date
    printf("Today's date is %s %dth, %d\n", month, day, year);
}
```
> Prints: <br />
> Today's date is January 100th, 1984 <br />

## fgets()
The _fgets()_ function reads a set amount of characters from a [_FILE*_](https://www.geeksforgeeks.org/data-type-file-c/) stream. Because the [standard streams](https://www.gnu.org/software/libc/manual/html_node/Standard-Streams.html) are 'files', you can use _fgets()_ to read from files _and_ from the standard input, output, and error streams. _fgets()_ takes three parameters: the buffer to store the characters read, the max amount of characters to read (typically the size of the buffer) and the 
_FILE*_ to read from ('stdin' is the keyboard).

The _sizeof()_ operator (yes, operator) returns the size of the datatype (/variable/data structure) in bytes, right? And a char is only 1 byte, right? So it just happens
to be the case that using the _sizeof()_ operator on the char array returns the exact amount of characters that _fgets()_ needs to read. Neat.
```C
#include <stdio.h>

int main(void)
{
    char buffer[50];

    printf("Enter a sentence: ");
    fgets(buffer, sizeof(buffer), stdin);  // 'stdin' is the keyboard

    printf("Input: %s", buffer);    // 'buffer' contains a '\n' from the user hitting enter

    return 0;
}
```
> This program will not crash if more than 50 characters are entered; at that point, it will just stop reading characters. <br />
>  This means that the buffer will not contain a newline (\n) character as 'enter' is the last character in the stream of characters. <br />
>
> Sources: <br />
> [_Educative.io: How to use the fgets() function in C_](https://www.educative.io/edpresso/how-to-use-the-fgets-function-in-c) <br />
> [_C++ Reference: \<cstdio\>, fgets()_](https://www.cplusplus.com/reference/cstdio/fgets/) <br />

## Miscellaneous
[Here](https://stackoverflow.com/questions/7880141/how-do-i-check-length-of-user-input-in-c) is a good reading on checking the length of user input.
