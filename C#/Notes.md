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

## I/O Operations
### Printing
```C#
Console.WriteLine("");
```

### Reading
```C#
Console.ReadLine();
```
