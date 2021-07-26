# Inheritance in C++
Inheritance is the ability of a class to be able to inherit the attributes (function and data members) of another class, extending and building off of the 
base class. The class that the new class inherits from is called the base class and the class inheriting the properties is called the derived class. For example, 
if you created a 'tool' class, you could then use that tool class as a base for more specific tools like pickaxes, wrenches, etc. This way, you don't have to write 
the same thing over and over again. In essence, inheritance allows for [D.R.Y. coding](https://dzone.com/articles/is-your-code-dry-or-wet) by greatly increasing 
[code reusability](https://www.c-sharpcorner.com/UploadFile/201fc1/what-is-code-reuse-and-why-we-use-it/).

## Inheritance
To inherit from an existing class, put a colon after the name of the derived class and then put an access modifier (_public_, _private_, _protected_) and then the name
of the class to inherit from. If you forget to put an access modifier, it will assume private.

Admittedly, there's some stuff in here that you probably haven't gotten to yet.  <br /> Refer below to [_Access Modifiers for Inheritance_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Object-Oriented%20Programming/Inheritance.md#access-modifiers-for-inheritance) and 
[_Calling the Constructor of a Base Class_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Object-Oriented%20Programming/Inheritance.md#calling-the-constructor-of-a-base-class) to clear things up a bit.

```C++
#include <iostream>
#include <string>
using namespace std;

// ****** ANIMAL CLASS ****** //
class Animal
{
     //'genus': any of the taxonomic groups into which a family
    // is divided and which contains one or more species.
    protected:
        int age;
        string genus;

    public:
        Animal(int, string);
        void eat();
        void drink();
        void sleep();
};

//Constructor
Animal::Animal(int Age, string Genus)
{
    age = Age;
    genus = Genus;
}

//Eat
void Animal::eat()
{
    cout << "Eating...\n";
}

//Drink
void Animal::drink()
{
    cout << "Drinking...\n";
}

//Sleeping
void Animal::sleep()
{
    cout << "Sleeping...\n";
}

// ****** DOG CLASS ****** //
class Dog: public Animal
{
    private:
        string breed;

    public:
        Dog(int, string, string);
        void bark();
        void wagTail();
};

//Constructor
Dog::Dog(int Age, string Genus, string Breed): Animal(Age, Genus)
{
    breed = Breed;
}

//Bark
void Dog::bark()
{
    cout << "Woof!\n";
}

//wagTail
void Dog::wagTail()
{
        cout << "*wagging tail*\n";
};

// ****** DRIVER CODE ****** //
int main()
{
    //Declare a new dog :)
    Dog labrador(6, "canis lupus familiaris", "Labrador Retriever");

    //Use the inherited functions from 'Animal'
    labrador.eat();
    labrador.sleep();

    //Use the new 'bark' and 'wagTail' methods from 'Dog'
    labrador.bark();
    labrador.wagTail();

    return 0;
}
```

## Access Modifiers for Inheritance
Access modifiers affect how members of a class (functions and variables) can be accessed by other code, _including_ derived classes. 
Because of this, the _protected_ modifier should be used for the data members of the base class instead of _private_ 
to allow derived classes to still access said class members.
When inheriting from a class, inherit it as _public_; you can inherit as _private_ or _protected_, but don't worry about that for now. If not specified, it will assume private.

```C++
// ****** DOG CLASS ****** //
class Dog: public Animal  //Inherit publicly from the 'Animal' class
{
    private:
        string breed;

    public:
        Dog(int, string, string);
        void bark();
        void wagTail();
};
```

## Calling the Constructor of a Base Class
You can call the constructor of a base class by putting a colon after the parameter list of the constructor of a derived class and then passing the 
variables to the base constructor. To call multiple base constructors, separate them by commas.

Calling the constructor of a base class makes initializing derived classes far less verbose.
```C++
//Constructor, passing 'Age' and 'Genus' to the base constructor 'Animall::Animal(int, string)'
Dog::Dog(int Age, string Genus, string Breed): Animal(Age, Genus)   
{
    breed = Breed;
}
```

## Multiple Inheritance
Multiple inheritance occurs when a derived class inherits from multiple, unrelated base classes.
Here, a 'Chest' is a block that contains items; although these two classes are unrelated, both of them can be combined 
using multiple inheritance.

```C++
#include <iostream>
#include <string>
using namespace std;

// ****** CONTAINER CLASS ****** //
class Container
{
    protected:
        //Max capacity for a container is 256 items, 'capacity' determines how many are used
        string Items[256];
        int capacity;

    public:
        Container(int);
        void open();
        void close();
};

//Constructor
Container::Container(int Capacity)
{
    capacity = Capacity;
}

//Open the container
void Container::open()
{
    cout << "Opening...\n";
}

//Close the container
void Container::close()
{
    cout << "Closing...\n";
}

// ***** BLOCK CLASS ****** //
class Block
{
    protected:
        string name;
        int id;

    public:
        Block(string, int);
        void place();
        void destroy();
};

//Constructor
Block::Block(string Name, int ID)
{
    name = Name;
    id = ID;
}

//Place the block
void Block::place()
{
    cout << "Placing the block...\n";
}

//Destroy the block
void Block::destroy()
{
    cout << "Destroyed the block...\n";
}

// ****** CHEST CLASS ****** //
class Chest: public Block, public Container  //A chest is a block that contains items
{
    public:
        Chest(string, int, int);
};

//Constructor -- calls the constructors for 'Block' and 'Container'
Chest::Chest(string Name, int ID, int Capacity): Block(Name, ID), Container(Capacity)
{
    //'Chest' implements no new members
}

int main()
{
    //New chest of 'Class Chest' type, ID: 167, and holds 64 items
    Chest chest("Classic Chest", 167, 64);

    //Calling 'Block' methods
    chest.place();
    chest.destroy();

    //Calling 'Container' methods
    chest.open();
    chest.close();

    return 0;
}
```

## Multi-level Inheritance
Multi-level inheritance occurs when you use a derived class as a base class for another derived class, creating a chain of inheritance.
Using the existing class 'Chest', I was able to derive a new class 'LockedChest' that can be locked.

```C++
#include <iostream>
#include <string>
using namespace std;

// ****** CONTAINER CLASS ****** //
class Container
{
    protected:
        //Max capacity for a container is 256 items, 'capacity' determines how many are used
        string Items[256];
        int capacity;

    public:
        Container(int);
        void open();
        void close();
};

//Constructor
Container::Container(int Capacity)
{
    capacity = Capacity;
}

//Open the container
void Container::open()
{
    cout << "Opening...\n";
}

//Close the container
void Container::close()
{
    cout << "Closing...\n";
}

// ***** BLOCK CLASS ****** //
class Block
{
    protected:
        string name;
        int id;

    public:
        Block(string, int);
        void place();
        void destroy();
};

//Constructor
Block::Block(string Name, int ID)
{
    name = Name;
    id = ID;
}

//Place the block
void Block::place()
{
    cout << "Placing the block...\n";
}

//Destroy the block
void Block::destroy()
{
    cout << "Destroyed the block...\n";
}

// ****** CHEST CLASS ****** //
class Chest: public Block, public Container  //A chest is a block that contains items
{
    public:
        Chest(string, int, int);
};

//Constructor -- calls the constructors for 'Block' and 'Container'
Chest::Chest(string Name, int ID, int Capacity): Block(Name, ID), Container(Capacity)
{
    //'Chest' implements no new members
}

// ****** LOCKEDCHEST CLASS ****** //
class LockedChest:  public Chest
{
    //Private because I won't inherit from it
    private:
        bool isLocked;

    public:
        LockedChest(string, int, int, bool);
        void inspectLock();
};

//Constructor
LockedChest::LockedChest(string Name, int ID, int Capacity, bool Locked): Chest(Name, ID, Capacity)
{
     isLocked = Locked;
}

//Inspect lock
void LockedChest::inspectLock()
{
    if (isLocked)
        cout << "Hmm...seems the chest is locked...\n";
    else
        cout << "The lock on the chest appears broken...\n";
}

int main()
{
    //New chest of 'LockedChest' type, ID: 170, holds 32 items, and is locked
    LockedChest chest("A Mysterious Chest", 170, 32, true);

    //Calling 'Block' methods
    chest.place();
    chest.destroy();

    //Calling 'Container' methods
    chest.open();
    chest.close();

    //Calling 'LockedChest' methods
    chest.inspectLock();

    return 0;
}
```

## Overriding Methods of a Base Class
You can override a method of the base class by simply redefining it in the derived class; however, do this with care, as doing so will hide all versions of the base class's
method. The following code does not compile because an object of the derived class calls _print()_, which is inherited from the base class, but _print()_ is hidden
because it was overriden by _print(string)_.

```C++
// Note: this code does not compile //

#include <iostream>
#include <string>
using namespace std;

// ****** BASE CLASS ****** //
class Base
{
    public:
        void print()
        {
            cout << "Called 'print()' from the base class!" << endl;
        }
};

// ****** DERIVED CLASS ****** //
class Derived : public Base
{
    public:
        void print(string message)
        {
            cout << message << endl;
        }
};


// DRIVER CODE //
int main()
{
    Derived object;

    object.print();
}
```

## Calling an Overridden Method of a Base Class
Just because a derived class you wrote overrides a method from the base class doesn't mean the derived class can't still access the original function from the 
base class. All you have to do to access the superclass's method is put the name of the superclass followed by the scope-resolution operator, `::`.

```C++

#include <iostream>
#include <string>
using namespace std;

// ****** BASE CLASS ****** //
class Base
{
    public:
        void print()
        {
            cout << "Called 'print()' from the base class!" << endl;
        }
};

// ****** DERIVED CLASS ****** //
class Derived : public Base
{
    public:
        void print(string message)
        {
            cout << message << endl;
        }
};


// DRIVER CODE //
int main()
{
    Derived object;

    //Call 'print()' from the class 'Base'
    object.Base::print();
}
```

## Virtual Methods


```C++

```

## Pure Virtual Methods and Abstract Classes


```C++

```

## Sources
TutorialsPoint: [_C++ Inheritance_](https://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm) <br />
GeeksforGeeks: [_Inheritance in C++_](https://www.geeksforgeeks.org/inheritance-in-c/) <br />
GeeksforGeeks: [_Multiple Inheritance in C++_](https://www.geeksforgeeks.org/multiple-inheritance-in-c/#:~:text=Multiple%20Inheritance%20is%20a%20feature,in%20which%20they%20are%20inherited.&text=The%20destructors%20are%20called%20in%20reverse%20order%20of%20constructors.) <br />
TutorialsPoint: [_C++ Inheritance_](https://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm) <br />
CProgramming: [_Multiple Inheritance in C++_](https://www.cprogramming.com/tutorial/multiple_inheritance.html) <br />
isocpp.org: [_Inheritance — Multiple and Virtual Inheritance_](https://isocpp.org/wiki/faq/multiple-inheritance) <br />
