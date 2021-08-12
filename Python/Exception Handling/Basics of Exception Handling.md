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

```

## Cleaning up with _finally_

```Python

```

## Manually Raising Errors with _raise_

```Python

```
