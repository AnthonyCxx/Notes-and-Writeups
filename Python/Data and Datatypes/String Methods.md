# String Methods in Python

## Modifying Strings

## Formatting Strings

### _.center()_
_.center()_ returns a new string with the text centered in the middle of the amount of characters specified. <br />
Providing a character as the second argument will fill the blank space with the given character.

```Python
event = "showdown"

event = event.center(10, '.')
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

## Miscellaneous

### _.count()_
Returns the amount of times a substring occurs in the string. <br />
You can also specify a start and end index as optional arguments.

```Python
sentence = "This is a sentence about a needle in a haystack. How many needles are in this haystack? Well, as many needles as there are."

count = sentence.count("needle")

print(f"The amount of times the word 'needle' appears in the sentence is: {count}")
```
