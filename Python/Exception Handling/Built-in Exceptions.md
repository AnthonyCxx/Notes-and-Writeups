# Built-in Exception in Python
Here are some common exceptions that are built into Python.

Don't expect this to be comprehensive, because it isn't. Reference Python's documentation, [_Built-in Exceptions_](https://docs.python.org/3/library/exceptions.html#built-in-exceptions), for a master reference.

## Exception
_Exception_ is the parent exception of all exceptions. Catching _Exception_ will catch any and all errors.

```Python
try:
    num = 0 / 0
except Exception:
    print("Caught an error")
```

## IndexError
An _IndexError_ occurs when you try to access an index that does not exist.

```Python
numbers = [1, 2, 3, 4, 5]

# Error, index '999' does not exist
print(numbers[999])
```

## KeyError
A _KeyError_ is thrown when you access a value with a key that does not exist.

```Python
heights = {"Harold":"5' 7", "Marissa":"5' 9", "Taylor":"6' 0"}

# Error, 'Lauren' does not exist in the dictionary
print(heights["Lauren"])
```

## AttributeError
An _AttributeError_ is thrown when you access an attribute of a class that does not exist. <br />
Abstract base classes help avoid this problem.

```Python
class DummyClass:
    pass

dummy = DummyClass()
print(dummy.this_property_does_not_exist)
```

## ValueError
Raised when an operation is performed on a valid type but an invalid value (like a negative square root). <br />
If the operation is performed on an invalid type (like the square root of "dog"), then a _TypeError_ will be thrown instead.

```Python
import math

# Illegal, square roots are undefined for negative numbers
print(math.sqrt(-10))
```

## TypeError
Raised when an operation is performed on a type/types that do not have a definition for said operation. <br />
If you create a type and perform an operation on it without implemented the right dunder method, you will get a _TypeError_.

```Python
import math

print(math.sqrt("dog"))
```
