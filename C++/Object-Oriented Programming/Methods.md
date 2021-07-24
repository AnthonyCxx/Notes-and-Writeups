# Methods in C++
A method is a function that is associated with a class or struct. Methods are blocks of code that can be invoked by name, executing the body of the method (its code).
Methods have full access to the members of a class, including private members.

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
