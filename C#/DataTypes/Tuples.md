# Tuples in C#
A tuple is a mutable (changable, think _mut_ as in _mutate_) data structure that contains two or literals or variables, which may be of different types.

## Declaring a Tuple
```C#
//Default method
Tuple<int, int, int> exampleTuple = Tuple<int, int, int>(1, 2, 3);' also works

//Using the .Create() method
Tuple<int, int, int> exampleTuple = Tuple.Create(1, 2, 3);
```
> Consider using the [_var keyword_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/DataTypes/Keywords.md#var) when declaring a tuple.

## Accessing Data Members of a Tuple
