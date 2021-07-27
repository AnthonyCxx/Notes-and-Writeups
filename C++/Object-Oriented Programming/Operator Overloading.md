# Operator Overloading in C++
When you write a simple expression like _2 + 2_, the computer gives you _4_ because it knows how to add two integers; however, if you had a class '_date_' and added 
1 to it, what would happen? Well to be frank, the compiler would throw an error because it doesn't know how to handle addition with a class. That right there is the heart
of operator overloading: providing definitions for how the program should treat expressions that involve classes. All you have to do is write a function that explains to the
compiler what to do.

##

special operators: <<, >>, [bool](https://stackoverflow.com/questions/4600295/what-is-the-meaning-of-operator-bool-const), prefix and postfix operators

## Deleting Operators
`className::operator& = delete;`

## Sources
