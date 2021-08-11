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
Python has two dunder methods for creating a string representation of a class: _\_\_str()\_\__ and _\_\_repr()\_\__. I've linked an article below for more detail,
but the long and short of it is that _\_\_str()\_\__ is for the end-user and _\_\_repr()\_\__ (the interal representation of the object) is for the developer. If you 
printed a list, you would favor `print(', '.join(list))` over `print(list)`, no? Well that's the difference between _\_\_str()\_\__ and _\_\_repr()\_\__.

If you overload both _\_\_str()\_\__ and _\_\_repr()\_\__, then Python will favor _\_\_str()\_\__ when printing the object (for obvious reasons). If you want the result
of _\_\_repr()\_\__, then use then [_repr()_](https://www.programiz.com/python-programming/methods/built-in/repr) function.

Reference: [_When should I use \_\_str()\_\_ over \_\_repr()\_\_?_](https://stackoverflow.com/questions/1436703/what-is-the-difference-between-str-and-repr)

```Python
class Class:
    def __str__(self):
        return "This is the __str__ representation"
        
    def __repr__(self):
        return "This is the __repr__ representation"
     
# // DRIVER CODE // # 
def main():
    x = Class()
    print(x)    # <== Calls '__str__' since it takes precedence
    
main()
```
> P.S. The return value of both functions must be strings.

## Getting length with _\_\_len()\_\__
_\_\_len()\_\__ defines the result of the _\_\_len()\_\__ function.

```Python
class ListWrapper:
    data = [1, 2, 3, 4, 5, 6, 7]   # <== Class attribute (not instance)
    
    # len() Overload
    def __len__(self):
        return len(self.data)
      
# // DRIVER CODE // #
def main():
    lst = ListWrapper()
    print(f"The data is {len(lst)} elements long...")
    
main()
```

## Overloading the \[ \] Operator
The _\_\_getitem()\_\__, _\_\_setitem()\_\__, and _\_\_delitem()\_\__  methods allow you to access a class via the operator \[ \]. _\_\_getitem()\_\__ allows you to retrieve elements like 
`print(chest[0])`,  _\_\_setitem()\_\__ allows you to assign to elements like `chest[0] = value`, and  _\_\_delitem()\_\__ allows you to delete items by index or value (depending
on how you program it; here, I chose index).

Overloading the \[ \] opreator can be useful for accessing for accessing many different types of data: strings, lists, tuples, dictionaries...
```Python
class Chest:
    def __init__(self, *items: str): # 'items' should be any amount of strings)
        self.items = list(items)     # Change the passed tuple of arguments into a list
    
    # [] Overload (get items)
    def __getitem__(self, index):
        try:
            return self.items[index]
        except IndexError:
            return None
    
    # [] Overload (set items)
    def __setitem__(self, index, item):
        try:
            self.items[index] = item 
        except IndexError:
            pass
        
    # [] Overload (delete items by index)
    def __delitem__(self, index):
        if (index >= 0 and index < len(self.items)):
            del self.items[index]
        else:
            raise IndexError("index out of range")
    
    def __str__(self):
        return ", ".join(self.items)
     
# // DRIVER CODE // # 
def main():
    chest = Chest("pencil", "paper", "eraser")
    
    # Print the items in the chest (calls __str__)
    print(chest) # pencil, paper, eraser
    
    # Get the first item (calls __getitem__)
    print(f"The first item in the chest: {chest[0]=}") # chest[0]='pencil'
    
    # Change the value of the first item (calls __setitem__)
    chest[0] = "book"
    
    # Deleting the second item
    del chest[1]
    
    # Print the items in the chest (calls __str__)
    print(chest) # book, eraser
    
main()
```
