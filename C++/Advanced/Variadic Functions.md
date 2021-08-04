# Variadic Functions in C++
A variadic function is a function varying [arity](https://en.wikipedia.org/wiki/Arity) (the amount of arguments it can take). Variadic functions allow you to write a single 
function like _add()_ that can take any number of variables, literals, or combination of the two. I could call _add(1, 2)_ or _add(7, 14, 900)_ and it would work all the same.

## Variadic Templates (C++11)
[https://eli.thegreenplace.net/2014/variadic-templates-in-c/](https://eli.thegreenplace.net/2014/variadic-templates-in-c/) <br />
[https://kevinushey.github.io/blog/2016/01/27/introduction-to-c++-variadic-templates/](https://kevinushey.github.io/blog/2016/01/27/introduction-to-c++-variadic-templates/) <br />
[https://docs.microsoft.com/en-us/cpp/cpp/ellipses-and-variadic-templates?view=msvc-160](https://docs.microsoft.com/en-us/cpp/cpp/ellipses-and-variadic-templates?view=msvc-160) <br />
[https://www.modernescpp.com/index.php/c-insights-variadic-templates](https://www.modernescpp.com/index.php/c-insights-variadic-templates) <br />

## Fold Expressions (C++17)
C++17 added a cleaner, non-recursive way to write variadic functions: fold expressions.
[https://www.youtube.com/watch?v=nhk8pF_SlTk](https://www.youtube.com/watch?v=nhk8pF_SlTk) <br />

## C-Style Variadic Functions
Don't use this in C++, it's not type-safe and if you aren't careful, you'll get a segmentation fault.

## Sources
