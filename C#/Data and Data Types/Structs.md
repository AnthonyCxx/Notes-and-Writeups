# Structs in C#
Structures (often called _structs_) are a user-defined [value type](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/builtin-types/value-types) that serves as
a collection of variables. Because structs are value types (which means they are allocated on the [stack instead of the heap](https://www.c-sharpcorner.com/article/stack-vs-heap-memory-c-sharp/)), they are both light-weight, quick to access, and easily copiable. These qualities make structures ideal for small collections of data,
especially those with little to no methods. When working with structs, you should be aware of their [limitations](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/builtin-types/struct#limitations-with-the-design-of-a-structure-type), notably that structs cannot have default constructors (since one is implicitly provided), cannot be used in inheritance (except in the context of [interfaces](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/interface)), and you cannot have [finalizers](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/finalizers) (since they are value types). 

```C#
//An example of a structure representing the date
public struct Date 
{
    //Auto-implemented properties (get + set)
    public int Day {get; set;}
    public int Month {get; set;}
    public int Year {get; set;}

    //Constructor
    public Date(int day, int month, int year)
    {
        Day   = day;
        Month = month;
        Year  = year;
    }

    //Get the date as a formatted string (mm/dd/yyyy)
    public override string ToString()
    {
        return $"{Month}/{Day}/{Year}";
    }
}


//Usage
public static void Main(string[] args)
{
    Date today = new Date(12,9,2021);
    Console.WriteLine(today.ToString());
}
```
> For C++ devs: notice that struct and class declations do not need semi-colons in C#

# Sources
- C# Documentation [Structure Types](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/builtin-types/struct#:~:text=A%20structure%20type%20)
- C# Corner [Struct In C#](https://www.c-sharpcorner.com/UploadFile/puranindia/struct-in-C-Sharp/)
- TutorialsPoint: [C# - Structures](https://www.tutorialspoint.com/csharp/csharp_struct.htm)
- TutorialsTeacher: [C# - Struct](https://www.tutorialsteacher.com/csharp/csharp-struct)
