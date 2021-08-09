Conditionals in Python
Conditionals are control structures that allow you to control the flow of a program based on certain criteria. <br />

## _if_, _else_, and _elif_
_if_, _else_, and _elif_ allow you to execute code based on [boolean](https://realpython.com/python-boolean/) criteria.

### _if_
To have an _else_ or an _elif_, you must first have an _if_. <br />
An _if_ statement will execute its respective block of code if its condition evaluates to _True_.

```Python
response = "yes"

print("Do you want to quit the game?")

# Quit the game IF the user responded 'yes'
if response == "yes":
    print("Quitting the game...")
```

### _else_
An _else_ statement will execute its respective block if the _if_ statement doesn't executes its. <br />

```Python
response = "yes"

print("Do you want to quit the game?")

# Quit the game IF the user responded 'yes', otherwise continue
if response == "yes":
    print("Quitting the game...")
else:                          
    print("Continuing the game...")  
```

### _elif_
_elif_ is a [portmanteau](https://www.britannica.com/topic/portmanteau-word) of '_else if_'. <br />
For an _elif_ statement to execute its block, the all preceeding blocks must have failed AND its condition must be true. <br />
Since _else_ statements must always come last, _elif_ goes after an _if_ and before an _else_. You can have as many _elif_ statement as you want.

```Python
response = "no"

print("Do you want to quit the game?")

# Quit the game IF the user responded 'yes', continue if 'no'
if response == "yes":                  # Exit if their answer is 'yes'
    print("Quitting the game...")
elif response == "no":                 # Continue if their answer is 'no'
    print("Continuing the game...")
else:                                  # Correct invalid response
    print("You didn't respond 'yes' or 'no' -- try again...")
```

## The 'Ternary Operator', \_\_ if \_\_ else \_\_

```Python

```

## Pattern Matching
Until Python 3.10, Python lacked [structural pattern matching](https://www.python.org/dev/peps/pep-0636/), which is their take on the classic _switch_ statement. <br />
It's doubtful that you're working in Python 3.10, so you'll probably just have to use _if_-_else_ chains instead.

[Here](https://www.python.org/dev/peps/pep-0636/#matching-specific-values) is a good, official example of how to write a Python 'switch' statement.

### Format

```Python

```

### Example

```Python

```
