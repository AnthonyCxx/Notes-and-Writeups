# Static and Class Methods in Python
Think of static and class methods like class attributes: they are a member of a class but not bound to any particular instance of said class. <br />
Static and class methods are denoted by the `@staticmethod` and `@classmethod` [decorators](https://realpython.com/primer-on-python-decorators/#simple-decorators) respectively.

## Static Methods
Static methods are a method of a class that can be called without needing an instance of the class like `Class.method()`. However, as consequence, they do not have _any_ access
to the members (data members or function members) of the class. The benefit of static members is organization; a utility-based class (like a temperature converter) may be 
entirely composed of static methods.

## Class Methods
