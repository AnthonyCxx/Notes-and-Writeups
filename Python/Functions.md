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
When defining a function, you can put variables in the parameter list (the parentheses). Doing so allows you to pass data to the function when you call it that the function
can then use (the data becomes tied to the variable names).

Here, the function 'add' declares two parameters (a and b) so you can pass whatever two numbers to the function and it will return their sum.
```Python
# Function 'add' adds two numbers
def add(a, b):     # Takes two numbers, 'a' and 'b'
    return a + b   # Returns the sum of 'a' and 'b'
    
print(add(7, 5))
print(add(9, 14))
```

## Default Parameters
In the event that a function is called without some or all parameters, measures can be put into place to ensure that each parameter still has some default value.
To add default parameters, simple put an equals sign followed by a [literal](https://thabo-ambrose.medium.com/what-is-a-literal-in-computer-programming-560eace90b5b) 
(some value). That way, the parameter will take on that value if and only if no other value is provided.

```Python
def add(a = 0, b = 0):     # 'a' and 'b' have a default value of 0
    return a + b 
    
# Calling 'add' with both parameters
print(add(12, 100))

# Calling 'add' with one paramter (b = 0)
print(add(50))

# Calling 'add' with no parameters (a = 0, b = 0)
print(add())
```

## Variadic Functions
Intimidating name for a simple concept. Variadic functions are functions that can take a varying amount of parameters.
To make a function variadic, give it a special parameter _\*args_, which is a list that takes in the arguments.

```Python
# Concatenate all the strings given into one large string
def concatenate(*args):
    result = str() 
    
    # Iterate over the list of arguments
    for string in args:
        result += string
        
    return result
    
all = concatenate("this", "_function", "_takes", "_any", "_amount", "_of", "_strings")

print(all)
```
