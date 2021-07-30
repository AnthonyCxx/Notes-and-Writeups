# Working with Files in C++
> Jump to: <br />
> [Reading from Files](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#reading-from-files): by [character](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#reading-a-file-by-character), [word](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#reading-a-file-by-word),  or [line](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#reading-a-file-by-line)  <br />
> [Detecting EOF](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#detecting-the-end-of-file-eof) (end of file) <br />
> [Writing to Files](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#writing-to-files)  <br />

C++ provides support for reading files with the [_\<fstream\>_](https://www.cplusplus.com/reference/fstream/) header file. The _\<fstream\>_ library contains
three streams (classes) to work with files, [_ifstream_](https://www.cplusplus.com/reference/fstream/ifstream/) (for reading files), [_ofstream_](https://www.cplusplus.com/reference/fstream/ofstream/) (for writing files), and [_fstream_](https://www.cplusplus.com/reference/fstream/fstream/) (for reading 
and writing files). Since _ifstream_, _ofstream_, and _fstream_ are all a part of the [I/O class inheritance hierarchy](https://www.cplusplus.com/reference/iolibrary/),
they can be formatted with [_\<iomanip\>_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Input%20and%20Output/iomanip.md) and use _<<_ and _>>_ just like _cin_ and _cout_.

## Basic File I/O
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
so there are a number of ways people tend to write their loop conditions, only some of which are perfectly valid. Most people tend to write something like
_!file.eof()_ to check for _EOF_, but [this approach is considered bad practice](https://stackoverflow.com/questions/5605125/why-is-iostreameof-inside-a-loop-condition-i-e-while-stream-eof-cons) as the badbit is only set after _EOF_ is read, causing an extra, blank line to be read.

For these examples, I'm going to be using [_getline()_](https://www.journaldev.com/39743/getline-in-c-plus-plus) and storing the contents in a string.

### while(file >> word) and while(file >> character)
This is a much better approach than checking for EOF directly as it won't leave an extra line.

```C++
//String delcarations
string contents;    //Store the file contents in one large string
string line;       //Stores each line temporarily

//Until the end of the file
while(file.good())  
{
    //Get the line from the file
    getline(file, line);

    //Append the line to the contents
    contents += line += ' ';  //Extra '+= <<space>>' to put a space between lines
}
```

## Reading a File by Character

## Reading a File by Word

## Reading a File by Line

``C++
//String delcarations
string contents;    //Store the file contents in one large string
string line;       //Stores each line temporarily

//Until the end of the file
while(file.good())  
{
    //Get the line from the file
    getline(file, line);

    //Append the line to the contents
    contents += line += ' ';  //Extra '+= <<space>>' to put a space between lines
}
```

## Storing a File with _string_

```C++

```

## Storing a File with _vector\<T\>_
> Pre-requisite: [_vectors_](https://www.educative.io/edpresso/what-is-a-c-vector)

Some text here...

```C++

```

## Storing a File with _stringstream_

```C++

```

# Writing to Files
Writing to files is much simpler than reading from files.

## Working with File Modes

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
