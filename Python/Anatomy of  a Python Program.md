# Anatomy of a Python Program
> Reference: [_Python Basic Syntax_](https://www.tutorialspoint.com/python/python_basic_syntax.htm) <br />

Here is an analysis of a simple Pythonprogram. For reference, Python source code files should end with the .py extension and are run with `Python3 filename.py`.
```Python
# This is a single-line comment

'''
This is a multi-line
comment
'''

def main():
    print("Hello, World!")

if __name__ == '__main__':
    main()
```

## The _main()_ function and clause
The _main()_ function should be the entry point of your code. The clause `if __name__ == '__main__'` is explained [here](https://stackoverflow.com/questions/419163/what-does-if-name-main-do) and basically just prevents other files from automatically running when being imported (which is a problem since Python is an interpreted language).

## _print("Hello, World!")_
This line outputs the string "Hello, World!" onto the screen and implicitly begins a new line

## Comments
Pythony uses a single octothorp (#) for single-line comments and uses either ''' or """ for multi-line comments.

## Blocks of Code in Python via Indentation
Python is a very simple language, so it threw out all the semi-colons and braces from languages like C in favor of using identation to distinguish blocks of code.
Blocks of code in Python start with a colon (:) and all the lines of the block are indented. Once the indentation ends, so does the block. Blocks can have blocks within
them with further indentation.

Always use tabs instead of spaces for indentation to reduce indentation errors.
```Python
# A function named 'func'
def func():                         # Start of function block
    for number in [1, 2, 3]:        # Start of of loop block
        print(number)               # End of loop block
                                    # End of function block
                                    
# Call the function 'func'
func()
```
