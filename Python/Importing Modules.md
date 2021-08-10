# Importing Files and Modules in Python
All references to contents from other files must be prefixed with the name of the file followed by a dot (e.g. `filename.function()`) <br />
You can import anything with an identifier from a file: variables, classes, functions...

[Definitive Guide to Python's _import_ Statement](https://chrisyeh96.github.io/2017/08/08/definitive-guide-python-imports.html) <br />

## Importing Modules
Importing native modules (from [the Python standard library](https://docs.python.org/3/py-modindex.html)) is as simple. Just write _import_ followed by the module name.

```Python
import datetime
```

## Importing User-made Modules
The only catch here is that the files must be in the same folder.

```Python
import filename     # or 'from . import filename'

# Reference contents from the file 'filename'
filename.function()
```
> This assumes

## Importing Specific Objects from a File

```Python
from filename import something

# Don't need the 'filename.' prefix anymore...
something()
```
