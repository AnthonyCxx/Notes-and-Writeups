# Inheritence in C#
 Unlike in some other languages such as Perl and C++, 
C# does not support [multiple inheritance](https://docstore.mik.ua/orelly/perl4/porm/ch11_06.htm)  (the ability for a derived class to have more than one base class) to avoid
poor organization and problems like [diamond inheritance](https://medium.com/@harshamw/deadly-diamond-of-death-e8bb4355c343).
If you need to 'inherit' from multiple base classes, you have to use [interfaces](https://docs.microsoft.com/en-us/dotnet/csharp/fundamentals/types/interfaces) instead. Although, C# does not support multiple inheritance, it does support [multilevel (chain) inheritance](https://www.geeksforgeeks.org/c-sharp-multilevel-inheritance/), 
allowing you use a derived class as a base class for another class; Multilevel inheritance is different from multiple inheritance in that multiple inheritance 
allows a new class to inherit from two unrelated classes, whereas  multilevel inheritance allows a class to inherit from a class that is itself a derived class.

## Key Points
- Inheritance is the ability for a class to inherit the attributes of a pre-existing class.
- Inheritance allows for [D.R.Y. coding](https://dzone.com/articles/is-your-code-dry-or-wet) by increasing [code reusability](https://www.c-sharpcorner.com/UploadFile/201fc1/what-is-code-reuse-and-why-we-use-it/).
- C# supports multilevel inheritance, but not multiple inheritance (but can achieve a similar effect through interfaces).

## Simple (Standard) Inheritence
Inheritance is the ability of a class to be able to adopt the attributes (fields, properties, methods, and events) of another class, extending and 
building off of the base class. The class that the new class inherits from is called the base class and the class inheriting the properties is called the derived class.
For example, if you created a _furniture_ class with some attributes for the color, weight, and material, you could create a new class _chair_ that inherited from the the
_furniture_ class and only have to implement a few new attributes such as number of legs and chair model.

```C#
//****************** Main Function *********************\\
static void Main(string[] args)
{
  //Testing the 'Tool' class
  var pickaxe = new Tool("Pickaxe", 100);

  Console.WriteLine(pickaxe.Stats);

  pickaxe.Swing();

  Console.WriteLine(pickaxe.Stats);

  //Testing the 'Sword' class (derived from the 'Tool' class)
  var sword = new Sword("A Sharp Sword", 100);

  Console.WriteLine(sword.Stats);

  sword.Swing();

  Console.WriteLine(sword.Stats);
}
    
//****************** Tool class (base class) *********************\\
class Tool
{
  public string Name { get; init; }
  public int Durability { get; protected set; }

  public string Stats { get { return Name + ": " + Durability; } }

  //Constructor
  public Tool(string name = "Tool", int durability = 100)
  {
    Name = name;
    Durability = durability;
  }

  public virtual void Swing()  //Use (swing) the sword
  {
    Console.WriteLine("Swinging...");
    Durability--;
  }
}


//****************** Sword class (derived class) *********************\\
class Sword : Tool   //Inherit from the 'Tool' class
{
  public int Damage { get; private set; }

  public Sword(string name, int durability, int damage = 5) : base(name, durability)    //calls the base constructor
  {
    Damage = damage;
  }

  public override void Swing()
  {
    Console.WriteLine($"Swinging the {this.GetType().Name}");  //prints 'Swinging the sword'
    Durability--;
  }
}
```
> Prints: <br />
> Pickaxe: 100 <br />
> Swinging...  <br />
> Pickaxe: 99  <br />
> ... <br />
> A Sharp Sword: 100 <br />
> Swinging the Sword <br />
> A Sharp Sword: 99  <br />

## Multiple Inheritence using Interfaces
C# is a single-inheritence, so a class can only have one base class. If you want multiple inheritence, you must use interfaces. 
```C#
using System;

namespace InheritencePractice
{
    class Program
    {
        public static void Main(string[] args)
        {
            //Create a chest that contains the following items (with a max of 10 items)
            var chest = new Chest<string>("Small chest", 641, 10, new string[] { "wood", "stone", "brimstone", "nails" });

            //Prints: Chest Items: wood, stone, brimstone, nails
            Console.WriteLine($"Chest Items: {chest.ItemList}");
            
            //Prints: Max Chest Capacity: 10
            Console.WriteLine($"Max Chest Capacity: {chest.Capacity}");
            
        }
    }

    interface IPlaceable
    {
        public void Place();
    }

    interface IDestroyable
    {
        public void Destroy();
    }

    //The base class, 'Block', that inherits from the interfaces 'IPlaceable' and 'IDestroyable'
    class Block : IPlaceable, IDestroyable   //a block is an object which can be created and destroyed
    { 
        //Name of the block
        public string Name { get; init; }

        //Block ID
        public int ID { get; init; }
        
        //Constructor
        public Block(string name, int id)
        {
            Name = name;
            ID = id;
        }

        public void Place()
        {
            Console.WriteLine("Placed the block");
        }

        public void Destroy()
        {
            Console.WriteLine("Destroyed the block");
        }
    }
    
    interface IContainer<T>  //a generic container
    {
        //The amount of items the container can hold
        public int Capacity { get; init; }

        //The array of items the container has
        public T[] Items { get; set; }

        public string ItemList { get; }

        //An indexer to access the items 
        T this[int index] { get; set;}
    }

    //The derived class, 'Chest', which inherits from 'Block' and 'IContainer' 
    class Chest<T> : Block, IContainer<T>  //A chest is a block that contains items.
    {
        //************* Inherited Properties from 'Block' ****************\\
        //public string Name { get; init; }

        //public int ID { get; init; }

        //public void Place();  

        //public void Destroy(); 

        //************* Container<T> Implementation *****************\\

        //The max amount of items
        public int Capacity { get; init; }  //capacity is immutable

        //The array of items
        public T[] Items { get; set; }

        //Returns all the items as a CS (comma-separated) string
        public string ItemList
        {
            get
            {
                return string.Join(", ", Items);
            }
        }

        //Defines how 'T[] Items' should be accessed ( [] Overload )
        public T this[int index]
        {
            get => Items[index];
            set => Items[index] = value;
        }

        //************* Chest Implementation *****************\\
        public Chest(string name, int id, int capacity, T[] items): base(name, id)   //call the base class constructor
        {
            Items = items;
            Capacity = capacity;
        }
    }
}
```
> Reference: [GeeksForGeeks: Inheritence in C#](https://www.geeksforgeeks.org/c-sharp-interface/) <br />
> Reference: [GeeksForGeeks: Multiple Inheritence in C# using Interfaces](https://www.geeksforgeeks.org/c-sharp-multiple-inheritance-using-interfaces/) <br />
