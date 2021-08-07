# Lists in Python
Lists are dynamic arrays that can store any number of elements of any type (including different datatypes). <br />
Lists are denoted with brackets (\[ \]) and comma-separated elements (in declarations and throughout Python) <br />
Like arrays, lists can be accessed with brackets (e.g. `somelist[0]`) and manipulated via [splicing](https://www.geeksforgeeks.org/python-list-slicing/). <br />

## Rundown on Lists
```Python

''' CREATING LISTS '''
# Default constructor (creates a blank list)
blank_list = list()

# Initialized List
names = ["Harold", "Steve", "Charlotte", "Harley"]

# Create a copy of the list 'names'
'''Copying is important because direct assignment just creates an alias'''
copy_list = names.copy()


''' ACCESSING LISTS '''
# Accessing a single element in a list
print("The first name in the list is: ", names[0])  # The first item in a list is 0

# Accessing multiple elements (splicing)
print("The first three elements in the list are: ", names[0:3])   # Stop before index 3 (not grab 3 elements)

''' ALTERING LISTS '''
# Add a new element
names.append("Charlie")

# Change an element
names[0] = "Bridgitte"

# Remove a Specific Element (by content)
names.remove("Charlotte")

# Remove a Specific Element (by index)
del names[0]

# Remove all elements
names.clear()

# Append a collection (like a list)
newlist = ["Bekah", "Jeremey", "Wesley", "Savannah", "Steve"]
names.extend(newlist)

''' ITERATION AND MEMBERSHIP '''
# Iterating over the list
for name in names:
    print(name)

# Checking Members
if "Steve" in names:
    print("Steve is here!")
else:
    print("Steve is absent :(!")
```

# List Methods

## Inserting Elements

### _.append()_
_.append()_ appends an element to the end of a list.

```Python
# Declare a list of 4 integers
numbers = [10, 20, 30, 40]

# Append the number '50' to the end
numbers.append(50)

# Print the new list
print(numbers)  # numbers = [10, 20, 30, 40, 50]
```

### _.extend()_
_.extend()_ appends a collection of elements (like another list or a set).

```Python
list_one = [10, 20, 30, 40, 50]
list_two = [60, 70, 80, 90, 100]

# Append list_two to list_one
list_one.extend(list_two)

# Print list_one
print(list_one)  # list_one = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
```

### _.insert()_
_.insert()_ allows you to insert items at a specific index.

```Python
# Declare a new list of 4 integers
numbers = [1, 2, 4, 5]

# Insert the word "three" at index 2
numbers.insert(2, "three")

# Print the list
print(numbers)  # numbers = [1, 2, "three", 4, 5]
```

### _.clear()_
_.clear()_ removes all the elements from a list.

```Python
# Declare a list of 4 integers
numbers = [10, 20, 30, 40]

# Append the number '50' to the end
numbers.append(50)

# Print the new list
print(numbers)  # numbers = []

```

### _.copy()_
Copy returns a new list that is an exact copy of the list that called _.copy()_. <br />
_.copy()_ is necessary because direct assignment (e.g. `some_list = some_other_list`) just makes an alias of the other list.

```Python
# Declare a list of 5 integers
numbers = [10, 20, 30, 40, 50]

# Create a copy of the list 'numbers'
copy_list = numbers.copy()

# Delete the first element of the new list
del copy_list[0]

# Show that the original list is unaffected
print(numbers)
```

### _.count()_
_.count()_ returns the amount of instances of the given element in the list.

```Python
# Declare a new list of scores
test_scores = [90, 80, 85, 47, 95, 90, 100, 13, -12, -9999, 90]

# Find the amount of students that scored a 90 ('test_scores.count(90)')
print(f"A total of {test_scores.count(90)} scored a 90 on the test")
```

### _.index()_
_.index()_ returns the index of the first occurance of the given value.

```Python
# Declare a new list of 4 integers
numbers = [1, 2, 4, 5, 4]

# Find the first index of the int '4' (which is 2)
print(f"The first index of the integer '4' is: {numbers.index(4)}")
```

### _.pop()_

```Python

```

### _.remove()_
```Python

```

### _.reverse()_
```Python

```

### _.sort()_

```Python

```

# List Comprehension
[List Comprehension](https://www.tutorialsteacher.com/python/python-list-comprehension) is a succinct method of creating a list.
