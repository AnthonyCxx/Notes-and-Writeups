# Enumerations in C++
> Unless you are using legacy C++, use [enum classes](https://www.learncpp.com/cpp-tutorial/enum-classes/) instead of normal enums.
An enumerated type (enum) is a user-defined type that can be one of a defined set of values, each of which is represented internally by an integer constant. Enums provide
programmers with a clear way of representing the possible states/values of an object. For example, a simple machine may have an enum defining its state with two simple
values, 'ON' and 'OFF' (by convention, enum values are typically fully capitalized). Enums may be preferable to booleans because they can represent a number of states (as
opposed to a boolean's two states) but still keep the advantage of a boolean in that they are fundamentally integral. By default, the first value of an enum is 0, 
the second is 1, the third is 2, and so on; however, this can be overwritten by manually assigning the values inside of the enum declaration. 
A good summary of enums can be found [_here_](https://www.youtube.com/watch?v=x55jfOd5PEE). <br />

Enums can also be clearer booleans because they can represent two or more potentially unrelated states, whereas a boolean implies a single state that either is or is not.

## Declaring an Enum
An enum is declared like so `enum enum_name { list_of_possible_values };`. The list of possible values is comma-separated.

```C++
#include <iostream>
using namespace std;

// An enum 'Team' which can be one of four teams
enum Team { RED, YELLOW, BLUE, GREEN };   // Yes, these are the team colors from Mario Party 8

struct Player
{
    int health;
    int score;
    Team team;
};

int main()
{
    // Initialize a player
    Player player_one = {
                          .health = 10,
                          .score = 0,
                          .team = RED   // 'RED' is the integer value 0
                        };

    // Print stats
    cout << "Health: " << player_one.health << '\n';
    cout << "Score: " << player_one.score << '\n';
    cout << "Team: " << player_one.team << " (red)\n";

    return 0;
}
```
> Prints: <br />
> Health: 10 <br />
> Score: 0 <br />
> Team: 0 (red) <br />

## Manually Setting the Internal Values
Each possible value of an enum is mapped to an integer constant that is always one greater than the last (starting at 0). If you assign the values manually,
then the values of the enum will take on said integer value. If you assign one value manually and do not assign the ones that follow it, then the following 
values will just follow the pattern of adding one to the previous value. <br />

If you don't understand regex (regular expressions) yet, that's fine. Regex is just an algorithm for pattern matching. <br />
Here, I used regex to check if a string contained any illegal symbols (%, !, ^, \, or \*).

```C++
#include <iostream>
#include <string>
#include <regex>
using namespace std;

// Enum of possible error states for a string
enum StrErrCode { GOOD_STR = 0, EMPTY_STR = 100, INVALID_CHAR = 110 };

// Function to check if a given string is valid (not empty nor contain illegal symbols)
StrErrCode StrCheck(const string& str)
{

    // If the string is empty
    if (str.empty())
        return EMPTY_STR;

    // If contains illegal characters (%, !, ^, \, or *)
    if (regex_match(str, regex("[%!^\\*]")))
        return INVALID_CHAR;

    return GOOD_STR;
}

// DRIVER CODE //
int main()
{
    // Declare two illegal strings and a legal string
    string emptyString = "";
    string illegalString = "%";
    string goodString = "Some non-empty text without illegal symbols";

    // Check the empty string
    if (StrCheck(emptyString) == GOOD_STR)
        cout << "The string is good (not empty and nor contains illegal symbols)\n";
    else
        cout << "The string is illegal; Error code: (" << StrCheck(emptyString) << ")\n";

    // Check the illegal string
    if (StrCheck(illegalString) == GOOD_STR)
        cout << "The string is good (not empty and nor contains illegal symbols)\n";
    else
        cout << "The string is illegal; Error code: (" << StrCheck(illegalString) << ")\n";

    // Check the good string
    if (StrCheck(goodString) == GOOD_STR)
        cout << "The string is good (not empty and nor contains illegal symbols)\n";
    else
        cout << "The string is illegal; Error code: (" << StrCheck(goodString) << ")\n";
    return 0;
}
```
> Prints: <br />
> The string is illegal; Error code: (100) <br />
> The string is illegal; Error code: (110) <br />
> The string is good (not empty and nor contains illegal symbols) <br />

## Getting the Value of an Enum as a String
The values of an enum are internally stored as strings, and there is no way to convert the name of a value of an enum into a string. If you want to use the value
as a string, you have to write a _switch_ statement that returns the proper value. If you find yourself using this often, it may be better to use an array
of strings and match each enum to a string in the array (this is called a lookup table).

```C++
#include <iostream>
#include <string>
using namespace std;

// An enum 'Team' which can be one of four teams
enum Team { RED, YELLOW, BLUE, GREEN };

// Struct mapped to the 'Player' alias
struct Player
{
    int health;
    int score;
    Team team;
};

// Function delcaration
string get_team(const Player& player);


// Driver code //
int main(void)
{
    // Initialize a player (using a designed initializer)
    Player player_one = { .health = 10, .score = 0, .team = RED };

    // Print stats
    cout << "Health: " << player_one.health << '\n';
    cout << "Score: " << player_one.score << '\n';
    cout << "Team: " <<  get_team(player_one) << '\n';

    return 0;
}

// get_team implementation
string get_team(const Player& player)
{
    switch (player.team)   // Eval team
    {
        case RED:
            return "RED";
        case YELLOW:
            return "YELLOW";
        case BLUE:
            return "BLUE";
        case GREEN:
            return "GREEN";

        default:
            return "UNKNOWN";
    }   // ^ Implicit 'break' in the 'return' statement
}
```
> Prints: <br />
> Health: 10 <br />
> Score: 0 <br />
> Team: RED <br />
