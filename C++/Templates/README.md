# Templates in C++
> "It's dangerous to go alone! Take this": [\<type_traits\> reference](https://en.cppreference.com/w/cpp/header/type_traits) <br />

On the surface, templates are pretty simple; they're just a way to make a function generic/type-neutral, right? Well, no. C++'s templates are _far_ more powerful than
C# and Java's generics. Once you get really deep into it, you'll start exploring [recursive templates](http://www.oxfordalgorithmics.com/2014/10/06/c-template-recursion-and-specialisation/), [variadic templates](https://eli.thegreenplace.net/2014/variadic-templates-in-c/), and even [template metaprogramming](https://www.fluentcpp.com/2017/06/02/write-template-metaprogramming-expressively/). Templates are powerful, but also very hard to use since they require a foundational understanding of the language to implement properly and are infamous for causing disgustingly long errors. Don't believe me? Mess up the direction of the arrows and run `cout >> x` — just see how many errors the template spawns.

Long story short: templates are powerful, but also very dangerous and many people are either starkly for or against templates.

| File | Explanation |
| ---- | ----------- |
| [Introduction to Templates](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Templates/Introduction%20to%20Templates.md) | explanation of templates and how to use them for functions and classes |
| [Default Template Arguments and Controlling Type Deduction](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Templates/Miscellaneous.md) | some more cool stuff you can do with templates |
| [Concepts and Constraints](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Templates/Constraints%20and%20Concepts.md) | constrainting templates with _std::enable\_if_ and _requires_/_concept_ |
| [Variadic Templates](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Advanced/Variadic%20Functions.md#variadic-templates-c11) | templates that can take a varying amount of arguments  |
| [Template Metaprogramming](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Templates/Template%20Metaprogramming.md) | don't click. don't do it. |
| [Cracked Stuff](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Templates/Cracked%20Stuff.md) | a collection of the craziest things I've seen done with templates |

A lot of the notes here come from various sources, but I undoubtedly drew the most from David Vandevoorde's, Nicolai Josuttis', and Douglas Gregor's [_C++ Templates: The Complete Guide_](https://www.amazon.com/C-Templates-Complete-Guide-2nd/dp/0321714121), 2nd edition. Even though it's 822 pages, even just the first few chapters cover more than you need
to know to be able to use templates effectively.
