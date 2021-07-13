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
    FILE* readfile = fopen("textfile.txt", "r");  // Open 'textfile.txt' in 'r' (read) mode

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

### File Modes
| Mode | Function | If the File If the file Does Not Exist |
| ---- | -------- | -------------------------- |
| r | read | returns NULL |
| rb | read (binary mode) | returns NULL |
| w |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
> Citation: this chart belongs to [Programiz](https://www.programiz.com/) and is from their article [_C File Handling_](https://www.programiz.com/c-programming/c-file-input-output).

## Sources: 
Programiz: [_C File Handling_](https://www.programiz.com/c-programming/c-file-input-output) <br />
Study.com [_Declaring, Opening & Closing File Streams in C Programming_](https://study.com/academy/lesson/declaring-opening-closing-file-streams-in-c-programming.html) <br />
