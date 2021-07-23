Classes are the heart of C++. A class is essentially a user-defined datatype that serves as a collection of data and functions.
Classes are meant to mimic some concrete object or abstract idea. For example, a class 'Player' would contain a string for their name, an integer for their health, 
an integer for their attack damage and another integer to represent their level. These four variables together would allow us to create a single variable of type 'Player' 
that would have all of these properties.

In addition to data, classes can have methods which allow to class to perform actions. 
These actions don't have to affect other data; in fact, many methods are entirely internal. For example, if we extended the definition of a string, we could define 
a method 'isPalindrome' which return true if the word was a palindrome and false if the word wasn't. 
