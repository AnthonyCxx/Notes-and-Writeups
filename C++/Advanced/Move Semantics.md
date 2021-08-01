# Move Semantics in C++
Move semantics is an optimization that reallocates the resources (contents) of a temporary object instead of copying it. <br />
Move semantics is especially efficient when dealing with large objects, and even more efficient if the transfer is marked [_noexcept_](https://www.learncpp.com/cpp-tutorial/exception-specifications-and-noexcept/).

## _lvalues_ and _rvalues_
Before you understand move semantics, you must first understand the difference between an _lvalue_ and an _rvalue_.
"Put simply, an lvalue is an object reference and an rvalue is a value." - Ray Lischner, [_C++ in a Nutshell_](https://www.amazon.com/C-Nutshell-Ray-Lischner/dp/059600298X).
For context, by 'object', he means an object (a value) stored in memory, not an instantiation of a class. An example of an _lvalue_ could be the string variable '_name_', 
whereas an _rvalue_ could be the integer literal '_10_'. Of course it may not always be this simple, a _rvalue_ could just as easily be the whole expression '_12 * 129 % pow(3, 92)_'
or a series of string concatenations like '_"Weather: " + weather_' or even '_title + name_'.

### _lvalue_ and _rvalue_ References

You may not have run into this problem since passing a non-modifiable (_const_) _lvalue_ reference can also take an _rvalue_.

## The Problem with 

## Sources
TheCherno:[_lvalues and rvalues in C++_](https://www.youtube.com/watch?v=fbYknr-HPYE) <br />
TheCherno: [_Move Semantics in C++_](https://www.youtube.com/watch?v=ehMg6zvXuMY) <br />
InternalPointers.com: [_Understanding the meaning of lvalues and rvalues in C++_](https://www.internalpointers.com/post/understanding-meaning-lvalues-and-rvalues-c) <br />
O'Rielly Media: [_C++ in a Nutshell_](https://www.amazon.com/C-Nutshell-Ray-Lischner/dp/059600298X) <br />
CppCon 2019: [_Back to Basics: Move Semantics (1/2)_](https://www.youtube.com/watch?v=St0MNEU5b0o&t) by Klaus Iglberger <br />
CppCon 2019: [_Back to Basics: Move Semantics (2/2)_](https://www.youtube.com/watch?v=pIzaZbKUw2s) by Klaus Iglberger <br />
> Sorted by depth and difficulty of material (increasing)
