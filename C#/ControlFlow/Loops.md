# Iteration Statements (Loops) in C#
Loops (iteration statements) allow you to repeat a statement or block of statements multiple times, usually until some condition is no longer true.
C# has 4 types of iteration statements: for statements, foreach statements, do statements, and while statements. Loops consist of a condition and a body <br />

## For Statement
The _for_ statement allows you to execute a block of statements a specific number of times. A _for_ statement consists of a declaration statement, a condition,
and an update statemnt in that order; each of these sections are separated by semi-colons. It is best to use a for loop when the exact amount of executions is known. <br />
```C#
//Prints "Hello, World!" five times
for (int iterator = 0; iterator < 5; iterator++)  /Declaration, condition, and update statements
{
  System.Console.WriteLine("Hello, World!");     //Body
}
```
> Note: It is commonplace to use just _i_ as a shorthand 'iterator'
>> | Loop Section | Function |
>> | ------------ | -------- |
>> | int interator = 0 | declare an integer _iterator_ and set it to 0 |
>> | iterator < 5 | as long as the iterator is less tha 5, execute the body |
>> | iterator++ | increment the iterator by 1 ([postfix operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/arithmetic-operators#increment-operator-)) |

### Advanced For Loops
Both the declaration and update statements of a _for_ loop can contain more than one value, as long as they are separated by commas. If you need multiple conditions,
just use the logical _&&_ and _||_ operators. The following code snippet declares two counters, _i_ and _j_, which count from 0-5 and 0-10 respectively. 
Counter _j_ counts by twos.
```C#
//Prints two counters simultaneously
for(int i=0, j=0; i < 6; i += 1, j += 2 )
{
  System.Console.WriteLine(i + " " + j);
}
```
> Output: <br />
> 0  0 <br />
> 1  2 <br />
> 2  4 <br />
> 3  6 <br />
> 4  8 <br />
> 5 10 <br />
## Foreach Statement
