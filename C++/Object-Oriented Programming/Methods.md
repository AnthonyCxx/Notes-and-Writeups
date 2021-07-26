# Functions and Methods in C++
If you already know what functions are, [click here](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Object-Oriented%20Programming/Methods.md#methods) to skip to methods.

# Functions
A function is a block of code that can be called upon by name, executing it. A function declaration requires a return type, the name of the function, and a list of the
parameters that it takes. For now, only worry about the name, since we'll be using void functions.

```C++
#include <iostream>
using namespace std;

//Definition of a function 'printHello' with no return type (void) or parameters
void printHello()
{
    cout << "Hello, world!" << '\n';
}

int main()
{
    //Calling function 'printHello'
    printHello();

    return 0;
}
```

## The _return_ Keyword and Return Types
Functions can return a value to wherever it was called. The return keyword returns that value, which could be a literal, a variable, an expression, or even a 
data structure (an array, tuple, map, etc.). Once the return statement is executed, the function ends, regardless of whether there was code after the return statement. 
Any good compiler should warn you that the code after the return statement is 'dead code' (code that cannot and will not be executed). The datatype of the value that 
will be returned must be declared as a part of the function declaration (just before the name). Here, the return5() method returns an integer, 5. 
If a method does not return any value, then its return type is void.

```C++
#include <iostream>
using namespace std;

/*
    A function 'return5' that returns the integer 5
    to where it was called
*/
int return5()
{
    return 5;
}

int main()
{
    int number = return5();

    cout << "The number returned by function 'return5' is: " << number << '\n';

    return 0;
}
```

## Parameters
Functions can take [parameters](https://www.thoughtco.com/definition-of-parameters-958124) (sometimes called arguments). The function can then use these 
values as variables. When declaring parameters, be sure to declare their type as well. A simple method '_add_' could take two numbers as parameters and return their sum.
Parameters should be declared as a part of the parameters list (inside the parentheses following the function name) and should be prefaced by their datatype. If you have
multiple parameters, they should be comma-separated.

```C++
#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int main()
{
    cout << "5 + 5 = " << add(5, 5) << '\n';
}
```
## Default Parameters
In the event that a method is called without some or all parameters, measures can be put into place to ensure that each parameter still has some default value.
To add default parameters, simple put an equals sign followed by a [literal](https://thabo-ambrose.medium.com/what-is-a-literal-in-computer-programming-560eace90b5b) 
(some value). That way, the parameter will take on that value if and only if no other value is provided.

```C++
#include <iostream>
using namespace std;

/*
    Function 'add' adds two integers.
    If a value is not supplied, it is
    assumed to be 0.
*/
int add(int a = 0, int b = 0)
{
    return a + b;
}

int main()
{
    cout << "Calling 'add(5, 5)': " << add(5, 5) << '\n';               // a = 5, b = 5
    cout << "Calling 'add(7)' (one parameter): " << add(7) << '\n';    //  a = 7, b = 0
    cout << "Calling 'add()' (no parameters): " << add() << '\n';     //   a = 0, b = 0
}
```

## Function Overloading
C++ is an object-oriented language, so it supports [polymorphism](https://www.geeksforgeeks.org/polymorphism-in-c/). One of the major ways C++ support the object-oriented
programming paradigm is through function overloading (the others being operator overloading and virtual functions). Function overloading allows two functions to share
the same name and yet remain entirely distinct; the way the compiler can differentiate between functions is by the amount of parameters and/or their type, so you cannot
having two different functions that only differ in return type will not work ([reference](https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm#:~:text=Function%20Overloading%20in%20C%2B%2B,differ%20only%20by%20return%20type.)).

In this example, you have two different add functions, one of integers, and one for doubles. In actual practice, this would be best achieved by [templates](https://www.tutorialspoint.com/cplusplus/cpp_templates.htm), but you haven't learned those yet.

```C++
#include <iostream>
using namespace std;

//'add' function for integers
int add(int a = 0, int b = 0)
{
    return a + b;
}

//'add' funtion for doubles
double add(double a = 0, double b = 0)
{
    return a + b;
}

int main()
{
    //Calls two separate functions
    cout << "Calling the 'add' function for integers: " << add(1, 12) << '\n';
    cout << "Calling the 'add' function for double: " << add(3.5, 7.9) << '\n';
}
```

## Improving Performance with _inline_
The _inline_ keyword can be used to insert the actual body of the code into the program wherever the function is called — this can help increase efficiency by
preventing [function overhead](https://stackoverflow.com/questions/144993/how-much-overhead-is-there-in-calling-a-function-in-c). Furthermore "Functions expanded 
inline are subject to code optimizations not available to normal functions." 
([quote](https://docs.microsoft.com/en-us/cpp/cpp/inline-functions-cpp?view=msvc-160#inline-__inline-and-__forceinline); note this is the Microsoft C++ compiler).
Keep in mind that just because you mark a function as _inline_ does not mean that it will be inlined — your compiler treats it more as a suggestion, really.
If you _must_ inline a function for whatever reason, you can use compiler-specific techniques like GCC's `\_\_attribute\_\_((always_inline)) ([source](https://www.keil.com/support/man/docs/armcc/armcc_chr1359124974010.htm))

```C++
#include <iostream>
using namespace std;

inline int absurdMath(int a, int b)
{
    return a * b + 2 / 15;
}

int main()
{
    //'absurdMath()' is inlined, so 'absurdMath(157, 31135)' is directly replaced by '157 * 31135 + 2 / 15'
    cout << "The result of this absurd math is: " << absurdMath(157, 31135) << '\n';

    return 0;
}
```
> Sources: <br />
> cplusplus.com: [_What is C++ inline functions_](https://www.cplusplus.com/articles/2LywvCM9/) <br />
> Microsoft C++ Documentation: [_Inline Functions (C++)_](https://docs.microsoft.com/en-us/cpp/cpp/inline-functions-cpp?view=msvc-160) <br />
> GeeksforGeeks: [_Inline Functions in C++_](https://www.geeksforgeeks.org/inline-functions-cpp/) <br />
> StackOverflow: [_Do compilers always ignore inline hints?_](https://stackoverflow.com/questions/32047466/do-c11-compatible-compilers-always-ignore-inline-hints) <br />

## Improving Performance with _constexpr_
A constant expression (marked by the _constexpr_ keyword) indicates that the function can be evaluated at compile time and can be substituted with the result of the function
to increase performance at runtime. For a function to be a valid constant expression, it must be exceedingly simple, like a function with no more than one return statement
or a constructor with just an [initializer list](https://www.educative.io/edpresso/what-are-initializer-lists-in-cpp). Constant expressions cannot be virtual or a coroutine,
must return a literal type (i.e. not a user-defined type like a class), and cannot contain a whole slew of things, including but not limited to: a _try_/_catch_ block, 
any uninitialized variables, or variables that aren't literal types. If a constant expression contains any of these things, the _constexpr_ keyword will be ignored.

```C++
#include <iostream>
using namespace std;

constexpr int absurdMath(int a, int b)
{
    return a * b + 2 / 15;
}

int main()
{
    /*
       'absurdMath()' is a constant expression, so 'absurdMath(157, 31135)' is replaced
       by the result of '157 * 31135 + 2 / 15' (4,888,195)
    */
    cout << "The result of this absurd math is: " << absurdMath(157, 31135) << '\n';

    return 0;
}
```
> Sources: <br />
> Youtuber CPP Nuts: [_constexpr C++ | C++11_](https://www.youtube.com/watch?v=frifFlPO_uI) <br />
> CPPReference.com: [_constexpr specifier (since C++11)_](https://en.cppreference.com/w/cpp/language/constexpr) <br />
> Microsoft C++ Documentation: [_constexpr (C++)_](https://docs.microsoft.com/en-us/cpp/cpp/constexpr-cpp?view=msvc-160) <br />
> GeeksforGeeks: [_Understanding constexpr specifier in C++_](https://www.geeksforgeeks.org/understanding-constexper-specifier-in-c/) <br />
> StackOverflow: [_Difference between _constexpr_ and _const__](https://stackoverflow.com/questions/14116003/difference-between-constexpr-and-const) <br />


# Methods
A method is a function that is associated with a class or struct. Methods are blocks of code that can be invoked by name, executing the body of the method (its code).
Methods have full access to the members of a class, including private members.

## Defining a Method
To define a method, just define a function inside of a class. To use the method, call the function on an object using the [member-access operator](https://docs.microsoft.com/en-us/cpp/cpp/member-access-operators-dot-and?view=msvc-160).

```C++
#include <iostream>
using namespace std;

class Tool
{
    public:
        void use()
        {
            cout << "Using the tool!\n";
        }
};

int main()
{
    //Declare a new tool
    Tool tool;

    //Use the tool
    tool.use();

    return 0;
}
```

## Defining a Method Outside of a Class
In actual practice, classes can have many functions, some of which may have hundreds of lines of code. This makes class definitions quite crowded.
So, you can split the implementation of a class from the declaration inside the class; in practice, you should always divide the declaration and implementation
of methods. That way, you can quickly see what a class does without necessarily having to see the implementation.

When implementing a method outside of a class, you have to prefix the name of the function by the name of the class followed by the scope resolution operator, `::`,
to specify which class the method belongs to.

```C++
#include <iostream>
using namespace std;

class Tool
{
    public:
        //Declaring that there is a function called 'use()'
        void use();
};

//Implementing the function 'use' outside the class
void Tool::use()
{
    cout << "Using the tool!\n";
}

int main()
{
    //Declare a new tool
    Tool tool;

    //Use the tool
    tool.use();

    return 0;
}
```

## Special Method: Constructors
A constructor is a special type of method that is used to initialize the data members of a class. Constructors are automatically called when an instance of the 
class is made, which makes them incredibly convenient. You can differentiate general methods from the constructor because the constructor shares the name of the 
class verbatim. Classes also do not have a return type.

To pass values to the constructor, write them in a parameter list `( )` at the end of the object declaration as if declaring an instance of the class were calling
a function (because it is).
```C++
#include <iostream>
using namespace std;

class Tool
{
    public:
        // DATA MEMBERS //
        //Adding a data member for the constructor to initialize
        int durability;

        // FUNCTIONS //
        //Declaring the constructor (no return type)
        Tool(int);

        //Declaring that there is a function called 'use()'
        void use();
};

//Implementing the construtor outside of the class
Tool::Tool(int Durability)
{
    durability = Durability;
}

//Implementing the function 'use' outside the class
void Tool::use()
{
    cout << "Using the tool!\n";
}

int main()
{
    //Declare a new tool
    Tool tool(100);   //Durability is 100

    //Use the tool
    tool.use();

    return 0;
}
```

## Special Method: Copy Constructor
If you were to copy the contents of an array, how would you do it? Would you write `newArray = existingArray`? If you would, you would have just written a 
[shallow copy](https://stackoverflow.com/questions/184710/what-is-the-difference-between-a-deep-copy-and-a-shallow-copy) of the existing array, 
which means that both arrays are now pointing to the same space in memory. This is problematic because any changes to one array will affect the other. Even worse,
if one array is delete/goes out of scope, the other array won't become a dangling pointer, which could crash your program very easily. To solve this problem, write a
copy constructor. A copy constructor takes a single instance of the current class as its parameter and copies all of its members. If there is an array, a copy constructor
won't create a shallow copy — instead, it will create a deep copy by sequentially copying all the elements in the existing array into the new array.

### Extra: Understanding Why Shallow Copying Exists: <br />
Shallow copying occurs when you directly assign one pointer to another. You see, the variable that contains an array (e.g. 'arr' in `int arr[15]`) actually
stores the memory address of the first element in the array. So, when you write `newArray = existingArray`, you're really just assigning the memory address of
the existing array to the new array. _This_ is what causes the problem. Now you have two different variables referencing the exact same array in memory.

```C++
#include <iostream>
using namespace std;

// ****** ARRAYCONTAINER CLASS ****** //
class ArrayContainer
{
    private:
        int array[10];
        size_t length;
        //^ Length should always be 'size_t', as an integer may be too small

    public:
        //Parameterized Constructor
        ArrayContainer(int);

        //Copy constructor
        ArrayContainer(const ArrayContainer& Other);

        //Print array elements
        void print();

        //Assign an element in the array
        void set(int, int);
};

//Default Constructor
ArrayContainer::ArrayContainer(int beginning = 0)
{
    length = 10;

    for(int i=0; i < length; i++)
    {
        //Assigns and then increments (postfix)
        array[i] = beginning++;
    }
}

//Copy Constructor
ArrayContainer::ArrayContainer(const ArrayContainer& Other)
{
    //You have access to the other class's private members since it's the same class
    length = Other.length;

    //Sequentially copy each element of the array
    for(int i=0; i < Other.length; i++)
    {
        array[i] = Other.array[i];
    }
}


//Print
void ArrayContainer::print()
{
    //Print all 10 items in the array in a line
    for(int i=0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    cout << '\n';
}

//Set
void ArrayContainer::set(int index, int value)
{
    //If the index is valid (0 through 10), go ahead and assign the element
    if (index >= 0 and index <= 10)
    {
        array[index] = value;
    }
}

// DRIVER CODE //
int main()
{
    //Declare an array
    ArrayContainer originalArray(16);

    //Declare a new array that copies the original
    ArrayContainer newArray(originalArray);

    //Print the original values of the arrays
    originalArray.print();
    newArray.print();
    cout << '\n';

    //Change the new array
    newArray.set(0, 9999);

    //Show that there is no change in the original
    originalArray.print();
    newArray.print();

    return 0;
}
```

## Special Method: Destructors
Like constructors, destructors also have a special purpose and are called automatically. "Destructors are usually used to deallocate memory and do other cleanup 
for a class object and its class members when the object is destroyed. A destructor is called for a class object when that object passes out of scope or is explicitly 
deleted" ([quote](https://www.ibm.com/docs/en/i/7.3?topic=only-destructors-c)). Destructors also share the name of the class but are prefixed with a single tilde (~).

Sorry this example doesn't fit the others, but there just wasn't a good way to do it.
```C++
#include <iostream>
using namespace std;

class Scoreboard
{
    private:
        int* scores;        //A scoreboard to store points (as ints)
        size_t length;     //The length of the array (needed for looping)

    /*
       'size_t' is just a special datatype for storing the size of stuff (strings, data structures...).
       Anytime you are storing the size of something, make it 'size_t'.
    */

    public:
        Scoreboard(int);
        ~Scoreboard();
        void showScores();
};

//Constructor
Scoreboard::Scoreboard(int players)
{
    //Keep track of the scores for each player
    length = players;
    scores = new int[length];

    //Set all player's score to zero (initializing the array)
    for(int i=0; i < length; i++)
    {
        scores[i] = 0;
    }

    cout << "Created a scorebeard with " << length << " elements...\n";
}

//Destructor
Scoreboard::~Scoreboard()
{
    //Delete the array of scores
    delete [] scores;

    cout << "Deleting the array of " << length << " elements...\n";
}

void Scoreboard::showScores()
{
    for(int i=0; i < length; i++)
    {
        cout << "Player " << i + 1 << ": " << scores[length] << '\n';
    }
}

int main()
{
    //A scoreboard that keeps track of 5 players
    Scoreboard scoreboard(5);

    //Output all the scores
    scoreboard.showScores();

}
```

## _const_ Methods
When declaring the parameters of a function, you can declare them as _const_; this creates a problem for class methods because the data members of a class
are not taken as parameters, so you cannot label them as _const_ when writing the function parameters. To solve this, write the _const_ after the parameter list;
doing so will prevent the function from changing any of the data members of the class. And no, you cannot have a _const_ constructor.

```C++
#include <iostream>
using namespace std;

class Tool
{
    public:
        // DATA MEMBERS //
        //Adding a data member for the constructor to initialize
        int durability;

        // FUNCTIONS //
        //Declaring the constructor (no return type)
        Tool(int);

        //Declaring that there is a function called 'use()'
        void use() const;
};

//Implementing the construtor outside of the class
Tool::Tool(int Durability)
{
    durability = Durability;
}

//Implementing the function 'use' outside the class
void Tool::use() const
{
    cout << "Using the tool!\n";
}

int main()
{
    //Declare a new tool
    Tool tool(100);   //Durability is 100

    //Use the tool
    tool.use();

    return 0;
}
```
