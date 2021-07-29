# Working with Files in C++
> Jump to: <br />
> [Reading from Files](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#reading-from-files): by [character](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#reading-a-file-by-character), [word](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#reading-a-file-word),  or [line](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#reading-a-file-by-line)  <br />
> [Detecting EOF](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Input%20and%20Output/File%20Input%20and%20Output.md#detecting-the-end-of-file) (end of file) <br />
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
Files can be set to different modes, all of which are inherited from 

# Reading from Files

## Detecting the End of File
When looping over a file to read its contents, you either need to know how long the file is or you need to be able to detect the end of the file (EOF).
99% of time, you won't know the size of the file, so being able to detect EOF is the only viable method. C++ provides a number of ways to check for EOF,
so there are a number of structures that people use to check for EOF, all of which are perfectly valid ways. Here are 5 ways to check for the end of a file,
be it explicit or not.

### while(!file.eof())
```C++

```

### while(file.good())
```C++

```

### while(file)
```C++

```

### while(file >> word) and while(file >> character)
```C++

```

### while(getline(file, str))
```C++

```


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
DecodeJava: [_C++ File and File Modes_](https://www.decodejava.com/cpp-file-and-file-modes.htm) <br />
StackOverflow: [_What is the difference among ios::app, out, and trunc in C++?_](https://stackoverflow.com/questions/48085781/what-is-the-difference-among-iosapp-out-and-trunc-in-c/48086058) <br />
: [__]() <br />
: [__]() <br />
StackOverflow: [_How to Read from a Text File, Character by Character in C++_](https://stackoverflow.com/questions/12240010/how-to-read-from-a-text-file-character-by-character-in-c) <br />
