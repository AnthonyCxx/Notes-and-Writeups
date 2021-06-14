# Operators in C#
A list of the operators in C#, taken from [_The C# Language Reference: Operators_](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/)

## Arithmetic Operators
| Operator | Operands | Function |
| -------- | -------- | -------- |
| ++ (prefix) | 1 | increments by 1 _before_ the expression is evaluated |
| ++ (postfix) | 1 | increments by 1 _after_ the expression is evaluated  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |

## Comparison Operators
| Operator | Operands | Function |
| -------- | -------- | -------- |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |

## Boolean Logic Operators
| Operator | Operands | Function |
| -------- | -------- | -------- |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |

## Bitwise and Shift Operators
| Operator | Operands | Function |
| -------- | -------- | -------- |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |


## The Range Operator
The range operator, _.._ , allows for referencing sections of collections by index.
```C#
string greeting = "Hello";
int[] array = { 1, 2, 3, 4, 5, 6, 7 }

//Start at index 0 and end before index 2
Console.WriteLine( greeting[0..2] );  //prints 'He'

//Start at index 0 (implied) and stop at the final index (implied)
Console.WriteLine(String.Join(", ", array[..]));    //prints '1, 2, 3, 4, 5, 6, 7'

//Start at index 0 (implied) and stop at index 4
Console.WriteLine(String.Join(", ", array[..4]));   //prints '1, 2, 3, 4'

//Start at index 3 and stop at the final index (implied)
Console.WriteLine(String.Join(", ", array[3..]));   //prints '4, 5, 6, 7'
```

## The Negative Index Operator
The negative index refers to the element nth element from the end of the array and is denoted by the ^ unary operator. Unlike normal indicies, negative indices are not zero-indexed. ^1 refers to the final index of an array.
```C#
var array = new int[] { 1, 2, 3, 4, 5, 6, 7 };

//prints '7', the last element
Console.WriteLine( array[^1] );

//prints '1', the first element
Console.WriteLine( ^array.Length );
```

## Is Operator
The _is_ operator does two things:
1. "checks if the result of an expression is compatible with a given type"
2. "matchs an expression against a [pattern](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/patterns#property-pattern)"
> Reference: [C# Documentation: Is Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/is)

### Format
```C#
//Format
[expression] is [type]

//Example
someVar is bool;
```

### Example
```C#
//Data Validation
if (result is not null)
{
    Console.WriteLine(result.ToString());
}
//This example is taken straight from the C# documentation referenced below 
```
> _result_ cannot be null, because invoking a method (such as _.ToString()_) on a null value results in a [_NullReferenceException_](https://docs.microsoft.com/en-us/dotnet/api/system.nullreferenceexception?view=net-5.0). <br />
> Reference: [C# Documentation: is Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/is).
