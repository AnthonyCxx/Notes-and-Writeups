# Data Structures and Algorithms, using C++
A collection of implementations of data structures and algorithms, prefaced by their complexity. `DNU` means "**DO NOT USE**", marking something that exists only for you to explore or understand. For example, using a [linear congruential generator](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Randomization/Linear%20Congruential%20Generator.cpp) (like `rand()`) is an objectively inferior choice when 
compared to C++'s implementation of the Mersenne Twister algorithm ([mt19937](https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine)); even if you weren't 
to consider mt19937, `rand()` is infamous for being biased towards the lower end the distribution. Regardless of your use case, it should be marked `DNU`.

> [Data Structures](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Data%20Structures%20and%20Algorithms/README.md#data-structures) <br />
> [Searching Algorithms](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Data%20Structures%20and%20Algorithms/README.md#searching-algorithms) <br />
> [Sorting Algorithms](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Data%20Structures%20and%20Algorithms/README.md#sorting-algorithms) <br />

# Data Structures
- [Arrays](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C++/Data%20Structures%20and%20Algorithms/Data%20Structures/Arrays.md)

# Searching Algorithms
| Time Complexity | Space Complexity | Algorithm | Requirements |
| --------------- | ---------------- | --------- | ------------ |
| `O(log n)` | `O(1)` | [Iterative Binary Search](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Searching%20Algorithms/Binary%20Search%20Iterative.cpp) | sorted data |
| `O(log n)` | `O(log n)` | [Recursive Binary Search](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Searching%20Algorithms/Binary%20Search%20Recursive.cpp) | sorted data |
| `O(n)` | `O(1)` | [Sequential Search](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Searching%20Algorithms/Sequential%20Search.cpp) | - |

# Sorting Algorithms
| Time Complexity | Space Complexity | Algorithm | Best on | Worst on | Stable? |
| --------------- | ---------------- | --------- | ------- | -------- | ------- |
| `O(n log n)` | `` | [Quick Sort](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Sorting%20Algorithms/Quick%20Sort.cpp) |  - | - | unstable |
| `O(n log n)` | `` | [Merge Sort](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Sorting%20Algorithms/Merge%20Sort.cpp) |  - | - | - |
| `O(n²)` | `` | [Exchange Sort](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Sorting%20Algorithms/Exchange%20Sort.cpp) |  - | - | - |
| `O(n²)` | `` | [Selection Sort](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Sorting%20Algorithms/Selection%20Sort.cpp) | - | - | unstable |
| `O(n²)` | `` | [Bubble Sort](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Sorting%20Algorithms/Bubble%20Sort.cpp) | - |  - | stable |
| `O(n²)` | `` | [Insertion Sort](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Sorting%20Algorithms/Insertion%20Sort.cpp) | - | - | stable |
> [What is Algorithmic Stability and Why is it Important?](https://www.youtube.com/watch?v=KJuxI1BBLyQ)

# Other Algorithms
- [Fibonacci Sequence](https://github.com/EthanC2/Notes-and-Writeups/tree/main/C++/Data%20Structures%20and%20Algorithms/Other%20Algorithms/Fibonacci%20Sequence)
- [Randomization](https://github.com/EthanC2/Notes-and-Writeups/tree/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Randomization)

# Miscellaneous Tricks and Problems
- [Reverse an Integer](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Miscellaneous/Reverse%20a%20Number.cpp)
- Levenshtein Distance: [Check for String Similarity](https://www.cuelogic.com/blog/the-levenshtein-algorithm)

# Concepts
- [Algorithmic Stability](https://www.youtube.com/watch?v=KJuxI1BBLyQ)

# LeetCode Solutions
