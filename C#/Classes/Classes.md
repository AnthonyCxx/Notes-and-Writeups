# Classes in C#
A class is a custom data type, which is composed of fields, properties, methods, and events. All classes are [reference types](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/reference-types) and thus heap-allocated.

## Format
```C#
class ClassName
{
    //Data members
    
    //Function members (methods)
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
    //Fields (date members), should always have a prepended underscore
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

## Fields

### Default Values

## Properties

## Methods

## Events

