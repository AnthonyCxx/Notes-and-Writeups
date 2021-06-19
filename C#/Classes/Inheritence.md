# Inheritence in C#

## Interfaces
- Can contain: properties, methods, events, or indexers 

## Simple Inheritence
```C#
static void Main(string[] args)
{
  //Testing the 'Item' class
  var pickaxe = new Item("Pickaxe", 100);

  Console.WriteLine(pickaxe.Stats);

  pickaxe--;

  Console.WriteLine(pickaxe.Stats);


  Console.WriteLine("");   //Endline

  //Testing the 'Sword' class
  var sword = new Sword("A Sharp Sword", 100);

  Console.WriteLine(sword.Stats);

  sword.Swing();

  Console.WriteLine(sword.Stats);
}
    
class Item   //Abstract class, cannot be instantiated!
{
  public string Name { get; init; }
  public int Durability { get; protected set; }

  public string Stats { get { return Name + ": " + Durability; } }

  //Constructor
  public Item(string name = "Item", int durability = 100)
  {
    Name = name;
    Durability = durability;
  }

  //Overloaded  '-' operator
  public static Item operator --(Item item)
  {
    item.Durability--;
    return item;
  }
}

class Sword: Item
{
    public int Damage { get; private set; }

    public Sword(string name = "Sword", int durability = 100, int damage = 5)
    {
        Name = name;
        Durability = durability;
        Damage = damage;
    }

    public void Swing()  //Use (swing) the sword
    {
        this.Durability--;
    }
}
```

## Multiple Inheritence using Interfaces

> Reference: [GeeksForGeeks: Inheritence in C#](https://www.geeksforgeeks.org/c-sharp-interface/) <br />
> Reference: [GeeksForGeeks: Multiple Inheritence in C# using Interfaces](https://www.geeksforgeeks.org/c-sharp-multiple-inheritance-using-interfaces/) <br />
