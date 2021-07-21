# Input in C++ with _cin_
_cin_, which stands for 'character input' belongs to the [\<iostream\>](https://en.cppreference.com/w/cpp/header/iostream) library and is used to read characters to [stdin](http://www.cs.kent.edu/~durand/CS1/Notes/06_IO/cs1_io.html) (the keyboard). _cin_ generally uses an [overloaded](https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm) 
left bit-shift operator (>>) to read from the keyboard (e.g. `cin >> someVariable`), but also has other functions like [_cin.get()_](https://www.geeksforgeeks.org/cin-get-in-c-with-examples/) 
and [_cin.getline()_](https://www.includehelp.com/cpp-programs/cpp-program-to-read-string-using-cin-getline.aspx). 

Note: cin is an object within the std (standard) namespace. If you want to use it without `using namespace std`; at the top of your program, you'll have to write `std::cin` instead of just `cin` every time you use it.

## Sources
GeeksforGeeks: [_cin.get() in C++ with Examples_](https://www.geeksforgeeks.org/cin-get-in-c-with-examples/) <br />
