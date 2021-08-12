# Abstract Classes and Abstract Methods in Python
An abstract base class (ABC) is a class that cannot be instantiated (because it's abstract); instead, an abstract base class serves as a template to derive other classes from.
For a class to become an abstract base class, they must inherit from the _ABC_ class under the [_abc_](https://docs.python.org/3/library/abc.html) module and have one or more
abstract methods (denoted by `@abstractmethod`).
