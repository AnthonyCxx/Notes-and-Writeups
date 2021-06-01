# Classes in C#
A class is a custom data type, which is composed of data members member functions (methods).

### Format
```C#
class ClassName
{
    //Data members
    
    //Function members
}
```

### Example
```C#
class Item
{
    //Data Members
    public int ItemID;
    public string Name;
    
    //Constructor (a special member function, shares the name of the class)
    public Item(int id, string itemName)
    {
        this.ItemID = id;
          this.Name = itemName;
    }
}
```

### Conventions
Per [Microsoft's C# Coding Convention Guidelines](https://docs.microsoft.com/en-us/dotnet/csharp/fundamentals/coding-style/coding-conventions), always do the following:
```C#
class DummyClass      //Name classes using PascalCase
{
    public int XCoord, YCoord;      //Name public data members using PascalCase
    private int _health;           //Name private data members using camelCase AND prepending an underscore, _
    
    //Name public member functions using PascalCase, and private with camelCase
    public void throw(string thrownObj)      //Name parameters with camelCase
    {
        System.Console.WriteLine($"The dummy threw {thrownObj}");
    }
}
```
> Note: [What is PascalCase/camelCase?](https://techterms.com/definition/pascalcase)
