# Strings

## Quotations
### Raw Strings (@)
Prefixing a string with a _@_ will make the string raw (disables metacharacters, such as escape characters). <br />
This comes in extremely handy with Windows as Windows uses backslashes as a delimiter to separate files and folders.
```C#
//Declaring a filepath
string filepath = @"C:\Program Files";

//Quoting someone
Console.WriteLine("And they said "Next time, be more careful"");
```

### Interpolated Strings ($, { })
Prefixing a string with a _$_ and then putting a variable, function, expression, etc. in _{ }_ will replace it with the value/result. <br />
String interpolation is a shorthand for calling the _String.Format()_ method. <br />
```C#
//Promp the user for their name
Console.Write("Enter your name: ");  //No implicit \n

//Read in their name
string name = Console.ReadLine();

//Greet the user by name
Console.WriteLine($"Hello, {name}"; 
```

## Methods

### .Join()
The _string.Join(**_separator_**, **_collection_**)_ method converts all the elements of a collection into a single string, separated
by a separator
```C#
//Declare and initialize an array of students
string[] students = {"Henry", "Charlie", "Seth"};

//Print the students in a comma-separated string
Console.WriteLine(string.Join(", ", students));
```

### .Format()
The _string.Format(**_string_**, **_variable_**) method replaces sections of the string the the result of an expression or value of a variable
```C#
string animal = "squirrel";
//The {0} is replaced by the value of 'animal'. If you added another variable, you'd do {1}
Console.WriteLine( string.Format("That\'s a cute {0}", animal) );
```
