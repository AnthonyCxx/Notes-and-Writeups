# Properties in Python
I'm sure you're familar with [getter and setter methods](https://www.geeksforgeeks.org/getter-and-setter-in-python/), which allow you to more clearly regulate how a 
class or instance attribute (a variable) can be updated or retrieved — if at all. The [_property()_](https://www.geeksforgeeks.org/python-property-function/) function
(and by extend, the `@property` decorator) allow you to write a method that can be accessed like an attribute (without the parentheses of a method). These properties 
can have getter and setter functions easily added to them; the benefit of using properties is that getter and setter methods that utilize properties will be implicitly
called whenever you access/set the property so you can write `print(class.x)` and `class.x = y` instead of `print(class.get_x())` and `class.set_x(y)`. <br />
Properties make things simple.

The examples used here are a simplified version of the one in Corey Schafer's [Python OOP Tutorial 6: Property Decorators - Getters, Setters, and Deleters](https://www.youtube.com/watch?v=jCzT9XFZ5bw).

## Properties with _@property_
To declare a property, write a method and tag it with the `@property` decorator.

The method tagged with `@property` will act as the getter method.
```Python

```

## Setters

```Python

```

## Deleters
