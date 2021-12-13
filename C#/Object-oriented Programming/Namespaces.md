# Namespaces in C#
Just like classes help organize variables and functions, [namespaces](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/language-specification/namespaces) help
organize classes into coherent groups. For example, the [System.Collections](https://docs.microsoft.com/en-us/dotnet/api/system.collections?view=net-6.0) namespace contains
an assortment of classes (as datastructures) and interfaces (for implementing datastructures). Names of namespaces should be an overarching catagory and nested namespaces
should follow the pattern `<Company>.(<Product>|<Technology>)[.<Feature>][.<Subnamespace>]` (ref: [Names of Namespaces](https://docs.microsoft.com/en-us/dotnet/standard/design-guidelines/names-of-namespaces))

# Declaring a Namespace
To delcare a namespace, just use the `namespace` keyword followed by the name of the namespace; anything inside the parentheses will be a part of that namespace.

```C#
namespace NameSpaceIdentifier
{
  //Classes go here
}
```

# Using Directives
Typically, you have access a member of a namespace, you have to preface the member with the name of the namespace. To avoid having to write the namespace every time you 
access a member, you can use a [using directive](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/language-specification/namespaces#using-directives) like
`using NameSpaceIdentifier`. If you only want to use a specific member of a namespace, you can use a [using static directive](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/language-specification/namespaces#using-static-directives).

# Using Aliases
Using directives can also be used to create aliases. To create a using alias, just write `using <alias> = <namespace>`.


# Sources
- C# Documentation: [Namespaces](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/language-specification/namespaces#using-static-directives)
- Educba: [Namespaces in C#](- https://www.educba.com/namespaces-in-c-sharp/)
- C# Documentation: [Using Directive](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/language-specification/namespaces#using-static-directives)
- C# Documentation: [Using Static Directive](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/language-specification/namespaces#using-static-directives)
- C# Documentation: [Names of Namespaces](https://docs.microsoft.com/en-us/dotnet/standard/design-guidelines/names-of-namespaces)
