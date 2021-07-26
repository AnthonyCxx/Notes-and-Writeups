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
Data members are often private to acheive [abstraction](https://www.nerd.vision/post/polymorphism-encapsulation-data-abstraction-and-inheritance-in-object-oriented-programming).
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
> Reference: [Microsoft C++ Documentation: Private Keyword](https://docs.microsoft.com/en-us/cpp/cpp/private-cpp?view=msvc-160) <br />

## Protected
Protected members are similar to private members in that they are only interally accessable; however, protected members are also accessible to derived classes.
If you don't know what inheritance is yet, feel free to ignore this keyword and stick with _public_ and _private_.

```C++
/* Note: this code does not compile. */

#include <iostream>
#include <string>
using namespace std;

class BaseClass
{
    protected:
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

    //Accessing the protected string 'data' from the main function (ERROR!)
    cout << "Accessing the public string 'data' from the main function: " << base.data << '\n';

    //Accessing the protected string 'data' from the derived class, 'DerivedClass' (OK!)
    derived.print();

    return 0;
}
```
> Reference: [Microsoft C++ Documentation: Protected Keyword](https://docs.microsoft.com/en-us/cpp/cpp/protected-cpp?view=msvc-160) <br />

## Granting Access to Private Data Members with _friend_
Functions, classes, and methods can all gain access to a class's private members if they are declared as a _friend_ within said class. To declare
a function/class/method as a friend, just declare it within the class as you normally would, and put '_friend_' in front of it. It's literally that easy.

```C++
#include <iostream>
using namespace std;

//Prior declaration required to include each other in each other's definitions...
class PrivateClass;

//Friend Method
class GenericClass
{
    public:
        void friendMethod(const PrivateClass&);
};

// PRIVATE CLASS //
class PrivateClass
{
    private:
        //Private data member
        int number = 10;

        //Friend function
        friend void friendFunction(const PrivateClass&);

        //Friend class
        friend class FriendClass;

        //Friend method
        friend void GenericClass::friendMethod(const PrivateClass&);

    public:
        //Constructor
        PrivateClass(int num = 0)
        {
            number = num;
        }
};

//Friend function
void friendFunction(const PrivateClass& pc)
{
    cout << "Accessing private data member from a function! Number is: " << pc.number << '\n';
}

//Friend class
class FriendClass
{
    public:
        void printNumber(const PrivateClass& pc)
        {
            cout << "Accessing the private data member from a friend class! Number is: " << pc.number << '\n';
        }
};

//Friend method (must be defined AFTER the defininition of 'PrivateClass' since it's a parameter
void GenericClass::friendMethod(const PrivateClass& pc)
{
    cout << "Accessing private data member from a method! Number is: " << pc.number << '\n';
}

// DRIVER CODE //
int main()
{
    PrivateClass pc(10);
    FriendClass  fc;
    GenericClass gc;

    //Friend function
    friendFunction(pc);

    //Friend class
    fc.printNumber(pc);

    //Friend method
    gc.friendMethod(pc);

    return 0;
}
```
> Sources: <br />
> TutorialsPoint: [_C++ Friend Functions_](https://www.tutorialspoint.com/cplusplus/cpp_friend_functions.htm) <br />
> GeeksforGeeks [_Friend class and function in C++_](https://www.geeksforgeeks.org/friend-class-function-cpp/) <br />
