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
There are [three ideal qualities](http://web.mit.edu/1.124/LectureNotes/sorting.html) for sorting algorithms: O(n log n) time, O(1) space complexity, and [stability](https://www.youtube.com/watch?v=KJuxI1BBLyQ).

| Time Complexity | Space Complexity | Algorithm | Best on | Worst on | Stable? |
| --------------- | ---------------- | --------- | ------- | -------- | ------- |
| `O(nk)`| `O(n+k)` | Radix Sort | - | - | stable |
| `O(n log n)` | `O(log n)` | [Quick Sort](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Sorting%20Algorithms/Quick%20Sort.cpp) |  - | - | unstable |
| `O(n log n)` | `O(1)` | Heap Sort | all same value | distinct values | unstable |
| `O(n log n)` | `O(n)` | [Merge Sort](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Sorting%20Algorithms/Merge%20Sort.cpp) |  - | - | stable |
| `O(n²)` | `O(1)` | [Exchange Sort](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Sorting%20Algorithms/Exchange%20Sort.cpp) |  - | - | stable |
| `O(n²)` | `O(1)` | [Bubble Sort](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Sorting%20Algorithms/Bubble%20Sort.cpp) | - |  - | stable |
| `O(n²)` | `O(1)` | [Insertion Sort](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Sorting%20Algorithms/Insertion%20Sort.cpp) | - | - | stable |
| `O(n²)` | `O(1)` | [Selection Sort](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Sorting%20Algorithms/Selection%20Sort.cpp) | - | - | unstable |

# General Algorithms
- [Randomization](https://github.com/EthanC2/Notes-and-Writeups/tree/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Randomization)

# Other Algorithms
- [Fibonacci Sequence](https://github.com/EthanC2/Notes-and-Writeups/tree/main/C++/Data%20Structures%20and%20Algorithms/Other%20Algorithms/Fibonacci%20Sequence)

# Miscellaneous Tricks and Problems
- [Custom atoi() Function](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Miscellaneous/Custom%20atoi()%20Function.cpp)
- Levenshtein Distance: [Check for String Similarity](https://www.cuelogic.com/blog/the-levenshtein-algorithm)

# Concepts
- [Common Data Structures](https://leetcode.com/explore/learn/) (+ exercises)
- [Big O Notation](https://www.youtube.com/watch?v=v4cd1O4zkGw&)
- [Algorithmic Stability](https://www.youtube.com/watch?v=KJuxI1BBLyQ)

# Resources
- Leetcode: [Problems](https://leetcode.com/problemset/all/) and [DSA problems](https://leetcode.com/explore/learn/)
- Neetcode: [Algorithms Playlists](https://www.youtube.com/c/NeetCode/playlists) and [_How I Got Good at Coding Interviews_](https://www.youtube.com/watch?v=SVvr3ZjtjI8)
- [300 Coding Interview Problems](https://www.interviewbit.com/coding-interview-questions/)

# LeetCode Solutions
- 1: [Two Sum](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Leetcode/1.%20Two%20Sum.cpp)
- 7: [Reverse an Integer](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Leetcode/7.%20Reverse%20Integer.cpp)
- 20: [Valid Parentheses](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Leetcode/20.%20Valid%20Parentheses.cpp)
- 26: [Remove Duplicates from Sorted Array](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Leetcode/26.%20Remove%20Duplicates%20from%20Sorted%20Array.cpp)
- 65: [Valid Number](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Leetcode/65.%20Valid%20Number.cpp)
- 74: [Search a 2D Matrix](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Leetcode/74.%20Search%20a%202D%20Matrix.cpp)
- 75: [Sort Colors](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Leetcode/75.%20Sort%20Colors.cpp)
- 125: [Valid Palindrome](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Leetcode/125.%20Valid%20Palindrome.cpp)
- 191: [Number of 1 Bits](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Leetcode/191.%20Number%20of%201%20Bits.cpp)
- 344: [Reverse String](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Leetcode/344.%20Reverse%20String.cpp)
- 1480: [Running Sum of 1d Array](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Leetcode/1480.%20Running%20Sum%20of%201d%20Array.cpp)
- 1672: [Richest Customer Wealth](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Leetcode/1672.%20Richest%20Customer%20Wealth.cpp)
- 1929: [Concatenation of Array](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%2B%2B/Data%20Structures%20and%20Algorithms/Leetcode/1929.%20Concatenation%20of%20Array.cpp)
