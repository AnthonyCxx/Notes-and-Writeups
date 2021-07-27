# Operator Overloading in C++

### Notable Restrictions on Operator Overloading <br />
- You cannot change operator precedence <br />
- Associativity cannot be changed  <br />
- You cannot use default parameters <br />
- You cannot create new operators <br />
- You cannot overload some operators [.](https://docs.microsoft.com/en-us/cpp/cpp/member-access-operators-dot-and?view=msvc-160), [.*](https://docs.microsoft.com/en-us/cpp/cpp/pointer-to-member-operators-dot-star-and-star?view=msvc-160), [::](https://docs.microsoft.com/en-us/cpp/cpp/scope-resolution-operator?view=msvc-160), [?:](https://docs.microsoft.com/en-us/cpp/cpp/conditional-operator-q?view=msvc-160), [sizeof()](https://docs.microsoft.com/en-us/cpp/cpp/sizeof-operator?view=msvc-160)
		
- Some overloaded operators (<< and >> notably) cannot be a part of the class itself, but still need access <br /> 
  to the data members of the class (public and private). Using the keyword friend at the front of a function  <br />
  declaration gives the function access to all the data members of the given class. **The keyword friend is only   <br />
  included in the function declaration**.  <br />


## Overloading Unary Operators


## Overloading Binary Operators


## Differentiating Between Unary and Binary Operators


## Special Cases
The following operators are special cases. Only the stream insertion/extraction, and prefix/postfix operators are on the test for CSC-1720.

### _bool_ Operator

### Stream Insertion and Extraction Operators (<< and >>)


### Prefix and Postfix Operators (++ and --)


## Deleting Operators
`className::operator& = delete;`


## Sources
Book: [_C++ Programming: Program Design Including Data Structures, 8th Edition_](https://www.amazon.com/Programming-Program-Design-Including-Structures/dp/1337117560) by D.S. Malik <br />
IBM: [_Overloading operators (C++ only)_](https://www.ibm.com/docs/en/zos/2.4.0?topic=only-overloading-operators-c) <br />
Microsoft C++ Documentation: [_Operator overloading_](https://docs.microsoft.com/en-us/cpp/cpp/operator-overloading?view=msvc-160) <br />
GeeksforGeeks: [_Operator Overloading in C++_](https://www.geeksforgeeks.org/operator-overloading-c/) <br />
TutorialsPoint: [_C++ Overloading (Operator and Function)_](https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm) <br />
Programiz: [_C++ Operator Overloading_](https://www.programiz.com/cpp-programming/operator-overloading) <br />
TheCherno: [_OPERATORS and OPERATOR OVERLOADING in C++_](https://www.youtube.com/watch?v=mS9755gF66w) <br />
Artima: [_The Safe Bool Idiom_](https://www.artima.com/articles/the-safe-bool-idiom) <br />
