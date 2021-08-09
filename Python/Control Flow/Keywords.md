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
> This really should be written as `if num % 2 == 0: print(num)`. Always be as direct as possible.

## _pass_
