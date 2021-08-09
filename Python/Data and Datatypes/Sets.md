# Sets and Frozen Sets in Python
A set is a mutable, ordered collection of unique elements. <br />
To better understand sets, I recommend you learn some [set theory](https://www.youtube.com/watch?v=tyDKR4FG3Yw) (if you're in Discrete Math, sub to this guy) <br />

A frozen set is just a set that is immutable.

## Sets by Example

```Python
''' CREATING SETS '''
# Default Constructor
default_set = set()

# Initializing a Set
init_set = set((1, 2, 2, 3))  # <== Wrap all elements in '()' to make 1 argument  
other_way = {1, 2, 3}
print(init_set)

# Create a copy of a set (just doing '= init_set' creates an alias, not a copy)
copy_set = init_set.copy()  # <== Avoids creating an alias

''' ADDING AND REMOVING ELEMENTS '''
# Add an element
init_set.add(10)

# Remove an element
init_set.discard(10)

# Remove and return a random element
print(f"Removed item: {init_set.pop()}")

# Remove all elements
init_set.clear()

''' CHEAT: REMOVING DUPLICATES FROM LIST '''
# Temporary cast to set removes duplicates
redundant_list = [1, 1, 1, 2, 2, 3, 3, 3, 3]
without_duplicates = list(set(redundant_list)) # [1, 2, 3]

print(without_duplicates)
```

## Set Methods
Set methods can be generally categorized like so:

- [Adding Elements to Sets](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Python/Data%20and%20Datatypes/Sets.md#adding-elements-to-sets) 
- [Removing Elements from a Set](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Python/Data%20and%20Datatypes/Sets.md#removing-elements-from-sets)
- [Set Theory Operations](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Python/Data%20and%20Datatypes/Sets.md#set-theory-operations)
- [Miscellaneous](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Python/Data%20and%20Datatypes/Sets.md#miscellaneous)

## Adding Elements to Sets

### _.add()_
Appends an element to the set.

```Python
nums = {1, 2, 3}

# Add an element to the set
nums.add(5)
```

### _.update()_
Appends an iterable object (like a list or a range) to the set.

```Python
# Declare an empty set
set1 = set()

# Add the number 0-9 to the set
set1.update(range(10))
```

## Removing Elements from Sets

### _.discard()_
_.discard()_ removes an element by name. <br />
If the element does not exist, nothing will happen.

```Python
set1 = {'a', 'b', 'c', 'e'}

# Remove the letter 'z' from the set
set1.discard('z')    # Does not throw an error; does nothing.
```

### _.remove()_
_.remove()_ removes an element by name. <br />
If the element does not exist, a [KeyError](https://realpython.com/python-keyerror/) will be thrown.

```Python
set1 = {'a', 'b', 'c', 'e'}

# Remove the letter 'z' from the set
set1.remove('z')    # Throws a KeyError
```

### _.pop()_
Removes and returns a random element from the set. <br />
No, I'm not lying.

```Python
students = {"Matthew", "Harriet", "Andrew"}

# Until students is empty
while students:
    print(f"Random element: {students.pop()}")
    
# Show the set is empty
print(students)
```

### _.clear()_
Deletes every element in the set.

```Python
nums = {1, 2, 3}

# Clear the set
nums.clear()
```

## Set Theory Operations

### _.difference()_
Returns a new set that contains the elements that the first set didn't but the second did.

```Python
set1 = {'a', 'b', 'c'}
set2 = {'a', 'b', 'c', 'd'}

# Take the difference between two sets
print(set2.difference(set1))  # Prints 'd', reversing 'set1' and 'set2' prints nothing
```

### _.difference\_update()_
_.difference\_update()_ removes items from the first set that appear in both sets.

```Python
set1 = {'a', 'b', 'c', 'e'}
set2 = {'a', 'b', 'c', 'd'}

set1.difference_update(set2)  # 'set1' = {'e'}
```

### _.intersection()_
Compares two sets and returns a new set containing the elements that were in both sets.

```Python
set1 = {'a', 'b', 'c', 'e'}
set2 = {'a', 'b', 'c', 'd'}

print(set1.intersection(set2))
```

### _.instersection\_update()_
Compares two sets and removes the elements from the first set that weren't in both sets

```Python
set1 = {'a', 'b', 'c', 'e'}
set2 = {'a', 'b', 'c', 'd'}

set1.intersection_update(set2)
```

### _.isdisjoint()_
Returns _True_ if there are no common elements between the sets.

```Python
set1 = {'a', 'b', 'c', 'e'}
set2 = {'a', 'b', 'c', 'd'}

# Check if disjoint
if set1.isdisjoint(set2): # False, 'a', 'b', and 'c' and in common
    print("There are no common elements between the sets")
```

### _.issubset()_
Returns _True_ if the first set is a subset of the second.

```Python
set1 = {'a', 'b', 'c', 'e'}
set2 = {'a', 'b', 'c'}

# Check if set2 is subset of set1
if set2.issubset(set1):  # True
    print("Set2 is a subset of set1")
```

### _.issuperset()_
Returns _True_ if the 

```Python
set1 = {'a', 'b', 'c', 'e'}
set2 = {'a', 'b', 'c'}

# Check if set1 is a superset of set2
if set1.issuperset(set2):  # True
    print("set1 is a superset of set2")
```

### _.symmetric\_difference()_
Return a new set that contains the elements that the sets did not have in common.

```Python
set1 = {'a', 'b', 'c', 'e'}
set2 = {'a', 'b', 'c', 'd'}

print(set1.symmetric_difference(set2))  # {'e', 'd'}
```

### _.symmetric\_difference\_update()_
Overwrites the first set to contain the elements that the sets did not have in common.

```Python
set1 = {'a', 'b', 'c', 'e'}
set2 = {'a', 'b', 'c', 'd'}

# Before
print(set1)

# Overwrite
set1.symmetric_difference_update(set2)

# After
print(set1)  # {'e', 'd'}
```

### _.union()_
Returns a new set that contains all the elements from both sets (excluding duplicates)

```Python
set1 = {'a', 'b', 'c'}
set2 = {'x', 'y', 'z'}

print(set1.union(set2))
```

## Miscellaneous

### _.copy()_
Returns a new set that is a copy of the original set. <br />
If you do not use _.copy()_ when assigning one set to another, they will both be aliases for the same set.

```Python
original = {1, 2, 3}

# Properly copy the set
copy = original.copy()
```
