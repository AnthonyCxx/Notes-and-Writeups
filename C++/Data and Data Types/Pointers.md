# Pointers in C++
> NOTE: this section is waiting to be updated on RAII. Seldom should you use raw pointers in your code.

A pointer is a derived datatype that points to some location in memory and are used to keep track of [dynamically-allocated memory](https://www.cplusplus.com/doc/tutorial/dynamic/) amongst other things. Like any variable, pointers are [strongly-typed](https://www.cs.cornell.edu/courses/cs1130/2012sp/1130selfpaced/module1/module1part4/strongtyping.html); however, they can also be [type-casted](https://docs.microsoft.com/en-us/cpp/cpp/reinterpret-cast-operator?view=msvc-160) easily. Pointers are the same size regardless of what type they point to (8 bytes on 64-bit platforms, 4 on 32-bit) ([ref](https://stackoverflow.com/questions/399003/is-the-sizeofsome-pointer-always-equal-to-four)).

## Declaring a Pointer
Pointers are declared like a normal variable, but include a '\*' after the datatype. If not given a value, the pointer will point to [NULL](https://www.learncpp.com/cpp-tutorial/null-pointers/#:~:text=A%20null%20value%20is%20a,1).
```C++
#include <iostream>
using namespace std;

int main(void)
{
    // A pointer that can point to an integer
    int* ptr;   // int* pointer is not given a value

    // Declare multiple points like: 'int *ptr, *ptr2, *ptr3;'
    
    if (ptr == NULL)   // true
        cout << "Default value of a pointer is NULL" << endl;

    return 0;
}
```
> Prints: <br />
> Default value of a pointer is NULL

## The & Operator
The [& (address-of) operator](https://www.techopedia.com/definition/25580/address-of-operator--c) yields the memory address of a variable.
The '&' operator can be used to assign pointers a value (either an existing variable or memory allocated with the [_new_](https://www.geeksforgeeks.org/new-and-delete-operators-in-cpp-for-dynamic-memory/) operator). <br />

Here is a demonstration of how a pointer can be used to create aliases to existing variables. Later, we'll touch on dynamic memory allocation.
```C++
#include <iostream>
using namespace std;

int main()
{
    int  var = 5;       // Declare
    int* ptr = &var;   // Assign the pointer to the memory address of 'var'.

    cout << "The value of 'var' is: " << var << '\n';

    *ptr = 10;   // 'ptr' is the memory address, '*ptr' is the value stored in 'ptr'

    cout << "The value of 'var' is: " << var << '\n';

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

To clarify, putting '\*' before a pointer while declaring a pointer is what indicates it is a pointer. Putting '\*' before an existing pointer variable references the contents
at the memory address of the pointer. 

```C++
#include <iostream>
using namespace std;

int main()
{
    // Declaring an integer and an integer pointer
    int  var = 5;
    int* ptr = &var;   // Assign the pointer to the memory address of 'var'

    /*
        ptr  = the memory address stored in 'ptr'
        &ptr = the memory address of 'ptr'
        *ptr = the data of the address being pointed to by 'ptr'
    */

    // Accessing memory addresses
    cout << "The memory address of 'var' is: " << ptr << '\n';       // 'ptr' is the address stored in the pointer
    cout << "The memory address of 'ptr' is: " << &ptr << "\n\n";   // '&ptr' is the address of the pointer

    // Dereferecning a pointer
    cout << "The value pointed to by the pointer is: " << *ptr << endl;

    return 0;
}
```
> Prints: <br />
> The memory address of 'var' is: 0x7fffd372b7fc <br />
> The memory address of 'ptr' is: 0x7fffd372b800 <br />

> The value pointed to by the pointer is: 5 <br />

## Deferencing Non-primitive Pointers with the -> Operator
Pointers can also be used with [non-primitive datatypes](https://geekstocode.com/primitive-and-non-primitive-data-types-in-cpp/), such as [structures](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Data%20and%20Data%20Types/Structures.md).
However, it becomes a bit more complex due to a problem with [operator precedence](https://docs.microsoft.com/en-us/cpp/cpp/cpp-built-in-operators-precedence-and-associativity?view=msvc-160). 
The ['.' (member access) operator](https://docs.microsoft.com/en-us/cpp/cpp/pointer-to-member-operators-dot-star-and-star?view=msvc-160) has a higher
precedence than the ['\*' (dereferencing) operator](https://www.computerhope.com/jargon/d/dereference-operator.htm); so, if you don't put parentheses around the '\*', you end up 
trying to access the data member of an arbitrary address in memory and then dereference that, which is utter nonsense. Needless to say the structure 
`(*pointer_to_struct).data_member)` is a bit verbose, so the `->` operator was invented as a shorthand. That way, you can simple write `pointer_to_struct->data_member` 
and be done.

```C++
#include <iostream>
using namespace std;

// 'Player' structure
struct Player
{
    int health;
    int attack;
    int exp;

};


// DRIVER CODE //
int main()
{
    // A 'Player' with 10 health, 7 attack, and 300 exp
    Player player1 = { .health = 10, .attack = 7, .exp = 300 };

    // A pointer to 'player1'
    Player* ptr = &player1;     // a pointer of datatype 'Player' pointing to player1;

    // Using (*ptr).member to access members
    cout << "Health: " << (*ptr).health << '\n';
    cout << "Attack: " << (*ptr).attack << '\n';
    cout << "EXP: " <<  (*ptr).exp << "\n\n";

    // Using ptr->member to access members
    cout << "Health: " << ptr->health << '\n';   // Lot simpler, huh?
    cout << "Attack: " << ptr->attack << '\n';
    cout << "EXP: " << ptr->exp << endl;

    return 0;
}
}
```
> Health: 10 <br />
> Attack: 7  <br />
> EXP: 300   <br />
>
> Health: 10 <br />
> Attack: 7  <br />
> EXP: 300   <br />

## Pointer Arithmetic
Basic arithmetic operations are allowed on pointers in the form of addition and subtraction. For example, the expression `ptr++` just means 'increment the pointer by one',
which would add `1 * sizeof(typeof(ptr))` to the pointer. Take an array for example, you may be used to writing `array[3]` to access the third element, but really what you're
writing is `*(array + 3)` -- the compiler just substitutes the expression. You see an array is just a raw series of bytes as is evident from the expression 
`malloc(10 * sizeof(int))` (from C); thus, in order to access the individual elements, the computer calculates the right element by starting at the pointer to the beginning of the 
array (`array`) and then adding the amount of bytes needed to reach the right location in memory. Assuming that the earlier example `*(array + 3)` is an int array, the 
computer would just take the address of the beginning of the array (`array`) and adds _3 \* sizeof(int)_ (a total of 12 bytes), and then dereference the result.

```C++
#include <iostream>
#define SIZE(array) sizeof(array) / sizeof(array[0])
using namespace std;

int main()
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        // Print out all the elements
    for(int i=0; i < SIZE(array); i++)
    {
        // '*(array + i)' means 'take the beginning of the array and access the 'i'th element
        cout << *(array + i) << " ";
    }
    cout << '\n';

    return 0;
}
```

## Differencing and Comparisons
A lot more than just addition can be done with pointers Pointers are just integers so you can also subtract the difference between them or compare them
using relational operators (<, >, <=, >=, ==, !=). And before you ask, don't even try to multiply pointers or use _pow()_ on them.

```C++
#include <iostream>
#define SIZE(array) sizeof(array) / sizeof(array[0])
using namespace std;

int main()
{
    //Declare an int array and two integer pointers
    int *front, *end;
    int arr[5] = {1, 2, 3, 4, 5};

    //Set the pointers to the front and back of the array
    front = &arr[0];
    end = &arr[SIZE(arr) - 1];

    if (front < end)   //End has a higher memory address, so it's greater
        cout << "The front of the array is sooner than the last\n";

    return 0;
}
```
