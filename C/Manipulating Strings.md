# Manipulating C-Strings in C
The [_\<string.h\>_](https://www.tutorialspoint.com/c_standard_library/string_h.htm) library contains a number of functions for manipulating c-strings like [_strlen()_](https://www.tutorialspoint.com/c_standard_library/c_function_strlen.htm), [_memcpy()_](https://www.tutorialspoint.com/c_standard_library/c_function_memcpy.htm), [_memset()_](https://www.tutorialspoint.com/c_standard_library/c_function_memset.htm), and [_strcat()_](https://www.tutorialspoint.com/c_standard_library/c_function_strcat.htm).

Note: whenever I say 'string', I'm really referring to a c-string, which is just an array of characters.

## Length of a String, _strlen()_
[_strlen()_](https://www.tutorialspoint.com/c_standard_library/c_function_strlen.htm) returns the length of a string, discluding the null-terminating character (\0).

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

## Copying Strings with _strcpy()_ and _strncpy()_
All strings are char arrays, which are just pointers behind the scenes. If you assign one pointer to another (one string to another), then you just get an alias for
the exact same string, not a new copy. So, C provides the [_strcpy()_](https://www.tutorialspoint.com/c_standard_library/c_function_strcpy.htm) and [_strncpy()_](https://www.tutorialspoint.com/c_standard_library/c_function_strncpy.htm) functions to iteratively copy strings from a source to a destination.

The only difference between _strcpy()_ and _strncpy()_ is that _strncpy()_ only copies _n_ characters where _n_ is a number passed to the function.
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //Going to assume that I don't know how long the orignal string is and I have to allocate the memory
    char* original = "Madame Zostra";
    char* copy = (char*) malloc(strlen(original) +1);
    
    strcpy(copy, original);

    puts(copy);
    free(copy);

    return 0;
}
```
