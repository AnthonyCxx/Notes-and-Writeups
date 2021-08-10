# Reading and Writing Files in Python
RealPython has a really good guide on [reading/writing files in Python](https://realpython.com/read-write-files-python/).

For reference, I use the [walrus operator](https://realpython.com/lessons/assignment-expressions/) (:=) a lot here.

## Opening a File
Open a file with the built-in [_open()_](https://www.w3schools.com/python/python_file_handling.asp) function, which returns a [file object](https://www.geeksforgeeks.org/file-objects-python/). Remember to always call [_.close()_](https://www.w3schools.com/python/ref_file_close.asp) on a file.

```Python
# Open the file 'file.txt' in read/write mode
with open("file.txt", "r+") as f:   # <== No need to call f.close() now
    # Read a character
    character = f.read(1)
    print(character)

    # Read a line
    line = f.readline()
    print(line)

    # Read the whole file
    rest = f.read()
    print(rest)

    # Write a single line
    f.write("This is appended to the file")
```

**WARNING**: "Warning Calling _f.write()_ without using the [_with_](https://www.geeksforgeeks.org/with-statement-in-python/) keyword or calling _f.close()_ might result 
in the arguments of _f.write()_ not being completely written to the disk, even if the program exits successfully." -Python Documentation Section 7.2, [Reading and Writing Files](https://docs.python.org/3/tutorial/inputoutput.html#reading-and-writing-files).

### File Modes
_r_ mode throws a [_FileNotFoundError_](https://docs.python.org/3/library/exceptions.html#FileNotFoundError) if the file does not exist, _x_ mode throws a [_FileExistsError_](https://docs.python.org/3/library/exceptions.html#FileExistsError) if the file does exist, and _w_ mode overwrites the file if it exists.
| Mode | Function |
| ---- | --------- | 
| r | reads file |
| w | writes to file | 
| a | append to file |
| x | creates a file; read mode |
| r+ | read and write to file |
| w+ | read and write to file | 
| a+ | read and append to file |
> To work with [binary files](https://en.wikipedia.org/wiki/Binary_file) (.bin), add a 'b' (for binary) after the first letter (rb, wb, ab, rb+, wb+, ab+) <br />

# Reading Files

## Safely Reading Files

```Python

```

## Reading by Character
The [_read()_](https://www.w3schools.com/python/ref_file_read.asp) method reads a given amount of characters. <br />
If no amount is specified, _read()_ will read the entire file. To read by character, do _read(1)_.

```Python
with open("file.txt", "r") as f:
    while char := f.read(1):
        print(char)
```
> Reference: [walrus operator](https://realpython.com/lessons/assignment-expressions/), :=

## Reading by Line
file.readline()

```Python

```

## Reading Entire File as String
file.read()

```Python

```

## Reading Entire File as List
file.readlines()

```Python

```

# Writing to Files

```Python

```
