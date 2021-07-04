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

# Strings

## scanf()

## gets()
The _gets()_ function reads from [stdin](https://en.wikipedia.org/wiki/Standard_streams#Standard_input_(stdin)) until it encounters a newline (\n) or EOF character.
Though convenient, using the _gets()_ function is considered bad practice because it will continue to write characters even when your buffer runs out of memory 
(50 characters in this case). If _gets()_ writes more characters than the buffer can hold, the program will automatically terminate because it will detect 
[stack smashing](https://stackoverflow.com/questions/40416516/what-is-stack-smashing-c).
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
> Compile this program and then enter more than 50 characters. The program will automaticaly terminate with a warning: <br /> 
> \*\*\* stack smashing detected \*\*\*: terminated <br />
> Aborted (core dumped) <br />

## fgets()
The _fgets()_ function reads a set amount of characters from a [_FILE*_](https://www.geeksforgeeks.org/data-type-file-c/) stream. Because the [standard streams](https://www.gnu.org/software/libc/manual/html_node/Standard-Streams.html) are 'files', you can use _fgets()_ to read from files _and_ from the standard input, output, and error streams. _fgets()_ takes three parameters: the buffer to store the characters read, the max amount of characters to read (typically the size of the buffer) and the 
_FILE*_ to read from ('stdin' is the keyboard).
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
> This program will not crash if more than 50 characters are entered; however, if more than 50 characters are entered than the buffer will not contain the '\n' from
> the user hitting enter like it would if they entered less than 50 characters. <br />
> t
> Sources: <br />
> [_Educative.io: How to use the fgets() function in C_](https://www.educative.io/edpresso/how-to-use-the-fgets-function-in-c) <br />
> [_C++ Reference: \<cstdio\>, fgets()_](https://www.cplusplus.com/reference/cstdio/fgets/) <br />

