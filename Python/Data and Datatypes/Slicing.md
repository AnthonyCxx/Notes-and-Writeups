# Slicing in Python
Slicing returns a range of elements from an iterable sequence like a string, list, or tuple. <br />
For sake of simplicity, I'm going to be using lists throughout these examples.

## Introduction to Slicing Notation
Slicing is entirely based on the [_slice()_](https://www.w3schools.com/python/ref_func_slice.asp) function.
You can use the _slice()_ function directly, but slice notation is much more legible. Slice notation looks like
`list[0:3]` and translates to 'take the object _list_ and return indices 0 through 2' (stopping before index 3).

```Python
# A list of 5 integers
nums = [1, 2, 3, 4, 5]

# [0:3] returns indices 0-2, stopping before index 3
print(nums[0:3]) # [1, 2, 3]
```

## Implying Indices
You can imply the first or last index by omitting it like `list[0:]`.

```Python
# A list of 5 integers
nums = [1, 2, 3, 4, 5]

# [:3] returns indices 0-2, stopping before index 3
print(nums[:3]) # [1, 2, 3]

# [2:] returns indices 2-4, stopping before index 5 (non-existent)
print(nums[2:]) # [3, 4, 5]

# [:] returns indices 0-4, stopping before index 5 (non-existent)
print(nums[:]) # [1, 2, 3, 4, 5]
```

## Negative Indexing
Since the length of the object is known via the [\_\_len\_\_](https://stackoverflow.com/questions/49929998/what-is-magic-about-len/49930062), you can iterate over it in 
reverse. <br /> 
By providing a negative index, you can reference the end of the object. 

```Python
# A list of 10 integers, corrosponding to their index
nums = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

# [0:-2] returns indices 0-7, stopping before index 8
print(nums[0:-2]) # [0, 1, 2, 3, 4, 5, 6, 7]

# [3:-3] returns indices 3-6, stopping before index 7
print(nums[3:-3]) # [3, 4, 5, 6]
```

## Introducing a Step
Introducing a third number will provide a step, skipping every _int_ numbers where _int_ is the number provided. <br />

```Python
# A list of 10 integers, corrosponding to their index
nums = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

# [0:10:2] returns indices 0-9 and iterates over them by 2s
print(nums[0:10:2]) # [0, 2, 4, 6, 8]

# [0:10:3] returns indices 0-9 and iterates over them by 3s
print(nums[0:10:3]) # [0, 3, 6, 9]
```

## Negative Steps
Providing a negative step will cause the slice to iterate backwards. <br />
I have no idea how this works.

```Python
# A list of 10 integers, corrosponding to their index
nums = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

print(nums[::-1])    # all items in the array, reversed
print(nums[1::-1])   # the first two items, reversed
print(nums[:-3:-1])  # the last two items, reversed
print(nums[-3::-1])  # everything except the last two items, reversed

# [::-1]
print(nums[::-1]) # [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
```
