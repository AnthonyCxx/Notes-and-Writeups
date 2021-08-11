# Inheritance in Python
Inheritance is the ability of a class to be able to inherit the attributes (function and data members) of another class, extending and building off of the 
base class. The class that the new class inherits from is called the base class and the class inheriting the properties is called the derived class. For example, 
if you created a 'tool' class, you could then use that tool class as a base for more specific tools like pickaxes, wrenches, etc. This way, you don't have to write 
the same thing over and over again. In essence, inheritance allows for [D.R.Y. coding](https://dzone.com/articles/is-your-code-dry-or-wet) by greatly increasing 
[code reusability](https://www.c-sharpcorner.com/UploadFile/201fc1/what-is-code-reuse-and-why-we-use-it/).

The class being inherited from is called the parent class and the derived class is called the child class.

## Simple Inheritance
Simple inheritance is composed of one parent class and one derived class. To inherit from a class, just add the parent class's name in parentheses after the 
name of the derived class in the derived class declaration. To include multiple parent classes, separate the parent class names with commas.

Here is a class _Employee_ that inherits from _Person_, extending it.
```Python
# // PERSON CLASS (PARENT) // #
class Person:
    # Instance Attributes
    def __init__(self, name, age):
        self.name = name
        self.age = age
        
    # String representation
    def __str__(self):
        return self.name + ", " + str(self.age)
        
# // EMPLOYEE CLASS (CHILD) // #
class Employee(Person):
    # Inherits 'name' and 'age' from class 'Person'
    def __init__(self, name, age, company, yearly_salary):
        # Call the constructor of the parent class
        Person.__init__(self, name, age)
    
        # Initialize instance attributes
        self.company = company
        self.yearly_salary = yearly_salary
        
    # String representation
    def __str__(self):
        return Person.__str__(self) + ", " + self.company + ", " + str(self.yearly_salary)

# // DRIVER CODE // #
Waldo = Person("Waldo", 32)
Harold = Employee("Harold", 45, "Wells Fargo", 87000)

print(Harold)  # Harold, 45, Wells Fargo, 87000
``` 

## The _super()_ Function
Python's [_super()_](https://rhettinger.wordpress.com/2011/05/26/super-considered-super/) function makes referencing the parent class from the derived class simpler.
Whenever you cann _super()_, it returns a delegate to the parent class. That way, you don't have to explicitly write out the name of the parent class each time.

Using _super()_ with single inheritance isn't that useful, but it's incredibly useful for multiple inheritance. When you call an inherited function in a derived class
that was inherited from two or more different class, then Python refers to the derived class's [Method Resolution Order](https://www.geeksforgeeks.org/method-resolution-order-in-python-inheritance/) (MRO) to figure out which inherited function to call. The resolution order depends on what order you inherited the classes in. If you had a class '_Wolf_'
that inherited from '_Canine_' and '_Predator_' that both had different _hunt()_ methods, then you could guarantee that the _Wolf_ class called _Canine_'s _hunt()_ methods
by inherited from _Canine_ before _Predator_.

If you want to know the MRO for a class, print `Class.__mro__` or `Class.mro()`.


[_Why Should I use super()?_](https://stackoverflow.com/questions/222877/what-does-super-do-in-python-difference-between-super-init-and-expl)
```Python
class Base:
    def __init__(self):
        print("Calling the base constructor")
    
class Derived:
    def __init__(self):
        print("Calling the derived constructor")
        super().__init__()
        
def main():
    derived = Derived()

main()
```

## Multi-level Inhertiance
Multi-level inheritance occurs when you use a derived class as a parent class for a new derived class, creating a chain of inheritance.

Because things are getting more complicated, I used [function annotations](https://www.python.org/dev/peps/pep-3107/) to help you keep track of the parameter and return types.
```Python
# Parent class 'Item'
class Item:
    def __init__(self, cost: int, weight: float):
        self.cost = cost         # In gold coins
        self.weight = weight     # In pounds
        
    def __repr__(self):
        return str(self.cost) + ", " + str(self.weight)


# Derived class 'Weapon' inherits from 'Item'
class Weapon(Item):
    def __init__(self, cost: int, weight: float, sharpness: int):
        self.sharpness = sharpness
        # Call parent constructor
        Item.__init__(self, cost, weight)
        
    def swing(self) -> None:
        print("Swinging the weapon!")
        
    def __repr__(self):
        return Item.__repr__(self) + ", " + str(self.sharpness)
 

# Derived class 'Sword' inherits from 'Weapon'
class Sword(Weapon):
    def __init__(self, cost: int, weight: float, sharpness: int):
        # 'Sword' implements no new members       
        Weapon.__init__(self, cost, weight, sharpness)
        
    # 'Sword' overrides 'Weapon.swing()'
    def swing(self) -> None:
        print("Swinging the sword!")
        
    def __repr__(self):
        return Weapon.__repr__(self)

# // DRIVER CODE // #
def main():
    sword = Sword(10, 3, 12)  # Cost, weight, sharpness
    print(sword)
 
main()
```


## Multiple Inheritance
Multiple inheritance occurs when a derived class inherits from two unrelated parent classes. <br />
Multiple inheritance is less common, but useful.

```Python
class Container:
    def __init__(self, capacity: int=64, items: list=[]):
        self.items = items
        self.capacity = capacity
        
    # Open the container
    def open() -> None:
        print("Opening the container...")
    
    # Close the container
    def close() -> None:
        print("Closing the container...")
    
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
    
    def __repr__(self):
        return '[' + ', '.join(self.items) + ']'
    
class Block:
    def __init__(self, id: int):
        self.id = id
        
    def place(self):
        print("Placing the block...")
        
    def destroy(self):
        print("Destroying the block")
        
    def __repr__(self):
        return str(id)
    
class Chest(Block, Container):
    def __init__(self, id: int, capacity: int=64, items: list=[]):
        Block.__init__(self, id)
        Container.__init__(self, capacity, items)
        
    def __repr__(self):
        return Container.__repr__(self)

def main():
    # A chest (ID: 167) that takes 64 items and is given the following items
    chest = Chest(167 ,64, ["Book", "Map", "RC-XD"])
    
    # Print all items
    print(chest)
    
    # Getting items with [] Overload (__getitem__()) works
    print(chest[0])
    
    # Assigning with [] Overload (__setitem__()) works
    chest[1] = "Pretzel Roll"
    
    # Print all items
    print(chest)

main()
```


## Overriding Methods
To override a method inherited from a parent class, just redefine it in the derived class. That simple.

```Python

```

## Calling an Overriden Parent Method


```Python

```

## Method Chaining

```Python

```
