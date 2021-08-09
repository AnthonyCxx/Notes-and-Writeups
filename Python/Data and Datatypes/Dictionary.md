# Dictionaries in Python
Dictionaries are an associative array, allowing you to store pairs of keys and values like `dictionary[key] = value`. Whenever you access a dictionary with a key (like `dictionary[key]`), it will
return the value associated with the key.

## Dictionaries by Example

```Python
''' DECLARING A DICTIONARY '''
# Default Constructor
default_constructor = dict()
empty_dict = {}

# Initializing a Dictionary
ages = {"Harold":47, "Charlie":21, "Sun Tzu":2570}   # key:value

# Creating a copy of a dictionary
copy_dict = ages.copy()   # <== Needed because just '= ages' makes 'copy_dict' an alias of 'ages'

''' ACCESSING DICTIONARY MEMBERS '''
# Getting a value from a key
print(ages["Harold"])

''' MODIFYING DICTIONARIES'''
# Adding a new key/value pair
ages["Lord Harkon"] = 'Immortal'  # Doesn't have to be the same type
print(ages["Lord Harkon"])

# Editing an existing pair
ages["Lord Harkon"] = 1000

# Deleting a dictionary entry
del ages["Lord Harkon"]

# Delete an entire dictionary
ages.clear()     # <== Make this a comment when running...

''' ITERATING OVER DICTIONARIES '''
# Iterating over Keys
for key in ages.keys():
    print(key)

# Iterating over Values
for value in ages.values():
    print(value)

# Iterating over Keys and Values
for key, value in ages.items():
    print(key, ", ", value)
```

## Dictionary Methods

### _.keys()_
_.keys()_ returns a list containing the dictionary's keys.

```Python
ages = {"Harold":47, "Charlie":21, "Sun Tzu":2570} 

# Print all the keys in the dictionary
for key in ages.keys():
    print(key)
```

### _.values()_
_.values()_ returns a list containing the dictionary's values.

```Python
ages = {"Harold":47, "Charlie":21, "Sun Tzu":2570} 

# Print all the values in the dictionary
for value in ages.values():
    print(value)
```

### _.items()_
_.items()_ returns a list of lists, where each sublist is a keys/value pair.

```Python
ages = {"Harold":47, "Charlie":21, "Sun Tzu":2570} 

# Print all the key/value pairs in the dictionary
for key, value in ages.items():
    print(key, " : ", value)
```

### _.get()_
_.get()_ provides a safe way to access dictionary values. If the key/value pair does not exist for a given key, then
it will return none (unless you provide a different default value as a second argument).

```Python
ages = {"Harold":None, "Charlie":21, "Sun Tzu":2570} 

# Get potential result
result = ages.get("this key doesn't exist eigoaiegjoeiajg")

# Print result
if result is not None:   # If the result is good
    print(f"The result was: {result}")
else:
    print("The given key did not exist...")
```

### _.setdefault()_
Like, _.get()_, _.setdefault()_ provides a safe way to access dictionary values. <br />
If the given key does not exist, it creates the key/value pair. The default value is _None_.

```Python
ages = {"Harold":None, "Charlie":21, "Sun Tzu":2570} 

print(ages.setdefault("Homer", 39))   # "Homer":39 now exists
```

### _.update()_
_.update()_ allows you to copy the contents of a dictionary into another dictionary.
I made a morse code translator a while back and made three separate dictionaries for each of the sets (numbers, letters, symbols) and was able to use _.update()_
to create one master morse code dictionary from the three.

```Python
colors = {"Black":"#000000", "White":"#FFFFFF", "Grey":"#878788"}
primary_colors = {"Red":"#FF0400", "Yellow":"#FFF700", "Blue":"#0021FF "}

# Add 'primary_colors' to 'colors'
colors.update(**primary_colors)   # '**' unpacks the dictionary
print(colors)
```

### _.fromkeys()_
_.fromkeys()_ creates a dictionary from an iterable object like a range or a list. <br />
If you don't provide a default argument for each item in the dictionary, their value will be _None_.

```Python
numbers = dict.fromkeys(range(15))
print(numbers)
```

### _.copy()_
_.copy()_ returns a new dictionary that is a copy of the original dictionary.
The _.copy()_ method should be used over raw assignment `= some_dictionary` because raw assignment just creates an alias of the same dictionary.

```Python
# Initializing a Dictionary
ages = {"Harold":47, "Charlie":21, "Sun Tzu":2570}   # key:value

# Creating a copy of a dictionary
copy_dict = ages.copy()
```

### _.clear()_
_.clear()_ deletes all the elements of the dictionary.

```Python
ages = {"Harold":47, "Charlie":21, "Sun Tzu":2570} 

# Delete all pairs in the dictionary
ages.clear()

print(ages)
```

### _.pop()_
_.pop()_ removes and returns the value of the key provided as the argument. <br />
In case the key does not exist, you can provide a second argument as a default return value.

```Python
ages = {"Harold":47, "Charlie":21, "Sun Tzu":2570} 

# Remove and return the value of 'Harold'
print(ages.pop("Harold", "N/A"))
print(ages)
```

### _.popitem()_
Removes and returns the most recently inserted item as a tuple. <br />
If the dictionary is empty, an error will be thrown.

```Python
ages = {"Harold":47, "Charlie":21, "Sun Tzu":2570} 

# Remove and return the last key/value pair
print(ages.popitem())
print(ages)
```

