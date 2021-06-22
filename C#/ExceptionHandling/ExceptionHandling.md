# Exception Handling Keywords in C#
It's never uncommon to have unexpected results in programming, especially when opening up your program to a layman. Take the following snippet for example. Here, 
you can see that the user is prompted to enter a number between 1 and 100 to display the contents of that index in the array (all of which are 0, by the way). If 
the user enters a number outside of that range, then the program will crash with a _System.IndexOutOfRange_ exception. Now, you could solve this a few ways. For one,
you could use a [do-while loop](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/ControlFlow/Loops.md#dowhile-statement) to validate the their input.
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

## Finally

## Try...Catch Example

## Try...Throw...Catch

## Try...Finally Example

### Try...Catch...Finally Example
