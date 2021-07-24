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
    cout << "Calling 'add(5, 5)': " << add(5, 5) << '\n';
    cout << "Calling 'add(7)' (one parameter): " << add(7) << '\n';
    cout << "Calling 'add()' (no parameters): " << add() << '\n';
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

## Special Methods: Constructors
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

## _const_ Methods
When declaring the parameters of a function, you can declare them as _const_; this creates a problem for class methods because the data members of a class
are not taken as parameters, so you cannot label them as _const_ when writing the function parameters. To solve this, write the _const_ after the parameter list;
doing so will prevent the function from changing any of the data members of the class.

```C++
#include <iostream>
using namespace std;

class Tool
{
    public:
        //Declaring that there is a function called 'use()'
        void use() const;
};

//Implementing the function 'use' outside the class
void Tool::use() const
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
