
# Interfaces in C#
"An interface is a type definition similar to a class, except that it purely represents a contract between an object and its user. \[An interface\] cannot be directly instantiatied as an object, nor can its data members be defined. So, an interface is nothing but a collection of method and property declarations." <br />
\- Bobby Davis, Jr. ([video ref](https://www.youtube.com/watch?v=_zCR1Rq7qB0))

Essentially, an interface is a contract that states that any class that inherits from it must implement all of the members of the interface. However, it does not 
specify how.


# Built-In Interfaces

## IEquatable<T>
Defines a method _Equals(**\<T\> other**)_ that compares two objects of the same type.

## Conventions
- Identifiers should have a prepended letter 'I' (for interface) to distinguish them from classes
