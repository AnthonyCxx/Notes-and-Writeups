# Operator Overloading in C++
Operator overloading is the ability to define what should happen when operators are applied to classes (a user-defined type). Anything that can be done with operator
overloading can be done with just functions, but operator overloading makes code far more readable. I mean, do you _really_ 
want to write out `coordinates.multiply(Othercoordinates.negate())` when you could write `coordinates * -OtherCoordinates` instead? Obivously, there is a question of clarity, 
but that's where the programmer's discretion should come in. As a rule of thumb, if you have to refer to the implementation of the class
to understand what an overloaded operator does, then it's poorly written. Operators should only be overloaded when it makes perfect sense and aids the clarity of the code.
To overload an operator, declare a function like so: <br /> `returnType operator operatorSymbol(parameters);`. For example, `bool operator==(const Date& other) const;`
could be used to compare a class '_Date_'.

## Notable Restrictions on Operator Overloading <br />
- You cannot change [operator precedence](https://www.ibm.com/docs/en/zos/2.4.0?topic=operators-operator-precedence-associativity) <br />
- [Associativity](https://www.ibm.com/docs/en/zos/2.4.0?topic=operators-operator-precedence-associativity) cannot be changed  <br />
- You cannot use default parameters <br />
- You cannot create new operators <br />
- You cannot overload some operators [.](https://docs.microsoft.com/en-us/cpp/cpp/member-access-operators-dot-and?view=msvc-160), [.*](https://docs.microsoft.com/en-us/cpp/cpp/pointer-to-member-operators-dot-star-and-star?view=msvc-160), [::](https://docs.microsoft.com/en-us/cpp/cpp/scope-resolution-operator?view=msvc-160), [?:](https://docs.microsoft.com/en-us/cpp/cpp/conditional-operator-q?view=msvc-160), [sizeof()](https://docs.microsoft.com/en-us/cpp/cpp/sizeof-operator?view=msvc-160)
		
- Some overloaded operators (<< and >> notably) cannot be a part of the class itself, but still need access <br /> 
  to the data members of the class (public and private). Using [the keyword friend](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Object-Oriented%20Programming/Access%20Modifiers.md#granting-access-to-private-data-members-with-friend) at the front of a function  <br />
  declaration gives the function access to all the data members of the given class. **The keyword friend is only   <br />
  included in the function declaration**.  <br />


## Overloading Unary Operators
Unary operators are the simplest to overload, as they take no parameters. <br />
In this example, coordinates can be easily made positive or negative by putting a positive or negative sign in front of them.

The overloaded operators here return a new set of coordinates (as an anonymous object) because we don't want to alter the original set 
of coordinates. Plus, you can't use _void_ functions in expression (like 2 + 2), so we have to return something. If you do alter
the original coordinates, return [_\*this_](https://www.geeksforgeeks.org/this-pointer-in-c/) instead of a new set of coordinates.
The _\*this_ keyword is a pointer to the current instance of the class, which allows you to refer to the current object.
```C++
#include <iostream>
#include <string>
using namespace std;

// COORDINATES CLASS //
class Coordinates
{
    private:
        int x, y;

    public:
        Coordinates(int, int);
        string getCoords() const;

        //Unary Plus and Minus
        Coordinates operator+();
        Coordinates operator-();
};

//Constructor
Coordinates::Coordinates(int X, int Y)
{
    x = X;
    y = Y;
}

//Get coordinates
string Coordinates::getCoords() const
{
    //Return the coordinates as a string
    return to_string(x) + ", " + to_string(y);
}

//+ Overload (unary plus)
Coordinates Coordinates::operator+()
{
    //Return a new set of coordianates (each coordinate is negative if the coordinate was originally positive)
    return Coordinates((x > 0 ? x : x * -1), (y > 0 ? y : y * -1));
}

//- Overload (unary minus)
Coordinates Coordinates::operator-()
{
    //Return a new set of negated coordinates
    return Coordinates(-x, -y);
}


// DRIVER CODE //
int main()
{
    //Declare two sets of coordinates
    Coordinates location(50, 70);

    cout << "Initial coordinates: " << location.getCoords() << '\n';

    //Negate the location and THEN get the coordinates. Returns a new set of negated coordinates.
    cout << "Negated coordinates: " << (-location).getCoords() << '\n';

    //Show the original coordinates were unaffected
    cout << "Initial coordinates: " << location.getCoords() << '\n';

    return 0;
}
```
> Reference: [_to\_string()_](https://www.geeksforgeeks.org/stdto_string-in-cpp/) 

## Overloading Binary Operators
Binary operators take one function parameter, which is usually a const reference.

```C++
#include <iostream>
#include <string>
using namespace std;

// COORDINATES CLASS //
class Coordinates
{
    private:
        int x, y;

    public:
        Coordinates(int, int);
        string getCoords() const;

        //Unary Plus and Minus
        Coordinates operator+();
        Coordinates operator-();

        //Binary Addition and Subtraction
        Coordinates operator+(const Coordinates&);
        Coordinates operator-(const Coordinates&);
};

//Constructor
Coordinates::Coordinates(int X, int Y)
{
    x = X;
    y = Y;
}

//Get coordinates
string Coordinates::getCoords() const
{
    //Return the coordinates as a string
    return to_string(x) + ", " + to_string(y);
}

//+ Overload (unary plus)
Coordinates Coordinates::operator+()
{
    //Return a new set of coordianates (each coordinate is negative if the coordinate was originally positive)
    return Coordinates((x > 0 ? x : x * -1), (y > 0 ? y : y * -1));
}

//- Overload (unary minus)
Coordinates Coordinates::operator-()
{
    //Return a new set of negated coordinates
    return Coordinates(-x, -y);
}

//+ Overload (binary addition)
Coordinates Coordinates::operator+(const Coordinates& other)
{
    //Return a new set of coordinates -- the sum of the two sets of coordinates
    return Coordinates(x + other.x, y + other.y);
}

//- Overload (binary subtraction)
Coordinates Coordinates::operator-(const Coordinates& other)
{
    //Return a new set of coordinates -- the difference of the two sets of coordinates
    return Coordinates(x - other.x, y - other.y);
}


// DRIVER CODE //
int main()
{
    //Declare two sets of coordinates
    Coordinates location(50, 70);
    Coordinates hiddenLair(-30, -500);

    //Get the difference between the sets of coordinates
    Coordinates difference = location - hiddenLair;
    cout << "Difference between 'location' and 'hiddenLair': " << difference.getCoords() << '\n';

    return 0;
}
```

## Special Cases
The following operators are special cases. Only the stream insertion/extraction and prefix/postfix operators are on the test for CSC-1720. <br />
The others are just kinda cool.

### _bool_ Operator
I'll be honest, I had no idea this existed until I came across [this cracked StackOverflow question](https://stackoverflow.com/questions/4600295/what-is-the-meaning-of-operator-bool-const).
The _bool_ overload allows a class to have a trait called implicit booleanness, which is the idea that the class itself can have a boolean value. You know how you can
write `if (inFile)` and it will evaluate to false if the file is bad or it's the end of the file? Well, that's implicit booleanness at work.

A _bool_ overload should be const and, unlike other overloads, should not have any return type but should have a return value (don't ask me why or how...).

```C++
#include <iostream>
#include <string>
using namespace std;

// COORDINATES CLASS //
class Coordinates
{
    private:
        int x, y;

    public:
        Coordinates(int, int);

        //Bool overload
        operator bool() const;
};

//Constructor
Coordinates::Coordinates(int X, int Y)
{
    x = X;
    y = Y;
}

//Bool overload
Coordinates::operator bool() const
{
    //An object 'Coordinates' is true if both the x- and y-coordinate are positive.
    return (x > 0 and y > 0);
}

// DRIVER CODE //
int main()
{
    //Delcare a new set of coordinates
    Coordinates location(50, 70);

    //The object 'location' of type 'Coordinates' can now be used as a boolean
    if(location)
        cout << "Both coordinates in 'location' are positive\n";  //Executed, 'location' is true
    else
        cout << "At least one of the coordinates in 'location' is negative :(\n";

    return 0;
}
```

### Typecast Operators
operator float() const

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
