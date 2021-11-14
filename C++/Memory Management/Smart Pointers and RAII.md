# Smart Pointers and RAII in C++
RAII is one of the defining distinctions between legacy and modern C++. C++11 introduced [smart pointers](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Memory%20Management/Smart%20Pointers%20and%20RAII.md) (also called scoped pointers), which automatically take care of allocating and freeing memory.
Smart pointers are essentially a class that acts as a thin wrapper around a raw (normal) pointer; the wrapper allocates dynamic memory in their constructor and deallocates it in
their destructor. By binding the dynamically-allocated (heap) memory to the pointer that's allocated on the stack, you entirely avoid the problem of memory leak. This approach
to memory management is called "**R**esource **A**cquisition **I**s **I**nitialization". This is why C++'s approach to memory management is so effective — is entirely nullifies the need for a garbage collector by not creating any garbage in the first place. As an added bonus, smart pointers also eliminate the problem of dangling pointers.

# Unique, Shared, and Weak Pointers
C++ defines three types of smart pointers in the [\<memory\>](https://en.cppreference.com/w/cpp/header/memory) library, each with their own type of ownership.

## Unique Pointers
Unique pointers are the most common type of smart pointer.

## Shared Pointers

## Weak Pointers

# Smart Pointers and Exception Safety
By automatically taking care of freeing the allocated memory, smart pointers allow you to safely throw errors without risking memory leak.
