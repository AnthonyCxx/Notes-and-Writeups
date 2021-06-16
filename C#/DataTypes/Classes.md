# Classes in C#
A class is a custom data type, which is composed of data members member functions (methods).

### Format
```C#
class ClassName
{
    //Data members
    
    //Function members (methods)
}
```

### Example
```C#
using System;

namespace Main
{
    class Program
    {
        static void Main()
        {
            Item backpack = new Item("Backpack", 100);
            backpack.Info();

            backpack.ID = 2000;

            backpack.Info();
        }
    }
}

class Item
{ 
    //Data members
    private string name { get; set; }
    private int id { get; set; }

    public string Name
    {
        get { return name; }
        set { name = value; }
    }

    public int ID
    {
        get { return id; }
        set { id = value; }
    }

    //Default Constructor
    public Item()
    {
        name = "";
        id   = 0;
    }

    //Parameterized constructor
    public Item(string item_name, int item_id)
    {
        name = item_name;
        id   = item_id;
    }

    //Example method -- no return value (void)
    public void Info()
    {
        Console.WriteLine($"Item: {name}, ID: {id}");
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
