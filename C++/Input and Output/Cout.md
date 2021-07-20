# Output in C++ with _cout_
_cout_, which stands for 'common output' (at least what I heard from college, I've also seen 'character output' and 'console output') writes characters to [stdout](https://en.cppreference.com/w/cpp/io/c/std_streams). _cout_ generally uses an [overloaded](https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm) right bit-shift
operator (<<) to write to the screen (e.g. `cout << "Hello, World!\n"`). In addition to providing
