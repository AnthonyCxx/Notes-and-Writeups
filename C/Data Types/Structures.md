# Structures in C
Structures (colloquially called a 'struct') are a user-defined datatype that serve as a collection of variables. 
They are defined as a block of code prefaced with the [_struct_ keyword](https://www.educative.io/edpresso/what-is-a-c-struct) and end with a semi-colon.
Unlike in C++, structs in C cannot contain methods (however they can contain function pointers, which effectively emulate methods).
```C
struct Person
{
    char name[257];           // 256 is the max length of 'Display-Name' in Active Directory (256 char + '\0')
    char phone_number[15];   // 1 (country code) + 3 (area code) + 7 (telephone number) + 3 (dashes) + '\0'
};
// ^ Note the semi-colon. A struct is a definition of a datatype and so needs a semi-colon

int main(void)
{
    // Declaring an instance of 'Person'
    struct Person henry;
    
    // Initializing data members
    henry.name = "Henry";
    henry.phone_number = "540-321-2080";
     // ^ C does not name access modifiers (private, public, etc.) so everything is public

    // Print contents of struct 'henry'
    printf("Name: %s\n", henry.name);                 
    printf("Phone number: %s\n", henry.phone_number);

    return 0;
}
```
> Prints: <br />
> Name: Henry <br />
> Phone number: 540-321-2080 <br />
>
> 'phone_number' is of type _char_ so you can regulate the length easily (source: [random phone number generator](https://www.randomphonenumbers.com/)). <br />

## Intializing Structs


## Simplifying Struct Usage with _typedef_
The [_typedef_](https://www.tutorialspoint.com/cprogramming/c_typedef.htm) keyword allows the programmer to create aliases for datatypes. If you make the definition of your
struct an alias, you won't have to write _struct_ constantly when declaring or using the struct. In larger programs, you should be careful when using _typedef_ because it 
tends to pollute the global namespace when overused; however, using _typedef_ poses no harm in smaller programs and makes your code cleaner.
```C
// Format of typedef: 'typedef <datatype> <alias>'
typedef struct
{
    char name[257];           // 256 is the max length of 'Display-Name' in Active Directory (256 char + '\0')
    char phone_number[15];   // 1 (country code) + 3 (area code) + 7 (telephone number) + 3 (dashes) + '\0'
} Person;

int main(void)
{
    // Declaring an instance of 'Person'
    Person henry = {"Henry", "540-321-2080"};

    printf("Name: %s\n", henry.name);
    printf("Phone number: %s\n", henry.phone_number);

    return 0;
}
```
> Notice how the datatype is anonymous (has no name) - there is no name. <br />
> This is acceptable because the anonymous struct is now mapped to the 'Person' alias. <br />

## 'Inheritance' with Structures
Structures do not support inheritance, but you can effectively mimic the concept via [composition](https://www.codementor.io/@arpitbhayani/powering-inheritance-in-c-using-structure-composition-176sygr724) 
(i.e. making one the the structure's fields another structure). Some people believe that composition is the only way that structs (and objects in object-oriented
programming) should take on another struct's/object's attributes - see [_Composition over Inheritance_](https://en.wikipedia.org/wiki/Composition_over_inheritance)
```C

```
