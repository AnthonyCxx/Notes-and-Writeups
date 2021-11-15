# Smart Pointers and RAII in C++
RAII ("**R**esource **A**cquisition **I**s **I**nitialization") is one of the defining distinctions between legacy and modern C++. C++11 introduced [smart pointers](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Memory%20Management/Smart%20Pointers%20and%20RAII.md) (also called scoped pointers), which automatically take care of allocating and freeing memory.
Smart pointers are essentially a class that acts as a thin wrapper around a raw (normal) pointer; the wrapper allocates dynamic memory in their constructor and deallocates it in
their destructor. By binding the dynamically-allocated (heap) memory to the pointer that's allocated on the stack, you entirely avoid the problem of memory leak. This is why C++'s approach to memory management is so effective — is entirely nullifies the need for a garbage collector by not creating any garbage in the first place. As an added bonus, smart pointers also eliminate the problem of dangling pointers.

As a (cultural?) note, the debate between raw vs smart pointers is one of those hills that people have pretty strong opinions on as a by-project of the near-religous stances people have on how you should write C++ code and whether or not it's ok to use "non-modern" features like raw pointers and C-style arrays. Honestly, I think that using raw pointers is fine as long as you are careful, especially since smart pointers may lead to less efficient code (see Chandler Carruth's [_There Are No Zero-cost Abstractions_](https://www.youtube.com/watch?v=rHIkrotSwcc)). At the same time, Herb Sutter's [_Elements of Modern C++ Style_](https://herbsutter.com/elements-of-modern-c-style/) explicitly says "always use the standard smart pointers, and non-owning raw pointers. Never use owning raw pointers and delete, except in rare cases when 
implementing your own low-level data structure (and even then keep that well encapsulated inside a class boundary)."

---

# Unique, Shared, and Weak Pointers
C++ defines three types of smart pointers in the [\<memory\>](https://en.cppreference.com/w/cpp/header/memory) library, each with their own type of ownership.
Smart pointers are fundamentally tied to the concept of memory ownership, so you shouldn't use them as references to other variables — only to safely manage dynamic memory.

---

## Unique Pointers
Unique pointers are the most common type of smart pointer. Unique pointers are called unique because they are the _only_ references to their data. Assignment from
unique pointers (`operator=`) as well as references (`&`) to them are illegal and will raise compile-time errors — this is necessary to prevent dangling pointers. 
The only transfer operation allowed on unique pointers is moving (via `std::move()`), which will leave it as `nullptr`.

## Declaring a Unique Pointer
If you are following modern C++ guidelines, you should never see the _new_ operator anywhere in your code. Whenever you declare a unique pointer, you should
always initialize it with the built-in helper function `std::make_unique<T>()`, which returns a new object of type T. `std::make_unique<T>()` forwards its arguments
argument to the constructor of the object it creates, so don't worry about lvalues and rvalues.

```C++
#include <iostream>
#include <memory>
int main()
{
    //Declare a unique pointer to a new integer
    std::unique_ptr<int> ptr = std::make_unique<int>(10);
    
    //Use the new pointer
    std::cout << "Point value: " << *ptr << '\n';
    
    return 0;
} 
// The unique pointer is automatically freed //
```

## Passing Unique Pointers
Since passing by value makes a copy, you cannot pass a unique pointer by value like `func(std::unique_ptr<int> ptr)` without calling `std::move()`. You must either pass by reference. You _could_ use the `.get()` function to return a reference to the internal pointer, but that can be dangerous since the deallocation of a unique
pointer is automatic and if you cannot guarantee that the unique pointer will exist for the whole function call, then you run the risk of dereferencing a dangling pointer,
which is UB (undefined behavior).

```C++
#include <iostream>
#include <memory>

template <typename T>
void byUniqueRef(std::unique_ptr<T>& ptr)  //Passed unqiue_ptr by reference
{
    std::cout << "Passed the unique pointer by reference: " << *ptr << '\n';
}

template <typename T>
void byUniqueMove(std::unique_ptr<T> ptr)  //Passed unique_ptr by value (requires std::move()!)
{
    std::cout << "Passed the unique pointer by value (std::move()): " << *ptr << '\n';
}

template <typename T>
void byRawPtr(T* ptr)  //Passed raw pointer by value
{
    std::cout << "Passed by raw pointer: " << *ptr << '\n';
}


int main()
{
    //Declare a unique pointer
    std::unique_ptr<int> ptr = std::make_unique<int>(10);

    //Pass the unique pointer to a function by reference
    byUniqueRef(ptr);

    //Pass the unique pointer to a function by raw pointer -- risks dangling pointer! (ok, not in this context, but others)
    byRawPtr(ptr.get());

    //Pass the unique pointer to a function by moving it (leaves 'ptr' as a nullptr)
    byUniqueMove(std::move(ptr));

    //Because you moved ptr, it should be equal to nullptr
    if (ptr == nullptr)
        std::cout << "ptr == nullptr\n";   //True
    else
        std::cout << "ptr != nullptr\n";  //False

    return 0;
}
```

---

## Shared Pointers

---

## Weak Pointers

---

# Smart Pointers and Exception Safety
By automatically taking care of freeing the allocated memory, smart pointers allow you to safely throw errors without risking memory leak.
