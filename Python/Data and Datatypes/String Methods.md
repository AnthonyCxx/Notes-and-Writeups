# String Methods in Python
Python is all about strings. So, naturally they have a host of methods for manipulating them.

## Searching Strings

### _.find()_
_.find()_ returns the index of a substring. If the string is not found, _.find()_ returns -1. <br />
Optionally, you can specify a start and end index as integers. 

```Python
text = "Arma virumque cano, Troiae qui primus ab oris..."

if text.find("goejagiae this is not a valid substring") == -1:
    print("Hmm... guess that substring wasn't in the text...")
```

### _.index()_
_.index()_ returns the index of a substring. If the string is not found, an [ValueError](https://docs.python.org/3/library/exceptions.html#ValueError) is thrown. <br />
Optionally, you can specify a start and end index as integers. 

```Python

```

### _.endswith()_
_.count()_ returns _True_ if the string ends with the given substring. <br />
Optionally, you can specify a start and end index as integers. 

```Python
sentence = "This sentence ends with the word apple"

if sentence.endswith("apple"):
    print("The sentence ends with 'apple'")
```

### _.count()_
_.count()_ returns the amount of times a substring occurs in the string. <br />
You can also specify a start and end index as optional arguments.

```Python
sentence = "This is a sentence about a needle in a haystack. How many needles are in this haystack? Well, as many needles as there are."

count = sentence.count("needle")

print(f"The amount of times the word 'needle' appears in the sentence is: {count}")
```

## Modifying Strings

## Formatting Strings

### _.format()_
The _.format()_ method is the pre-Python 3.6 way to format strings. <br />
You should always use [f-strings](https://www.programiz.com/python-programming/string-interpolation) for string interpolation. <br />
_.format()_ works very much like [_printf()_](https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm) from C. 

```Python
name = input("Enter your name: ")

greeting = "Hello, {}! How are you today :)?".format(name) # 'name' replaces '{}'
```

### _.format\_map()_
_.format\_map()_ formats a string automatically using a dictionary.

```Python
person_dict = {"name":"Cthulhu", "occupation":"construction worker"}

greeting =  "Hello, my name is {name} and my I am a {occupation}".format(**person_dict)
```

### _.center()_
_.center()_ returns a new string with the text centered in the middle of the amount of characters specified. <br />
Providing a character as the second argument will fill the blank space with the given character.

```Python
event = "showdown"

event = event.center(10, '.')
```

### _.expandtabs()_
_.expandtabs()_ takes an integer that represents the amount of characters a space will be printed as for that strings.

```Python
tabbedstring = "\tThis\tis\ttabbed\ttext"

print(tabbedstring)                   # Default tab (8 chars)
print(tabbedstring.expandtabs())      # Default tab
print(tabbedstring.expandtabs(2))     # Two characters
print(tabbedstring.expandtabs(5))     # Five characters
```

## Altering Case

### _.capitalize()_
Returns a new string, capitalizing the first letter in the string.

```Python
sentence = "this is not a proper sentence because the first letter is not capitalized."

sentence = sentence.capitalize()
```

### _.casefold()_
_.casefold()_ returns a new string that is entirely lowercase. <br />
Unlike _.lower()_, _.casefold()_ works with unicode capitals.

```Python
surname = "Weißflog"

surname = surname.casefold() # Changed to 'weissflog'
```

## Classifying Strings

### _.isalpha()_
Returns _True_ if the string is alphabetic (letters a-zA-Z)

```Python
sentence = "This is a plain an simple English sentence"

if sentence.isalpha():
    print("The string is alphabetic")
```

### _isnumeric()_
Returns _True_ if the string is numeric (contains only digits 0-9)

### _.isalnum()_

### _.isdecimal()_

### _.isdigit()_


## Miscellaneous

### _.encode()_
_.encode()_ returns a new string, converting unicode characters to ASCII. <br />
The way the string is encoded depends on the second argument, _errors_, which can be set to any of a set of [replacement protocols](https://www.w3schools.com/python/ref_string_encode.asp) for properly translating unicode characters.

```Python
surname = "Weißflog"

ascii_name = surname.encode()
```
