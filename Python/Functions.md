# Functions in Python
A function is a block of code that can be invoked by name. <br />
Functions allow you to break up your code into sections, achieving [modular programming](https://en.wikipedia.org/wiki/Modular_programming). <br />
If you don't care about that, then you might like that it lets you write code once and then use it as many times as you want where you want.

## Defining a Function
A function definition begins with the [_def_](https://docs.python.org/3/tutorial/controlflow.html#defining-functions) keyword followed by the name of the function,
and parameter list (parentheses) and a colon to start the block. After that, anything within the block is a part of the function.

Notice that running your code didn't run the function. That's because you have to call your function to use it. To call a function, write the function name followed by 
parentheses, like `sayHello()`.
```Python
# A simple function named 'sayHello' that prints 'Hello!'
def sayHello():
    print("Hello!")  # <== Body of the function
    
# Call the function
sayHello()
```

## The _return_ Keyword
The [_return_](https://realpython.com/python-return-statement/#understanding-the-python-return-statement) keyword lets you return data from a function to wherever the 
function was called. This simple function _add5()_ returns the sum of _5 + 5_ (10) to the variable _result_.

```Python
def add5():
    return 5 + 5
    
# Call 'add5', returning '10'
result = add5()
    
# Print the result
print(f"5 + 5 = {result}")
```

## Parameters

```Python

```

## Default Parameters

```Python

```

## Function Overloading

```Python

```
