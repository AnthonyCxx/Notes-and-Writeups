# Data Structures in Powershell
> [Arrays](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Data%20Structures%20in%20Powershell.md#arrays) <br />
>   \>\> [Properties](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Data%20Structures%20in%20Powershell.md#properties) <br />
>   \>\> [Methods](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Data%20Structures%20in%20Powershell.md#methods) <br />
> [Hashtables](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Data%20Structures%20in%20Powershell.md#hashtables) <br />
>   \>\> [Properties](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Data%20Structures%20in%20Powershell.md#properties-1) <br />
>   \>\> [Methods](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Data%20Structures%20in%20Powershell.md#methods-1) <br />

# Arrays
Arrays are a collection of elements that can be of different types. These elements can be accessed individually by the element's [index](https://www.geeksforgeeks.org/introduction-to-arrays/). To create an array, use the array subexpression operator (`@()`) like `$arr = @(1, 2, 3, 4, 5)`.
Alternatively, you can declare an array by assigning a comma-separated list to a varaible with `$arr = 1,2,3,4,5`. 
- You can append to an array using `+=` operator.
- To create an array of a single value, preface it with a comma like `$arr = ,7`
- Create an array from multiple values or access multiple values using the `..` operator 
- Negative indices refer to the distance from the end of the array (negative indices are **_not_** zero-indexed)
- Strongly type an array by casting it at declaration with `[datatype[]]`

## Properties
| Property | Function |
| -------- | -------- |
| `.Length` | returns the length of the array |
| `.Count` | an alias for .Length |
| `.LongLength` | used when .Length is greater than \[int\]::MaxValue (2,147,483,647) | 
| `.Rank` | returns the amount of dimensions the array has | 

## Methods
| Method | Function | Example | 
| ------ | -------- | ------- |
| `.Clear()` | resets all values in the array to their default value (`$null` for non-typed arrays) |
| `.ForEach()` | apply an operation to each element in the array ([op ref](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_arrays?view=powershell-7.2#foreach)) |
| `.Where()` | filters the array given a predicate as a scriptblock ([filter ref](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_arrays?view=powershell-7.2#where)) |

# Hashtables
A hashtable, often called a map or a dictionary, are an associative datastructure that maps keys to values. You can declare a hashtable with the same `$()` you can with
arrays, but and the pairs with `;`.

## Properties

## Methods

# Sources
- Powershell Documentation: [about\_Arrays](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_arrays?view=powershell-7.2)
- Powershell Documentation: [Everything You Wanted to Know About Arrays](https://docs.microsoft.com/en-us/powershell/scripting/learn/deep-dives/everything-about-arrays?view=powershell-7.2)
- Dr. Scripto: [Easily Create and Manipulate an Array of Arrays in PowerShell](https://devblogs.microsoft.com/scripting/easily-create-and-manipulate-an-array-of-arrays-in-powershell/)
- EDUCBA: [Array in Powershell](https://www.educba.com/array-in-powershell/)
- Varonis: [PowerShell Array Guide: How to Use and Create](https://www.varonis.com/blog/powershell-array/)
- Powershell Documentation: [about\_Hash\_Tables](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_hash_tables?view=powershell-7.2)
- Powershell Documentation: [Everything You Wanted to Know about Hashtables](https://docs.microsoft.com/en-us/powershell/scripting/learn/deep-dives/everything-about-hashtable?view=powershell-7.2)
- EDUCBA: [Hashtable in Powershell](https://www.educba.com/hashtable-in-powershell/)
- TutorialsPoint: [Powershell Hashtables](https://www.tutorialspoint.com/powershell/powershell_hashtables.htm)
- Dr. Scripto: [Easily Create a Powershell Hash Table](https://devblogs.microsoft.com/scripting/easily-create-a-powershell-hash-table/)
