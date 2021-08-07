# Built-in Types in Python

## String Type, _str_
Strings are the heart of Python

## Numeric Types: _int_, _float_, and _complex_

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
to declare a variable for later use (assuming you don't want to give it a specific constructor like _str()_ or _bool()_).

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
