# Structures in C++
Structures (colloquially called a 'struct') are a user-defined datatype that serve as a collection of variables. 
They are defined as a block of code prefaced with the [_struct_](https://docs.microsoft.com/en-us/cpp/cpp/struct-cpp?view=msvc-160) keyword and end with a semi-colon. 
Structs are just like classes in that they support not only data members, but also functions members -- they even support inheritance. This directly contrasts structs in C
in which structs can only have data members and must use function pointers to emulate methods. The primary difference between structs and classes is that members of a struct
are public by default, while those of a class are private by default.

## Declaring a Struct
Declaring a struct only requires you to define a block of code, within which are the data/function members of the struct. <br />
Notice how you don't need to prefix struct declarations/usage with _struct_ like you have to in C.

```C++
#include <iostream>
#include <string>
using namespace std;

struct Employee
{
    string name;
    string title;
    int id;        // Naming should be consistant (even though 'ID' looks better)
};

int main()
{
    Employee john = {
                      "John",                 // Name
                      "Senior Manager",      // Title
                      123                   // ID
                    };

    cout << "Employee name: " << john.name << '\n';
    cout << "Employee title: " << john.title << '\n';
    cout << "Employee ID: " << john.id << '\n';

    return 0;
}
```
> Prints: <br />
> Employee name: John <br />
> Employee title: Senior Manager <br />
> Employee ID: 123 <br />

## Designed Initializers
When initializing a struct, you can use a designed initializer to make your initialization more intelligible. <br />

Note: I did get an error when trying to initialize 'title' before 'name' because it was out of order, which is strange because that works fine in C.

```C++
#include <iostream>
#include <string>
using namespace std;

struct Employee
{
    string name;
    string title;
    int id;        // Naming should be consistant (even though 'ID' looks better)
};

int main()
{
    Employee john = {
                      .name = "John",
                      .title = "Senior Manager",
                      .id = 123
                    };

    cout << "Employee name: " << john.name << '\n';
    cout << "Employee title: " << john.title << '\n';
    cout << "Employee ID: " << john.id << '\n';

    return 0;
}
```
> Prints: <br />
> Employee name: John <br />
> Employee title: Senior Manager <br />
> Employee ID: 123 <br />

## Struct Methods
If you define a function inside of a struct, it becomes a _method_, which is a function that belongs to said struct. <br />
Having function members (methods) allows you to easily manipulate the data of a struct or put it to some use. <br />


```C++
#include <iostream>
#include <string>
using namespace std;

struct Employee
{
    string name;
    string title;
    int id;        // Naming should be consistant (even though 'ID' looks better)

    void getInfo()
    {
        cout << "Employee name: " << name << '\n';
        cout << "Employee title: " << title << '\n';
        cout << "Employee ID: " << id << '\n';
    }
};

int main()
{
    // Declare an employee named 'john'
    Employee john = {
                      .name = "John",
                      .title = "Senior Manager",
                      .id = 123
                    };

    // Call 'getInfo()', printing John's name, title, and ID
    john.getInfo();

    return 0;
}
```
> Prints: <br />
> Employee name: John <br />
> Employee title: Senior Manager <br />
> Employee ID: 123 <br />


## Returning Multiple Values with Structs
A function can only return one variable, but nothing's to say that the variable can't be a struct that contains 5 different variables.

```C++
#include <iostream>
#define SIZE(array) sizeof(array) / sizeof(array[0])
using namespace std;

// A struct of two integers (mimics tuple)
struct Tuple
{
    int min;
    int max;
};

// Find the min and max element in an array
Tuple findMinMax(int array[], int size)
{
    int min, max;

    // Initialize for comparisions
    min = max = array[0];

    // Compare all elements
    for(int i=0; i < size; i++)
    {
        // If new min.
        if (min > array[i])
            min = array[i];

        // If new max.
        if (max < array[i])
            max = array[i];
    }

    // Return an anonymous (nameless) tuple
    return Tuple {min, max};
}

// DRIVER CODE //
int main()
{
    // An array of 5 integers
    int array[5] = {35, 14, 31, 21, 6};

    // Find the minimum and maximum values of the array
    Tuple minMax = findMinMax(array, SIZE(array));

    // Print the min and max
    cout << "Minimum: " << minMax.min << '\n';
    cout << "Maximum: " << minMax.max << '\n';
}
```
> Prints: <br />
> Minimum: 6 <br />
> Maximum: 35 <br />

## Structs within Structs
A data member of a struct can even be another struct. Here, a folder is an array of file structures (not really accurate -- this is just an example).

```C++
#include <iostream>
#include <string>
using namespace std;

struct File
{
    string name;
    string contents;
};

struct Folder
{
    string name;
    char shortcut;
    File files[30];
};

int main()
{
    Folder dir {
                  .name = "Home Directory",
                  .shortcut = '~',
                  .files = { /* Initialize files here */}
               };

    cout << "Folder name: " << dir.name << '\n';
    cout << "Shortcut: " << dir.shortcut << '\n';

    return 0;
}
```
