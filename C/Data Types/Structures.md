# Structures in C
Structures (colloquially called a 'struct') are a user-defined datatype that serve as a collection of variables. <br />
They are defined as a block of code prefaced with the [_struct_ keyword](https://www.educative.io/edpresso/what-is-a-c-struct) and end with a semi-colon.
```C
struct Person
{
    char name[256];           // 256 is the max length of 'Display-Name' in Active Directory
    char phone_number[15];   // 1 (country code) + 3 (area code) + 7 (telephone number) + 3 (dashes) + '\0'
};
// ^ Note the semi-colon. A struct is a definition of a datatype and so needs a semi-colon

int main(void)
{
    // Declaring an instance of 'Person'
    struct Person henry = {"Henry", "540-321-2080"};

    // Print contents of struct 'henry'
    printf("Name: %s\n", henry.name);                 
    printf("Phone number: %s\n", henry.phone_number);
    // ^ C does not name access modifiers (private, public, etc.) so everything is public

    return 0;
}
```
> Prints: <br />
> Name: Henry <br />
> Phone number: 540-321-2080 <br />
>
> 'phone_number' is of type _char_ so you can regulate the length easily (source: [random phone number generator](https://www.randomphonenumbers.com/). <br />

## 'Inheritance' with Structures
Structures do not support inheritance, but you can effectively mimic the concept via [composition](https://www.codementor.io/@arpitbhayani/powering-inheritance-in-c-using-structure-composition-176sygr724) 
(i.e. making one the the structure's fields another structure). Some people believe that composition is the only way that structs (and objects in object-oriented
programming) should take on another struct's/object's attributes - see [_Composition over Inheritance_](https://en.wikipedia.org/wiki/Composition_over_inheritance)
```C

```
