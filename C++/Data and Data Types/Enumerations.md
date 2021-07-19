# Enumerations in C++
An enumerated type (enum) is a user-defined type that can be one of a defined set of values, each of which is represented internally by an integer constant. Enums provide
programmers with a clear way of representing the possible states/values of an object. For example, a simple machine may have an enum defining its state with two simple
values, 'ON' and 'OFF' (by convention, enum values are typically fully capitalized). Enums may be preferable to booleans because they can represent a number of states (as
opposed to a boolean's two states) but still keep the advantage of a boolean in that they are fundamentally integral. By default, the first value of an enum is 0, 
the second is 1, the third is 2, and so on; however, this can be overwritten by manually assigning the values inside of the enum declaration. 
A good summary of enums can be found [_here_](https://www.youtube.com/watch?v=x55jfOd5PEE). <br />

Enums can also be clearer booleans because they can represent two or more potentially unrelated states, whereas a boolean implies a single state that either is or is not.
