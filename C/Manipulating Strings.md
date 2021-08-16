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
#include <stdlib.h>
#include <string.h>

//Going to assume that I don't know how long the orignal string is and I have to allocate the memory
char* original = "Madame Zostra";
char* copy = (char*) malloc(strlen(original) +1);
    
strcpy(copy, original);

puts(copy);
free(copy);
```

## Concatenating String with _strcat()_ and _strncat()_
_strcat()_ and _strncat()_ [concatenate](https://en.wikipedia.org/wiki/Concatenation) two strings.

Like with _strcpy()_ and _strncpy()_, _strncat()_ is just _strcat()_ but stops after _n_ characters.

```C  
char greeting[50] = "Good morning, ";
char name[26];
    
//Get the user's name
printf("Enter your name: ");
fgets(name, sizeof(name), stdin);
    
//Make the full greeting
strcat(greeting, name);
    
//Greet the user
puts(greeting);
```

## Comparing Strings with _strcmp()_ and _strncmpy()_
Comparing strings is incredibly useful for a number of things, like alphabetizing.
[_strcmp()_](https://www.tutorialspoint.com/c_standard_library/c_function_strcmp.htm) returns an integer depending on the result of the comparison. 0 is equal, greater than 0 means first was greater, less than 0 means second was greater.

Yes, _strcmp()_ has a _strncmpy()_ counterpart. Yes it does the exactly what you expect.

| Result | Meaning |
| ------ | ------- |
| > 0 | first string is greater |
| == 0 | the strings are identical |
| < 0 | first string is lesser |
> Note: capital letters are smaller than lowercase ones because they come first in ASCII.

```C
const char* name1 = "Seth";
const char* name2 = "Seth";
    
if (strcmp(name1, name2) == 0)
    puts("The names are identical in content and in case");
```

## Searching for Substrings with _strstr()_
[_strstr()_](https://www.tutorialspoint.com/c_standard_library/c_function_strstr.htm) returns a char pointer to the first instance of a substring.

```C
const char* text = "Hello, I can\'t hear you. Hello? Hello?";
const char* substring = "hear";
    
char* instance = strstr(text, substring);
printf("The rest of the text after and including the substring is: %s\n", instance);
```

## Searching for Characters with _strchr()_ and _strrchr()_
[_strchr()_](https://www.tutorialspoint.com/c_standard_library/c_function_strchr.htm) returns a char pointer to the first instance of a character in a string. <br />
If the character is not found, _strchr()_ returns _NULL_. _strrchr()_ works just like _strchr()_ except _strrchr()_ searches in reverse.

_strchr()_ DOES include the character searched for in the pointer, so I added 1 here to disclude it.
```C
const char* phoneNumber = "+1-716-839-0712";
const char* rawNumber = strchr(phoneNumber, '-') + 1;   //Add 1 to ignore the '-'
    
printf("The phone number without the country code is: %s", rawNumber);
```
> If you want the specific character and not the rest of the array, do `rawNumber[0]` to only access that element.
