# Move Semantics in C++
Move semantics are an optimization that reallocates the resources (contents) of a temporary object instead of copying it. <br />
Move semantics are especially efficient when dealing with large objects, and even more efficient if the transfer is marked [_noexcept_](https://www.learncpp.com/cpp-tutorial/exception-specifications-and-noexcept/).

## _lvalues_ and _rvalues_
Before you understand move semantics, you must first understand the difference between an _lvalue_ and an _rvalue_.
"Put simply, an lvalue is an object reference and an rvalue is a value." - Ray Lischner, [_C++ in a Nutshell_](https://www.amazon.com/C-Nutshell-Ray-Lischner/dp/059600298X).
For context, by 'object', he means an object (a value) stored in memory, not an instantiation of a class. An example of an _lvalue_ could be the string variable '_name_', 
whereas an _rvalue_ could be the integer literal '_10_'. Of course it may not always be this simple, a _rvalue_ could just as easily be the whole expression '_12 * 129 % pow(3, 92)_' or a string concatenation like '_"Weather: " + weather_', or even '_title + name_'.

### _lvalue_ and _rvalue_ References
You are likely familiar with _lvalue_ references, which use the [address-of operator](https://www.dummies.com/programming/cpp/how-address-operators-work-in-c/) (&).
We use _lvalue_ references for a number of things like passing and returning by reference (e.g. `void print(const string& str)`) or assigning a pointer to an existing 
variable (e.g. `int* ptr = &x`). Just like you can use _&_ to reference an _lvalue_, you can use _&&_ to reference an _rvalue_ (not to be confused with the 
[logical and operator](https://www.w3schools.com/cpp/cpp_operators_logical.asp), which is also &&). _&&_ can be used to indicate an _rvalue_ reference
like `void print(string&& str)`, which would only take a string literal like '_Hello, World!_' and not a string variable like '_name_'.

You may not have run into the problem of not being able to pass a literal (an _rvalue_, like '_Hello_') into a function that takes a _const lvalue&_ 
(like `void print(const string& str)`) because _const_ _lvalues_ are interchangable with _rvalues_ in some situtations since both are non-modifiable data. 
If you re-wrote the function _print()_ to only take `string& str`, then passing '_Hello_' would cause an error.

You can remember the difference between _lvalues_ and _rvalues_ so: _lvalues_ have an _identifier_, a name that you can reference them with, like  string variable '_name_'; conversely, _rvalues_ are nameless. The number '_10_' does not have a name that you can call it with, and neither does the result
of the expression '_title + name_' — the result of the expression '_title + name_' is just a nameless, temporary string object (called an _xvalue_, for 'expiring value').
The only exception to this rule is that an _lvalue_ is an _rvalue_ when used on the right-side of an assignment operation and is not modified in any way (e.g. `x = y`).
And the only exception to that exception is when an unmodified _lvalue_ is used in a _return_ statement (e.g. `return x`), in which case it's an _rvalue_.

## Unnecessarily Copying Temporary Objects
Let's say you assign one string to another; what stops you from simply reallocating the resources of the string to the new string? Well, the old string still needs its
resources since it's its own variable. Reallocating the resources of the old string to the new string would steal them from the old string, which is a problem. But what if
we could guarantee that the old string wouldn't need its resources again? Say, if the string was a temporary string created as the result of an expression like '_title + name_'.
Copying in this case would be unnecessarily inefficient because the temporary string object as a result of '_title + name_' is going to go out of scope in a moment anyway.
You might as well just steal the resources from the temporary string since it's not going to do any harm.

This is the entire point of move semantics. Move semantics are an optimization that reallocates the resources (contents) of a temporary object instead of copying it.
Move semantics are especially efficient when dealing with large objects, and even more efficient if the transfer is marked
[_noexcept_](https://www.learncpp.com/cpp-tutorial/exception-specifications-and-noexcept/). Move semantics was impossible before C++11 because there was no way to 
differentiate between _lvalues_ and _rvalues_ syntactically. Now that we can explicitly refer to _rvalues_ with the _&&_ operator, we can do things like overload the
assignment operator (=) to 'steal' the resources of an _xvalue_, allowing you to avoid copying where it is unnecessary.

## Reallocation of Resources with Move Semantics
> At this point, I recommend watching [_Back to Basics: Move Semantics - David Olsen - CppCon 2020_](https://www.youtube.com/watch?v=ZG59Bqo7qX4)

The reallocation of resources in move semantics takes form in two special member functions: the move constructor (`ClassName(ClassName&&)`) and the move assignment operator (`ClassName& operator=(ClassName&&)`). Notice how neither of these functions take _const_ references, since they will be altering the taken object. By the end of the operation,
the new object should have copied all primitive values and taken control of all references belonging to the old object and the old object should be left in a "valid but undefined state" (Klaus Iglberger, [CPPCon 2019](https://www.youtube.com/watch?v=St0MNEU5b0o)), containing no references to its previous data members. To quote the C++ Core Guidelines directly,
"Ideally, that moved-from should be the default value of the type. Ensure that unless there is an exceptionally good reason not to." ([C.64](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c64-a-move-operation-should-move-and-leave-its-source-in-a-valid-state)).
If you are moving a class, then make the 'default state' is the default state for each data member.

> See below for an explanation on [_std::move()_](https://www.learncpp.com/cpp-tutorial/stdmove/)
```C++

```

In case you're confused on the exact differences between any of the special functions:
| Special Member Function | Purpose | Returns | 
| ----------------------- | ------- | ------- |
| Constructor | creates a new object from nothing | Nothing |
| Copy Constructor | creates a new object based on another object | Nothing |
| Assignment Operator Overload | copies the content of an existing object into another existing object | \*this |
| Move Constructor | creates a new object; moves the resources of an existing object into the new object | Nothing | 
| Move Assignment Operator Overload | Moves the resources of an existing object into another one | \*this |

### A look at _std::move()_
[_move()_](https://www.learncpp.com/cpp-tutorial/stdmove/) is not a library function to automatically perform move semantics for you. I wish. The _move()_ function is
a shorthand for a very long and somewhat obscure static cast (`static_cast<remove_reference_t<T>&&>(lvalue)`) that casts _lvalues_ into _rvalues_, allowing you to move 
the _lvalue_ instead of copying it. Only use _move()_ when you know that the object is about to be destroyed or initialized with a new value.

```C++

```

### Simultaneous Reassignment with _exchange()_
The [_exchange()_](https://docs.w3cub.com/cpp/utility/exchange) function allows you to reassign the values of both the old and new objects at once, which is especially
useful for pointers since you always have to set a stolen pointer to nullptr in the old object..

### Making Move Functions _noexcept_
If a move constructor/assignment operator is marked as [_noexcept_](https://www.learncpp.com/cpp-tutorial/exception-specifications-and-noexcept/), it can take
a different, more efficient code path because it will not have to worry about exceptions potentially iterrupting the moving process. In this video, Dr. Iglberger
was able to reduce the time it took to move an object from 0.005 seconds to 0.002 seconds (60% less time). If you can, always mark your move constructors and assignment
operator overloads as _noexcept_ ([_C.66_](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rc-move-noexcept)).

## Sources
TheCherno: [_lvalues and rvalues in C++_](https://www.youtube.com/watch?v=fbYknr-HPYE) <br />
TheCherno: [_Move Semantics in C++_](https://www.youtube.com/watch?v=ehMg6zvXuMY) <br />
InternalPointers.com: [_Understanding the meaning of lvalues and rvalues in C++_](https://www.internalpointers.com/post/understanding-meaning-lvalues-and-rvalues-c) <br />
Thomas Becker: [_C++ Rvalue References Explained_](http://thbecker.net/articles/rvalue_references/section_01.html) <br />
O'Rielly Media: [_C++ in a Nutshell_](https://www.amazon.com/C-Nutshell-Ray-Lischner/dp/059600298X) <br />
CppCon 2019: [_Back to Basics: Move Semantics (1/2)_](https://www.youtube.com/watch?v=St0MNEU5b0o&t) by Klaus Iglberger <br />
CppCon 2019: [_Back to Basics: Move Semantics (2/2)_](https://www.youtube.com/watch?v=pIzaZbKUw2s) by Klaus Iglberger <br />
> Sorted by depth and difficulty of material (increasing)
