# Access Modifiers in C++
Access modifiers regulate how a member of a class (data members and methods) can be accessed in relation to external code.
There are three types of access: public, private, and protected. By default, classes class members are private; however, you should still always explicitly 
write out the accessor to maintain clean, readable code.

## Public
Public members have no restrictions and can be accessed by any code, inside and outside of the class. Methods are often public.
```C++
#include <iostream>
#include <string>
using namespace std;

class BaseClass
{
    public:
        //Single public string
        string data;

        //Constructor
        BaseClass()
        {
            data = "some data";
        }
};

class DerivedClass: public BaseClass
{
    public:
        //Constructor
        DerivedClass()
        {
            data = "some data";
        }

        //Single function 'print()' prints the inherited public string 'data'
        void print()
        {
            cout << "Accessing the public data member 'data' from  the derived class 'DerivedClass': " << data << '\n';
        }
};

int main()
{
   //Object definitions
   BaseClass base;
   DerivedClass derived;

    //Accessing the public string 'data' from the main function
    cout << "Accessing the public string 'data' from the main function: " << base.data << '\n';

    //Accessing the public string 'data' from the derived class, 'DerivedClass'
    derived.print();

    return 0;
}
```
> Reference: [Microsoft C++ Documentation: Public Keyword](https://docs.microsoft.com/en-us/cpp/cpp/public-cpp?view=msvc-160) <br />

## Private
Private members can only be accessed and modified from within the class itself. External code, including classes derived from the class, has no access to private members. 
Data members are often private
```C++
/* Note: this code does not compile. */

#include <iostream>
#include <string>
using namespace std;

class BaseClass
{
    private:
        //Single public string
        string data;

    public:
        //Constructor
        BaseClass()
        {
            data = "some data";
        }
};

class DerivedClass: public BaseClass
{
    public:
        //Constructor
        DerivedClass()
        {
            data = "some data";
        }

        //Single function 'print()' prints the inherited public string 'data'
        void print()
        {
            cout << "Accessing the public data member 'data' from  the derived class 'DerivedClass': " << data << '\n';
        }
};

int main()
{
    //Object definitions
    BaseClass base;
    DerivedClass derived;

    //Accessing the private string 'data' from the main function (ERROR!)
    cout << "Accessing the public string 'data' from the main function: " << base.data << '\n';

    //Accessing the private string 'data' from the derived class, 'DerivedClass' (ERROR!)
    derived.print();

    return 0;
}
```
> Reference: [C# Documentation: Private Keyword](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/private) <br />

## Protected
Protected members are similar to private members in that they are only interally accessable; however, protected members are also accessible to derived classes.
```C#
static void Main(string[] args)
{
    Console.WriteLine($"Accessing through Main function: {ProtectedExample.field}");  //Illegal, 'field' is protected

    //Accessing 'Field' through the derived class
    otherClass.Print();    //Legal, protected members are accessible to derived classes!
}
 
public class ProtectedExample
{
    protected static string field = "protected field";   //static, so an instance of the class is not necessary
}

public class otherClass : ProtectedExample
{
    public static void Print()
    {
        Console.WriteLine($"Accessing through derived class's method: {ProtectedExample.field}");
    }
}
```
> Reference: [C# Documentation: Protected Keyword](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/protected) <br />
