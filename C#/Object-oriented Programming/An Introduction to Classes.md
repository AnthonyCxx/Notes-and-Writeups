# Classes and Object-Oriented Programming in C#
Object-oriented programming is a [programming paradigm](https://cs.lmu.edu/~ray/notes/paradigms/) in which concepts (abstract or concrete) are represented as user-defined
datatypes. These custom types, called classes, contain both the state and actions related to the concept being represented. For example, a class "Dog" would be designed 
to model a dog (perhaps in the context of a video game or a similar program). The dog class would contain collection of variables describing the dog (strings for its
name and breed, and maybe an int for its age) as [functions](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/methods) (aka methods) for performing actions (like barking or wagging its tail). At the end of the day, classes are just a means of organizing data to promote well-structured programs. Just as a note, 
classes are [reference types](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/reference-types), making them [heap-allocated](https://www.c-sharpcorner.com/article/C-Sharp-heaping-vs-stacking-in-net-part-i/). For a complete references for classes, see C#'s documentation: [class keyword](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/class).

# Declaring and Using Classes

```C#
class ClassName
{
    //Fields (variables)
    public int X;

    //Methods (functions)
    public void DoSomething()
    {
        Console.WriteLine("class function called!");
    }

    //Other class members (properties, operators, indexers...)
}
```

# References
