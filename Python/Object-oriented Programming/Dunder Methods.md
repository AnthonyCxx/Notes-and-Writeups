# Dunder Methods in Python
Dunder methods (_dunder_ == 'double underscore') are special methods that can be used to enhance your classes. Dunder methods are prefixed and postfixed by two underscores
and their functionality covers everything from constructors to operator overloading.

[Here](https://levelup.gitconnected.com/python-dunder-methods-ea98ceabad15) is the only comprehensive article I've found on dunder methods.

## Constructors: _\_\_init()\_\__
The _\_\_init()\_\__ method is used to declare and initialize the [instance attributes](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Python/Object-oriented%20Programming/Classes.md#instance-attributes) of a class. <br />
_\_\_init()\_\__ is automatically called when a class is created and should exist for nearly all classes.

```Python
class Class:
    # Constructor takes 1 paramter 'num' which is assigned to 'self.num'
    def __init__(self, num):
        self.num = num
      
# // DRIVER CODE // #
def main():
    number = Class(10)
    
    print(number.num)
    
main()
```

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

## Getting Content with the _in_ Operator
You can overload the _in_ operator for you class via the _\_\_contains()\_\__ method, which should return a boolean (_True_ or _False_).

```Python
class ListWrapper:
    data = [1, 2, 3, 4, 5, 6, 7]   # <== Class attribute (not instance)
       
    # 'in' Overload 
    def __contains__(self, element):
        return element in self.data   # Returns 'True' or 'False'
      
# // DRIVER CODE // #
def main():
    lst = ListWrapper()
    
    if 7 in lst: # if the number '7' is in lst.data (overloading 'in')
        print("7 is in the class data")
    else:
        print("7 is NOT in the class data")
    
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
    
    # Deleting the second item (calls __delitem__)
    del chest[1]
    
    # Print the items in the chest (calls __str__)
    print(chest) # book, eraser
    
main()
```

## Calling an Object like a Function
Class can be called like functions (like `object()`) via the _\_\_call()\_\__ method, which is especially useful for things like [functors](https://www.geeksforgeeks.org/functors-use-python/).

```Python
class Object:
    def __call__(self):
        print("Calling the object like a function...")
      
# // DRIVER CODE // #
def main():
    obj = Object()
    
    # Use object like a function (calls __call__)
    obj()
    
main()
```
