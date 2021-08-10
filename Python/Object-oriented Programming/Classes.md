# Classes in Python
A class is essentially a user-defined datatype that serves as a collection of data. 
Classes are meant to mimic some concrete object or abstract idea. For example, a class 'Location' would contain two floats to represent its x and y coordinates.
These two variables together would allow us to create a single variable of type 'Location' that would have both of these properties. In addition to storing data (state), 
classes can have functions (called methods), which allow to class to perform actions (modify state via behavior). These actions don't have to affect other data outside 
the class; in fact, many methods are entirely internal. A class function (method) 'coords' could be as simple as returning the coordinates of the location.

**NOTE**: All references to members of a class (both data members and methods) must be prefixed with _self_ (e.g. `self.x`).
### Format
```Python
class ClassName:
    pass
```
> Replace _pass_ with the body of the class.

### Example
For more on the _\_\_init\_\__ method, see the next section.

```Python
class Location:
    
    # Constructor
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    # Method: returns coordinates
    def coords(self):
        return str(self.x) + ", " + str(self.y)

# // DRIVER CODE //
def main():
    home = Location(10, -50)
    print(f"The house is located at: {home.coords()}")

main()
```

## Constructors: _\_\_init\_\__
The  _\_\_init\_\__ method is a special method called a [constructor](https://www.geeksforgeeks.org/constructors-in-python/). In most languages, constructors
only initialize variables; however, in Python variables are declared by assigning them a value (even with it's with a default constructor or _None_). So, in Python 
constructors declare the data members of a class and initialize them too.

The two underscores before and after the function name indicate that it is a [dunder method](https://www.geeksforgeeks.org/dunder-magic-methods-python/) (colloquially called
magic methods).
