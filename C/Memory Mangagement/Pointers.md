# Pointers in C
A pointer is a variable that points to some location in memory and are often used to keep track of [dynamically-allocated memory](https://www.programiz.com/c-programming/c-dynamic-memory-allocation). Like any variable, pointers are [strongly-typed](https://www.cs.cornell.edu/courses/cs1130/2012sp/1130selfpaced/module1/module1part4/strongtyping.html); however, they can also be [type-casted](https://ecomputernotes.com/what-is-c/function-a-pointer/type-casting-of-pointers) easily.

## Declaring a Pointer
Pointers are declared like a normal variable, but include a '\*' after the datatype. If not given a value, the pointer will point to [NULL](https://www.tutorialspoint.com/null-pointer-in-c).
```C
#include <stdio.h>

int main(void)
{
    // A pointer that can point to an integer
    int* ptr;   // int* pointer is not given a value

    // Print what 'ptr' points to (NULL)
    printf("The memory address of 'ptr' is: %p\n", ptr);

    return 0;
}
```
> Prints: <br />
> The memory address of 'ptr' is: (nil)

## The & Operator
The [& operator](https://fresh2refresh.com/c-programming/c-interview-questions-answers/what-is-ampersand-and-star-operators-in-c/) yields the memory address of a variable.
The '&' operator can be used to assign pointers a value (either an existing variable or memory allocated with [_malloc()_](https://www.tutorialspoint.com/c_standard_library/c_function_malloc.htm)). <br />

Here is a demonstration of how a pointer can be used to create aliases to existing variables. Later, we'll touch on dynamic memory allocation.
```C
#include <stdio.h>

int main(void)
{
    int  var = 5;       // Declare
    int* ptr = &var;   // Assign the pointer to the memory address of 'var'.

    printf("The value of 'var' is: %d\n", var);

    *ptr = 10;   // 'ptr' is the memory address, '*ptr' is the value stored in 'ptr'

    printf("The value of 'var' is: %d\n", var);

    return 0;
}
```
> Prints: <br />
> The value of 'var' is: 5  <br />
> The value of 'var' is: 10 <br />

## Dereferencing (accessing) Pointers
Remember that pointers store the memory address of a variable, not the contents itself. Pointers are not a mirror image of another variable; 'ptr' in the previous examples 
is the actual address in memory. If you want to access the variable at the memory address pointed to by the pointer, then you have to use the [indirection/dereferencing
operator, '\*'](https://www.computerhope.com/jargon/d/dereference-operator.htm). Putting '\*' before the pointer will access the contents stored at the pointer's location
in memory.

To clarify, putting '\*' before a pointer while declaring a pointer is what indicates it is a pointer. Putting '\*' before an existing pointer references the contents
at the memory address of the pointer.
```C
#include <stdio.h>

int main(void)
{
    // Declaring an integer and an integer pointer
    int  var = 5;
    int* ptr = &var;   // Assign the pointer to the memory address of 'var'

    // Accessing memory addresses
    printf("The memory address of 'var' is: %p\n", ptr);      // 'ptr' is the address stored in the pointer
    printf("The memory address of 'ptr' is: %p\n\n", &ptr);   // '&ptr' is the address of the pointer

    // Dereferecning a pointer
    printf("The value pointed to by the pointer is: %d\n", *ptr);

    return 0;
}
```
> Prints: <br />
> The memory address of 'var' is: 0x7ffff9162afc <br />
> The memory address of 'ptr' is: 0x7ffff9162b00 <br />
>
> The value pointed to by the pointer is: 5 <br />


## Deferencing Non-primitive Pointers with the -> Operator

## Sources
JavaTPoint: [_C Pointers_](https://www.javatpoint.com/c-pointers) <br />
TutorialsPoint: [_C - Pointers_](https://www.tutorialspoint.com/cprogramming/c_pointers.htm) <br />
GeeksforGeeks: [_Void, Null, and Wild Pointers_](https://www.geeksforgeeks.org/dangling-void-null-wild-pointers/) <br />
Programiz: [_C Pointers_](https://www.programiz.com/c-programming/c-pointers) <br />
Guru99: [_Pointers in C Programming: What is Pointer, Types & Examples_](https://www.guru99.com/c-pointers.html) <br />
BeginnersBook: [_Pointers in C Programming with examples_](https://beginnersbook.com/2014/01/c-pointers/) <br />
