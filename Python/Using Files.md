# Reading and Writing Files in Python
RealPython has a really good guide on [reading/writing files in Python](https://realpython.com/read-write-files-python/).

## Short Example

## Opening a File
Open a file with the built-in [_open()_]() function.

```Python

```

**WARNING**: "Warning Calling _f.write()_ without using the [_with_](https://www.geeksforgeeks.org/with-statement-in-python/) keyword or calling _f.close()_ might result 
in the arguments of _f.write()_ not being completely written to the disk, even if the program exits successfully." -Python Documentation Section 7.2, [Reading and Writing Files](https://docs.python.org/3/tutorial/inputoutput.html#reading-and-writing-files)

### File Modes
_r_ mode throwns a [_FileNotFoundError_](https://docs.python.org/3/library/exceptions.html#FileNotFoundError) if the file does not exist; _w_ mode overwrites the file if it does.
| Mode | Function |
| ---- | --------- | 
| r | reads file |
| w | writes to file | 
| a | append to file |
| r+ | read and write to file |
| w+ | read and write to file | 
| a+ | read and append to file |
> To work with [binary files](https://en.wikipedia.org/wiki/Binary_file) (.bin), add a 'b' (for binary) after the first letter (rb, wb, ab, rb+, wb+, ab+) <br />

# Reading Files

# Writing to Files
