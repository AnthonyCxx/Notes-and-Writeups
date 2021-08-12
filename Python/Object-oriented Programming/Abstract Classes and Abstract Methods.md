# Abstract Classes and Abstract Methods in Python
An abstract base class (ABC) is a class that cannot be instantiated (because it's abstract); instead, an abstract base class serves as a template to derive other classes from.
For a class to become an abstract base class, they must inherit from the _ABC_ class under the [_abc_](https://docs.python.org/3/library/abc.html) module and have one or more
abstract methods (denoted by `@abstractmethod`).

You cannot instantiate an abstract class or any class that has inherited an abstract method without overriding it.
```Python
from abc import ABC, abstractmethod

class Tool(ABC):
    @abstractmethod
    def use(self):
        pass
    
class Saw(Tool):
    # Overrides abstract method 'use()' from parent 'Tool'
    def use(self):
        print("Cutting something in half")
    
def main():
    saw = Saw()
    saw.use()
    
main()
```
> Reference: [_Why should I use abstract base classes?_](https://stackoverflow.com/questions/3570796/why-use-abstract-base-classes-in-python/3571946) <br />
