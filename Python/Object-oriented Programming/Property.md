# Properties in Python
I'm sure you're familar with [getter and setter methods](https://www.geeksforgeeks.org/getter-and-setter-in-python/), which allow you to more clearly regulate how a 
class or instance attribute (a variable) can be updated or retrieved — if at all. The [_property()_](https://www.geeksforgeeks.org/python-property-function/) function
(and by extend, the `@property` [decorator](https://realpython.com/primer-on-python-decorators/)) allow you to write a method that can be accessed like an attribute (without the parentheses of a method). These properties 
can have getter and setter functions easily added to them; the benefit of using properties is that getter and setter methods that utilize properties will be implicitly
called whenever you access/set the property so you can write `print(class.x)` and `class.x = y` instead of `print(class.get_x())` and `class.set_x(y)`. <br />
Properties make things simple.

The examples used here are a simplified version of the one in Corey Schafer's [Property Decorators - Getters, Setters, and Deleters](https://www.youtube.com/watch?v=jCzT9XFZ5bw).

## Properties with _@property_
To declare a property, write a method and tag it with the `@property` decorator.

The method tagged with `@property` will act as the getter method.
```Python
class Person:
    def __init__(self, first: str, last: str):
        self.first = first
        self.last = last
        
    # 'fullname' acts as the get method
    @property
    def fullname(self):
        return f"{self.first} {self.last}"
        
def main():
    person = Person("Michael", "Bennet")  # A random name
    
    # Notice how 'fullname' is called like a data member, not a method
    print(person.fullname)
    
main()
```

## Setters
To write a setter, write a new method with the same name as the original property (the get method) and tag it with `property_name.setter`. <br />
Here, I am writing a setter for _fullname_ so I have a setter function _fullname_ tagged `@fullname.setter`.

Setters will be automatically called when you try to assign to a property like `class.property = something`.
```Python
class Person:
    def __init__(self, first: str, last: str):
        self.first = first
        self.last = last
        
    # 'fullname' acts as the get method
    @property
    def fullname(self):
        return f"{self.first} {self.last}"
        
    @fullname.setter
    def fullname(self, fullname):
        self.first, self.last = fullname.split(' ')
        
def main():
    person = Person("Michael", "Bennet")  # A random name
    
    # Get the person's full name (calls fullname())
    print(person.fullname)
    
    # Update the person's first and last name in one go (calls fullname.setter)
    person.fullname = "Leah Stuart"
    print(person.fullname)
    
main()
```

## Deleters
Deleters are automatically called when you delete a property like `del class.some_property`. <br />
You write a deleter the same way you write a setter, but replace the tag with `@property_name.deleter`.

```Python
class Person:
    def __init__(self, first: str, last: str):
        self.first = first
        self.last = last
        
    # 'fullname' acts as the get method
    @property
    def fullname(self):
        return f"{self.first} {self.last}"
        
    @fullname.setter
    def fullname(self, fullname):
        self.first, self.last = fullname.split(' ')
        
    @fullname.deleter
    def fullname(self):
        self.first = self.last = None  # Set both first and last name to None
        
def main():
    person = Person("Michael", "Bennet")  # A random name
    
    # Get the person's full name (calls fullname())
    print(person.fullname)
    
    # Update the person's first and last name in one go (calls fullname.setter)
    person.fullname = "Leah Stuart"
    print(person.fullname)
    
    # Delete the person's fullname
    del person.fullname
    print(person.fullname)
    
main()
```
