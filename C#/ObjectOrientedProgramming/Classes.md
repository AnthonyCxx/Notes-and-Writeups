# Classes in C#
Classes are the heart of C#. A class is essentially a custom datatype that serves as a collection of data. Classes are meant to mimic some concrete object or abstract idea.
For example, a class 'Player' would contain a string for their name, an integer for their health, and then a [dictionary](https://docs.microsoft.com/en-us/dotnet/api/system.collections.generic.dictionary-2?view=net-5.0) of the player's stats (here, a dictionary would map the name of the stat to its value). These three datatypes
together would allow us to create variables of type 'Player' that would have all of these properties. In addition to data, classes can have [methods](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/ObjectOrientedProgramming/Methods.md) which allow to class to perform actions. These actions don't have to
affect other data; in fact, many methods are entirely internal. For example, if we extended the definition of a string, we could define a method 'isPalindrome' which
return true if the word was a palindrome and false if the word wasn't.

A class is a custom data type, which is composed of fields, properties, methods, and events. All classes are [reference types](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/reference-types) and thus [heap-allocated](https://www.c-sharpcorner.com/article/C-Sharp-heaping-vs-stacking-in-net-part-i/).

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

# Fields
A field is a data member of a class. Data members are almost always private (only accessible internally) and are always denoted with a prepended underscore when private.
```C#
class HouseAddress
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
A property is a public data member that allows for accessing/changing private or protected data members. Although properties are technically special methods 
(similarly to how lambdas are functors),  it's best if you think of them as public data members that give guided access to a class's private data members by
regulating how other code interacts with them. <br /> 

## Property Accessors
The _get_, _set_, and _init_ property accessors.

### Property Accessor Format
```C#
public <dataType> <name>
{
    //accessors
}
```

### Property Accessor Example
```C#
public double Speed
{
    get => _speed;
    set => _speed = value;
}
``` 
> Reference: [C# Documentation: => Operator](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/operators/lambda-operator) <br />
> Reference: [What is the '=>' Operator?](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/Classes/Classes.md#the--operator)  <br />
> Reference: [C# Documentation: Value Keyword](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/value) <br />
> Reference: [What is the 'value' Keyword?](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C%23/Classes/Classes.md#the--operator) <br />
> Reference: [Contextual Examples of the 'value' Keyword](https://stackoverflow.com/questions/12019528/get-set-and-value-keyword-in-c-net) <br />

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
    //Declare a new house address (street address, city, state, and zipcode)
    var address = new HouseAddress("7198 W. Southampton St.", "Cleveland", "Tennessee", "37312");

    //Access the private data members using public properties
    Console.WriteLine($"Street address: {address.Street}");
    Console.WriteLine($"City: {address.City}");
    Console.WriteLine($"State: {address.State}");
    Console.WriteLine($"Zipcode: {address.Zipcode}");

    //Print the full address (7198 W. Southampton St., Cleveland, Tennessee 37312)
    Console.WriteLine(address.FullAddress);
                      
    //Changing the house address (via public accessors)
    address.Street = "4217 Roane Avenue";
    address.City = "Hughesville";
    address.State = "Maryland";
    address.Zipcode = "20637";

    //Print the new full address (4217 Roane Avenue, Hughesville, Maryland 20637)
    Console.WriteLine(address.FullAddress);
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
> Reference: [C# Documentation: Value Keyword](https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/value) <br />
> Reference: [What is the contextual 'value' Keyword?](https://stackoverflow.com/questions/12019528/get-set-and-value-keyword-in-c-net) <br />
> Note: Both address were made-up using [this website](https://www.fakeaddressgenerator.com/). <br />

### _Init_ Property Accessor
An _init_ accessor performs the same function as a _set_ accessor, except the value can only be set during initialization. After that,
the variable becomes read-only.

```C#
static void Main(string[] args)
{
    //Declare a new 'Package' object
    var package = new Package(5, 4, 8);  // (length, width, height)
    var otherPackage = new Package { Length = 5, Width = 3, Height = 7 };  //Also legal; would be illegal using 'private set'

    //Testing the public accessors
    Console.WriteLine($"Package Length: {package.Length}");
    Console.WriteLine($"Package Width: {package.Width}");
    Console.WriteLine($"Package Height: {package.Height}");

    //Testing the read-only 'Area' 
    Console.WriteLine($"Area of the Package: {package.Area}");

    package.Length = 10;  //Error! _length can only be set during initialization
}

public class Package
{
    //Private fields: the length, width, and height of the package
    private double _length, _width, _height;

    //** Public Properties **\\

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
        get => FindArea();
    }

    //Constructor (default and parameterized)
    public Package(double length = 0, double width = 0, double height = 0)
    {
        _length = length;
        _width = width;
        _height = height;
    }
    
    //An unnecessary private method - used to show how accessors can use expressions
    private double FindArea()
    {
        return _length * _width * _height;  //calculates and returns the area
    }
   
}
```

## The => Operator
The => operator allows for writing succinct method bodies by directly connecting the function name to its body. With special methods (such as the _get_ accessor), the
=> operator may imply parts of the body, such as the _return_ keyword.
```C#
//A succinct function, written with the => operator
public void DummyFunction() => Console.WriteLine("Hello, World!");
```

## The _value_ Keyword
The _value_ keyword is used with the _set_ and _init_ property accessors to represent the value being assigned to the variable.

## Auto-Implemented Properties
Since fields and their accessors often come in pairs, C# has a feature named 'auto-implented properties' that allows you to declare a property and imply both
the accessor's methods and the private field. In some cases, Auto-implemented properties can even eliminate the need for constructors if there are no explicit fields. 
<br /> <br />

Though convenient, auto-implemented properties may not always be the way to go because they also eliminate the ability to access the private fields outside 
of the public properties and prevent doing anything out of a simple _get_, _set_, or _init_ method.

```C#
static void Main(string[] args)
{
    var iPhone = new Phone("Apple iPhone 7 Plus", "+1-202-555-0188");

    Console.WriteLine($"Phone Model: {iPhone.Model}");
    Console.WriteLine($"Phone Number: {iPhone.Number}");
}

public class Phone
{
    //Auto-implemented properties -- imply the private fields
    public string Model { get; init; }
    public string Number { get; set; }

    //Parameterized constructor with default values
    public Phone(string phone_model = "unknown", string phone_number = "unknown")
    {
        Model  = phone_model;
        Number = phone_number;
    }
}
```

# Events
Don't worry about this for now :)
