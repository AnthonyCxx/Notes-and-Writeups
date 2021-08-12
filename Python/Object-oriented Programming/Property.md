# Properties in Python
I'm sure you're familar with [getter and setter methods](https://www.geeksforgeeks.org/getter-and-setter-in-python/), which allow you to more clearly regulate how a 
class or instance attribute (a variable) can be updated or retrieved — if at all. The [_property()_](https://www.geeksforgeeks.org/python-property-function/) function
(and by extend, the `@property` decorator) allow you to write a method that can be accessed like an attribute (without the parentheses of a method). These properties 
can have getter and setter functions easily added to them; the benefit of using properties is that getter and setter methods that utilize properties will be automatically
called whenever you access/set the property so you can write `print(class.x)` and `class.x = y` instead of `print(class.get_x())` and `class.set_x(y)`. Properties make things
simple.

## Properties with _@property_


```Python

```

## Getters and Setters

```Python

```
