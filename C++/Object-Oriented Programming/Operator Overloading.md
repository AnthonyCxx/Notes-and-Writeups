# Operator Overloading in C++
Operator overloading is the ability to define what should happen when operators are applied to classes (a user-defined type).

Anything that can be done with operator overloading can be done with just functions, but operator overloading makes code far more readable. I mean, do you _really_ 
want to write out `coordinates.multiply(Othercoordinates.negate())` when you could write `coordinates * -OtherCoordinates` instead? Obivously, there is a question of clarity, 
but that's where the programmer's discretion should come in. As a rule of thumb, if you have to refer to the implementation of the class
to understand what an overloaded operator does, then it's poorly written. Operators should only be overloaded when it makes perfect sense and aids the clarity of the code.

## Notable Restrictions on Operator Overloading <br />
- You cannot change [operator precedence](https://www.ibm.com/docs/en/zos/2.4.0?topic=operators-operator-precedence-associativity) <br />
- [Associativity](https://www.ibm.com/docs/en/zos/2.4.0?topic=operators-operator-precedence-associativity) cannot be changed  <br />
- You cannot use default parameters <br />
- You cannot create new operators <br />
- You cannot overload some operators [.](https://docs.microsoft.com/en-us/cpp/cpp/member-access-operators-dot-and?view=msvc-160), [.*](https://docs.microsoft.com/en-us/cpp/cpp/pointer-to-member-operators-dot-star-and-star?view=msvc-160), [::](https://docs.microsoft.com/en-us/cpp/cpp/scope-resolution-operator?view=msvc-160), [?:](https://docs.microsoft.com/en-us/cpp/cpp/conditional-operator-q?view=msvc-160), [sizeof()](https://docs.microsoft.com/en-us/cpp/cpp/sizeof-operator?view=msvc-160)
		
- Some overloaded operators (<< and >> notably) cannot be a part of the class itself, but still need access <br /> 
  to the data members of the class (public and private). Using the keyword friend at the front of a function  <br />
  declaration gives the function access to all the data members of the given class. **The keyword friend is only   <br />
  included in the function declaration**.  <br />


## Overloading Unary Operators
Unary operators are the simplest to overload, as they take no paramters. In this example, coordinates can be easily made positive or negative by putting a
positive or negative sign in front of them.

```C++
#include <iostream>
using namespace std;

class Coordinates
{
    private:
        int x, y;

    public:
        Coordinates(int, int);
        void printCoords() const;

        /*
            operator+ and operator- take no parameters,
            so it's clear that they are the unary plus and minus
            operators, not the binary addition and subtraction operators
        */
        void operator+();
        void operator-();
};

//Constructor
Coordinates::Coordinates(int X, int Y)
{
    x = X;
    y = Y;
}

//Get coordinates
void Coordinates::printCoords() const
{
    cout << "Coordinates: " << x << ", " << y << '\n';
}

//+ Overload (unary plus)
void Coordinates::operator+()
{
    //If x or y is negative, make them positive

    if (x < 0)
        x *= -1;

    if (y < 0)
        y *= -1;
}

//- Overload (unary minus)
void Coordinates::operator-()
{
    x = -x;
    y = -y;
}

int main()
{
    //Declare a location with the coordinates 50, 70 (x, y)
    Coordinates location(50, 70);

    //Print coordinates
    location.printCoords();

    //Make coordinates negative
    -location;

    //Print coordinates
    location.printCoords();

    //Make coordinates positive
    +location;

    //Print coordinates
    location.printCoords();

    return 0;
}
```


## Overloading Binary Operators
....Differentiating Between Unary and Binary Operators


## Special Cases
The following operators are special cases. Only the stream insertion/extraction, and prefix/postfix operators are on the test for CSC-1720.

### _bool_ Operator

### Stream Insertion and Extraction Operators (<< and >>)


### Prefix and Postfix Operators (++ and --)


## Deleting Operators
`className::operator& = delete;`


## Sources
Book: [_C++ Programming: Program Design Including Data Structures, 8th Edition_](https://www.amazon.com/Programming-Program-Design-Including-Structures/dp/1337117560) by D.S. Malik <br />
IBM: [_Overloading operators (C++ only)_](https://www.ibm.com/docs/en/zos/2.4.0?topic=only-overloading-operators-c) <br />
Microsoft C++ Documentation: [_Operator overloading_](https://docs.microsoft.com/en-us/cpp/cpp/operator-overloading?view=msvc-160) <br />
GeeksforGeeks: [_Operator Overloading in C++_](https://www.geeksforgeeks.org/operator-overloading-c/) <br />
TutorialsPoint: [_C++ Overloading (Operator and Function)_](https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm) <br />
Programiz: [_C++ Operator Overloading_](https://www.programiz.com/cpp-programming/operator-overloading) <br />
TheCherno: [_OPERATORS and OPERATOR OVERLOADING in C++_](https://www.youtube.com/watch?v=mS9755gF66w) <br />
Artima: [_The Safe Bool Idiom_](https://www.artima.com/articles/the-safe-bool-idiom) <br />
