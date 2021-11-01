# Working with Files in C++
> Jump to: <br />
> [Reading from Files](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#reading-from-files): by [character](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#reading-a-file-by-character), [word](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#reading-a-file-by-word), [line](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#reading-a-file-by-line), or [custom delimiter](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#reading-a-file-by-line-with-custom-delimiter)  <br />
> [How to Detect EOF](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#detecting-the-end-of-file-eof) (end of file) <br />
> Storing files in [strings](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#storing-a-file-with-string), [vectors](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#storing-a-file-with-vectort), [stringstreams](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#storing-a-file-with-stringstream) <br />
> [Writing to Files](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#writing-to-files)  <br />

C++ provides support for reading files with the [_\<fstream\>_](https://www.cplusplus.com/reference/fstream/) header file. The _\<fstream\>_ library contains
three streams (classes) to work with files, [_ifstream_](https://www.cplusplus.com/reference/fstream/ifstream/) (for reading files), [_ofstream_](https://www.cplusplus.com/reference/fstream/ofstream/) (for writing files), and [_fstream_](https://www.cplusplus.com/reference/fstream/fstream/) (for reading 
and writing files). Since _ifstream_, _ofstream_, and _fstream_ are all a part of the [I/O class inheritance hierarchy](https://www.cplusplus.com/reference/iolibrary/),
they can be formatted with [_\<iomanip\>_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Input%20and%20Output/iomanip.md) and use _<<_ and _>>_ just like _cin_ and _cout_.

## File I/O Summary
Here's a quick rundown on how to use files.

```C++
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    //Declare a file named 'file' (fstream = read & write) and a string for the file name
    fstream file;
    const string filename = "file.txt";

    //Open the file
    file.open(filename);  //.open("file.txt") also works

    //Read and write to the file
    if (file)  //File objects evaluate to true if they're good to use (returns file.good())
    {
        //To store the read word in
        string word;

        //Read a word from the file
        file >> word;
        cout << "The first word in the file is: " << word << '\n';

        //Write to the file (overwriting the file, since 'ios::out' is one of the default modes of 'fstream')
        file << "This string will be written to the file";

        //Close the file
        file.close();
    }

    return 0;
}
```

## Using Files Modes
Files can be set to different modes, which dictates how the file stream reads/writes to the file.
These modes are not necessarily exclusive, as you can combine compatible flags (e.g. _ios::in_ and _ios::binary_).
To combine flags, put a [bitwise OR](https://www.programiz.com/cpp-programming/bitwise-operators) (a single '\|') between the flags.

Example of opening a file: `file.open("filename", ios::in | ios::binary)`.
| Mode | Full Name | Description | If Found | If Not Found |
| ---- | --------- | ----------- | -------- | ------------ |
| _ios::in_ | Input | standard read mode | N/A | N/A |
| _ios::out_ | Output | standard write mode | overwrites the file | creates file |
| _ios::ate_ | At End | write mode; starts pointer at the end of the file (can be changed) | appends data (by default) | creates file |
| _ios::app_ | Append | write mode; starts pointer at the end of the file (cannot be changed) | appends data | creates file |
| _ios::trunc_ | Truncate | write mode; wipes file contents | wipes file contents | creates file |
| _ios::binary_ | Binary | read/write mode modifier; treats the file as binary data instead of text | N/A | N/A |
> _ios::in_ is the default for _ifstream_, _ios::out_ is the default for _ofstream_, and _ios::in \| ios::out_ is the default for _fstream_.

# Reading from Files

## Detecting the End of File (EOF)
When looping over a file to read its contents, you either need to know how long the file is or you need to be able to detect the end of the file.
99% of time, you won't know the size of the file, so being able to detect _EOF_ is the only viable method. C++ provides a number of ways to check for _EOF_,
so there are a number of ways people tend to write their loop conditions, only some of which actually work. Most people tend to write something like
`while(!file.eof())` to check for _EOF_, but this approach is considered bad practice as the badbit is only set after _EOF_ is read, causing an extra, blank line to be read. Instead, write something like `while(file >> data)`, which is safe since it relies on the return value of the
overloaded _<<_ opreator from the _istream_ class.
> Source: The ISO C++ Standard: [_Why does my input seem to process past the end of file?_](https://isocpp.org/wiki/faq/input-output#istream-and-eof)

## Reading a File by Character
Read a file character by character by using _>>_ with a char datatype. By default, _istream_ streams (like _cin_ and files) skip whitespace. <br />
If you want to include whitespace, put `file >> noskipws;` (no skip whitespace) in front of the loop.

If you're parsing by character to look for specific character, consider using the [_\<cctype\>_](https://en.cppreference.com/w/cpp/header/cctype) library, which contains
pre-written functions for classifying characters like [_isalpha()_](https://en.cppreference.com/w/cpp/string/byte/isalpha), [_isdigit()_](https://en.cppreference.com/w/cpp/string/byte/isdigit), [_ispunct()_](https://en.cppreference.com/w/cpp/string/byte/ispunct), [_isspace()_](https://en.cppreference.com/w/cpp/string/byte/isspace), [_isupper()_](https://en.cppreference.com/w/cpp/string/byte/isupper), and [_islower()_](https://en.cppreference.com/w/cpp/string/byte/islower) as well as two functions for manipulating character case: [_toupper()_](https://en.cppreference.com/w/cpp/string/byte/toupper) and [_tolower()_](https://en.cppreference.com/w/cpp/string/byte/tolower).
```C++
//Delcarations
string contents;    //Store the file contents in one large string
char character;    //Temporarily store a single character

//file >> noskipws;    <== include this to read whitespace

//Until the end of the file
while(file >> character)   //Get a single character
{
    //Add the contents to the string
    contents += character;
}
```

## Reading a File by Word
Read a file word by word by using _>>_ with a string datatype. 

For some reason, my program broke and only read the first word when I added `file >> noskipws;` like I did in the previous example.
```C++
//String delcarations
string contents;    //Store the file contents in one large string
string word;       //Temporarily store a single string

//Until the end of the file
while(file >> word)   //Get a single word
{
    //Append the string to the file contents
    contents += word + ' ';    //Have to append an extra space since not reading whitespace
}
```

## Reading a File by Line
Read a file line by line by using [_getline()_](https://www.javatpoint.com/cpp-getline) with a string datatype.
_getline()_ only needs two arguments: the file to read from and the string to store the data in (in that order). 

```C++
//String delcarations
string contents;    //Store the file contents in one large string
string line;       //Temporarily store a whole line

//Until the end of the file
while(getline(file, line))   //Get a a whole line (until '\n')
{
    //Append the string to the file contents
    contents += line + ' ';  //Have to append an extra space since not reading whitespace
}
```

## Reading a File By Line with Custom Delimiter
Read a file line by line by using [_getline()_](https://www.javatpoint.com/cpp-getline) with a string datatype.
If you provide a [delimiter](https://searchoracle.techtarget.com/definition/delimiter) (a character) as a third argument to _getline()_ (after the file to read from and the string to store the data in), 
then _getline()_ will read up to the given delimiter instead of a newline ('\n') like it normally does. <br />

**WARNING:** _getline()_ does not include the delimiter it stops at in the data it returns. 
```C++
//String delcarations
string contents;    //Store the file contents in one large string
string line;       //Temporarily store a whole line

//Until the end of the file
while(getline(file, line, 'z'))   //Get a a whole line (up to and excluding the character 'z')
{
    //Append the string to the file contents
    contents += line + ' ';  //Have to append an extra space since not reading whitespace
}
```

## Storing a File with _string_
Storing a file in a string is simplest way to store the contents of a file. Storing a file's content in a string does lose track of the individual lines, 
so store your files in a string when you have no special needs, like formatting or keeping the lines separate.

Strings are [mutable](https://lemire.me/blog/2017/07/07/are-your-strings-immutable/) in C++, so there's no problem with constantly changing a string unlike in C# or Java.
```C++
//String delcarations
string contents;    //Store the file contents in one large string
string line;       //Temporarily store a whole line

//Until the end of the file
while(getline(file, line))   //Get a a whole line (until '\n')
{
    //Append the string to the file contents
    contents += line + ' ';  //Have to append an extra space since not reading whitespace
}
```

## Storing a File with _vector\<T\>_
> Pre-requisite: [_vectors_](https://www.educative.io/edpresso/what-is-a-c-vector)

A vector is basically an array except you can change the size as you need, making it useful for storing a file of an unknown size, while still
being able to keep the individual lines separate. Vectors have very little overhead, so don't worry about slowing down your program by using one.

If you're going to loop over the vector (for printing, reading, etc.), I would recommend a [_ranged-based for loop_](https://www.geeksforgeeks.org/range-based-loop-c/).
```C++
#include <vector>
//Storage delcarations
vector<string> contents;    //Store the lines of the files separately in a vector
string line;               //Temporarily store a whole line

//Until the end of the file
while(getline(file, line))   //Get a a whole line (until '\n')
{
    //Append the string to the file content vector
    contents.push_back(line);
}
```
> Reference: [_std::vector functions_](https://www.cplusplus.com/reference/vector/vector/)

## Storing a File with _stringstream_
> Pre-requisite: [_stringstream_](https://www.geeksforgeeks.org/stringstream-c-applications/)

A stringstream is essentially a string, but it inherits from the [_iostream_](https://www.cplusplus.com/reference/istream/iostream/) class so it can be used like a stream.
This means that you can use the _<<_ and _>>_ operators with it, as well as format it using format flags from [_\<iomanip\>_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Input%20and%20Output/iomanip.md). I like to use _stringstream_ as a replacement for _string_ when I want to format the contents of the file, 
but don't want to format the file object itself (yes it's is circumstantial, but useful).

You can return the contents of a stringstream as a string with `stringstream.str()`.
```C++
#include <sstream>
//Storage delcarations
stringstream contents;     //Store the lines of the file as a stringstream
string line;              //Temporarily store a whole line

//Until the end of the file
while(getline(file, line))   //Get a a whole line (until '\n')
{
    //Append the string to the file content vector
    contents << line + ' ';   //Have to append an extra space since not reading whitespace
}
```
> Reference: [_std::stringstream functions_](https://www.cplusplus.com/reference/sstream/stringstream/)

# Writing to Files
Writing to files is much simpler than reading from files. You can just use the _<<_ operator like you do with _cout_. <br />
How the text is written to the file depends on the mode the file was opened in (_ios::out_, _ios::app_, etc.).

```C++
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    //Declare a file named 'file' (ofstream = write) and a string for the file name
    ofstream file;
    const string filename = "file.txt";

    //Open the file, appending to the it (ios::app)
    file.open(filename, ios::out | ios::app);

    //Read and write to the file
    if (file)  //File objects evaluate to true if they're valid (good to use; 'file.good()' also works)
    {
        //Write to the file
        file << "Appending this text to the end of the file :)";

        //Close the file
        file.close();
    }
    else
    {
        cerr << "File could not be read...\n";
    }
    
    return 0;
}
```
> Jump: [File Modes](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#using-files-modes)

# Sources
cplusplus.com: [_Input/output with files_](https://www.cplusplus.com/doc/tutorial/files/) <br />
W3Schools: [_C++ Files_](https://www.w3schools.com/cpp/cpp_files.asp) <br />
clpusplus.com: [_\<fstream\>_](https://www.cplusplus.com/reference/fstream/) <br />
cplusplus.com: [_std::fstream_](https://www.cplusplus.com/reference/fstream/fstream/) <br />
Guru99: [_C++ File Handling: How to Open, Write, Read, Close Files in C++_](https://www.guru99.com/cpp-file-read-write-open.html) <br />
DecodeJava: [_C++ File and File Modes_](https://www.decodejava.com/cpp-file-and-file-modes.htm) <br />
StackOverflow: [_What is the difference among ios::app, out, and trunc in C++?_](https://stackoverflow.com/questions/48085781/what-is-the-difference-among-iosapp-out-and-trunc-in-c/48086058) <br />
StackOverflwo: [_C++ Filehandling: Difference between ios::app and ios::ate?_](https://stackoverflow.com/questions/10359702/c-filehandling-difference-between-iosapp-and-iosate) <br />
StackOverflow: [_How to Read from a Text File, Character by Character in C++_](https://stackoverflow.com/questions/12240010/how-to-read-from-a-text-file-character-by-character-in-c) <br />
