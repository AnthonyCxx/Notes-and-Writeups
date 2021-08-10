# Reading and Writing Files in Python
RealPython has a really good guide on [reading/writing files in Python](https://realpython.com/read-write-files-python/).

For reference, I use the [walrus operator](https://realpython.com/lessons/assignment-expressions/) (:=) a lot here.

## Opening a File
Open a file with the built-in [_open()_](https://www.w3schools.com/python/python_file_handling.asp) function, which returns a [file object](https://www.geeksforgeeks.org/file-objects-python/). Remember to always call [_.close()_](https://www.w3schools.com/python/ref_file_close.asp) on a file.

```Python
with open("file.txt", "r") as f:
    for count, line in enumerate(f):
        print(f"{count + 1}: {line.rstrip()}")
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
The [_read()_](https://www.w3schools.com/python/ref_file_read.asp) method reads a given amount of characters. <br />
If no amount is specified, _read()_ will read the entire file. To read by character, do _read(1)_.

```Python
with open("file.txt", "r") as f:
    while char := f.read(1):
        print(char)
```
> Reference: [walrus operator](https://realpython.com/lessons/assignment-expressions/), :=

## Reading by Line
file.readline() reads a single line from the file. <br />
If you provide an _int_ as an argument, it will read _int_ lines.

```Python
# Best way        
with open("file.txt", "r") as f:
    for count, line in enumerate(f):
        print(f"{count + 1}: {line.rstrip()}")
        
# Alternative
with open("file.txt", "r") as f:
    while line := f.readline().rstrip():
        print(line)
```
> Reference: [walrus operator](https://realpython.com/lessons/assignment-expressions/), :=

## Reading Entire File as String
The [_read()_](https://www.w3schools.com/python/ref_file_read.asp) method read an entire file as a string if not given
an amount of characters to read.

```Python
with open("file.txt", "r") as f:
     content = f.read().rstrip()
     print(content)
```

## Reading Entire File as List
file.readlines() reads the entire <br />
Annoyingly, it does leave an ugly '\\n' on the end of each line, so I took the liberty of removing them for you.

```Python
with open("file.txt", "r") as f:
     lines = [line.rstrip('\n') for line in f.readlines()]
     print(lines)
```
> Reference: [List Comprehension](https://www.programiz.com/python-programming/list-comprehension)

# Writing to Files

```Python
with open("file.txt", "w") as f:
        f.write("Writing this to the file...")  
```
> Note: Since the file was opened in '_w_' mode, the contents of it will be overwritten
