# Working with Files in C++
> Jump: <br />
> [Reading from Files](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#reading-from-files): by [character](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#reading-a-file-by-character), [word](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#reading-a-file-word), [line](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#reading-a-file-by-line)  <br />
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
    if (file)  //File objects evaluate to true if they're valid (good to use)
    {
        string word;

        //Read a word from the file
        file >> word;
        cout << "The first word in the file is: " << word << '\n';

        //Write to the file (overwriting the file, since 'ios::out' is the default mode)
        file << "This string will be written to the file";

        //Close the file
        file.close();
    }

    return 0;
}
```

## Using Files Modes

# Reading from Files

## Reading a File by Character

## Reading a File Word

## Reading a File by Line

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

## Working with File Modes

# Sources
cplusplus.com: [_Input/output with files_](https://www.cplusplus.com/doc/tutorial/files/) <br />
W3Schools: [_C++ Files_](https://www.w3schools.com/cpp/cpp_files.asp) <br />
clpusplus.com: [_\<fstream\>_](https://www.cplusplus.com/reference/fstream/) <br />
cplusplus.com: [_std::fstream_](https://www.cplusplus.com/reference/fstream/fstream/) <br />
Guru99: [_C++ File Handling: How to Open, Write, Read, Close Files in C++_](https://www.guru99.com/cpp-file-read-write-open.html) <br />
StackOverflow: [_How to Read from a Text File, Character by Character in C++_](https://stackoverflow.com/questions/12240010/how-to-read-from-a-text-file-character-by-character-in-c) <br />
: [__]() <br />
