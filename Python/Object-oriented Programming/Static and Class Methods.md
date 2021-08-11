# Static and Class Methods in Python
Think of static and class methods like class attributes: they are a member of a class but not bound to any particular instance of said class. <br />
Static and class methods are denoted by the `@staticmethod` and `@classmethod` [decorators](https://realpython.com/primer-on-python-decorators/#simple-decorators) respectively.

## Static Methods
Static methods are a method of a class that can be called without needing an instance of the class like `Class.method()`. However, as consequence, they do not have _any_ access
to the members (data members or function members) of the class. The benefit of static members is organization; a utility-based class (like a temperature converter) may be 
entirely composed of static methods.

Static methods are marked with `@staticmethod` and do not take _self_ as a parameter.
```Python
class TempConverter:
    @staticmethod # Takes a float, returns (->) a float
    def toF(temp: float) -> float:  # Fahrenheit
        return round(temp * (9 / 5) + 32, 2)
    
    @staticmethod # Takes a float, returns (->) a float
    def toC(temp: float) -> float:  # Celcius
        return round((temp - 32) * (5 / 9), 2)
    
# // DRIVER CODE // # 
def main():
    print(f"80F in Celcius is: {TempConverter.toC(80)}C")
    print(f"15C in Fahrenheit is: {TempConverter.toF(15)}F")

main()
```
> Notice how you can use the _toF()_ and _toC()_ methods without needing an instance of _TempConverter_.

## Class Methods
Unlike static methods, class methods do know of the class, having access to the class attributes and methods; class methods can even modify class attributes; however,
class methods cannot access instance attributes as they are not bound to an instance. Class methods implicitly take an instance of the class as the first argument (abbreviated
_cls_) and are exceptionally useful for creating [factory methods](https://dev.to/danyson/how-classmethod-in-python-helps-in-implementing-factory-methods-23gl).

Class methods are marked with `@classmethod` and take _cls_ (a class, passed implcitly) as a parameter.
```Python

```
