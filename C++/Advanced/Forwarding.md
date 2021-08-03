# Forwarding in C++

## Forwarding (Universal) References
Just because a reference contains _&&_ does not mean it's an _rvalue_ references — it may be a forwarding reference.
Unlike _lvalue_ references, which can only bind to _lvalues_, and _rvalue_ references, which can only bind to _rvalues_, a forwarding reference can bind to both
_lvalues_ and _rvalues_ (hence why it is also called a universal reference). What you think of as an _rvalue_ reference becomes a forwaring reference when the datatype
is left to be deduced (like in templated functions (`T&&`) or `auto&& var`).

## Sources
TechMunching: [_Universal Reference and Perfect Forwarding_](https://techmunching.com/universal-reference-and-perfect-forwarding/) (this article is really good) <br />
Petr Zemek's Blog: [_Universal vs Forwarding References in C++_](https://blog.petrzemek.net/2016/09/17/universal-vs-forwarding-references-in-cpp/) <br />
open-std.org: [_Forwarding References_](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4164.pdf) (technical article, worth reading) <br />
Drew Campbell's Blog: [_Understanding Move Semantics and Perfect Forwarding: Part 3_](https://drewcampbell92.medium.com/understanding-move-semantics-and-perfect-forwarding-part-3-65575d523ff8) <br />
CPPCon 2019: [_Klaus Iglberger: “Back to Basics: Move Semantics (part 2 of 2)”_](https://www.youtube.com/watch?v=pIzaZbKUw2s&t) <br />
