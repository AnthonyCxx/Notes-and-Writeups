# Operator Overloading in C++
When you write a simple expression like _2 + 2_, the computer gives you _4_ because it knows how to add two integers; however, if you had a class '_date_' and you added 
1 to it, what would happen? Well to be frank, the compiler would throw an error because it doesn't know how to handle addition with a class. That right there is the heart
of operator overloading: providing definitions for how the program should treat expressions that involve classes. That way, you could write a function that increases the day
by 1 everytime you add 1 to a '_date_' class.

special operators: <<, >>, [bool](https://stackoverflow.com/questions/4600295/what-is-the-meaning-of-operator-bool-const)

## Deleting Operators
`className::operator& = delete;`

## Sources
