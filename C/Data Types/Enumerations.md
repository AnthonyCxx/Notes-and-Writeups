# Enumerations in C
An enumerated type (enum) is a user-defined type that can be one of a defined set of values, each of which is represented internally by an integer constant. Enums provide
programmers with a clear way of representing the possible states/values of an object. For example, a simple machine may have an enum defining its state with two simple
values, 'ON' and 'OFF' (by convention, enum values are typically fully capitalized). By default, the first value of an enum is 0, the second is 1, the third is 2, and so on;
however, this can be overwritten by manually assigning the values inside of the enum declaration. A good summary can be found [_here_](https://www.youtube.com/watch?v=lWzZ2l5n81c) (yes, CodeVault again - he's just so good at explaining stuff).

## Declaring an Enum
An enum is declared like so `enum enum_name { list_of_possible_values };`. The list of possible values is comma-separated.

```C
#include <stdio.h>

// An enum 'Team' which can be one of four teams
enum Team { RED, YELLOW, BLUE, GREEN};   // Yes, these are the team colors from Mario Party 8

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
directly. That way, you can just write the alias and stop writing 'enum' everywhere.
 
\an [_anonymous object_](https://docs.microsoft.com/en-us/cpp/cpp/anonymous-class-types?view=msvc-160)
(an enum in this case) to an alias. That way, you can just write the alias and stop writing 'enum' everywhere.

```C
#include <stdio.h>

// An enum 'Team' which can be one of four teams
enum Team { RED, YELLOW, BLUE, GREEN};
typedef enum Team Team;

struct Player
{
    int health;
    int score;
    Team team;
};
typedef struct Player Player;

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
