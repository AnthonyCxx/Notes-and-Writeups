# Methods in C++
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
if one array is delete/goes out of scope, the other array will become a dangling pointer, which could crash your program very easily. To solve this problem, write a
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
