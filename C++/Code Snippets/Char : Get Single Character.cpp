/*
Generally, you can use 'cin.get()', but even that leaves a newline ('\n') character in the stream, which can affect your program.
This gave me a problem when I was making my Hangman game -- I needed raw input, without the newline.
*/

#include <limits>        //Contains numeric_limits::max()

// Get a single character, disposing of the input from the 'enter' key
char getSingleChar()
{
    char character;

    //Get character from the user
    cout << "Enter a character: ";
    cin.get(character);

    //Prevent leaving a '\n' in the stream from the user hitting enter
    cin.clear();                                                 //Always call 'cin.clear()' before 'cin.ignore()'
    cin.ignore(numeric_limits<streamsize>::max(), '\n');        // Ignore everything up to and including the user pressing 'enter'

    return character;
}
