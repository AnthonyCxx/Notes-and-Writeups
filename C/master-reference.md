# Master C Programming Reference Guide

## Output
```C
// General output
printf("Hello, world!");

// Output a variable
char name[] = "some name";
printf("%s\n", name);      
// The conversion specifier MUST match the datatype. Strings (char arrays) use %s
```
> Format: _printf(format section, expression section);_
> 
Ref: [Conversion/Format Specifiers](https://aticleworld.com/format-specifiers-in-c/)
## Input
```C
 //Get user input.
char input[50];                         //Declare a char array of 50 bytes
printf("Input: ");                     //Prompt
fgets(input, sizeof(input), stdin);   //Fgets implicitly copies in a newline character.
printf("%s", input);                 //Print user-provided string
```
> Format: _fgets(variable, sizeof(variable), source);_
