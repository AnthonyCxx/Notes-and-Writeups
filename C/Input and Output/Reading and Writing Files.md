# File I/O in C

## The _FILE_* Datatype
All files in C are pointers of the [_FILE_](https://www.geeksforgeeks.org/data-type-file-c/#:~:text=A%20FILE%20is%20a%20type,although%20it%20is%20system%20specific.) datatype.
Yes, this means that if you open a file with [_fopen()_](https://www.geeksforgeeks.org/c-fopen-function-with-examples/), then you must also close it with [_fclose()_](https://www.tutorialspoint.com/c_standard_library/c_function_fclose.htm) ([_ref_](https://stackoverflow.com/questions/21499080/memory-allocation-when-fopen-is-called-is-not-clear)).
Otherwise, you will have [memory leak](https://www.geeksforgeeks.org/what-is-memory-leak-how-can-we-avoid/).

## Opening and Closing Files
```C
#include <stdio.h>

int main()
{
    // Open the file
    FILE* readfile = fopen("textfile.txt", "r");  // Open 'textfile.txt' in 'r' (read) mode

    // Close the file
    fclose(readfile);

    return 0;
}
```

### File Modes



## Sources: 
Programiz: [_C File Handling_](https://www.programiz.com/c-programming/c-file-input-output) <br />
Study.com [_Declaring, Opening & Closing File Streams in C Programming_](https://study.com/academy/lesson/declaring-opening-closing-file-streams-in-c-programming.html) <br />
