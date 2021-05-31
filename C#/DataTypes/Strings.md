# Strings

## Quotations
### @"String"
Prefixing a string with a _@_ will make the string raw (disables escape characters). <br />
This comes in extremely handy with Windows as Windows uses backslashes as a delimiter to separate files and folders.
```C#
string filepath = @"C:\Program Files";
```

### $"{String}"
Prefixing a string with a _$_ and then putting a variable, function, expression, etc. in _{ }_ will replace it with the value/result.
```C#
//Promp the user for their name
Console.Write("Enter your name: ");

//Read in their name
string name = Console.ReadLine();

//Greet the user
Console.WriteLine($"Hello, {name}"; 
```

## Methods

### .Join()
The _string.Join(**_separator_**, **_iterable object_**)_
```C#
//Declare and initialize an array of students
string[] students = {"Henry", "Charlie", "Seth"};

//Print the students in a comma-separated string
Console.WriteLine(string.Join(", ", students));
```
