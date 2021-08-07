# Lists in Python
> Jump: <br />
> [Rundown on Lists](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Python/Data%20and%20Datatypes/lists.md#rundown-on-lists) <br />
> [List Methods](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Python/Data%20and%20Datatypes/lists.md#list-methods) <br />
> [List Comprehension](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Python/Data%20and%20Datatypes/lists.md#list-comprehension) <br />

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
_.index()_ returns the index of the first occurance of the given value. <br />
You can provide a start and end index after the value; if you have an end index, you must have a start index.

```Python
# Declare a new list of 4 integers
numbers = [1, 2, 4, 5, 4]

# Find the first index of the int '4' (which is 2)
print(f"The first index of the integer '4' is: {numbers.index(4)}")
```

### _.pop()_
_.pop()_ removes and returns an element. If not specified, it will remove and return the last element.

```Python
# Declare a list of 5 integers
numbers = [1, 2, 3, 4, 5]

# Remove and return the last element
last_element = numbers.pop()

# Remove and return the second element (index = 1)
second_element = numbers.pop(1)

# Show the values of the popped elements
print(f"The value of the second element was {second_element} and the value of the last element was {last_element}")

# Show the popped elements were removed from the list
print(numbers)
```

### _.remove()_
_.remove()_ removes the first occurance of the given value.

```Python
# Declare a list of 6 integers
numbers = [1, 2, 3, 4, 5, 4]

# Remove the first occurance of '4'
numbers.remove(4)

# Show the first occurance of '4' was removed
print(numbers)
```

### _.reverse()_
_.reverse()_ reverses the order of a list.

```Python
# Declare an array of 5 integers
numbers = [1, 2, 3, 4, 5]

# Reverse the list
numbers.reverse()

# Show the reversal
print(numbers)
```

### _.sort()_
_.sort()_ sorts a list from least to greatest using a given function as a key. If no function is given, it will sort the list alphabetically or by value <br />
You can also sort in reverse order by setting _reverse_ equal to _True_.

```Python
# Declare a list of 5 names
numbers = ["Harold", "Charlotte", "The entire country of Luxembourg", "My friend's rat, Hamster"]

# Sort the list
numbers.sort(key=len, reverse=True)  # Sort by the 'len()' function in reverse order (longest name -> shortest)

# Show the sorted list
print(numbers)
```

# List Comprehension
[List Comprehension](https://www.tutorialsteacher.com/python/python-list-comprehension) is a succinct method of creating a list. Typically, you have to write a verbose
for-loop to create a list automatically, and it gets even more complex if you want to add an if statement. List comprehension allows you to do all of that in one line: <br />
`numbers = [element for element in range(100)]`. The first _element_ is the item being appended to the list and the second _element_ represents that variable in the for-loop.
 In this case, _element_ and _element_ are the same; however, if you were to apply a function or some sort of conditional, then they would be different.

```Python
# List Comprehension over a for a Range
list_of_100 = [i for i in range(100)]  # Create a list of the integers 1-100

# Applying Functions to each element in the collection
uppercase_words = ["THIS IS A SENTENCE", "Hmmm, AngRy...", "I am NOT upset"]
lowercase_words = [word.lower() for word in uppercase_words]  # Now '.lower()' has been applied to each element in 'uppercase_words'

# Applying Conditionals to a collection
all_numbers = [i for i in range(100)]    # The numbers 1-100
even_numbers = [num for num in all_numbers if num % 2 == 0]  # Only copy numbers that are even (where '% 2 == 0' is True)

# Altering the result and applying conditionals
even_div_by_4 = [num / 4 for num in all_numbers if num % 2 == 0] # Add all even numbers to the list, but divide them by 4 before appending
```
