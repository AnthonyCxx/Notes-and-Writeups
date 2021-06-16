# Classes in C#
A class is a custom data type, which is composed of fields, properties, methods, and events. All classes are [reference types](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/reference-types) and thus heap-allocated.

## Format
```C#
public class ClassName    //Note: Classes can be private or protected too
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
    public string city;
    public string state; 
    public int zipcode;
}
```
> These data members (street, city, etc.) do not have values yet. Values are typically assigned by a [constructor](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/constructors). <br /> <br />
> Any member (field, property, method, or event) can be accessed by putting a period after the object name and then putting the name of the member.

# Properties
A property allows for accessing/changing private or protected data members. Although properties are technically special methods (similarly to how lambdas are functors), 
it's best if you think of them as public data members that give guided access to a class's private data members by regulating how other code interacts with them. <br /> <br />

## Property Accessors
The _get_, _set_, and _init_ property accessors.

### Property Accessor Format
```C#
public <datatype>
```

### Property Accessor Example
```C#
public double Speed
{
    get => _speed;
    set => _speed = value;
}
```
> Reference: [What is the contextual 'value' Keyword?](https://stackoverflow.com/questions/12019528/get-set-and-value-keyword-in-c-net) <br />

### _Get_ Property Accessor
The _get_ accessor returns a value when the property is called/accessed.
```C#
static void Main(string[] args)
{
    var shoes = new Shoes("black", "Nike");
    Console.WriteLine($"The {shoes.Brand} shoes are {shoes.Color}.");
    
    shoes.Color = "Blue";   //Error! The 'Color' accessor only supports 'get' functions
}

public class Shoes
{
    //private data member: the color of the shoes
    private string _color;  
    private string _brand;
    
    //public accessor: returns the value of the private data member
    public string Color 
    { 
        get { return _color; } 
    }  
    
    //public accessor: returns the value of the private data member
    public string Brand
    {
        get => _brand;     //Using the 'body definition' operator (returns _brand)
    }
    
    //Constructor
    public Shoes(string color, string brand) 
    { 
        _color = color; 
        _brand = brand;
    }
}
```
> Prints: "The Nike shoes are black."

### _Set_ Property Accessor

```C#
static void Main(string[] args)
{

}

public class
{

}
```
> Reference: [C# Documentation: Value Keyword](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/value) <br />
> Reference: [What is the contextual 'value' Keyword?](https://stackoverflow.com/questions/12019528/get-set-and-value-keyword-in-c-net) <br />

### _Init_ Property Accessor
An _init_ accessor performs the same function as a _set_ accessor, except the value can only be set during initialization. After that,
the variable becomes read-only.

```C#
static void Main(string[] args)
{
    //Declare a new 'Package' object
    var package = new Package(5, 4, 8);  // (length, width, height)

    //Testing the public accessors
    Console.WriteLine($"Package Length: {package.Length}");
    Console.WriteLine($"Package Width: {package.Width}");
    Console.WriteLine($"Package Height: {package.Height}");

    //Testing the read-only 'Area' 
    Console.WriteLine($"Area of the Package: {package.Area}");

    package.Length = 10;  //Error! _length can only be set during 
}

public class Package
{
    private double _length, _width, _height;

    public double Length
    {
        get { return _length; }
        init { _length = value; }
    }

    public double Width
    {
        get { return _width;  }
        init { _width = value; }
    }

    public double Height
    {
        get => _height;    //Using the 'body expression' operator
        init => _height = value;
    }

    public double Area
    {
        get => _height * _width * _length;
    }

    public Package(double length, double width, double height)
    {
        _length = length;
        _width = width;
        _height = height;
    }
}
```

### Example
```C#
using System;

namespace Project
{
    public class Program
    {
        static void Main(string[] args)
        {
            //Declare a new house address (street address, city, state, and zipcode)
            var address = new HouseAddress("7198 W. Southampton St.", "Cleveland", "Tennessee", "37312");

            //Access the private data members using public properties
            Console.WriteLine($"Street address: {address.Street}");
            Console.WriteLine($"City: {address.City}");
            Console.WriteLine($"State: {address.State}");
            Console.WriteLine($"Zipcode: {address.Zipcode}");

            //Print the full address (7198 W. Southampton St., Cleveland, Tennessee 37312)
            Console.WriteLine(address.FullAddress);
        }
    }
}
public class HouseAddress
{
    //These data members are private (so they have an underscore)
    private string _street;
    private string _city;
    private string _state;
    private string _zipcode;

    //Property for _street (read and write)
    public string Street
    {
        get { return _street; }
        set { _street = value; }
    }

    //Property for _city (read and write)
    public string City
    {
        get { return _city; }
        set { _city = value; }
    }

    //Property for _state (read and write)
    public string State
    {
        get { return _state; }
        set { _state = value; }
    }

    //Property for _zipcode (read and write)
    public string Zipcode
    {
        get { return _zipcode; }
        set { _zipcode = value; }
    }

    //A custom read-only property - returns the full address
    public string FullAddress
    {
        get { return $"{_street}, {_city}, {_state} {_zipcode}"; }
    }

    //Constructor
    public HouseAddress(string street, string city, string state, string zipcode)
    {
        _street = street;
        _city = city;
        _state = state;
        _zipcode = zipcode;
    }
}
```
> Note: 7198 W. Southampton St., Cleveland, Tennessee 37312 is a made-up address.

## Auto-Implemented Properties
The keywords _get_, _set_, and _init_ can be used to modify how a ...

## Access Modifiers and Property Accessors

# Methods

## Static Methods

# Events

# Access Modifiers
## Public

## Private

## Protected

