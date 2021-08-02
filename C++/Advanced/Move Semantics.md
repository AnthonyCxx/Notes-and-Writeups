# Move Semantics in C++
Move semantics is an optimization that reallocates the resources (contents) of a temporary object instead of copying it. <br />
Move semantics is especially efficient when dealing with large objects, and even more efficient if the transfer is marked [_noexcept_](https://www.learncpp.com/cpp-tutorial/exception-specifications-and-noexcept/).

## _lvalues_ and _rvalues_
Before you understand move semantics, you must first understand the difference between an _lvalue_ and an _rvalue_.
"Put simply, an lvalue is an object reference and an rvalue is a value." - Ray Lischner, [_C++ in a Nutshell_](https://www.amazon.com/C-Nutshell-Ray-Lischner/dp/059600298X).
For context, by 'object', he means an object (a value) stored in memory, not an instantiation of a class. An example of an _lvalue_ could be the string variable '_name_', 
whereas an _rvalue_ could be the integer literal '_10_'. Of course it may not always be this simple, a _rvalue_ could just as easily be the whole expression '_12 * 129 % pow(3, 92)_' or a string concatenation like '_"Weather: " + weather_', or even '_title + name_'.

### _lvalue_ and _rvalue_ References
You are likely familiar with _lvalue_ references, which use the [address-of operator](https://www.dummies.com/programming/cpp/how-address-operators-work-in-c/) (&).
We use _lvalue_ references for a number of things like passing and returning by reference (e.g. `void print(const string& str)`) and assigning a pointer to an existing 
variable (e.g. `int* ptr = &x`). Just like you can use _&_ to reference an _lvalue_, you can use _&&_ to reference an _rvalue_ (not to be confused with the 
[logical and operator](https://www.w3schools.com/cpp/cpp_operators_logical.asp), which is also &&). To my knowledge, using _&&_ to indicate an _rvalue_ reference
is exclusively used when writing a function parameter, like <br /> `void print(string&& str)`, which would only take a string literal like '_Hello, World!_' and not a string 
variable like '_name_'.

You may not have run into the problem of not being able to pass a literal (an _rvalue_, like '_Hello_') into a function that takes a _const lvalue&_ 
(like `void print(const string& str)`) because _const_ _lvalues_ are interchangable with _rvalues_ in some situtations since both are non-modifiable data. 
If you re-wrote the function _print()_ to only take `string& str`, then passing '_Hello_' would cause an error.

## Assignment

## Move Semantics

## Sources
TheCherno: [_lvalues and rvalues in C++_](https://www.youtube.com/watch?v=fbYknr-HPYE) <br />
TheCherno: [_Move Semantics in C++_](https://www.youtube.com/watch?v=ehMg6zvXuMY) <br />
InternalPointers.com: [_Understanding the meaning of lvalues and rvalues in C++_](https://www.internalpointers.com/post/understanding-meaning-lvalues-and-rvalues-c) <br />
Thomas Becker: [_C++ Rvalue References Explained_](http://thbecker.net/articles/rvalue_references/section_01.html) <br />
O'Rielly Media: [_C++ in a Nutshell_](https://www.amazon.com/C-Nutshell-Ray-Lischner/dp/059600298X) <br />
CppCon 2019: [_Back to Basics: Move Semantics (1/2)_](https://www.youtube.com/watch?v=St0MNEU5b0o&t) by Klaus Iglberger <br />
CppCon 2019: [_Back to Basics: Move Semantics (2/2)_](https://www.youtube.com/watch?v=pIzaZbKUw2s) by Klaus Iglberger <br />
> Sorted by depth and difficulty of material (increasing)
