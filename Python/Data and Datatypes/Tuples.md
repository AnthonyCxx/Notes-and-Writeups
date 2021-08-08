# Tuples in Python
Tuples are an immutable data structure that can store a collection of elements of various types. <br />
Think of a tuple like a list that can't be changed once made. Like lists, the individual elements can be accessed using brackets (\[ \]).

## Tuples by Example
```Python
''' DECLARING TUPLES '''
tup1 = tuple()   
tup2 = ()

# Declaring an Initialized Tuple
numbers = (1, 2, 3)

''' ACCESSING TUPLES '''
# Normal indexing
print(f"The first element in the tuple is: {numbers[0]}")

# Negative indexing (is not zero-based)
print(f"The last element in the tuple is: {numbers[-1]}")

''' ITERATING OVER TUPLES '''
# Iterating over a tuple
for num in numbers:
    print(num)
    
''' MEMBERSHIP OPERATIONS '''
if 1 in numbers and 5 not in numbers:
    print("The tuple of numbers has 1 in it, but not 5")
    
''' DELETING A TUPLE '''
del numbers   # You can only delete whole tuples
```

## Returning Multiple Values with and Unpacking Tuples
Tuples can be used to return multiple values from a function. <br />
These values can be caught by another tuple or with sequential variables.

```Python
# Implicitly returns a Tuple
def min_max(search_list):
    return min(search_list), max(search_list)
    
# A list of numbers
numbers = [-11, 993, 54, 2, -314, 0, 7.9, 315]

# Unpack the tuple into two variables: min and max
min, max = min_max(numbers)

print(f"The smallest value was {min} and the largest was {max}")
```
> You can use a single underscore, \_, to discard unwanted values (yes, even more than one and even in the middle of the tuple).

## Methods

### _.count()_
_.count()_ returns the amount of times the given item occurs in the tuple (which may be 0).

```Python
numbers = (1, 2, 3)

print(f"The number 999 appears {numbers.count(999)} times in the tuple 'numbers'.")
```

### _.index()_
_.index()_ returns the index of an element in the tuple. If not present, it will throw a [ValueError](https://docs.python.org/3/library/exceptions.html#ValueError).

```Python
numbers = (1, 2, 3)

try:
    print(f"The index of the number 3 is: {numbers.index(3)}")
except ValueError:
    print("Error: the number is not in the tuple.")
```
