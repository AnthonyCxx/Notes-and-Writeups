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
You can imply the first or last index by omitting it.

```Python

```

## Introducing a Step

```Python

```
