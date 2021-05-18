# Quick C Programming Reference Guide

## Output
```C
// General output
printf("Hello, world!");

// Output a variable
int num = 5;
printf("%d\n", num);      
// The conversion specifier MUST match the datatype. Standard integers use %d.
```
> Format: _printf(format section, expression section);_
> 
Ref: [C Conversion/Format Specifiers](https://aticleworld.com/format-specifiers-in-c/)
## Input
```C
 //Get user input.
char input[50];                         //Declare a char array of 50 bytes
printf("Input: ");                     //Prompt
fgets(input, sizeof(input), stdin);   //Fgets implicitly copies in a newline character.
printf("%s", input);                 //Print user-provided string
```
> Format: _fgets(variable, sizeof(variable), source);_

## 'Strings'
There are no strings in C, only char arrays and char pointerss, both of which must end in a null-terminating character. Below are two equally valid ways of writing a 'string'.
The main difference is that you will get a segmentation fault if you try to edit a char pointer.
```C
//C-String using Char Array
 char name[] = "bob";
printf("Name before (char array): %s\n", name);

name[2] = 'p';
printf("Name after (char array): %s\n\n", name);

//C-String using Char Pointer
char* surname = "bob";
printf("Name before (char pointer): %s\n", surname);

surname[2] = 'p';   //Seg fault.
printf("Name after (char pointer): %s\n", surname);
```
> Output: <br />
> Name before (char array): bob <br />
> Name after (char array): bop <br />
> Name before (char pointer): bob <br />
> Segmentation fault (core dumped) <br />
### Readings
- [A reference for C-strings](https://www.tutorialspoint.com/cprogramming/c_strings.htm)
- [Char Arrays vs Char Pointers](https://stackoverflow.com/questions/10186765/what-is-the-difference-between-char-array-and-char-pointer-in-c)
