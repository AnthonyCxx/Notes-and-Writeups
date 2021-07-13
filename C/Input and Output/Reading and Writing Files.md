# File I/O in C

## The _FILE_* Datatype
All files in C are pointers of the [_FILE_](https://www.geeksforgeeks.org/data-type-file-c/#:~:text=A%20FILE%20is%20a%20type,although%20it%20is%20system%20specific.) datatype.
Yes, this means that if you open a file with [_fopen()_](https://www.geeksforgeeks.org/c-fopen-function-with-examples/), then you must also close it with [_fclose()_](https://www.tutorialspoint.com/c_standard_library/c_function_fclose.htm).
Otherwise, you will have [memory leak](https://www.geeksforgeeks.org/what-is-memory-leak-how-can-we-avoid/) ([ref](https://stackoverflow.com/questions/21499080/memory-allocation-when-fopen-is-called-is-not-clear)).

## Opening and Closing Files
```C
#include <stdio.h>

int main()
{
    // Open a file 'textfile.txt' in read (r) mode
    FILE* readfile = fopen("textfile.txt", "r"); 

    // Check for errors
    if (readfile != NULL) {
        puts("File exists and was opened successfully");
    }
    else {
        puts("Error: files does not exist. Could not open the file.");
    }

    // Close the file
    if (readfile != NULL)
        fclose(readfile);    // If 'readfile' is NULL, fclose() causes a segmentation fault

    return 0;
}
```
> Reference: [_What is a Segementation Fault?_](https://www.geeksforgeeks.org/core-dump-segmentation-fault-c-cpp/#:~:text=Core%20Dump%2FSegmentation%20fault%20is,an%20error%20indicating%20memory%20corruption.) <br />

### File Modes
_r_ mode returns NULL if the file does not exist; _w_ mode overwrites the file if it does.
| Mode | Function | If File Exists | If File Does Not Exist |
| ---- | --------- | ------------- | ---------------------- |
| r | reads file | same as function | returns NULL |
| w | writes to file | overwrites file | creates file | 
| a | append to file | same as function | creates file |  
| r+ | read and write to file | same as function | returns NULL | 
| w+ | read and write to file | overwrites file | creates file | 
| a+ | read and append to file | same as function | creates file | 
> To work with [binary files](https://en.wikipedia.org/wiki/Binary_file) (.bin), add a 'b' (for binary) after the first letter (rb, wb, ab, rb+, wb+, ab+) <br />


> https://www.javatpoint.com/file-handling-in-c
> Citation: this chart belongs to [Programiz](https://www.programiz.com/) and is from their article [_C File Handling_](https://www.programiz.com/c-programming/c-file-input-output).

## Reading from Files

## Writing to Files

## Sources: 
Programiz: [_C File Handling_](https://www.programiz.com/c-programming/c-file-input-output) <br />
JavaTPoint: [_File Handling in C_](https://www.javatpoint.com/file-handling-in-c) <br />
Fresh2Refresh: [_C - File Handling_](https://fresh2refresh.com/c-programming/c-file-handling/) <br />
Study.com [_Declaring, Opening & Closing File Streams in C Programming_](https://study.com/academy/lesson/declaring-opening-closing-file-streams-in-c-programming.html) <br />
