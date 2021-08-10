# Inheritance in Python
Inheritance is the ability of a class to be able to inherit the attributes (function and data members) of another class, extending and building off of the 
base class. The class that the new class inherits from is called the base class and the class inheriting the properties is called the derived class. For example, 
if you created a 'tool' class, you could then use that tool class as a base for more specific tools like pickaxes, wrenches, etc. This way, you don't have to write 
the same thing over and over again. In essence, inheritance allows for [D.R.Y. coding](https://dzone.com/articles/is-your-code-dry-or-wet) by greatly increasing 
[code reusability](https://www.c-sharpcorner.com/UploadFile/201fc1/what-is-code-reuse-and-why-we-use-it/).

## Simple Inheritance


Here is a class _Employee_ that inherits from _Person_, extending it.
```Python
# // PERSON CLASS (PARENT) // #
class Person:
    # Class attribute
    species = "Human"
    
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
    
        self.company = company
        self.yearly_salary = yearly_salary
        
    # String representation
    def __str__(self):
        return Person.__str__(self) + ", " + self.company + ", " + str(self.yearly_salary)

# // DRIVER CODE // #
Waldo = Person("Waldo", 32)
Harold = Employee("Harold", 45, "Wells Fargo", 87000)

print(Harold)
```

## The _super()_ Function
Python's [_super()_](https://rhettinger.wordpress.com/2011/05/26/super-considered-super/)...

## Multi-level Inhertiance


```Python

```


## Multiple Inheritance


```Python

```


## Overriding Methods


```Python

```

## Calling an Overriden Parent Method


```Python

```
