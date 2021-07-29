#include <iostream>
#include <string>
#include <fstream>      //For file I/O
#include <vector>      //Contains 'vector' class
#include <utility>    //Contains pair<>
using namespace std;

//All this mess with 'pair<bool, vector<string>' could easily be replaced with C++17's 'std::optional<T>', but this works for C++11...
pair<bool, vector<string>> readFile(const string& path)    //Should be 'const char*' if hard-coded
{

    //Tie the file contents with a bool noting if the file was valid
    vector<string> contents;
    pair<bool, vector<string>> filepair(false, contents);

    //Declare (and open) a file with the filepath
    ifstream file(path);

    //Temporary string for reading the file contents
    string line;

    //If the file is valid
    if (file)
    {
        //File was readable
        filepair.first = true;

        //Read the file
        while (getline(file, line))
        {
            filepair.second.push_back(line);
        }

        //Cleanup
        file.close();
    }

    //Return <bool, vector<string>>
    return filepair;
}




/*
// EXAMPLE OF USAGE //

int main()
{
    //Read the contents of the file safely
    pair<bool, vector<string>> content = readFile("text.txt");   //Can replace 'pair<bool, vector<string>>' with 'auto' to shorten

    //If the file could be read successfully
    if (content.first)
    {
        cout << "File read successfully\n";

        //For each line in the string vector
        for (string line : content.second)
        {
            cout << line << '\n';
        }
    }
    else
        cout << "File could not be read...\n";

    return 0;
}
*/
