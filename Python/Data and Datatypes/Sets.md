# Sets and Frozen Sets in Python
A set is a mutable, ordered collection of unique elements.

## Sets by Example

```Python
''' CREATING SETS '''
# Default Constructor
default_set = set()

# Initializing a Set
init_set = set((1, 2, 2, 3))  # <== Wrap all elements in '()' to make 1 argument
print(init_set)

# Create a copy of a set (just doing '= init_set' creates an alias, not a copy)
copy_set = init_set.copy()  # <== Avoids creating an alias
```

## Set Methods

A frozen set is just a set that is immutable.
