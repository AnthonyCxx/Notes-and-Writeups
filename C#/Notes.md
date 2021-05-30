# Reference Notes for C#

## Compiling and Running on the Commandline with Mono
### Compiling 
```bash
mcs -out:hello.exe hello.cs
```
### Running
```bash
mono hello.exe
```

## Program Structure
```C#
//Class
class HelloWorld
{
    //Main Function
    static void Main(string[] args)
    {
        //Program
    }
}
```

## Data Types
| Data Type | Bytes | Minimum Value | Maximum Value |  
| --------- | ----- | ------------- | ------------- |
| bool | 1 | true | false |
| char | 2 | 0 | 65,535 |
| sbyte | 1 | -128 | 127 |
| byte | 1 | 0 | 255 |
| short | 2 | -32,768 | 32,767 |
| ushort | 2 | 	0 | 65,535 |
| int | 4 | -2,147,483,648 | 2,147,483,647 |
| uint | 4 | 0 | 4,294,967,295 |
| long | 8 | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,807 |
| ulong | 8 | 0 | 18,446,744,073,709,551,615 |
| float | 4 | -3.402823 x 10^38 | 3.402823 x 10^38 |
| double | 8 | -1.79769313486232 x 10^308 | 1.79769313486232 x 10^308 |
| decimal | 16 | ±1.0 × 10^−28 | ±7.9 × 10^28 |

## I/O Operations
### Printing
```C#
Console.WriteLine("");
```

### Reading
```C#
Console.ReadLine();
```
