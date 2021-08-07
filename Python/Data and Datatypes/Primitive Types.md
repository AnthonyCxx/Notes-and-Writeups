# Primitive Types in Python

## String Type, _str_
Strings are the heart of Python and easily the most-used type. In fact, strings are so prevalent in Python that all input is read in as a string.

```Python
name = input("Enter your name: ")

print("Your name is: " + name)
```

### Important Notes
- Unlike most languages (like C++), strings can use single or double quotation marks (' ' or " ") since there is no _char_ datatype in Python.
- Multi-lined strings can be initialized by using triple-quotation marks (''' ''' or """ """), just like multi-line comments can.
- [Strings are immutable](https://docs.python.org/3/faq/design.html#why-are-python-strings-immutable) in Python (for security's sake), so altering them frequently may be slow.

## Numeric Type, _int_
Python doesn't differentiate between different types of integers like _short_ and _unsigned long long_. All integers have the range of a _signed long long_ (-9 quintillion -
through 9 quintillion), so don't worry about going out of range.

```Python
num1 = 10
num2 = 20

print(num1 + num2)
```

## Numeric Type, _float_
_floats_ or [floating-point numbers](https://floating-point-gui.de/formats/fp/) are a numeric datatype that can represent numbers with decimals. Anything beyond 
the max/min value of a float (1.8x10^308) will be represented by [infinity](https://www.geeksforgeeks.org/python-infinity/) (inf/-inf).

```Python
pi = 3.1459265

print("The value of PI is: ", pi)

if pi < float("inf") and pi > float("-inf"):  #True
    print("Pi is a non-infinite number")
```

## Numeric Type, _complex_
The _complex_ type supports [complex numbers](https://mathworld.wolfram.com/ComplexNumber.html). You can performs most arithmetic operations on complex types,
but some operators like _floor()_ and _pow()_ will throw an exception if you try to use them.

Note: technically, _complex_ isn't a primitive type, but it fits here better than with lists, dictionaries, and such.
```Python
num1 = 10 + 5j
num2 = 5 + 10j

#Uses a formatted string
print(f"10 + 5j + 5 + 10j = {num1 + num2}")
```

## Boolean Type, _bool_
Booleans can either be _True_ or _False_ (mind the capital letter) and are used in control flow statements and loops (_if_, _while_, etc.).
Datatypes are [implicitly boolean](http://anh.cs.luc.edu/handsonPythonTutorial/boolean.html) are can be used as bools;
All numeric types are false when 0 and true otherwise, containers are false when empty (strings, lists, sets, etc.) and true otherwise, and _None_ is always false.
```Python
if True:
    print("Hello, World!")

firstname = ""
lastname = ""

# If name is empty...
if not firstname or not lastname:
    print("Hmm, you have to have both a lastname and a firstname...")
```

### Operators
Booleans have three operators associated with them: _and_, _or_ and _not_ (see [logical operators](https://www.w3schools.com/python/python_operators.asp)). <br />
These operators can be used to modify and/or chain conditionals like `if condition1 and not condition2:`.

## _None_
The [_None_](https://www.w3schools.com/python/ref_keyword_none.asp) type is the Python equivalent of [NULL](https://www.thoughtco.com/definition-of-null-958118#:~:text=Null%20is%20a%20built%2Din,pattern%20for%20a%20null%20pointer.). Since variables cannot be defined without being initialized, you can use _None_
to declare a variable for later use (assuming you don't want to give it a specific type with a constructor like _str()_ or _bool()_).

When checking for _None_, always use the [_is_](https://realpython.com/courses/python-is-identity-vs-equality/) operator and not _==_ ([PEP-8 Python Style Guide](https://www.python.org/dev/peps/pep-0008/#programming-recommendations))

```Python
variable = None

if variable is None:
    print("Hmm... this variable hasn't been initialized...")
```

## Sources
Python 3.9.6 Documentation: [_Built-in Types_](https://docs.python.org/3/library/stdtypes.html) <br />
W3Schools: [_Built-in Data Types_](https://www.w3schools.com/python/python_datatypes.asp) <br />
RealPython: [_Basic Data Types in Python_](https://realpython.com/python-data-types/) <br />
