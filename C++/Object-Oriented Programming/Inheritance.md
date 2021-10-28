# Inheritance in C++
> Jump: <br />
> [Inheritance](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Object-Oriented%20Programming/Inheritance.md#inheritance) <br />
> [Inheritance Access Modifiers](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Object-Oriented%20Programming/Inheritance.md#access-modifiers-for-inheritance) <br />
> [Calling the Constructor of a Base Class](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Object-Oriented%20Programming/Inheritance.md#calling-the-constructor-of-a-base-class) <br />
> [Multiple Inheritance](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Object-Oriented%20Programming/Inheritance.md#multiple-inheritance) <br />
> [Multi-level Inheritance](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Object-Oriented%20Programming/Inheritance.md#multi-level-inheritance) <br />
> [Virtual Methods](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Object-Oriented%20Programming/Inheritance.md#overriding-methods-with-virtual-and-override) <br />
> [Pure Virtual Methods (Interfaces)](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Object-Oriented%20Programming/Inheritance.md#pure-virtual-methods-interfaces) <br />

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
When inheriting from a class, inherit it as _public_; you can inherit as _private_ or _protected_ too, but don't worry about that for now. If not specified, it will assume private.

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
variables to the base constructor; the base constructor of a class is indicated by its name, since a class can inherit from multiple classes. 
To call multiple base constructors, separate them by commas.

Calling the constructor of a base class makes initializing derived classes far less verbose.
```C++
//Constructor, passing 'Age' and 'Genus' to the base constructor 'Animal::Animal(int, string)'
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

//Constructor, calls the constructor for 'Chest' (you can only call the constructor of a direct superclass)
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

## Overriding Methods with _virtual_ and _override_
Virtual methods have their binding delayed until runtime, rather than having it be done at compile time. This allows functions to take parameters of the base type
and still call the overriden version of the function. You see, if you have a pointer/function parameter of a base class and you assign it to a derived class, it will
still work; however, it will not call the overriden version of the function since it's type is the base class. Instead, it would call the method from the base class.
If you want to use overriden functions with function parameters/pointers of the type of the base class, then you have to use the keyword _virtual_. 

Anytime you override a virtual function, add [_override_](https://www.geeksforgeeks.org/override-keyword-c/) to the overriding function.
```C++
#include <iostream>
#include <string>
using namespace std;

// ****** BASE CLASS ****** //
class Base
{
    public:
        virtual void virtualPrint();
        void nonVirtualPrint();
};

//Virtual function
void Base::virtualPrint()
{
    cout << "Called 'virtualPrint()' from the base class!" << '\n';
}

//Non-virtual function
void Base::nonVirtualPrint()
{
    cout << "Called 'nonVirtualPrint()' from the base class!" << '\n';
}

// ****** DERIVED CLASS ****** //
class Derived: public Base
{
    public:
        void virtualPrint() override;
        void nonVirtualPrint();
};

//Virtual function
void Derived::virtualPrint()
{
    cout << "Called 'virtualPrint()' from the derived class!" << '\n';
}

//Non-virtual function
void Derived::nonVirtualPrint()
{
    cout << "Called 'nonVirtualPrint()' from the derived class!" << '\n';
}


//Function 'callPrint()' takes a 'Base' object as a parameter, but it passed the derived class
void callPrint(Base& obj)
{
    //Calls print on the object (virtual and non-)
    obj.virtualPrint();              //Calls 'Derived::virtualPrint()' (correct)
    obj.nonVirtualPrint();          //Class 'Base::nonVirtualPrint()' (incorrect)
}

// DRIVER CODE //
int main()
{
    Derived derivedObject;

    //Calls print on the 'Derived' object, which is possible since it's inherited from the 'Base' class
    callPrint(derivedObject);
}
```
> Read [this FAQ article](https://isocpp.org/wiki/faq/virtual-functions) to better understand virtual functions

## Virtual Destructors
Although [virtual constructors do not exist](https://www.stroustrup.com/bs_faq2.html#virtual-ctor), virtual destructors do. Virtual destructors are used to ensure
that all the resources of a derived class that is referenced by its base class are freed when you delete it. For example, if you had a pointer of type `Base*` that pointed
to a derived class object `derivedObj`, then calling `delete derivedObj` would ONLY call destructor of the base class (`~Base`) and potentially cause memory leak. As you can 
see, more than just RAII is needed to prevent memory leak.

This example also demonstrates the order in which constructors and destructors are called. Constructors are called in order of base -> derived, but destructors are called
in order of derived -> base.
```C++
#include <iostream>

//Base class
class Base
{
    public:
        int* ptr;

        //Constructor
        Base(int a)
        {
            std::cout << "Calling base constructor\n";
            ptr = new int{a};
        }

        //Destructor
        virtual ~Base()
        {
            std::cout << "Calling base destructor\n";
            delete ptr;
        }
};

//Derived class
class Derived: public Base
{
    public:
        int* other_ptr;

        //Constructo
        Derived(int a, int b): Base(a)
        {
            std::cout << "Calling derived destructor\n";
            other_ptr = new int{b};
        }

        //Deconstructor
        virtual ~Derived() override
        {
            std::cout << "Calling derived destructor\n";
            delete other_ptr;
        }
};

int main()
{
    //New instance of the derived class
    Base* base_ptr = new Derived(10, 20);

    std::cout << "\nA: " << *base_ptr->ptr << "\n\n";

    //If '~Base()' were not virtual, 'other_ptr' would not be deleted (causing memory leak)
    delete base_ptr;

    return 0;
}
```

## Pure Virtual Methods (Abstract Classes)
Pure virtual functions are functions declared in a base class that have no implementation and are intended to be overriden by the derived class. 
Derived classes _must_ provide their own implementations for pure virtual functions, guaranteeing that each class has its own implementation of the
virtual method. Any class with a pure virtual function becomes an [abstract base class](https://www.tutorialspoint.com/cplusplus/cpp_interfaces.htm), preventing them from 
being instantiated (typically because it wouldn't make sense). Abstract base classes ([ABCs](https://docs.python.org/3/library/abc.html)) are meant to be nothing more than a template to derive new classes from. To make a virtual method a pure virtual method, set the virtual metthod to 0 (e.g. `virtual void function() = 0`).

If you know Java or C#, you may know this as an [interface](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/interface). Unlike interfaces,
which cannot contain any implementations, abstract classes can have pure virtual methods (without implementations) alongside standard and virtual methods (with implementations).

```C++
#include <iostream>
using namespace std;

// ****** ANIMAL CLASS (ABSTRACT) ****** //
class Animal
{
    public:
        //Three pure virtual methods
        virtual void eat() = 0;
        virtual void sleep() = 0;
        virtual void move() = 0;
};

// ****** BAT CLASS ****** //
class Bat: public Animal
{
    public:
        void eat() override;
        void sleep() override;
        void move() override;
};

//Eat
void Bat::eat()
{
    cout << "The bat is eating delicious bugs...\n";
}

//Sleep
void Bat::sleep()
{
    cout << "The bat sleeps, hanging upside-down from the ceiling of the cave...\n";
}

//Move
void Bat::move()
{
    cout << "The horror of the night soars throughout the night sky...\n";
}


// ****** DRIVER CODE ****** //
int main()
{
    //Declare an animal, inherited from abstract class 'Animal'
    Bat bat;

    //'Bat' methods, overriden from 'Animal'
    bat.eat();
    bat.sleep();
    bat.move();

    return 0;
}
```

## Sources
TutorialsPoint: [_C++ Inheritance_](https://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm) <br />
GeeksforGeeks: [_Inheritance in C++_](https://www.geeksforgeeks.org/inheritance-in-c/) <br />
GeeksforGeeks: [_Multiple Inheritance in C++_](https://www.geeksforgeeks.org/multiple-inheritance-in-c/#:~:text=Multiple%20Inheritance%20is%20a%20feature,in%20which%20they%20are%20inherited.&text=The%20destructors%20are%20called%20in%20reverse%20order%20of%20constructors.) <br />
TutorialsPoint: [_C++ Inheritance_](https://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm) <br />
CProgramming: [_Multiple Inheritance in C++_](https://www.cprogramming.com/tutorial/multiple_inheritance.html) <br />
isocpp.org: [_Inheritance — Multiple and Virtual Inheritance_](https://isocpp.org/wiki/faq/multiple-inheritance) <br />
isocpp.org: [_Inheritance — virtual functions_](https://isocpp.org/wiki/faq/virtual-functions) <br />
isocpp.org: [_Inheritance — Multiple and Virtual Inheritance_](https://isocpp.org/wiki/faq/multiple-inheritance) <br />
GeeksforGeeks: [_Virtual Functions and Runtime Polymorphism in C++ | Set 1 (Introduction)_](https://www.geeksforgeeks.org/virtual-functions-and-runtime-polymorphism-in-c-set-1-introduction/) <br />
TheCherno: [_Virtual Functions in C++_](https://www.youtube.com/watch?v=oIV2KchSyGQ) <br />
TheCherno: [_Interfaces in C++ (Pure Virtual Functions)_](https://www.youtube.com/watch?v=UWAdd13EfM8) <br />
