# Inheritence in C#

## Interfaces
- Can contain: properties, methods, events, or indexers 

## Simple Inheritence
```C#

//****************** Main Function *********************\\
static void Main(string[] args)
{
  //Testing the 'Tool' class
  var pickaxe = new Tool("Pickaxe", 100);

  Console.WriteLine(pickaxe.Stats);

  pickaxe.Swing();

  Console.WriteLine(pickaxe.Stats);


  Console.WriteLine("");   //Endline

  //Testing the 'Sword' class
  var sword = new Sword("A Sharp Sword", 100);

  Console.WriteLine(sword.Stats);

  sword.Swing();

  Console.WriteLine(sword.Stats);
}
    
    
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
            var chest = new Chest<string>(10, new string[] { "wood", "stone", "brimstone", "nails" });

            Console.WriteLine($"Chest Items: {chest.ItemList}");
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
        public Chest(int capacity, T[] items)
        {
            Items = items;
            Capacity = capacity;
        }
    }
}
```
> Reference: [GeeksForGeeks: Inheritence in C#](https://www.geeksforgeeks.org/c-sharp-interface/) <br />
> Reference: [GeeksForGeeks: Multiple Inheritence in C# using Interfaces](https://www.geeksforgeeks.org/c-sharp-multiple-inheritance-using-interfaces/) <br />
