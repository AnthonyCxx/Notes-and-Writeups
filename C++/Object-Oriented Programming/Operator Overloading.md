# Operator Overloading in C++
> Jump: <br />
> [Overloading Unary Operators](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Object-Oriented%20Programming/Operator%20Overloading.md#overloading-unary-operators) <br />
> [Overloading Binary Operators](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Object-Oriented%20Programming/Operator%20Overloading.md#overloading-binary-operators) <br />
> [Special Cases](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Object-Oriented%20Programming/Operator%20Overloading.md#special-cases): [_++ and --_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Object-Oriented%20Programming/Operator%20Overloading.md#prefix-and-postfix-operators--and---) and [_<</>>_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Object-Oriented%20Programming/Operator%20Overloading.md#stream-insertion-and-extraction-operators--and-) <br />
> [Conversion Operators](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Object-Oriented%20Programming/Operator%20Overloading.md#conversion-operators) <br />
> [Disabling Operators](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Object-Oriented%20Programming/Operator%20Overloading.md#disabling-functions-with-delete) <br />

Operator overloading is the ability to define what should happen when operators are applied to classes (a user-defined type). Anything that can be done with operator
overloading can be done with just functions, but operator overloading makes code far more readable. I mean, do you _really_ 
want to write out `coordinates.multiply(Othercoordinates.negate())` when you could write `coordinates * -OtherCoordinates` instead (looking at you, Java programmers.)? 
Obivously, there is a question of clarity, but that's where the programmer's discretion should come in. As a rule of thumb, if you have to refer to the implementation 
of the class to understand what an overloaded operator does, then it's poorly written. Operators should only be overloaded when it makes perfect sense and aids the clarity of the code. To overload an operator, declare a function like so: `returnType operator operatorSymbol(parameters);`. For example,
`bool operator==(const Date& other) const;`
could be used to compare a class '_Date_'.

## Notable Restrictions on Operator Overloading <br />
- You cannot change [operator precedence](https://www.ibm.com/docs/en/zos/2.4.0?topic=operators-operator-precedence-associativity) <br />
- [Associativity](https://www.ibm.com/docs/en/zos/2.4.0?topic=operators-operator-precedence-associativity) cannot be changed  <br />
- You cannot use default parameters <br />
- You cannot create new operators <br />
- You cannot overload some operators [.](https://docs.microsoft.com/en-us/cpp/cpp/member-access-operators-dot-and?view=msvc-160), [.*](https://docs.microsoft.com/en-us/cpp/cpp/pointer-to-member-operators-dot-star-and-star?view=msvc-160), [::](https://docs.microsoft.com/en-us/cpp/cpp/scope-resolution-operator?view=msvc-160), [?:](https://docs.microsoft.com/en-us/cpp/cpp/conditional-operator-q?view=msvc-160), [sizeof()](https://docs.microsoft.com/en-us/cpp/cpp/sizeof-operator?view=msvc-160)
- Some overloaded operators (<< and >> notably) cannot be a part of the class itself.


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

# Special Cases
The following operators are special cases. Only the stream insertion/extraction and prefix/postfix operators are on the test for CSC-1720. <br />
The others are just kinda cool.

## Prefix and Postfix Operators (++ and --)
The only difference between the prefix increment operator and the postfix increment operator (++) is whether they are put before or after the variable,
so how do you overload them? Well, you differentiate between them by giving the postfix operator a dummy _int_ parameter.

Here, I chose to alter the actual class, so I chose to return _\*this_ instead of a new set of coordinates.
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

        //Overloaded Prefix and Postfix Increment
        Coordinates& operator++();          //Prefix Increment
        Coordinates& operator++(int);      //Postfix Increment
        Coordinates& operator--();        //Prefix Decrement
        Coordinates& operator--(int);    //Postfix Decrement
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

//Prefix Increment Overload
Coordinates& Coordinates::operator++()
{
    x++;
    y++;

    return *this;
}

//Postfix Increment Overload
Coordinates& Coordinates::operator++(int dummy)  //You won't use 'dummy'
{
    x++;
    y++;

    return *this;
}

//Prefix Decrement Overload
Coordinates& Coordinates::operator--()
{
    x--;
    y--;

    return *this;
}

//Postfix Decrement Overload
Coordinates& Coordinates::operator--(int dummy)  //You won't use 'dummy'
{
    x--;
    y--;

    return *this;
}

// DRIVER CODE //
int main()
{
    //Delcare a new set of coordinates
    Coordinates location(50, 70);

        //Original coordinates: 50, 70
	cout << "Original coordinates: " << location.getCoords() << '\n';

        location++;
        //Coordinates incremented by 1: 51, 71
	cout << "Coordinates incremented by 1: " << location.getCoords() << '\n';

        location--;
        location--;
	//Location decremented by 2: 49, 69
        cout << "Location decremented by 2: " << location.getCoords() << '\n';

    return 0;
}
```

## Stream Insertion and Extraction Operators (<< and >>)
> Pre-requisite: the [_friend_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Object-Oriented%20Programming/Access%20Modifiers.md#granting-access-to-private-data-members-with-friend) keyword <br />

The stream insertion operator (<<) and stream extraction operator (>>) overloads cannot be a part of the class definition to allow chain calling ([see here](https://stackoverflow.com/questions/9351166/does-overloading-operator-works-inside-the-class) for why). Because of this, you have to write the << and >> overloads
as [_friend_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Object-Oriented%20Programming/Access%20Modifiers.md#granting-access-to-private-data-members-with-friend) functions. The << and >> functions will both take two parameters, an [_ostream_](https://www.geeksforgeeks.org/c-stream-classes-structure/) or [_istream_](https://www.cplusplus.com/forum/beginner/73195/) variable respectively and then the class you want to overload for. In case you aren't familiar with the _istream_
and _ostream_ datatypes, they are class types of _cin_ and _cout_; _istream_ stands for 'input stream' and _ostream_ stands for 'output stream'.

The _friend_ keyword should only be included in the declaration; do not include it in the function implementation.
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

        //<< and >> Overloads (friend functions)
        friend ostream& operator<<(ostream&, const Coordinates&);
        friend istream& operator>>(istream&, Coordinates&);
};

//Constructor
Coordinates::Coordinates(int X = 0, int Y = 0)
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

//Stream Insertion Overload (<<)
ostream& operator<<(ostream& ostreamObject, const Coordinates& coords)
{
    //Try not to include newlines (\n) in overloads, because they prevent code flexibility
    ostreamObject << "Coordinates: " << coords.getCoords();

    return ostreamObject;
}

//Stream Extraction Overload (>>)
istream& operator>>(istream& istreamObject, Coordinates& coords)
{
    //Friend functions have access to a class's private members
    istreamObject >> coords.x >> coords.y;

    return istreamObject;
}

// DRIVER CODE //
int main()
{
    //Declare a new set of coordinates
    Coordinates remoteIsland;

    //Get the coordinates for remoteIsland
    cout << "Enter the location of the newfound island: ";
    cin >> remoteIsland;   //Is equal to 'cin >> remoteIsland.x >> remoteIsland.y'

    //Now you can straight-up output the location
    cout << remoteIsland << '\n';

    return 0;
}
```

# Conversion Operators
If you overload a datatype as an 'operator', then you can convert the class into that datatype whenever you (or the program) needs to. If you overload the _bool_
datatype, then you can use the class as a boolean. If you overload the _const char\*_ datatype, then you can use the class like a string literal (like "Hello, World!").

## _const char\*_ Operator
Overloading the _const char\*_ provides an alternative to overloading the stream insertion operator (_<<_). However, this approach is not favored as you must return
a c-string, not a string. And if you call _.c\_str()_ on a temporary string (like `return string("this is the returned literal").c_str()`), then it will return an empty
string because the c-string reflects the string and the string went out of scope. The solution to this is unfortunately adding a new string class member to store the string.
It's a sub-optimal solution in my opinion.

```C++
#include <iostream>
#include <string>
using namespace std;

// COORDINATES CLASS //
class Coordinates
{
    private:
        int x, y;
        string coords;

    public:
        Coordinates(int, int);
        operator const char*();
};

//Constructor
Coordinates::Coordinates(int X, int Y)
{
    x = X;
    y = Y;
}

//Const char* Operator Overload
Coordinates::operator const char*()
{
    coords = to_string(x) + ", " + to_string(y);
    return coords.c_str();
}

// DRIVER CODE //
int main()
{
    //Delcare a new set of coordinates
    Coordinates location(50, 70);
  
    //Prints '50, 70'
    cout << location << '\n';

    return 0;
}
```

## _bool_ Operator
I'll be honest, I had no idea this existed in C++ until I came across [this cracked StackOverflow question](https://stackoverflow.com/questions/4600295/what-is-the-meaning-of-operator-bool-const).
The _bool_ overload allows a class to be implicitly convered into a boolean when used as a bool, like in a loop or if statement.

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

# Disabling Functions with _delete_
As of C++11, you can set a function (or operator overload) to `= delete`, which will then prevent the compiler from using said function/operator.

## Deleting Operators and Functions
Something something, this example isn't done...

This example contains a class _SecureString_ which acts as a wrapper for a simple _char*_, preventing it from being copied in the program as well as disabling referencing
its address in memory. I used a c-string instead of a normal string because not only is it smaller, giving it a smaller memory footprint, but a c-string gives me the ability 
to manually overwrite the contents of the c-string with _memset()_, protecting it from memory imaging techniques that may be able otherwise fish it out.
```C++
#include <iostream>
#include <cstring>   //Contains 'memset()'
using namespace std;

// SECURESTRING CLASS //
class SecureString  //Mimics C#'s 'SecureString' class under 'System.Security'
{
    private:
        char*  data;
                size_t size;
        bool disposed;

    public:
        //Constructor
        SecureString(const char*);
        ~SecureString();

        //Dispose of the memory
        void dispose();

        //Delete all methods of referencing the 'SecureString' object (copy constructor, operators)
        SecureString(const SecureString&) = delete;               //Copy Constructor
        SecureString* operator&() const = delete;                //Address-of operator
        SecureString& operator=(const SecureString&) = delete;  //Assignment assignment operator
};

//Constructor (const char*)
SecureString::SecureString(const char* cstr)
{
    //Data is initialized
    disposed = false;

    //Get the size of the string
        size = strlen(cstr);

    //Copy the string literal into the data
    data = new char[size];           //Create a new c-string
    memcpy(data, cstr, size);       //Copy the given string
}

//Destructor
SecureString::~SecureString()
{
    /*
        If the password has not been disposed of before going out of scope,
        dispose of it.
    */

        //If not already disposed of, overwrite the memory
    if (!disposed)
        dispose();

        //Delete the heap allocated char array
        delete [] data;
}

//Dispose: zero-writes the memory the string was allocated to
void SecureString::dispose()
{
    //Write binary zeros to the c-string
    memset(data, '\0', strlen(data));
}

// DRIVER CODE //
int main()
{
    //Create a new secure c-string
    SecureString SSN("some social security number");

    //SecureString ptr = &SSN;    <== illegal, '&' is deleted

    //Overwrite the memory of the c-string, disposing of it
    SSN.dispose();

    return 0;

}
```

## Preventing Certain Implicit Type Conversions

## Sources
Book: [_C++ Programming: Program Design Including Data Structures, 8th Edition_](https://www.amazon.com/Programming-Program-Design-Including-Structures/dp/1337117560) by D.S. Malik <br />
IBM: [_Overloading operators (C++ only)_](https://www.ibm.com/docs/en/zos/2.4.0?topic=only-overloading-operators-c) <br />
Microsoft C++ Documentation: [_Operator overloading_](https://docs.microsoft.com/en-us/cpp/cpp/operator-overloading?view=msvc-160) <br />
GeeksforGeeks: [_Operator Overloading in C++_](https://www.geeksforgeeks.org/operator-overloading-c/) <br />
TutorialsPoint: [_C++ Overloading (Operator and Function)_](https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm) <br />
Programiz: [_C++ Operator Overloading_](https://www.programiz.com/cpp-programming/operator-overloading) <br />
TheCherno: [_OPERATORS and OPERATOR OVERLOADING in C++_](https://www.youtube.com/watch?v=mS9755gF66w) <br />
Artima: [_The Safe Bool Idiom_](https://www.artima.com/articles/the-safe-bool-idiom) <br />
stroustrup.com: [_control of defaults: default and delete_](https://www.stroustrup.com/C++11FAQ.html#default) <br />
IBM: [_Deleted functions (C++11)_](https://www.ibm.com/docs/en/zos/2.2.0?topic=definitions-deleted-functions-c11) <br />
GeeksforGeeks: [_Explicitly Defaulted and Deleted Functions in C++ 11_](https://www.geeksforgeeks.org/explicitly-defaulted-deleted-functions-c-11/) <br />
thispointer.com: [_C++11 / C++14 : ‘delete’ keyword and deleted functions with Use Cases | Examples_](https://thispointer.com/c11-c14-delete-keyword-and-deleted-functions-with-use-cases-examples/) <br />
StackOverflow: [_How to cleanse (overwrite with random bytes) std::string internal buffer?_](https://stackoverflow.com/questions/38702943/how-to-cleanse-overwrite-with-random-bytes-stdstring-internal-buffer) <br />
