# Quick C Programming Reference Guide for C++ Programmers
If it's not mentioned here, it's probably the same. <br />
I got most of this from a quick skim of [_Practical C Programming_](https://www.amazon.com/Practical-Programming-Does-Nutshell-Handbooks/dp/1565923065), by Steve Oualline

## Output
```C
//General output
printf("Hello, world!");

//Output a variable
int num = 5;
printf("%d\n", num);      
//The conversion specifier MUST match the datatype. Standard integers use %d.
```
> Format: _printf(format section, expression section);_
> 
Ref: [C Conversion/Format Specifiers](https://aticleworld.com/format-specifiers-in-c/)
## Input

### Getting User Input
```C
//Get user input
char input[50];                         //Declare a char array of 50 bytes
printf("Input: ");                     //Prompt
fgets(input, sizeof(input), stdin);   //Note: fgets implicitly copies in a newline character.
printf("%s", input);                 //Print user-provided string
```
> Format: _fgets(variable, sizeof(variable), source);_

### Processing User Input
```C
//Taken from the TutroialsPoint article 'C library function - sscanf()', linked below
int day, year;
char weekday[20], month[20], dtm[100];

//sscanf allows you to parse a single string for different variables
strcpy(dtm, "Saturday March 25 1989");   //assigns "Saturday March 25 1989" to "dtm"
sscanf(dtm, "%s %s %d  %d", weekday, month, &day, &year);   //Copies word/integer sequentially into the appropriate variables
```
> Format: _sscanf(source, format, variables)_ <br />
> Source: [TutorialsPoint](https://www.tutorialspoint.com/c_standard_library/c_function_sscanf.htm)

## 'Strings'
There are no strings in C, only char arrays and char pointers, both of which must end in a null-terminating character. 
Below are two equally valid ways of writing a 'string'. 
The main difference is that you will get a segmentation fault if you try to edit a char pointer.
```C
//C-String using Char Array
char name[] = "bob";
printf("(char array) Name before: %s\n", name);

name[2] = 'p';    //changes 'bob' to 'bop' ; legal
printf("(char array) Name after: %s\n\n", name);

//C-String using Char Pointer
char* surname = "bob";
printf("(char pointer) Name before: %s\n", surname);

surname[2] = 'p';   //Seg fault. ; cannot change char pointers
printf("(char pointer) Name after: %s\n", surname);
```

### Notable Functions
These functions are included in the `<string.h>` header file
| Function | Function |
| -------- | -------- |
| strlen(_**str**_) | returns the length of the string |
| strcmp(_**str**_, _**str**_) | compares the two strings; **returns 0 is equal** |
| strchr(_**str**_, _**int**_) | returns a pointer to the first instance of some character in the string - [guide](https://www.tutorialspoint.com/c_standard_library/c_function_strchr.htm) |
| strrchr(_**str**_, _**int**_) | returns a pointer to the last instance of some character in a string - [guide](https://www.tutorialspoint.com/c_standard_library/c_function_strrchr.htm) |
| strcat(_**str**_, _**str**_) | [concatonates](https://www.programmingsimplified.com/c-program-concatenate-strings) the second string to the first |
| strcpy(_**str**_, _**str**_) | copies the second string into the first |\
> Do _NOT_ do `if (strcmp(str1, str2))` since it returns 0. You have to do `if (strcmp(str1, str2) == 0)`.

### Readings
- [A reference for C-strings](https://www.tutorialspoint.com/cprogramming/c_strings.htm)
- [Char Arrays vs Char Pointers](https://stackoverflow.com/questions/10186765/what-is-the-difference-between-char-array-and-char-pointer-in-c)
