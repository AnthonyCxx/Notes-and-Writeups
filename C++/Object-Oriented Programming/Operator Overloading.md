# Operator Overloading in C++
When you write a simple expression like _2 + 2_, the computer gives you _4_ because it knows how to add two integers; however, if you had a class '_date_' and added 
1 to it, what would happen? Well to be frank, the compiler would throw an error because it doesn't know how to handle addition with a class. That right there is the heart
of operator overloading: providing definitions for how the program should treat expressions that involve classes. All you have to do is write a function that explains to the
compiler what to do.


## Overloading Unary Operators
[bool](https://stackoverflow.com/questions/4600295/what-is-the-meaning-of-operator-bool-const)


## Overloading Binary Operators


## Differentiating Between Unary and Binary Operators


## Special Cases
The following operators have special rules associated with them. Yes, all of these are on the test for CSC-1720.


### Stream Insertion and Extraction Operators (<< and >>)


### Prefix and Postfix Operators (++ and --)


## Deleting Operators
`className::operator& = delete;`


## Sources
