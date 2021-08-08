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
for key in ages.keys():
    print(ages[key])

# Iterating over Keys and Values
for key, value in ages.items():
    print(key, ", ", value)
```

## Dictionary Methods


