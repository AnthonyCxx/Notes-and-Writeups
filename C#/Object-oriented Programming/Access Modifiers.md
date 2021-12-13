# Access Modifiers in C#
Access modifiers regulate how a member of a class (a field, property, method, event, or even the class itself) can be accessed in relation to external or internal code.
There are three types of access: public, private, and protected. By default, classes class members are private; however, you should still always explicitly 
write out the accessor to maintain clean, readable code.

There are more access modifiers ([6 in total](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/access-modifiers)), but these are the three you will use most often.

## Public
Public members have no restrictions and can be accessed by any code, inside and outside of the class. Classes, properties, and methods are often public.
```C#

static void Main(string[] args)
{
    //Accessing 'Field' directly
    Console.WriteLine($"Accessing through Main function: {PublicExample.field}");

    //Accessing 'Field' through the derived class
    otherClass.Print();
}


public class PublicExample
{
    public static string field = "public field";   //static, so an instance of the class is not necessary
}

public class otherClass : PublicExample
{
    public static void Print() 
    {
        Console.WriteLine($"Accessing through derived class's method: {PublicExample.field}"); 
    }
}
```
> Reference: [C# Documentation: Public Keyword](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/public) <br />

## Private
Private members can only be accessed and modified from within the class itself. External code, including classes derived from the class, has no access to private members. 
Things like fields are often private.
```C#
static void Main(string[] args)
{
    Console.WriteLine($"Accessing through Main function: {PrivateExample.field}");  //Error! 'field' is private

    //Accessing 'field' through the derived class
    otherClass.Print(); //Error! 'field' is private
}


public class PrivateExample
{
    private static string field = "private field";   //static, so an instance of the class is not necessary
}

//A class derived from class 'PrivateExample' (will not have access to PrivateExample's private members)
public class otherClass : PrivateExample
{
    public static void Print()
    {
        Console.WriteLine($"Accessing through derived class's method: {PrivateExample.field}");  //Error! 'field' is private
    }
}
```
> Reference: [C# Documentation: Private Keyword](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/private) <br />

## Protected
Protected members are similar to private members in that they are only interally accessable; however, protected members are also accessible to derived classes.
```C#
static void Main(string[] args)
{
    Console.WriteLine($"Accessing through Main function: {ProtectedExample.field}");  //Illegal, 'field' is protected

    //Accessing 'Field' through the derived class
    otherClass.Print();    //Legal, protected members are accessible to derived classes!
}
 
public class ProtectedExample
{
    protected static string field = "protected field";   //static, so an instance of the class is not necessary
}

public class otherClass : ProtectedExample
{
    public static void Print()
    {
        Console.WriteLine($"Accessing through derived class's method: {ProtectedExample.field}");
    }
}
```
> Reference: [C# Documentation: Protected Keyword](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/protected) <br />

## Access Modifiers and Property Accessors
Access modifiers can be applied to an accessor method, but only to one. Accessors are public and so at least one accessor method must be public.
```C#
public class Item
{ 
    //Ok
    public string Name { get; protected set; }
    public int Durability { get; protected set; }
    
    //Error: accessors are public, so at least one accessor must be public!
    public int ID { protected get; protected init; } 
}
````
> Reference: [C# Docuemtation: Compiler Error CS0274: Both Accessor Methods Restricted](https://docs.microsoft.com/en-us/dotnet/csharp/misc/cs0274)
