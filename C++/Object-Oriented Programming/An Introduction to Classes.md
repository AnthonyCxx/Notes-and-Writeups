# Classes in C++
Classes are the heart of C++. A class is essentially a user-defined datatype that serves as a collection of data.
Classes are meant to mimic some concrete object or abstract idea. For example, a class 'Player' would contain a string for their name, an integer for their health, 
an integer for their attack damage and another integer to represent their level. These four variables together would allow us to create a single variable of type 'Player' 
that would have all of these properties. In addition to storing data, classes can have functions (called methods), which allow to class to perform actions. 
These actions don't have to affect other data outside the class; in fact, many methods are entirely internal. A class function (method) 'getLevel' could be as simple
as returning the method of the player.

### Format
```C++
class ClassName
{

};
```
> Notice the semi-colon at the end of the definition. <br />
> A class is a statement (in this case a description of a datatype) and so it needs a semi-colon.

### Example
```C++
class Player
{
    //Don't worry about the 'public' keyword for now
    public:
        string name;
        int health;
        int damage;
        int level;
};
```

## Accessing Data Members with the _._ Operator
The period is the [member-access operator](https://docs.microsoft.com/en-us/cpp/cpp/member-access-operators-dot-and?view=msvc-160) in C++ and allows you to individually
access the data members of a class.  <br />
Here, the member-access operator is being used to initialize the values of the class.

```C++
#include <iostream>
#include <string>
using namespace std;

class Player
{
    //Don't worry about the 'public' keyword for now
    public:
        string name;
        int health;
        int damage;
        int level;
};

int main()
{
    //Declare a Player, 'steve'
    Player steve;

    //Initialize the data members of the class
    steve.name = "Steve";
    steve.health = 20;
    steve.damage = 7;
    steve.level = 30;

    //Print the data members of the class
    cout << "Name: " << steve.name << '\n';
    cout << "Health: " << steve.health << '\n';
    cout << "Damage: " << steve.damage << '\n';
    cout << "Level: " << steve.level << '\n';

    return 0;
}
```
> Instances of classes are called objects. The word 'class' only refers to be blueprint of the datatype.

## Methods
As mentioned earlier, classes can contain functions. By moving all the print statements to a function in the class, we can write a single function that prints the stats
of any member of the 'Player' class, instead of having to customize it for each one.

```C++
#include <iostream>
#include <string>
using namespace std;

class Player
{
    //Don't worry about the 'public' keyword for now
    public:
        string name;
        int health;
        int damage;
        int level;

        //Method 'printStats()' prints the stats of the player
        void printStats()
        {
            cout << "Name: " << name << '\n';
            cout << "Health: " << health << '\n';
            cout << "Damage: " << damage << '\n';
            cout << "Level: " << level << '\n';
        }
};

int main()
{
    //Declare a Player, 'steve'
    Player steve;

    //Initialize the data members of the class
    steve.name = "Steve";
    steve.health = 20;
    steve.damage = 7;
    steve.level = 30;

    //Print the data members of the class
    steve.printStats();

    return 0;
}
```
