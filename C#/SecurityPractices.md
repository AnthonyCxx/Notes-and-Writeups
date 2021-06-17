# Best Security Practices in C#

## Handling Sensitive Information (Passwords, SSNs, etc.)
Any time you would store sensitive information as a string, store it in a char array instead. 
To understand why strings are a security threat, you have to understand the underlying implementation. 
Strings are immutable, which means they cannot be changed after they have been declared. 
Every time you perform some string-altering process on a string, C# just creates a new string and returns that. 
The previous string is still sitting in memory until the the [garbage collector](https://docs.microsoft.com/en-us/dotnet/standard/garbage-collection/fundamentals) frees it,
marking it as safe to be overwritten. But that's the thing - the string isn't overwritten until that memory is used for something else. 
The sensitive contents of the string continue to sit in memory, leaving that information vulnerable to memory-imaging techniques that could fetch it from physical memory.
The best way to avoid this problem is to simple overwrite the contents of the string like the Linux command [shred](https://en.wikipedia.org/wiki/Shred_(Unix)) does, but, again, strings aren't mutable.
The only real option to securely handle sensitive information is to use a char array and then _immediately_ overwrite its contents after you're done using it.
> Note: this principle also applies to Java.
