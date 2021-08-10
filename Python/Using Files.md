# Reading and Writing Files in Python
RealPython has a really good guide on [reading/writing files in Python](https://realpython.com/read-write-files-python/).

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

## Reading by Character
file.read(1)

## Reading by Line
file.readline()

## Reading Entire File into String
file.read()

## Reading Entire File into List
file.readlines()

# Writing to Files
