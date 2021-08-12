# Exception Handling in Python
Exceptions are errors that occur during runtime, like dividing by zero ([_ZeroDivisionError_](https://docs.python.org/3/library/exceptions.html#ZeroDivisionError)); exceptions
can be managed through a process called exception handling. Exception handling allows you to deal with errors in a way that allows the program to continue running seamlessly 
(hopefully). Sometimes, an exception cannot be truly 'recovered' from, but can only be dealt with, in which case exception handing allows a more graceful solution to be achieved.

Exception handling uses four keywords: [_try_](https://www.w3schools.com/python/ref_keyword_try.asp), [_except_](https://www.w3schools.com/python/ref_keyword_except.asp), [_finally_](https://www.w3schools.com/python/ref_keyword_finally.asp), and [_raise_](https://www.w3schools.com/python/ref_keyword_raise.asp).

## Error Blocks with _try_..._except_
Exception handling is fundamentally built upon two keywords: _try_ and _except_. _try_ defines a block of code within which the programmer expects an error may occur and _except_
catches the error, defining a block that runs after the error occurs. When an exception is raised, the program immediately exits the _try_ block and jumps to the relevant _except_
block; the remaining statement in the try block are ignored.

In the following example, I intentionally raise an [_IndexError_](https://docs.python.org/3/library/exceptions.html#IndexError) by accessing an element that does not exist.
Without exception handling, the program would have terminated with the following error message:

_Traceback (most recent call last): <br />
  File "<string>", line 6, in <module> <br />
File "<string>", line 4, in main <br />
IndexError: list index out of range_ <br />
 
```Python
def main():
    numbers = [1, 2, 3, 4, 5]
    
    # try...except block catches the error, allowing the program to continue
    try:
        print(numbers[999])
    except IndexError:
        print("The given index does not exist")

main()
```

## Cleaning up with _finally_
The _finally_ block follows a _try_..._except_ block and is generally used to clean up the result of an operation which may or may not have gone through.
  
In complete honesty, I've never really used _finally_ because I didn't think it was that useful, but I found a decent answer [here](https://stackoverflow.com/questions/11551996/why-do-we-need-the-finally-clause-in-python) for when to use it.  
```Python
def main():
    f = open("textfile.txt", "w")
    
    try:
        f.write(0 / 0)     # This won't write...
    except Exception:
        print("An error occured while writing to the file")
    finally:
        file.close()

main()
```

## Manually Raising Errors with _raise_
If you want to catch anything other than an error thrown by the program itself, you'll have to do it manually with the _raise_ keyword. If you know C++, think of _raise_ as the 
_throw_ keyword. Unlike in C++ where you can throw anything, including primitive types, in Python you can only throw objects that inherit from the _BaseException_ class.

Manually throwing errors sounds strange, but it's very useful when you want to throw an error that isn't built into Python. Later on, you'll get to creating your own custom
errors and you'll use _raise_ a lot then.
  
```Python
def main():
    try:
        raise ZeroDivisionError
    except ZeroDivisionError:
        print("Caught a manually-raised ZeroDivisionError")

main()
```
  
## Catching errors as ___
