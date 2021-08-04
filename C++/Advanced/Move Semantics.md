# Move Semantics in C++
Move semantics are an optimization that reallocates the resources (contents) of a temporary object instead of copying it. <br />
Move semantics are especially efficient when dealing with large objects, and even more efficient if the transfer is marked [_noexcept_](https://www.learncpp.com/cpp-tutorial/exception-specifications-and-noexcept/).

## _lvalues_ and _rvalues_
Before you understand move semantics, you must first understand the difference between an _lvalue_ and an _rvalue_.
"Put simply, an lvalue is an object reference and an rvalue is a value." -Ray Lischner, [_C++ in a Nutshell_](https://www.amazon.com/C-Nutshell-Ray-Lischner/dp/059600298X).
For context, by 'object', he means an object (a value) stored in memory, not an instantiation of a class. An example of an _lvalue_ could be the string variable '_name_', 
whereas an _rvalue_ could be the integer literal '_10_'. Of course it may not always be this simple, a _rvalue_ could just as easily be the whole expression '_12 * 129 % pow(3, 92)_' or a string concatenation like '_"Weather: " + weather_', or even '_title + name_'.

### _lvalue_ and _rvalue_ References
You are likely familiar with _lvalue_ references, which use the [address-of operator](https://www.dummies.com/programming/cpp/how-address-operators-work-in-c/) (&).
We use _lvalue_ references for a number of things like passing and returning by reference (e.g. `void print(const string& str)`) or assigning a pointer to an existing 
variable (e.g. `int* ptr = &x`). Just like you can use _&_ to reference an _lvalue_, you can use _&&_ to reference an _rvalue_ (not to be confused with the 
[logical and operator](https://www.w3schools.com/cpp/cpp_operators_logical.asp), which is also &&). _&&_ can be used to indicate an _rvalue_ reference
like `void print(string&& str)`, which would only take a string literal like '_Hello, World!_' and not a string variable like '_name_'.

You may not have run into the problem of not being able to pass a literal (an _rvalue_, like '_Hello_') into a function that takes a _const lvalue&_ 
(like `void print(const string& str)`) because _const_ _lvalues_ are interchangable with _rvalues_ in some situtations since both are non-modifiable data. 
If you re-wrote the function _print()_ to only take `string& str`, then passing '_Hello_' would cause an error.

You can remember the difference between _lvalues_ and _rvalues_ so: _lvalues_ have an _identifier_, a name that you can reference them with, like  string variable '_name_'; conversely, _rvalues_ are nameless. The number '_10_' does not have a name that you can call it with, and neither does the result
of the expression '_title + name_' — the result of the expression '_title + name_' is just a nameless, temporary string object (called an _xvalue_, for 'expiring value').
The only exception to this rule is that a variable is an _rvalue_ when used on the right-side of an assignment operation and is not modified in any way (e.g. `x = y`).
And the only exception to that exception is when an unmodified variable is used in a _return_ statement (e.g. `return x`), in which case it's an _rvalue_.

## Unnecessarily Copying Temporary Objects
Let's say you assign one string to another; what stops you from simply reallocating the resources of the string to the new string? Well, the old string still needs its
resources since it's its own variable. Reallocating the resources of the old string to the new string would steal them from the old string, which is a problem. But what if
we could guarantee that the old string wouldn't need its resources again? Say, if the string was a temporary string created as the result of an expression like '_title + name_'.
Copying in this case would be unnecessarily inefficient because the temporary string object as a result of '_title + name_' is going to go out of scope in a moment anyway.
You might as well just steal the resources from the temporary string since it's not going to do any harm.

This is the entire point of move semantics. Move semantics are an optimization that reallocates the resources (contents) of a temporary object instead of copying it.
Move semantics are especially efficient when dealing with large objects, and even more efficient if the transfer is marked
[_noexcept_](https://www.learncpp.com/cpp-tutorial/exception-specifications-and-noexcept/). Move semantics was impossible before C++11 because there was no way to 
differentiate between _lvalues_ and _rvalues_ syntactically. Now that we can explicitly refer to _rvalues_ with the _&&_ operator, we can do things like overload the
assignment operator (=) to 'steal' the resources of an _xvalue_, allowing you to avoid copying where it is unnecessary.

## Reallocation of Resources with Move Semantics
> Recommended Video: [_Back to Basics: Move Semantics - David Olsen - CppCon 2020_](https://www.youtube.com/watch?v=ZG59Bqo7qX4) <br />
> Alternative Video: [_Back to Basics: Move Semantics (1/2) - Klaus Iglberger - CppCon 2019_](https://www.youtube.com/watch?v=St0MNEU5b0o&t) <br />

The reallocation of resources in move semantics takes form in two special member functions: the move constructor (`ClassName(ClassName&&)`) and the move assignment operator (`ClassName& operator=(ClassName&&)`). Notice how neither of these functions take _const_ references, since they will be altering the taken object. By the end of the operation,
the new object should have copied all primitive values and taken control of all references belonging to the old object and the old object should be left in a "valid but undefined state" (Klaus Iglberger, [CPPCon 2019](https://www.youtube.com/watch?v=St0MNEU5b0o)), containing no references to its previous data members. To quote the C++ Core Guidelines directly, "Ideally, that moved-from should be the default value of the type. Ensure that unless there is an exceptionally good reason not to." 
([C.64](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c64-a-move-operation-should-move-and-leave-its-source-in-a-valid-state)). If you are moving a class, 
then make the 'default state' is the default state for each data member.

> [See below](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Advanced/Move%20Semantics.md#wait-stdmove-doesnt-move-resources) for an explanation on [_std::move()_](https://www.learncpp.com/cpp-tutorial/stdmove/)
```C++
#include <iostream>
#include <string>
using namespace std;

// LOCATION CLASS //
class Coordinates
{
    private:
        int x;      //x-coordinate
        int y;     //y-coordinate

    public:
        //Various constructors and assignment operator overloads
        Coordinates();                                              //Default Constructor
        Coordinates(double, double);                               //Parameterized Constructor
        Coordinates(const Coordinates&);                          //Copy Constructor
        Coordinates& operator=(const Coordinates&);              //Assignment Operator Overload
        Coordinates(Coordinates&&) noexcept;                    //Move Constructor
        Coordinates& operator=(Coordinates&&) noexcept;        //Move Assignment Operator Overload

        //Get info about the location...
        string str() const;                  //Prints 'x, y'

        //Mathematical Operator Overloads
        Coordinates operator+();                           //Unary plus
        Coordinates operator-();                          //Unary minus
        Coordinates operator+(const Coordinates&);       //Binary addition
        Coordinates operator-(const Coordinates&);      //Binary subtraction
};

//Default Constructor
Coordinates::Coordinates()
{
    cout << "Calling the default constructor\n";

    x = 0.0;
    y = 0.0;
}

//Parameterized Constructor
Coordinates::Coordinates(double X, double Y)
{
    cout << "Calling the parameterized constructor\n";
}

//Copy Constructor
Coordinates::Coordinates(const Coordinates& other)
{
    cout << "Calling the copy constructor\n";

    x = other.x;
    y = other.y;
}

//Assignment Operator Overload
Coordinates& Coordinates::operator=(const Coordinates& other)
{
    cout << "calling the overloaded assignment operator\n";

    x = other.x;
    y = other.y;

    return *this;
}

//Move Constructor
Coordinates::Coordinates(Coordinates&& other) noexcept
{
    cout << "Calling the move constructor\n";

    //Move the contents from the object
    x = move(other.x);
    y = move(other.y);

    //Reset the moved-from to a valid state
    other.x = other.y = 0.0;
}

//Move Assignment Operator Overload
Coordinates& Coordinates::operator=(Coordinates&& other) noexcept
{
    cout << "Calling the overloaded move assignment operator\n";

    //Move the contents from the object
    x = move(other.x);
    y = move(other.y);

    //Reset the moved-from to a valid state
    other.x = other.y = 0.0;

    return *this;
}

//str()
string Coordinates::str() const
{
   return to_string(x) + ", " + to_string(y);
}

//Unary Plus
Coordinates Coordinates::operator+()
{
    return Coordinates((x > 0 ? x : x * -1), (y > 0 ? y : y * -1));
}

//Unary minus
Coordinates Coordinates::operator-()
{
    return Coordinates(-x, -y);
}

//Binary addition
Coordinates Coordinates::operator+(const Coordinates& other)
{
    //Return a new set of coordinates -- the sum of the two sets of coordinates
    return Coordinates(x + other.x, y + other.y);
}

//Binary subtraction
Coordinates Coordinates::operator-(const Coordinates& other)
{
    //Return a new set of coordinates -- the difference of the two sets of coordinates
    return Coordinates(x - other.x, y - other.y);
}

Coordinates returnCoords()
{
    Coordinates tempCoords(-999, -999);

    return tempCoords;
}

// MAIN FUNCTION //
int main()
{
    //Default Constructor
    cout << "Using the default constructor...\n";
    Coordinates defaultCoords;

    //Parameterized Constructor
    cout << "\nUsing the parameterized constructor...\n";
    Coordinates paramCoords(-30, 60);

    //Copy Constructor
    cout << "\nUsing the copy constructor...\n";
    Coordinates copiedCoords(paramCoords);

    //Assignment Operator Overload (call twice to prevent just calling the copy constructor)
    cout << "\nUsing the overloaded assignment operator\n";
    Coordinates standardAssignmentCoords = defaultCoords = paramCoords;

    //Move Constructor
    cout << "\nUsing the move constructor...\n";
    Coordinates otherLocation(move(paramCoords + defaultCoords));  //Moves the contents of 'paramCoords + defaultCoords' into 'otherLocation'

    //Move Assignment Operator
    cout << "\nUsing the move assignment operator...\n";
    Coordinates movedLocation;
    movedLocation = returnCoords();  //An lvalue returned from a function is an rvalue

    return 0;
}
```

In case you're confused on the exact differences between any of the special functions:
| Special Member Function | Purpose | Returns | 
| ----------------------- | ------- | ------- |
| Default Constructor | Creates a new object from nothing | Nothing |
| Parameterized Constructor | Creates a new object from the given parameters | Nothing |
| Copy Constructor | Creates a new object based on an existing object | Nothing |
| Assignment Operator Overload | Copies the resources of an existing object into another existing object | \*this |
| Move Constructor | Creates a new object; moves the resources of the existing object into the new object | Nothing | 
| Move Assignment Operator Overload | Moves the resources of an existing object into another existing object | \*this |
> Reference: [_When does the Move Constructor get Called?_](https://stackoverflow.com/questions/13125632/when-does-move-constructor-get-called/13125851)

### Wait, _std::move()_ doesn't Move Resources?
[_move()_](https://www.learncpp.com/cpp-tutorial/stdmove/) is not a library function to automatically perform move semantics for you. The _move()_ function is
a shorthand for a very long and somewhat obscure static cast (`static_cast<remove_reference_t<T>&&>(lvalue)`) that casts _lvalues_ into _rvalues_, allowing you to move 
the _lvalue_ instead of copying it. Only use _move()_ (and by extent, move semantics) when you know that the object is about to be destroyed or initialized with a new value.

The _move()_ function is not necessary for every moved value, since some are already _rvalues_. For example, moving an integer _i_ from one object to another can be done
by simple assignment; regardless, you should use _move()_ in all circumstances since it's clearer.

### Moving Pointers and _exchange()_
When taking ownership of a pointer, things before a bit more complicated because of two things: <br />
1. The data the moved-to pointer contains must be deleted before it can take on the value of the moved-from (to avoid memory leak)
2. The moved-from pointer must be assigned _nullptr_

As you can see, this is more complex than a normal _move()_, requiring a bit of work both before and after the _move()_. The [_exchange()_](https://docs.w3cub.com/cpp/utility/exchange) function from the [_\<utility\>_](https://www.cplusplus.com/reference/utility/) library makes this easier by allowing you 
to swap the values of the pointers in a single line. _exchange()_ does NOT delete the value of the moved-to — it only makes swapping the pointer's value and _nullptr_ 
easier.

```C++
#include <iostream>
#include <utility>
using namespace std;

// ARRAYCONTAINER CLASS //
class ArrayContainer
{
    private:
        //An array of integers + array size
        int* data;
        size_t size;

    public:
        //Constructor + Destructor
        ArrayContainer(size_t, const int);
        ~ArrayContainer();

        //Move Constructor + Move Assignment Operator
        ArrayContainer(ArrayContainer&&) noexcept;
        ArrayContainer& operator=(ArrayContainer&&) noexcept;

        //Print (for demonstration)
        void print() const;
};

//Constructor
ArrayContainer::ArrayContainer(size_t Size = 0, const int value = 0)
{
    size = Size;
    data = new int[size];

    //Initialize the new array
    for(size_t i = 0; i < size; i++)
    {
        data[i] = value;
    }
}

//Destructor
ArrayContainer::~ArrayContainer()
{
    delete [] data;
}

//Move Constructor
ArrayContainer::ArrayContainer(ArrayContainer&& other) noexcept
{
    //Delete current array (to prevent memory leak)
    delete [] data;

    //Take posession of the other pointer and set the other pointer to 'nullptr'
    data = exchange(other.data, nullptr);
    
    //Adjust sizes
    size = move(other.size);
    other.size = 0;
}

//Move Assignment Operator
ArrayContainer& ArrayContainer::operator=(ArrayContainer&& other) noexcept
{
    //Delete current array (to prevent memory leak)
    delete [] data;

    //Take posession of the other pointer and set the other pointer to 'nullptr'
    data = exchange(other.data, nullptr);
    
    //Adjust sizes
    size = move(other.size);
    other.size = 0;

    return *this;
}

//Print
void ArrayContainer::print() const
{
    if (data == nullptr)  //Note: NULL == nullptr
    {
        cout << "Error in function \'" << __FUNCTION__ << "\'; array points to nullptr.\n";
    }
    else
    {
        //Print the array in a comma-separted list
        for(size_t i = 0; i < size; i++)
        {
            cout << data[i] << (i != size-1 ? ", " : "");
        }
        cout << '\n';
    }
}

// DRIVER CODE //
int main()
{
    //An array of 10 integers, initialized to '20'
    ArrayContainer arr1(10, 20);
    arr1.print();

    //An array of 5 integers, initialized to '3'
    ArrayContainer arr2(5, 3);
    arr2.print();

    /*
        Move arr2 into arr1, still leaving 'arr2' in a valid state
        since it points to 'nullptr' and the size becomes '0'
    */
    arr1 = move(arr2);    //You really should re-initialize an object after moving from it...

    //See results
    arr1.print();    //Contains the contents moved from 'arr2'
    arr2.print();   //Points to 'nullptr'; won't work

    return 0;
}
```

### Making Move Functions _noexcept_
If a move constructor/assignment operator is marked as [_noexcept_](https://www.learncpp.com/cpp-tutorial/exception-specifications-and-noexcept/), it can take
a different, more efficient code path because it will not have to worry about exceptions potentially iterrupting the moving process. In this video, Dr. Iglberger
was able to reduce the time it took to move an object from 0.005 seconds to 0.002 seconds (60% less time). If you can, always mark your move constructors and assignment
operator overloads as _noexcept_ (C++ Core Guidelines, [_C.66_](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rc-move-noexcept)).

## Avoiding Self-Assignment
You can avoid self-assignment in a move constructor/assignment operator in the same way you can in a copy constructor: by prefixing the operations of the move 
constructor/assignment operator with `if (this != &other)`. This comparison of memory addresses guarantees that you will not accidentally delete your own data
and then try to copy that deleted data, which can be fatal, especially when dealing with pointers since you call `delete` before copying.

## More Down-to-Earth Uses
Despite move semantics seeming somewhat arcane and circumstantial, they can also be used to write better code any time you need to move resources. 
For example, you could use move semantics to write a more efficient _swap()_ function (credit: [_Marek Polacek, Red Hat Developer_](https://developers.redhat.com/blog/2019/04/12/understanding-when-not-to-stdmove-in-c)).

```C++
#include <iostream>
using namespace std;

template <typename T>
void Swap(T& a, T& b)     //Two variable 'a' and 'b' of type 'T&'
{
    //Move the variables instead of copying
    T temp(move(a));
    a = move(b);
    b = move(temp);
}

int main()
{
    int a = 10, b = 20;

    //Before
    cout << "BEFORE Swap: a = " << a << ", b = " << b << '\n';

    //Swap
    Swap<int>(a, b);

    //After
    cout << "AFTER Swap: a = " << a << ", b = " << b << '\n';

    return 0;
}
```

## Sources
TheCherno: [_lvalues and rvalues in C++_](https://www.youtube.com/watch?v=fbYknr-HPYE) <br />
TheCherno: [_Move Semantics in C++_](https://www.youtube.com/watch?v=ehMg6zvXuMY) <br />
InternalPointers.com: [_Understanding the meaning of lvalues and rvalues in C++_](https://www.internalpointers.com/post/understanding-meaning-lvalues-and-rvalues-c) <br />
Thomas Becker: [_C++ Rvalue References Explained_](http://thbecker.net/articles/rvalue_references/section_01.html) <br />
O'Rielly Media: [_C++ in a Nutshell_](https://www.amazon.com/C-Nutshell-Ray-Lischner/dp/059600298X) <br />
CppCon 2019: [_Back to Basics: Move Semantics (1/2)_](https://www.youtube.com/watch?v=St0MNEU5b0o&t) by Klaus Iglberger <br />
CppCon 2019: [_Back to Basics: Move Semantics (2/2)_](https://www.youtube.com/watch?v=pIzaZbKUw2s) by Klaus Iglberger <br />
> Sorted by depth and difficulty of material (increasing)
