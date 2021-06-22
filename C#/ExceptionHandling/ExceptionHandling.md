# Exception Handling Keywords in C#
It's never uncommon to have unexpected results in programming, especially when opening up your program to a layman. Take the following snippet for example. Here, 
you can see that the user is prompted to enter a number between 1 and 100 to display the contents of that index in the array (all of which are 0, by the way). If 
the user enters a number outside of that range, then the program will crash with a _System.IndexOutOfRange_ exception. Now, you could solve this a few ways. For one,
you could use a [_do-while loop_](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/ControlFlow/Loops.md#dowhile-statement) to validate the their input.
Alternatively, you could mod (%) the input by the length of the array, preventing the result from exceeding the upper bound of the array; however, this does not prevent
the user from entering a negative number and exceeding the lower bound (which still throws a _System.IndexOutOfRange_ exception). Ideally, you would use a _do-while_ loop
to validate the input and then use exception handling as a fallback.

```C#
public static void Main(string[] args)
{
  //An array of 100 integers, all of which are 0
  int[] array = new int[100];   
  Array.Fill(array, 0);

  //Get an index from the user
  Console.Write("Enter an index (between 1 and 100): ");
  int index = int.Parse( Console.ReadLine() ) - 1;   //Subtract 1 because the max index is 99

  //Display the contents of that index
  Console.WriteLine($"Index {index} contains {array[index]}");
}
```

## Try and Catch
Basic exception handling is built upon two keywords: _try_ and _catch_. The _try_ keyword denotes a block of code that the programmer suspects an error
may occur in. In the example above, the error may occur when displaying the contents of the index, because it may access a non-existent index. So, the statment
_Console.WriteLine($"Index {index} contains {array\[index\]}");_ should be put in a _try_ block. Follwing the _try_ block should be a _catch_ block to catch the
exception. The parameter of the _catch_ block should be the expected exception. If you want to know the exception message, put an [identifier](https://docs.microsoft.com/en-us/cpp/c-language/c-identifiers?view=msvc-160) after the expected exception (remember, the exception name is a class) and then write the object to console.

```C#
public static void Main(string[] args)
{
  //An array of 100 integers, all of which are 0
  int[] array = new int[100];
  Array.Fill(array, 0);

  //Get an index from the user
  Console.Write("Enter an index (between 1 and 100): ");
  int index = int.Parse(Console.ReadLine()) - 1;

  try
  {
    //Display the contents of that index
    Console.WriteLine($"Index {index} contains {array[index]}");
  }
  catch (IndexOutOfRangeException)   //Identifier goes here, like 'IndexOutOfRangeException e', where 'e' is the name of the object
  {
    Console.WriteLine("Error: the given index does not exist");       //Console.WriteLine(e);  would display the message
  }
}
```
If you do not know the type of exception, use the generic [_Exception_](https://docs.microsoft.com/en-us/dotnet/api/system.exception?view=net-5.0) exception, which will catch any errors. Just as a final note, you can (and often should) have multiple _catch_ blocks for a single _try_ block, one for each possible error.

## Throw
The _throw_ keyword allows the programmer to manually raise an exception, which is good for directly controlling the flow of the program and is especially useful for throwing [user-defined exceptions](https://docs.microsoft.com/en-us/dotnet/standard/exceptions/how-to-create-user-defined-exceptions) (as opposed to compiler-generated exceptions).
```C#
public static void Main(string[] args)
{
  //Declare an array of items
  var backpack = new string[] { "Pencil", "Paper", "Scissors", "Strange Relic from the 4th Age...?" };

  try
  {
    //Refer to the notes below the code for an explanation on this behemoth
    if (!Array.Exists(backpack, str => str == "a non-existant item"))  //If no item in the backpack is 'a non-existant item'
      throw new ItemNotFoundException("The item does not exist");     //Then, throw 'ItemNotFoundException' with the message 'The item does not exist'
  }
  catch(ItemNotFoundException e)
  {
    Console.WriteLine(e.Message);   //Call the 'Message' property to access the string 'The item does not exist'
  }
 
}
        
//Custom error class 'ItemNotFoundException'
class ItemNotFoundException : Exception    //Custom exception inherits from the 'Exception' class
{
  //Default Constructor
  public ItemNotFoundException()
  { 

  }
  
  //Parameterized constructor (allows for custom messages via the 'Message' property)
  public ItemNotFoundException(string message) : base(message)
  { 

  }

  //Parameterized Constructor with an 'inner' exception (see the references below).
  public ItemNotFoundException(string message, Exception inner) : base(message, inner)
  { 

  }
}
```
> Note: the '[_new_](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/new-operator)' operator after the '_throw_' is necessary because it creates the exception. Without the _new_ keyword, the object would not exist. <br />
> 
> Reference: [C# Documentation: _Array.Exists(**_array_**, **_predicate_**)_ Method](https://docs.microsoft.com/en-us/dotnet/api/system.array.exists?view=net-5.0) <br />
> Reference: [C# Documentation: InnerException Property](https://docs.microsoft.com/en-us/dotnet/api/system.exception.innerexception?view=net-5.0) <br />

In this example, I used a [_lambda expression_](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/lambda-expressions) as the [_predicate delegate_](https://www.tutorialsteacher.com/csharp/csharp-predicate#:~:text=Predicate%20is%20the%20delegate%20like,a%20boolean%20%2D%20true%20or%20false.) for the _Array.Exists(**_array_**, **_predicate_**)_ method. A predicate delegate is just a simple expression that returns true or false based on whether the given criteria. Here,
I used a lambda expression as the criteria instead of declaring a whole function. Together, the lambda expression and predicate just take the string at the current index
(_str_) and check whether it is equal to the string 'a non-existant item'. Since no item is equal to 'a non-existant item', the _Array.Exists()_ method returns false, which
then throws the custom 'ItemNotFoundException' exception.

## Finally
> External Citation: the following was taken from the Microsoft C# Documentation cited below as 'C# Documentation: Finally Blocks'. <br />

"A finally block enables you to clean up actions that are performed in a try block. If present, the finally block executes last, after the try block and any matched catch block. A finally block always runs, whether an exception is thrown or a catch block matching the exception type is found. <br />

The finally block can be used to release resources such as file streams, database connections, and graphics handles without waiting for the garbage collector in the runtime to finalize the objects." <br />

```C#
FileStream? file = null;
FileInfo fileinfo = new System.IO.FileInfo("./file.txt");
try
{
    file = fileinfo.OpenWrite();    
    file.WriteByte(0xF);  //The number '15' in hexadecimal
}
finally
{
    //Check for null because OpenWrite might have failed (unauthorized access, invalid path format, etc.)
    file?.Close();
}
```
> [_File.OpenWrite()_ Exceptions](https://docs.microsoft.com/en-us/dotnet/api/system.io.file.openwrite?view=net-5.0#exceptions) <br />
> [_?. Operator_](https://docs.microsoft.com/en-us/dotnet/csharp/fundamentals/exceptions/exception-handling#finally-blocks) <br />
> [C# Documentation: Finally Blocks](https://docs.microsoft.com/en-us/dotnet/csharp/fundamentals/exceptions/exception-handling#finally-blocks) <br />
