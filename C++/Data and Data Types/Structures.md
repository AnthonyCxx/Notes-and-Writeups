# Structures in C++
Structures (colloquially called a 'struct') are a user-defined datatype that serve as a collection of variables. 
They are defined as a block of code prefaced with the [_struct_](https://docs.microsoft.com/en-us/cpp/cpp/struct-cpp?view=msvc-160) keyword and end with a semi-colon. 
Structs are just like classes in that they support not only data members, but also functions members -- they even support inheritance. This directly contrasts structs in C
in which structs can only have data members and must use function pointers to emulate methods. The primary difference between structs and classes is that members of a struct
are public by default, while those of a class are private by default.

## Declaring a Struct
Declaring a struct only requires you to define a block of code, within which are the data/function members of the struct.

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
