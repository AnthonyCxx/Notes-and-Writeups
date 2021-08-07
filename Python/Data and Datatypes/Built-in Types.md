# Built-in Types in Python

## String Type, _str_

## Boolean Type, _bool_
Booleans can either be _True_ or _False_ (mind the capital letter) and are used in control flow statements and loops (_if_, _while_, etc.).
Datatypes are [implicitly boolean](http://anh.cs.luc.edu/handsonPythonTutorial/boolean.html) are can be used as bools;
All numeric types are false when 0 and true otherwise, containers are false when empty (strings, lists, sets, etc.) and true otherwise, and _None_ is always false.
```Python
if True:
    print("Hello, World!")

name = ""

# If name is empty...
if not name:
    print("Hmm, you have to enter something for your name...")
```

### Operators
Booleans have three operators associated with them: _and_, _or_ and _not_ (see [logical operators](https://www.w3schools.com/python/python_operators.asp)). <br />
These operators can be used to modify and/or chain conditionals like `if condition1 and not condition2:`.

## _None_
The [_None_](https://www.w3schools.com/python/ref_keyword_none.asp) type is the Python equivalent of [NULL](https://www.thoughtco.com/definition-of-null-958118#:~:text=Null%20is%20a%20built%2Din,pattern%20for%20a%20null%20pointer.). Since variables cannot be defined without being initialized, you can use _None_
to declare a variable for later use.

When checking for _None_, always use the [_is_](https://realpython.com/courses/python-is-identity-vs-equality/) operator and not _==_ ([PEP-8](https://www.python.org/dev/peps/pep-0008/#programming-recommendations))

```Python
variable = None

if variable is None:
    print("Hmm... this variable hasn't been initialized...")
```

## Sources
Python 3.9.6 Documentation: [_Built-in Types_](https://docs.python.org/3/library/stdtypes.html) <br />
