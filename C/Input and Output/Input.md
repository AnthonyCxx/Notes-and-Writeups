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
