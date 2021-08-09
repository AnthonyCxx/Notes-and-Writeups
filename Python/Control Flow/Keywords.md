# Control Flow Keywords in Python
Keywords related to control flow. That's it.

## _break_
_break_ manually terminates a loop. If you write a for loop `for num in range(10):` and include `break` as the first statement, then the loop will never execute. <br />
Using too many _break_ statements is considered poor practice, but they are good for stopping things like infinite loops.

```Python
# Print a single number and then break out of the loop
for num in range(10):
    print(num)
    break
```

## _continue_
_continue_ skips the remaining statements in the loop for that iteration and begins the next iteration.

```Python
# Print the even numbers 1-100
for num in range(1,101):  # 1-100
    if num % 2 != 0:
        continue
    
    print(num)
```
> This really should be written as `if num % 2 == 0: print(num)`. Always use as little control flow as possible.

## _pass_
_pass_ is a strange thing because it's not really related to control flow in my opinion, but Python's official documentation lists it under [_More Control Flow Tools, Pass Statements_](https://docs.python.org/3/tutorial/controlflow.html#pass-statements), so I guess I'll include it. _pass_ allows you to omit syntactically necessary code without
consequence. If you use the omitted code, it just does nothing. For example, you can define the body of a function as _pass_ and it will just do nothing when called. Personally,
I use it for when I want to just ignore an exception (a lot of people do this).

```Python
text = "a"

try:
    print(text[9000])   # Throws an IndexError (no index 9000...)
except Exception:       # Catch all errors
    pass                # Just ignore the error
```
