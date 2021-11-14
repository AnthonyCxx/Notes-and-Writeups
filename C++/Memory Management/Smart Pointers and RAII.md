# Smart Pointers and RAII in C++
RAII is one of the defining distinctions between legacy and modern C++. C++11 introduced [smart pointers](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Memory%20Management/Smart%20Pointers%20and%20RAII.md) (also called scoped pointers), which automatically take care of allocating and freeing memory.
Smart pointers are essentially a class that acts as a thin wrapper around a raw (normal) pointer; the wrapper allocates dynamic memory in their constructor and deallocate it in
their destructor. By binding the dynamically-allocated (heap) memory to the pointer that's allocated on the stack, you entirely avoid the problem of memory leak. This is why
C++'s approach to memory management is so effective — is entirely nullifies the need for a garbage collector by not creating any in the first place. As an added bonus, smart
pointers also eliminate the problem of dangling pointers.

## Unique, Shared, and Weak Pointers

## Smart Pointers and Exception Safety
By automatically taking care of freeing the allocated memory, smart pointers allow you to safely throw errors without risking memory leak.
