# Binary Sequence Types in Python
The [_bytes_](https://www.programiz.com/python-programming/methods/built-in/bytes), [_bytearray_](https://www.programiz.com/python-programming/methods/built-in/bytearray), and [_memoryview_](https://www.geeksforgeeks.org/memoryview-in-python/) are datatypes oriented towards manipulating binary data. _bytes_ and _bytearray_ store binary data; 
_memoryview_ is used to access the data without needing to create a copy.

Here is some good reading on dealing with binary data in Python: <br />
Medium: [_Strings, Unicode, and Bytes in Python 3: Everything You Always Wanted to Know_](https://betterprogramming.pub/strings-unicode-and-bytes-in-python-3-everything-you-always-wanted-to-know-27dc02ff2686) <br />
Eli Bendersky's Blog: [_The bytes/str dichotomy in Python 3_](https://eli.thegreenplace.net/2012/01/30/the-bytesstr-dichotomy-in-python-3) <br />

## _bytes_
The _bytes_ datatype is immutable and stores a single byte (8 bits) of data. The valid range for the value of a _bytes_ object is 0-255 (2^8 possible values).

## _bytearray_
The _bytearray_ type is a mutable array of _bytes_ objects. It functions like a standard array and even has a host of methods for manipulating/changing the bytes inside 
it.

## _memoryview_
