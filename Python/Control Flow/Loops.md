# Loops in Python

## _for_ Loop
In Python, for loops work a bit differently. If you wrote `for num in [1, 2, 3]` then _num_ would actually take on the values of 1, 2, and 3 while it iterated over the list.
This is what makes Python's for-loops distinct — the fact that they take on the value of element at the index in an object (1, 2, 3) instead of the value of the index itself (0, 1, 2)

## _range()_
The _range()_ function returns a list of integers that can be iterated over and is used for traditional for-loops. <br />
Optionally, you can provide a range of numbers and even a step if needed.

**NOTE**: _range()_ stops BEFORE the end number and does not count it. You have to add 1 to include the end number.
```Python
# Traditional For-loop
for num in range(10):  # 0-9
    print(num)
    
# Loop Starting at Non-Zero Number
for num in range(50, 61): # 50-60
    print(num)

# Looping with a Step
for num in range(10, 21, 2): # 10-20, counting by 2s
    print(num)
```

## _while_ Loop
