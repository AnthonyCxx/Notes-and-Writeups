/*
    Read a file that may or may not exist, using C++17's 'std::optional<T>'.
    Compile with C++17: 'g++ -std=c++17 file.cpp'
*/
#include <iostream>       //For general I/O
#include <string>        //Contains 'String' class
#include <fstream>      //For file I/O
#include <vector>      //Contains 'vector<T>' class
#include <optional>   //Contains 'optional<T>' class
using namespace std;

//Read a file, given the file name
optional<vector<string>> readFile(const string& path)    //Can be 'const char*' if hard-coded
{

    //Declare (and open) a file with the filepath
    ifstream file(path);

    //Vector to store the file line-by-line
    vector<string> contents;

    //Temporary string for reading the file contents
    string line;

    //If the file is valid
    if (file)
    {
        //Read the file
        while (getline(file, line))
        {
            contents.push_back(line);
        }

        //Cleanup
        file.close();

        //Return the contents of the file
        return contents;
    }

    //Return an empty optional object
    return nullopt;
}

/*
// EXAMPLE OF USAGE //

int main()
{
    //Read the contents of the file safely
    optional<vector<string>> content = readFile("text.txt");

    //If the file could be read successfully
    if (content)   //'optional<T>' evaluates to true if 'optional<T>.has_value()' is true
    {
        cout << "File read successfully\n";

        //For each line in the string vector
        for (string line : content.value()) //'optoinal<T>.value()' returns the data stored
        {
            cout << line << '\n';
        }
    }
    else
        cout << "File could not be read...\n";

    return 0;
}
*/
