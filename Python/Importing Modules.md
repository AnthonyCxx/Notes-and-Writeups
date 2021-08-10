# Importing Files and Modules in Python
All references to contents from other files must be prefixed with the name of the file followed by a dot (e.g. `filename.function()`) <br />

You can import anything with an identifier from a file: variables, classes, functions...

## Importing Modules
Importing native modules (from the Python standard library) is

```Python
import datetime
```

## Importing User-made Modules

```Python
import filename

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
