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
> Compile this program and then enter more than 50 characters. The program will automaticaly terminate with a warning: '\*\*\* stack smashing detected \*\*\*: terminated <br />
Aborted (core dumped)'

## fgets()
