# Operator Overloading in C++
When you write a simple expression like _2 + 2_, the computer gives you _4_ because it knows how to add two integers; however, if you had a class '_date_' and added 
1 to it, what would happen? Well to be frank, the compiler would throw an error because it doesn't know how to handle addition with a class, and that right there is the heart
of operator overloading: providing definitions for how the compiler should treat expressions that involve classes. All you have to do is write a function that explains to the
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
Artima: [_The Safe Bool Idiom_](https://www.artima.com/articles/the-safe-bool-idiom) <br />
Book: [_C++ Programming: Program Design Including Data Structures, 8th Edition_](https://www.amazon.com/Programming-Program-Design-Including-Structures/dp/1337117560) by D.S. Malik <br />
IBM: [_Overloading operators (C++ only)_](https://www.ibm.com/docs/en/zos/2.4.0?topic=only-overloading-operators-c) <br />
Microsoft C++ Documentation: [_Operator overloading_](https://docs.microsoft.com/en-us/cpp/cpp/operator-overloading?view=msvc-160) <br />
GeeksforGeeks: [_Operator Overloading in C++_](https://www.geeksforgeeks.org/operator-overloading-c/) <br />
TutorialsPoint: [_C++ Overloading (Operator and Function)_](https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm) <br />
Programiz: [_C++ Operator Overloading_](https://www.programiz.com/cpp-programming/operator-overloading) <br />
TheCherno: [_OPERATORS and OPERATOR OVERLOADING in C++_](https://www.youtube.com/watch?v=mS9755gF66w) <br />
