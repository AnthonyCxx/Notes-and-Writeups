# Dunder Methods in Python
Dunder methods (_dunder_ == 'double underscore') are special methods that can be used to enhance your classes. Dunder methods are prefix and postfixed by two underscores
and their functionality covers everything from constructors to operator overloading.

If you're looking for operator overloading, [click here](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Python/Object-oriented%20Programming/Operator%20Overloading.md).

## Creation and Initialization
The following methods are run automatically when an object is created.

Reference: [_How is \_\_new()\_\_ different from \_\_init()\_\_?_](https://dev.to/pila/constructors-in-python-init-vs-new-2f9j)

| Dunder Method | Run when | Used for | 
| ------------- | -------- | -------- |
| _\_\_new()\_\__ | object is created | customize the object creation |
| _\_\_init()\_\__ | object is created | initialize the object's data members |
> Reference: [_When should I use \_\_new()\_\_?_](https://howto.lintel.in/python-__new__-magic-method-explained/)

## String Representation
Python has two dunder methods for creating a string representation of a class: _\_\_str()\_\__ and _\_\_repr()\_\__

Reference: [_When should I use \_\_str()\_\_ over \_\_repr()\_\_?_](https://stackoverflow.com/questions/1436703/what-is-the-difference-between-str-and-repr)
