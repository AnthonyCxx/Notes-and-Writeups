# Enumerations in C
An enumerated type (enum) is a user-defined type that can be one of a defined set of values, each of which is represented internally by an integer constant. Enums provide
programmers with a clear way of representing the possible states/values of an object. For example, a simple machine may have an enum defining its state with two simple
values, 'ON' and 'OFF' (by convention, enum values are typically fully capitalized). Enums may be preferable to booleans because they can represent a number of states (as
opposed to a boolean's two states) but still keep the advantage of a boolean in that they are fundamentally integral. By default, the first value of an enum is 0, 
the second is 1, the third is 2, and so on; however, this can be overwritten by manually assigning the values inside of the enum declaration. 
A good summary can be found [_here_](https://www.youtube.com/watch?v=lWzZ2l5n81c) (yes, CodeVault again - he's just so good at explaining stuff). <br />

Enums may also be preferable to booleans because they can represent two or more potentially unrelated states, whereas a boolean implies a single state that either is or is not.

## Declaring an Enum
An enum is declared like so `enum enum_name { list_of_possible_values };`. The list of possible values is comma-separated.

```C
#include <stdio.h>

// An enum 'Team' which can be one of four teams
enum Team { RED, YELLOW, BLUE, GREEN };   // Yes, these are the team colors from Mario Party 8

struct Player
{
    int health;
    int score;
    enum Team team;
};

int main(void)
{
    // Initialize a player
    struct Player player_one = { 10, 0, RED };    // Health, score, team ('Team' enum)
                                      // ^ 'RED' is 0, as it is the first value

    // Print stats
    printf("Health: %d\n", player_one.health);
    printf("Score: %d\n", player_one.score);
    printf("Team: %d (red)\n", player_one.team);

    return 0;
}
```
> Prints: <br />
> Health: 10 <br />
> Score: 0 <br />
> Team: 0 <br />

## Simplifying Enum Usage with _typedef_
Normally, you have to put _enum_ in front of any declaration or implementation of an enumerated type. To avoid this, you can use the [_typedef_ keyword](https://www.tutorialspoint.com/cprogramming/c_typedef.htm) to write an alias, mapping `enum enum_name` to `enum_name` so you can just use the name of the enum
directly. That way, you can just write the alias and stop writing _enum_ everywhere. Done easily, you can write the alias as a separate statement; but, you can
also combine the declaration and alias. 

### Simple Usage 
```C
#include <stdio.h>

// An enum 'Team' which can be one of four teams
enum Team { RED, YELLOW, BLUE, GREEN };
typedef enum Team Team;        // Aliases 'enum Team' to 'Team'

struct Player
{
    int health;
    int score;
    Team team;
};
typedef struct Player Player;   // Aliases 'struct Player' to 'Player'

int main(void)
{
    // Initialize a player
    Player player_one = { 10, 0, RED };

    // Print stats
    printf("Health: %d\n", player_one.health);
    printf("Score: %d\n", player_one.score);
    printf("Team: %d (red)\n", player_one.team);

    return 0;
}
```
> Prints: <br />
> Health: 10 <br />
> Score: 0 <br />
> Team: 0 <br />

### As a Single Line
Though a bit more complicated, you can combine the declaration of the enum with the declaration of the alias.

```C
#include <stdio.h>

// An enum 'Team' which can be one of four teams
typedef enum Team { RED, YELLOW, BLUE, GREEN} Team;

// Struct mapped to the 'Player' alias
typedef struct Player
{
    int health;
    int score;
    Team team;
} Player;

int main(void)
{
    // Initialize a player
    Player player_one = { 10, 0, RED };

    // Print stats
    printf("Health: %d\n", player_one.health);
    printf("Score: %d\n", player_one.score);
    printf("Team: %d (red)\n", player_one.team);

    return 0;
}
```
> Prints: <br />
> Health: 10 <br />
> Score: 0 <br />
> Team: 0 <br />


## Manually Setting the Internal Values
Each possible value of an enum is mapped to an integer constant that is always one greater than the last (starting at 0). If you assign the values manually,
then the values of the enum will take on said integer value. If you assign one value manually and do not assign the ones that follow it, then the following 
values will just follow the pattern of adding one to the previous value.

```C
#include <stdio.h>

// The days of the week, each mapped to a value (1 = lucky, 0 = not)
typedef enum lucky_days { SUNDAY = 1, MONDAY = 0, TUESDAY = 0, WEDNESDAY = 1, THURSDAY = 0, FRIDAY = 1, SATURDAY = 1 } lucky_days;

int main(void)
{
    // Today is friday
    lucky_days today = FRIDAY;

    // Is today a lucky day?
    if (today)   // if 1 (true)
        puts("Friday is a lucky day~!");
    else
        puts("Friday is not a lucky day...");

    // Reassign today
    today = MONDAY;

    // Is today a lucky day?1
    if (today)  // if 1 (true)
        puts("Monday is a lucky day~!");
    else
        puts("Monday is not a lucky day...");

    return 0;
}
```
> Prints: <br />
> Friday is a lucky day~! <br />
> Monday is not a lucky day... <br />

## Getting the Value of an Enum as a String
The values of an enum are internally stored as strings, and there is no way to convert the name of a value of an enum into a string. If you want to use the value
as a string, you have to write a _switch_ statement that returns the proper value.

```C
#include <stdio.h>

// An enum 'Team' which can be one of four teams
typedef enum Team { RED, YELLOW, BLUE, GREEN } Team;

// Struct mapped to the 'Player' alias
typedef struct Player
{
    int health;
    int score;
    Team team;
} Player;

// Function delcaration
const char* get_team(Player* player);

// Driver code //
int main(void)
{
    // Initialize a player (using a designed initializer)
    Player player_one = { .health = 10, .score = 0, .team = RED };

    // Print stats
    printf("Health: %d\n", player_one.health);
    printf("Score: %d\n", player_one.score);
    printf("Team: %s\n", get_team(&player_one) );

    return 0;
}

// get_team implementation
const char* get_team(Player* player)
{
    switch (player->team)   // Eval team
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

## Sources
- [_Microsoft Documentation: C Enumaration Declarations_](https://docs.microsoft.com/en-us/cpp/c-language/c-enumeration-declarations?view=msvc-160)
- [_GeeksforGeeks: Enumeration (or enum) in C_](https://www.geeksforgeeks.org/enumeration-enum-c/)
- [_Programiz: C enum (Enumeration)_](https://www.programiz.com/c-programming/c-enumeration)
- [_TutorialsPoint: Enum in C_](https://www.tutorialspoint.com/enum-in-c)
