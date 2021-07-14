# Reading from Files in C

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
    FILE* file = fopen("textfile.txt", "r"); 

    // Check for errors
    if (file != NULL) {
        puts("File exists and was opened successfully");
    }
    else {
        puts("Error: files does not exist. Could not open the file.");
    }

    // Close the file
    if (file != NULL)
        fclose(readfile);    // If 'file' is NULL, fclose() causes a segmentation fault

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

# Reading from Files

## fscanf()
[_fscanf()_](https://www.javatpoint.com/fprintf-fscanf-in-c) works like [_scanf()_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C/Input%20and%20Output/Input.md#scanf) for files, reading until it reaches whitespace. Like with _scanf()_, you can use scansets with _fscanf()_

```C
#include <stdio.h>
#include <stdlib.h>    // includes 'exit()'

int main()
{
    // Open a file 'textfile.txt' in read (r) mode
    FILE* file = fopen("textfile.txt", "r");   // Open 'textfile.txt' in 'r' (read) mode
    char text[256];                               // A buffer to store the file

    // If opening the file succeeded
    if (file != NULL)
    {
        // Read a single word from the file
        fscanf(file, "%s", text);    // file to read from, format, where to store the content

        // Print the line
        printf("The first word of the file is: \'%s\'\n", text);

        // Close the file
        fclose(file);
    }
    else   // Otherwise
    {
        puts("Error: files does not exist. Could not open the file.");
        exit(1);
    }

    return 0;
}
```

## fgetc()
[_fgetc_](https://www.tutorialspoint.com/c_standard_library/c_function_fgetc.htm) is [_getchar()_] for files, reading a single character from the file.

```C
#include <stdio.h>
#include <stdlib.h>    // includes 'exit()'

int main()
{
    // Open a file 'textfile.txt' in read (r) mode
    FILE* file = fopen("textfile.txt", "r");  // Open 'textfile.txt' in 'r' (read) mode
    char letter;

    // If opening the file succeeded
    if (file != NULL)
    {
        // Read from file
        letter = fgetc(file);

        // Print read character
        printf("The first letter of the file is: %c\n", letter);

        // Close the file
        fclose(file);
    }
    else   // Otherwise
    {
        puts("Error: files does not exist. Could not open the file.");
        exit(1);
    }

    return 0;
}
```

## fgets()
The _fgets()_ function reads a set amount of characters from a FILE* stream. _fgets()_ takes three parameters: the buffer to store the characters read, the max amount of characters to read (typically the size of the buffer) and the FILE* to read from ('stdin' is the keyboard).

The sizeof() operator (yes, operator) returns the size of the datatype (/variable/data structure) in bytes, right? And a char is only 1 byte, right? So it just happens to be the case that using the sizeof() operator on the char array returns the exact amount of characters that fgets() needs to read. Neat.

```C
#include <stdio.h>
#include <stdlib.h>    // includes 'exit()'

int main()
{
    // Open a file 'textfile.txt' in read (r) mode
    FILE* file = fopen("textfile.txt", "r");  // Open 'textfile.txt' in 'r' (read) mode
    char buffer[256];

    // If opening the file succeeded
    if (file != NULL)
    {
        // Read from file
        fgets(buffer, sizeof(buffer), file);   // The buffer to store data in, the amount of chars to read, and FILE* stream

        // Print the file contents (256 chars max)
        printf("File contents: %s", buffer);

        // Close the file
        fclose(file);
    }
    else   // Otherwise
    {
        puts("Error: files does not exist. Could not open the file.");
        exit(1);
    }

    return 0;
}
```

# Writing to Files

## fprintf()
[_fprintf()_](https://www.geeksforgeeks.org/fprintf-in-c/) works like [_printf()_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C/Input%20and%20Output/Output.md#printfstr-formatting-variables) for files, allowing you to write formatted strings to a file.
```C
#include <stdio.h>
#include <stdlib.h>    // includes 'exit()'

int main()
{
    // Open a file 'textfile.txt' in write (w) mode
    FILE* file = fopen("textfile.txt", "w");  // Open 'textfile.txt' in 'w' (write) mode

    // If opening the file succeeded
    if (file != NULL)
    {
        // Write to file
        fprintf(file, "The word of the day is: %s\n", "synecdoche");  // file to write to, string, formatting variables

        // Close the file
        fclose(file);
    }
    else   // Otherwise
    {
        puts("Error: files does not exist. Could not open the file.");
        exit(1);
    }

    return 0;
}
```

## fputc()
[_fputc_](https://www.tutorialspoint.com/c_standard_library/c_function_fputc.htm) is [_putchar()_](https://www.tutorialspoint.com/c_standard_library/c_function_putchar.htm) for
files, writing a single character to the file.

```C
#include <stdio.h>
#include <stdlib.h>    // includes 'exit()'

int main()
{
    // Open a file 'textfile.txt' in write (w) mode
    FILE* file = fopen("textfile.txt", "w");  // Open 'textfile.txt' in 'w' (write) mode

    // If opening the file succeeded
    if (file != NULL)
    {
        // Write to file
        fputc('A', file);

        // Close the file
        fclose(file);
    }
    else   // Otherwise
    {
        puts("Error: files does not exist. Could not open the file.");
        exit(1);
    }

    return 0;
}
```

## fputs()
[_fputs()_](https://www.tutorialspoint.com/c_standard_library/c_function_fputs.htm) is [_puts()_](https://www.tutorialspoint.com/c_standard_library/c_function_puts.htm) for files, writing an unformatted string to a file. If you can, use this over _fprintf()_, as it is faster.

```C
#include <stdio.h>
#include <stdlib.h>    // includes 'exit()'

int main()
{
    // Open a file 'textfile.txt' in write (w) mode
    FILE* file = fopen("textfile.txt", "w");  // Open 'textfile.txt' in 'w' (write) mode

    // If opening the file succeeded
    if (file != NULL)
    {
        // Overwrite the file contents
        fputs("Overwriting your file :D!", file);  // String to write, FILE* to write to

        // Close the file
        fclose(file);
    }
    else   // Otherwise
    {
        puts("Error: files does not exist. Could not open the file.");
        exit(1);
    }

    return 0;
}
```

## Sources: 
Programiz: [_C File Handling_](https://www.programiz.com/c-programming/c-file-input-output) <br />
JavaTPoint: [_File Handling in C_](https://www.javatpoint.com/file-handling-in-c) <br />
JavaTPoint: [_C fprintf() and fscanf()_](https://www.javatpoint.com/fprintf-fscanf-in-c) <br />
DelftStack: [_Read File Line by Line Using fscanf in C_](https://www.delftstack.com/howto/c/fscanf-line-by-line-in-c/) <br />
JavaTPoint: [_C fputc() and fgetc()_](https://www.javatpoint.com/fputc-fgetc-in-c) <br />
JavaTPoint: [_C fputs() and fgets()_](https://www.javatpoint.com/fputs-fgets-in-c) <br />
Fresh2Refresh: [_C - File Handling_](https://fresh2refresh.com/c-programming/c-file-handling/) <br />
Study.com [_Declaring, Opening & Closing File Streams in C Programming_](https://study.com/academy/lesson/declaring-opening-closing-file-streams-in-c-programming.html) <br />
