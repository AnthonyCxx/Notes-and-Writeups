# Chapter 1
This is going to be beefy.

- _Non-decreasing Order_: an ordering in which the numbers do not necessarily increase, but never decrease. Basically increasing order but the number could be the same;
\[1, 1, 2, 3\] is non-decreasing order, but not increasing order since there is no increase between 1 and 1.
- _Parameter_: a variable in a problem that has not been assigned a specific value yet.
- _Algorithm_: Step by step procedure that produces an answer to a question.

### Time Complexity
- _Time Complexity Analysis_: How many times is the basic operation done for each value of the input size.
- _Every-case Time Complexity_: When the number of times of the basic operation is done on an input size n(T(n)) is always the same (like sequential search).
- _Worst-case Time Complexity_: W(n) is the maximum number of times an algorithm will do its basic operation on an input of size _n_. If the every-case complexity exists, then W(n) = T(n).
- _Best-case Time Complexity_: B(n) the minimum number of times an algorithm will perform its basic operation on an input size of _n_. If every-case time complexity exists, B(n) = T(n).

- Overhead Instructions: instructions that must be performed prior to using an algorithm.
- Control Instructions: instructions that must be performed during the algorithm.

### Order of a Function (Big-O Notation)
- _Linear Time Algorithms_: n, n/2
- _Quadratic time algorithms_: 5n^2, (5n^2) + 100
