# Classes in Python
A class is essentially a user-defined datatype that serves as a collection of data. 
Classes are meant to mimic some concrete object or abstract idea. For example, a class 'Location' would contain two floats to represent its x and y coordinates.
These two variables together would allow us to create a single variable of type 'Location' that would have both of these properties. In addition to storing data (state), 
classes can have functions (called methods), which allow to class to perform actions (modify state via behavior). These actions don't have to affect other data outside 
the class; in fact, many methods are entirely internal. A class function (method) 'coords' could be as simple as returning the coordinates of the location.

### Format
```Python
class ClassName:
    pass
```
> Replace _pass_ with the body of the class.

### Example
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

## Constructors: _\_\_init\_\_()_
