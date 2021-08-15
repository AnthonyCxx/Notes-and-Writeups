# Manipulating C-Strings in C
The [_\<string.h\>_](https://www.tutorialspoint.com/c_standard_library/string_h.htm) library contains a number of functions for manipulating c-strings like [_strlen()_](https://www.tutorialspoint.com/c_standard_library/c_function_strlen.htm), [_memcpy()_](https://www.tutorialspoint.com/c_standard_library/c_function_memcpy.htm), [_memset()_](https://www.tutorialspoint.com/c_standard_library/c_function_memset.htm), and [_strcat()_](https://www.tutorialspoint.com/c_standard_library/c_function_strcat.htm).


## Finding the Length of a String, _strlen()_
_strlen()_ returns the length of a string, discluding the null-terminating character ('\0').

Size in C is stored with the [_size\_t_](https://www.geeksforgeeks.org/size_t-data-type-c-language/) datatype, which is basically just a special integer for storing size.
```C
#include <stdio.h>
#include <string.h>

int main()
{
    const char* name = "Simon";
    size_t length = strlen(name);
    
    //'length' is of type 'size_t' (z) and is unsigned (u), so it uses 'zu' as its format specifier
    printf("There are %zu characters in the name \'Simon\'", length);

    return 0;
}
```
