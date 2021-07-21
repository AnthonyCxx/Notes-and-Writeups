# Input in C++ with _cin_
_cin_, which stands for 'character input' belongs to the [\<iostream\>](https://en.cppreference.com/w/cpp/header/iostream) library and is used to read characters to [stdin](http://www.cs.kent.edu/~durand/CS1/Notes/06_IO/cs1_io.html). 

Note: cout is an object within the std (standard) namespace. If you want to use it without `using namespace std`; at the top of your program, you'll have to write `std::cin` instead of just `cin` every time you use it.


_cin_ generally uses an [overloaded](https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm) left bit-shift
operator (>>) to read from the keyboard (e.g. `cin >> someVariable`), but also has other functions like [_cout.put()_](https://en.cppreference.com/w/cpp/io/basic_ostream/put) and [_cout.write()_](https://en.cppreference.com/w/cpp/io/basic_ostream/write). 
