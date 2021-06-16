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
// **************  MAIN CLASS ***************** \\
using System;

namespace Main
{
    class Program
    {
        static void Main()
        {
            //Instantiate a backpack
            Item backpack = new Item("Backpack", 100);
            
            //Print the name and ID
            backpack.Info();

            //Set the ID to 2000 using the public 'ID' property
            backpack.ID = 2000;
            
            //Show name and ID AFTER change
            backpack.Info();
        }
    }
}


// ******************* ITEM CLASS ************************ \\
class Item
{ 
    //Data members (should always have a prepended underscore)
    private string _name { get; set; }     //a private string which can be read and written
    private int _id { get; set; }          //a private integer which can be read and written

    //A public-facing property, used to define how the 'name' variable is read and written
    public string Name
    {
        get { return _name; }
        set { _name = value; }
    }

    //A public-facing property, used to define how the 'id' variable is read and written
    public int ID
    {
        get { return _id; }
        set { _id = value; }
    }

    //Default Constructor
    public Item()
    {
        //Set both data members to blank
        _name = "";
        _id   = -1;
    }

    //Parameterized constructor
    public Item(string item_name, int item_id)
    {
        _name = item_name;
        _id   = item_id;
    }

    //Example method -- no return value (void)
    public void Info()
    {
        Console.WriteLine($"Item: {_name}, ID: {_id}");   //Prints "Item: <item>, ID: <id>"
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
