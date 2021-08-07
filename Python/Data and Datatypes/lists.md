# Lists in Python
Lists are dynamic arrays that can store any number of elements of any type (including different datatypes). <br />
Lists are denoted with brackets (\[ \]) and comma-separated elements (in declarations and throughout Python) <br />
Like arrays, lists can be accessed with brackets (e.g. `somelist[0]`) and manipulated via [splicing](https://www.geeksforgeeks.org/python-list-slicing/). <br />

## Declaring a List and Simple Operations
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

''' ITERATION AND MEMBERSHIP '''
# Iterating over the list
for name in names:
    print(name)

# Checking Members
if "Steve" in names:
    print("Steve is here!")
```

# List Methods

## _.append()_

## _.clear()_

## _.copy()_

## _.count()_

## _.extend()_

## _.index()_

## _.pop()_

## _.remove()_

## _.reverse()_

## _.sort()_

## List Comprehension
