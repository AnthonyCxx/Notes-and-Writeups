# Forwarding in C++
> Pre-requisite: [_lvalues and rvalues_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Advanced/Move%20Semantics.md#lvalues-and-rvalues) <br />

## Forwarding (Universal) References
> Recommended Video: [_Type Deduction and Why You Should Care_](https://www.youtube.com/watch?v=wQxj20X-tIU), by Scott Meyers

Just because a reference contains _&&_ does not mean it's an _rvalue_ reference — it may be a forwarding reference.
Unlike _lvalue_ references, which can only bind to _lvalues_, and _rvalue_ references, which can only bind to _rvalues_, a forwarding reference can bind to both
_lvalues_ and _rvalues_ (hence why it is also called a universal reference). What looks like an _rvalue_ reference (denoted by _&&_) becomes a universal reference when 
the datatype of the reference must be deduced (like in templated functions (`T&&`) or `auto&& var`). This is because whether the reference becomes an _lvalue_ or _rvalue_
reference depends on the type the function/variable is initialized with. Notice how I explicitly said 'datatype' and 'type', not treating them as interchangable, because they're
not (passing `int` to a parameter `T&&` is different from passing `const int`); This is because of the rulesets for type deductions, which are explained in the video linked above.
If the result of the deduction is a reference to a reference (like `(int& &&)`, which is illegal), then 
[reference collapsing](https://www.ibm.com/docs/en/xl-c-and-cpp-aix/13.1.2?topic=operators-reference-collapsing-c11) will occur.

## Forwarding

## Perfect Forwarding

## Sources
CPPCon 2014: [_Scott Meyers: "Type Deduction and Why You Care"_](https://www.youtube.com/watch?v=wQxj20X-tIU) <br />
TechMunching: [_Universal Reference and Perfect Forwarding_](https://techmunching.com/universal-reference-and-perfect-forwarding/) (this article is really good) <br />
Petr Zemek's Blog: [_Universal vs Forwarding References in C++_](https://blog.petrzemek.net/2016/09/17/universal-vs-forwarding-references-in-cpp/) <br />
open-std.org: [_Forwarding References_](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4164.pdf) (technical article, worth reading) <br />
Drew Campbell's Blog: [_Understanding Move Semantics and Perfect Forwarding: Part 3_](https://drewcampbell92.medium.com/understanding-move-semantics-and-perfect-forwarding-part-3-65575d523ff8) <br />
CPPCon 2019: [_Klaus Iglberger: “Back to Basics: Move Semantics (part 2 of 2)”_](https://www.youtube.com/watch?v=pIzaZbKUw2s&t) <br />
