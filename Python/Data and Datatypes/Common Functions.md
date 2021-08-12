# Common Functions in Python

eval, format

## _print()_
Python's generic print function; Equal to _Console.WriteLine()_ in C# or _System.out.println()_ in Java. <br />
If you want to prevent the implicit newline, add `, end=''` as the last argument.

```Python
print("Hello, World!", end='')
print("Hello, World!")
```

## _len()_
_len_ takes the length of any sequence: strings, lists — anything.

```Python
name = "Mitzelplik"

print(f"Your name is {len(name)} characters long")
```

## _range()_
_range()_ returns a list of integers that can be iterated over and is used for traditional for-loops. <br />
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

## _type()_
_type()_ returns the datatype of an object. Don't underestimate how useful this function is in a weak-typed system. It's great for finding bugs.

```Python
result1 = 4/2
result2 = 5/2

# Compare the datatypes of the two results
if type(result1) == type(result2):
    print(f"The two are of the same datatype: {type(result1)}")
else:
    print(f"The two are not of the same datatype; types: {type(result1)}, {type(result2)}")
```

## _sorted()_
_sorted()_ does not a sort a list. Instead, it returns a new, sorted version of the list that is separate from the original.
_sorted()_ can be sorted by key (e.g. `key=len`) or in reverse (e.g. `, reverse=True`).

```Python
# A list of strings
names = ["Joey Johnson", "Bradley Todd", "Vince Cook", "Victor Hum", "Kevin Silva"]

# Sorted names by length (shortest first)
for name in sorted(names, reverse=True):
    print(name)
```

## _sum()_
_sum()_ calculates the sum of a collection.

```Python
nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

print(f"The sum of the numbers is: {sum(nums)}")
print(f"The average of the numbers is: {sum(nums) / len(nums)}")
```

## _min()_ and _max()_
_min()_ and _max()_ returns the smallest/largest elements of an iterable.

```Python
# A string
name = "Sun Tzu"
print(f"The largest character in the string is: {max(name)}")

# A list of a few numbers
nums = [-13, 51, 78, 12334, -9998]
print(f"The smallest number in the list is: {min(nums)}")
```

## _round()_
_round()_ rounds a number to the given amount of digits. If not provided, numbers are rounded to the nearest integer.

```Python
pi = 3.14159

print(f"Pi rounded to 3 digits is: {round(pi, 3)}")
print(f"Pi rounded: {round(pi)}")
```

## _abs()_
_abs()_ returns the [absolute value](https://www.mathsisfun.com/definitions/absolute-value.html) of a number (its distance from zero).

```Python
num = -1.5

print(f"The absolute value -1.5 is: {abs(num)}")
```
