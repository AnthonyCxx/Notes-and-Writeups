# Forwarding in C++

## Forwarding (Universal) References
Just because a references contains _&&_ does not mean it's an _rvalue_ references — it may be a forwarding reference.
Unlike _lvalue_ references, which can only bind to _lvalues_, and _rvalue_ references, which can only bind to _rvalues_, a forwarding reference can bind to both
_lvalues_ and _rvalues_ (hence why it is also called a universal reference).

## Sources
CPPCon 2019: [_Klaus Iglberger: “Back to Basics: Move Semantics (part 2 of 2)”_](https://www.youtube.com/watch?v=pIzaZbKUw2s&t) <br />
