# Smart Pointers and RAII in C++
RAII ("**R**esource **A**cquisition **I**s **I**nitialization") is one of the defining distinctions between legacy and modern C++. C++11 introduced [smart pointers](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Memory%20Management/Smart%20Pointers%20and%20RAII.md) (also called scoped pointers), which automatically take care of allocating and freeing memory.
Smart pointers are essentially a class that acts as a thin wrapper around a raw (normal) pointer; the wrapper allocates dynamic memory in their constructor and deallocates it in
their destructor. By binding the dynamically-allocated (heap) memory to the pointer that's allocated on the stack, you entirely avoid the problem of memory leak. This is why C++'s approach to memory management is so effective — is entirely nullifies the need for a garbage collector by not creating any garbage in the first place. As an added bonus, smart pointers also eliminate the problem of dangling pointers.

---

# Unique, Shared, and Weak Pointers
C++ defines three types of smart pointers in the [\<memory\>](https://en.cppreference.com/w/cpp/header/memory) library, each with their own type of ownership.

---

## Unique Pointers
Unique pointers are the most common type of smart pointer. Unique pointers are called unique because they are the _only_ references to their data. Assignment from
unique pointers (`operator=`) as well as references (`&`) to them are illegal and will raise compile-time errors — this is necessary to prevent dangling pointers. 
The only transfer operation allowed on unique pointers is moving (via `std::move()`), which will leave it as `nullptr`.

## Passing Unique Pointers
Since passing by value makes a copy, you cannot pass a unique pointer by value like `func(std::unique_ptr<int> ptr)`. You must either pass by reference or call `std::move()`. 
Alternatively, you can use the `.get()` function to return a reference to the internal pointer, but that can be dangerous since the deallocation of a unique pointer is automatic
and if you cannot guarantee that the unique pointer will exist for the whole function call, then you run the risk of having a dangling pointer.



---

## Shared Pointers

---

## Weak Pointers

---

# Smart Pointers and Exception Safety
By automatically taking care of freeing the allocated memory, smart pointers allow you to safely throw errors without risking memory leak.
