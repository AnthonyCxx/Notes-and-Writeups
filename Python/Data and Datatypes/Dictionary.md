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

### _.copy()_
_.copy()_ returns a new dictionary that is a copy of the original dictionary. <br />
The _.copy()_ method should be used over raw assignment `= some_dictionary` because raw assignment just creates an alias of the same dictionary.

```Python
# Initializing a Dictionary
ages = {"Harold":47, "Charlie":21, "Sun Tzu":2570}   # key:value

# Creating a copy of a dictionary
copy_dict = ages.copy()
```

### _.clear()_

```Python

```

### _.pop()_

```Python

```

### _.popitem()_

```Python

```

### _.str()_

```Python

```

### _.get()_

```Python

```

### _.update()_

```Python

```

### _.setdefault()_

```Python

```

### _.has\_key()_

```Python

```

### _.fromkeys()_

```Python

```
