# Exception Handling Keywords in C#
It's never uncommon to have unexpected results in programming, especially when opening up your program to a layman. Take the following snippet for example. Here, 
you can see that the user is prompted to enter a number between 1 and 100 to display the contents of that index in the array (all of which are 0, by the way). If 
the user enters a number outside of that range, then the program will crash with a _System.IndexOutOfRange_ exception. Now, you could solve this a few ways. For one,
you could use a [do-while loop](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/ControlFlow/Loops.md#dowhile-statement) to validate the their input.
Alternatively, you could mod (%) the input by the length of the array, preventing the result from exceeding the upper bound of the array; however, this does not prevent
the user from entering a negative number and exceeding the lower bound (which still throws a _System.IndexOutOfRange_ exception).

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

## Try, Throw, and Catch
The _try_ keyword denotes a block of code that the programmer suspects an error may occur. If an error occurs in a _try_ block, then the error can be handled with a _catch_ block.


## Finally

## Try...Catch Example

## Try...Throw...Catch

## Try...Finally Example

### Try...Catch...Finally Example
