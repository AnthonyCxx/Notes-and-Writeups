# Structures in C
Structures (colloquially called a 'struct') are a user-defined datatype that serve as a collection of variables. They are defined as a block of code prefaced with the
[_struct_ keyword](https://www.educative.io/edpresso/what-is-a-c-struct) and end with a semi-colon.
```C

```


## 'Inheritance' of Structures
Structures do not support inheritance, but you can effectively mimic the concept via [composition](https://www.codementor.io/@arpitbhayani/powering-inheritance-in-c-using-structure-composition-176sygr724) 
(i.e. making one the the structure's fields another structure). Some people believe that composition is the only way that structs (and objects in object-oriented
programming) should take on another struct's attributes - see [_Composition over Inheritance_](https://en.wikipedia.org/wiki/Composition_over_inheritance)
