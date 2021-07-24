# Functions and Methods in C++
A method is a function that is associated with a class or struct. Methods are blocks of code that can be invoked by name, executing the body of the method (its code).
Methods have full access to the members of a class, including private members.

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
Parameters should be declared as a part of the parameters list (inside the parentheses following the function name) and should be prefaced

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

# Methods IGJEAIOJGOIEAJG not finished thanks

## Defining a Method

```C++
#include <iostream>
#include <string>
using namespace std;

class Pickaxe
{
    private:
        string name;
        int durability;

    public:
        //Constructor
        Pickaxe(string Name = "A Generic Pickaxe")
        {
            name = Name;
        }

        //Get + set methods for 'name'
        string getName() { return name; }
        void setName(string Name) { name = Name; }

        //Get + set methods for 'durability'
        int getDurability() { return durability; }
        void setDurability(int Durability) { durability = Durability; }

        void swing()
        {
            cout << "Swinging the pickaxe!\n";
            durability--;
        }
};

int main()
{
    Pickaxe pickaxe;

    pickaxe.swing();
}
```

## Defining a Method Outside of a Class
The body of a method does not have to be defined inside of a class; methods only have to be declared inside a class. <br />
When implementing a method outside of a class, you have to prefix the name of the function by the name of the class
followed by the scope resolution operator, `::`.

```C++
#include <iostream>
#include <string>
using namespace std;

class Pickaxe
{
    private:
        string name;
        int durability;

    public:
        //Functions
        Pickaxe(string);
        string getName();
        void setName(string);
        int getDurability();
        void setDurability(int);
        void swing();
};

// METHOD IMPLEMENTATION //

//Constructor
Pickaxe::Pickaxe(string Name = "A Generic Pickaxe")
{
    name = Name;
}

//Get + set methods for 'name'
string Pickaxe::getName()
{
    return name;
}

void Pickaxe::setName(string Name)
{
    name = Name;
}

//Get + set methods for 'durability'
int Pickaxe::getDurability()
{
return durability;
}

void Pickaxe::setDurability(int Durability)
{
    durability = Durability;
}

//Swing the pickaxe
void Pickaxe::swing()
{
    cout << "Swinging the pickaxe!\n";
    durability--;
}


// DRIVER CODE //
int main()
{
    Pickaxe pickaxe;

    pickaxe.swing();
}
```

## _const_ Methods

```C++

```
