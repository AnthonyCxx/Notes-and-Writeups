# Inheritance in C++
Inheritance is the ability of a class to be able to inherit the attributes (function and data members) of another class, extending and building off of the 
base class. The class that the new class inherits from is called the base class and the class inheriting the properties is called the derived class. For example, 
if you created a 'tool' class, you could then use that tool class as a base for more specific tools like pickaxes, wrenches, etc. This way, you don't have to write 
the same thing over and over again. In essence, inheritance allows for [D.R.Y. coding](https://dzone.com/articles/is-your-code-dry-or-wet) by greatly increasing 
[code reusability](https://www.c-sharpcorner.com/UploadFile/201fc1/what-is-code-reuse-and-why-we-use-it/).

## Inheritance
There's some stuff in here that you probably haven't gotten to yet.  <br /> Refer below to [_Access Modifiers for Inheritance_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Object-Oriented%20Programming/Inheritance.md#access-modifiers-for-inheritance) and 
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
    private:
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
};

//Constructor
Dog::Dog(int Age, string Genus, string Breed): Animal(Age, Genus)
{
    breed = Breed;
}

void Dog::bark()
{
    cout << "Woof!\n";
}

// ****** DRIVER CODE ****** //
int main()
{
    //Declare a new dog :)
    Dog labrador(6, "canis lupus familiaris", "Labrador Retriever");

    //Use the inherited functions from 'Animal'
    labrador.eat();
    labrador.sleep();

    //Use the new 'bark' method from 'Dog'
    labrador.bark();

    return 0;
}
```

## Access Modifiers for Inheritance


```C++

```

## Calling the Constructor of a Base Class


```C++

```

## Multi-level Inheritance


```C++

```

## Multiple Inheritance


```C++

```
## Virtual Methods


```C++

```

## Calling an Overridden Method of a Base Class


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
