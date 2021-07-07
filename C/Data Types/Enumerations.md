# Enumerations in C


## Declaring an Enum

```C
#include <stdio.h>

// An enum 'Team' which can be one of four teams
enum Team { RED, YELLOW, BLUE, GREEN};

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
