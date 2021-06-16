# Classes in C#
A class is a custom data type, which is composed of fields, properties, methods, and events. All classes are [reference types](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/reference-types) and thus heap-allocated.

## Format
```C#
class ClassName
{
    //Fields
    
    //Properties
    
    //Methods
    
    //Events
}
```
> For C++ devs: note the lack of a semi-colon after the class declaration.

## Example
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

            //Set _id to 2000 using the public 'ID' property
            backpack.ID = 2000;
            
            //Show name and ID AFTER change
            backpack.Info();
        }
    }
}


// ******************* ITEM CLASS ************************ \\
//Access modifier, 'class' keyword, and then the class name (identifier)
public class Item
{ 
    //Fields (date members), should always have a prepended underscore
    private string _name;    //a private string, accessible through the 'Name' property
    private int _id;         //a private integer, accessible through the 'ID' property

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

    //Default Constructor (a special method)
    public Item()
    {
        //Set both data members to blank
        _name = "";
        _id   = -1;
    }

    //Parameterized constructor (a special method)
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

# Fields
A field is a data member of a class. Data members are often private (only accessible internally) and are always denoted with a prepended underscore when private.
```C#
public class HouseAddress
{
    //These data members are public to avoid needing a property to access it
    public string street; 
    public string town;
    public string state; 
    public int zipcode;
}
```
> These data members (street, town, etc.) do not have values yet. Values are typically assigned by a [constructor](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/constructors). <br /> <br />
> Any member (field, property, method, or event) can be accessed by putting a period after the object name and then putting the name of the member.

# Properties
A property allows for accessing/changing private or protected data members. Although properties are technically special methods (similarly to how lambdas are functors), 
it's best if you think of them as public data members that regulate how other code interacts with the private data members of the class.

# Methods

## Static Methods

# Events

# Access Modifiers
## Public

## Private

## Protected

