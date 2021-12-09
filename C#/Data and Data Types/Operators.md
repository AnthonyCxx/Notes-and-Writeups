# Operators in C#
A list of the operators in C#, taken from [_The C# Documentation: Operators_](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/) and [_TutorialsPoint: C# Operators_](https://www.tutorialspoint.com/csharp/csharp_operators.htm)

## Arithmetic Operators
| Operator | Type | Function |
| -------- | ---- | -------- |
| ++ | unary prefix | increments by 1 _before_ the expression is evaluated |
| ++ | unary postfix | increments by 1 _after_ the expression is evaluated  |
| -- | unary prefix | decrements by 1 _before_ the expression is evaluated |
| -- | unary postfix | decrements by 1 _after_ the expression is evaluated |
| - | unary prefix | returns the numeric negation of the number |
| + | binary | adds two numbers |
| - | binary | subtracts two numbers |
| \* | binary | multiplies two numbers |
| / | binary | divides two numbers |
| % | binary | returns the remainder of division |
> Overloading an arithmetic operator implicitly overloads the corresponding compound assignment operator. You cannot explictly overload a compound assignment operator. ([reference](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/assignment-operator#operator-overloadability)) <br /> <br />
> For [_floor division_](https://www.pythontutorial.net/advanced-python/python-floor-division/), just divide two integers (truncates the decimal). <br />
> For exponents, use [_Math.Pow()_](https://docs.microsoft.com/en-us/dotnet/api/system.math.pow?view=net-5.0). <br />
>
> [Applications of Modulus (%)](https://betterexplained.com/articles/fun-with-modular-arithmetic/)

## Relational Operators
| Operator | Type | Function |
| -------- | -----| -------- |
| == | binary | returns true if two values are equal |
| != | binary | returns true of the true values are not equal |
| > | binary | returns true if the left value is greater |
| < | binary | returns true if the right value is greater |
| >= | binary | returns true if the left value is greater or equal to right |
| <= | binary | returns true if the right value is greater or equal to the left |
> If you overload overload _>_, then you must also overload _<_. The same goes for _>=_ and _<=_ ([reference](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/comparison-operators#operator-overloadability)). <br /> <br />
> You can remember the order of _>=_ and _<=_ by remembering that how you write them is how you read them. The symbol and then the equal sign. <br />

## Boolean Logic Operators
| Operator | Type | Function |
| -------- | ---- | -------- |
| && | binary | returns true if both operands are true |
| \|\| | binary | returns true if at least one operand is true |
| & | binary | non-short-circuiting && |
| \| | binary | non-short-circuiting \|\| |
| ^ | binary | returns true if only 1 expression is true |
| ! | unary prefix | negates the result of an expression |
> If you want to use `&&` and `||` without short-circuit evaluation, use `&` and `|`

## Bitwise and Shift Operators
These operators return a byte which is the result of the following manipulation.

| Operator | Type | Function |
| -------- | ---- | -------- |
| & | binary | for each bit, returns 1 if both bits are 1 |
| \| | binary | for each bit, returns 1 if either or both bits are 1|
| ^ | binary | for each bit, returns 1 if and only if 1 bit is one, but not both |
| ~ | unary prefix | performs a [1's complement](https://www.youtube.com/watch?v=lKTsv6iVxV4) (inverts the bits) |
| >> | binary | shifts the bits to the right by the amount of places of the right value |
| << | binary | shifts the bits to the right by the amount of places of the left value |

## Assignment Operators
| Operator | Type | Function |
| -------- | -------- | -------- | 
| = | binary | stores the right r-value into the left l-value ([lvalues vs rvalues](https://docs.microsoft.com/en-us/cpp/cpp/lvalues-and-rvalues-visual-cpp?view=msvc-160)) |
| += | binary | adds the value to itself and the value and then stores the result |
| -= | binary | subtracts the value from itself and the value and then stores the result |
| \*= | binary | multiplies the value by itself and the value and then stores the result |
| /= | binary | divides the value by itself and stores the result and then stores the result |
| %= | binary | takes the remainder of division by itself and the value and then stores the result |
| &= | binary | performs a bitwise _and_ and then stores the result |
| \|= | binary | performs a bitwise _or_ and then stores the result |
| ^= | binary | performs a bitwise _xor_ and then stores the result  |
| >>= | binary | performs a left shift and then stores the result |
| <<= | binary | performs a right shift and then stores the result |
> Even though it's C++, the article on lvalues and rvalues is still worth reading.

## Null Operators
These operators are used to avoid a [_NullReferenceException_](https://docs.microsoft.com/en-us/dotnet/api/system.nullreferenceexception?view=net-5.0).

| Operator | Operands | Function |
| -------- | -------- | -------- | 
| ?? | binary | returns the first expression if non-[_null_](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/null), otherwise returns the right expression |
| ?. | unary postfix | return null if null, otherwise returns the result of the expression |
| ?\[ \] | unary postfix | returns null if null, otherwise returns the value |
| ??= | binary | assign a value to the variable _if_ it is null |
| ! | unary postfix | tells the compiler to dismiss any concerns about the value being null |

## Miscellaneous Operators
| Operator | Operands | Function |
| -------- | -------- | -------- | 
| ? : | ternary | returns the first value if true and the second if false |
> There are more operators that belong here. Refer to [this section](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/#operator-precedence) of the C# documentation.


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

```C#
//Data Validation
if (result is not null)
{
    Console.WriteLine(result.ToString());
}
//This example is taken straight from the C# documentation referenced below 
```
> _result_ cannot be null, because invoking a method (such as _.ToString()_) on a null value results in a [_NullReferenceException_](https://docs.microsoft.com/en-us/dotnet/api/system.nullreferenceexception?view=net-5.0). <br />
> Reference: [C# Documentation: _is_ Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/is).
