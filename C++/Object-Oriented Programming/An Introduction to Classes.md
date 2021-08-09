# Classes in C++
Classes are the heart of C++. A class is essentially a user-defined datatype that serves as a collection of data.
Classes are meant to mimic some concrete object or abstract idea. For example, a class 'Player' would contain a string for their name, an integer for their health, 
an integer for their attack damage and another integer to represent their level. These four variables together would allow us to create a single variable of type 'Player' 
that would have all of these properties. In addition to storing data, classes can have functions (called methods), which allow to class to perform actions. 
These actions don't have to affect other data outside the class; in fact, many methods are entirely internal. A class function (method) 'getLevel' could be as simple
as returning the level of the player.

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

## Special Methods: Constructors
A constructor is a special type of method that is used to initialize the data members of a class. Constructors are automatically called when an instance of the class 
is made, which makes them incredibly convenient. You can differentiate general methods from the constructor because the constructor shares the name of the class verbatim.
Classes also do not have a return type.

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

        //The constructor (shares the name 'Player')
        Player(string Name, int Health, int Damage, int Level)
        {
            //<data member> = <parameter>
            name = Name;
            health = Health;
            damage = Damage;
            level = Level;
        }

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
    //Declare a Player, 'steve' using the constructor
    Player steve("Steve", 20, 7, 30);    //Name, health, damage, level

    //Print the data members of the class
    steve.printStats();

    return 0;
}
```

## Access Modifiers, Getters, and Setters
[Access modifiers](https://www.geeksforgeeks.org/access-modifiers-in-c/) define the way the members of a class are meant to be interacted with.
Take a player's health and healthbar in a videogame for example; the gave developer has written the game such that when a player takes damage, the health of the _Player_
class and the in-game display of the _healthbar_ class are both appropriately updated — this would likely be done in a function _updateHealth()_. Now imagine that another game
developer comes along and ignorantly decides to modify the player's health directly, ignoring the _updateHealth()_ function. Now, the healthbar never gets updated
and the amount of health the player actually has is different from what's displayed on-screen. This is utterly game-breaking. The access modifiers _public_, _private_,
and _protected_ solve this problem.

For the sake of simplicity, I'm only going to talk about _public_ and _private_ here. Members of a class (data members of functions) that are public are fully accessible. 
Above, we were able to access the individual stats of the _Player_ 'steve' via the member-access operator (.) — this would not be the case if the members were private.
Private members are only accessible internally by other members of the class; if you try to access a private method otherwise, your code will not compile. 
To work with or modify these private methods, _get_ and _set_ functions (called _getters_ and _setters_) are used. Unlike constructors, which are special because of 
a property of the language, getters and setters are purely convention, but should still be recognized and used for clarity's sake.

```C++
#include <iostream>
#include <string>
using namespace std;

class Player
{
    //Data memebers should generally be private
    private:
        string name;
        int health;
        int damage;
        int level;

    //Functions should generally be public
    public:
        //The constructor (shares the name 'Player')
        Player(string Name, int Health, int Damage, int Level)
        {
            //<data member> = <parameter>
            name = Name;
            health = Health;
            damage = Damage;
            level = Level;
        }

        //Method 'printStats()' prints the stats of the player
        void printStats()
        {
            cout << "Name: " << name << '\n';
            cout << "Health: " << health << '\n';
            cout << "Damage: " << damage << '\n';
            cout << "Level: " << level << '\n';
        }

        /*
           Get + Set methods. Generally, don't condense them
           like I did here. I just did this because I didn't
           want to take up too much space
        */

        //Getter + Setter for name
        string getName() { return name; }
        void setName(string Name) { name = Name; }

        //Getter + Setter for health
        int getHealth() { return health; }
        void setHealth(int Health) { health = Health; }

        //Getter + Setter for damage
        int getDamage() { return damage; }
        void setDamage(int Damage) { damage = Damage; }

        //Getter + Setter for level
        int getLevel() { return level; }
        void setLevel(int Level) { level = Level; }

};

int main()
{
    //Declare a Player, 'steve' using the constructor
    Player steve("Steve", 20, 7, 30);    //Name, health, damage, level

    //Print the data members of the class
    steve.printStats();

    //Change Steve's name
    steve.setName("Herobrine");

    //Print new stats
    steve.printStats();

    return 0;
}
```
