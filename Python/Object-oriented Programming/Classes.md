# Classes in Python
A class is essentially a user-defined datatype that serves as a collection of data. 
Classes are meant to mimic some concrete object or abstract idea. For example, a class 'Location' would contain two floats to represent its x and y coordinates.
These two variables together would allow us to create a single variable of type 'Location' that would have both of these properties. In addition to storing data (state), 
classes can have functions (called methods), which allow to class to perform actions (modify state via behavior). These actions don't have to affect other data outside 
the class; in fact, many methods are entirely internal. A class function (method) 'coords' could be as simple as returning the coordinates of the location.

**NOTE**: All references to members of a class (both data members and methods) must be prefixed with [_self_](https://www.programiz.com/article/python-self-why) (e.g. `self.x`).
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

## Class Attributes
When a variable is declared normally (i.e. without the _self_ keyword) like `name = "Deathstroke"`, then that variable is shared across all instances of the class.
Class attributes can and can't be compared to [_static_ class members](https://www.tutorialspoint.com/cplusplus/cpp_static_members.htm) in languages like C++, depending
on what you mean. Like _static_ class members, class attributes can modify all instances of the class by assigning to the class attribute of the class itself instead of 
just an instance. All that means is that if you had a class '_Location_' that had a class attribute '_address_', you could directly affect all _Location_ objects by assigning
to `Location.address`. However, you could choose to only affect one instance of an object by assigning to that object like `object.address = "something"`.

```Python
class Location:
    address = "Unknown"   # <== Class attribute
    
    # Constructor
    def __init__(self, x, y): 
        self.x = x     # <== Instance attribute
        self.y = y     # <== Instance attribute
    
    # Method: returns coordinates
    def coords(self):
        return str(self.x) + ", " + str(self.y)

# // DRIVER CODE //
def main():
    home = Location(10, -50)
    school = Location(30, 30)
    
    print(home.address)
    print(school.address)
    
    # Change the name of the location for ALL instances of the 'Location' class
    Location.address = "221B Baker St."
    
    print(home.address)
    print(school.address)
    
main()
```

## Instance Attributes
Instance attributes are class members that are tied to the individual instances of a class. You can try to affect all instances of the class like you can with
class attributes, but it won't do anything. Instance members are typically declared in and initialized by the  _\_\_init()\_\__ function, which is the special name of
the constructor in Python.

```Python
class Location:
    address = "Unknown"   # <== Class attribute
    
    # Constructor
    def __init__(self, x, y): 
        self.x = x     # <== Instance attribute
        self.y = y     # <== Instance attribute
    
    # Method: returns coordinates
    def coords(self):
        return str(self.x) + ", " + str(self.y)

# // DRIVER CODE //
def main():
    home = Location(10, -50)
    school = Location(30, 30)
    
    print(home.coords())
    print(school.coords())
    
    Location.x = 20   # <== Does nothing, 'x' is an instance attribute
    
    print(home.coords())
    print(school.coords())
    
main()
```

## 'Public' and '\_\_Private' Data Members
Python does not support [access modifiers](https://www.geeksforgeeks.org/access-modifiers-in-c/) through keywords like _public_ and _private_ like languages such as 
C++ or Java. Instead, accessability is determined by the syntax of the name. If the name of a class member (variables, functions, etc.) starts with two underscores 
like `__name`, then the member will be inaccessible outside of the class. If you try to reference a 'private' member, then you will get an [_AttributeError_](https://www.geeksforgeeks.org/python-attributeerror/).

```Python
class Container:
    __number = 5   # <== Private class attribute
    
    def __function(self):
        print("This is a private function")
  
def main():  
    num = Container()

    #print(num.__number)   <== Illegal, '__number' is private
    #num.__function()      <== Illegal, '__function()' is private

main()
```

## Constructors: _\_\_init\_\__
The  _\_\_init\_\__ method is a special method called a [constructor](https://www.geeksforgeeks.org/constructors-in-python/). In most languages, constructors
only initialize variables; however, in Python variables are declared by assigning them a value (even with it's with a default constructor or _None_). So, in Python 
constructors declare the data members of a class and initialize them too.

The two underscores before and after the function name indicate that it is a [dunder method](https://www.geeksforgeeks.org/dunder-magic-methods-python/) (colloquially called
magic methods).

## Methods
Methods are functions that are specific to a class. In Python, all methods (including _\_\_init\_\__) must take [_self_](https://www.programiz.com/article/python-self-why) 
as their first parameter (even if they have none). This is because Python favors being explicit and the stark division between what is and is not a part of the class is helpful.

## Destructors: _\_\_del\_\__
