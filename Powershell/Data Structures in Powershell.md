# Data Structures in Powershell
> [Arrays](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Data%20Structures%20in%20Powershell.md#arrays) <br />
>   > [Properties](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Data%20Structures%20in%20Powershell.md#properties) <br />
>   > [Methods](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Data%20Structures%20in%20Powershell.md#methods) <br />
> [Hashtables](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Data%20Structures%20in%20Powershell.md#hashtables) <br />

# Arrays
Arrays are a collection of elements that can be of different types. These elements can be accessed individually by the element's [index](https://www.geeksforgeeks.org/introduction-to-arrays/). To create an array, use the array subexpression operator (`@()`) like `$arr = @(1, 2, 3, 4, 5)`.
Alternatively, you can declare an array by assigning a comma-separated list to a varaible with `$arr = 1,2,3,4,5`. 
- You can append to an array using `+=` operator.
- To create an array of a single value, preface it with a comma like `$arr = ,7`
- Create an array from multiple values using the `..` operator
- Strongly type an array by casting it at declaration with `[datatype[]]`

## Properties
| Property | Function | Example | 
| -------- | -------- | ------- |
| `` |  | `` | 
| `` |  | `` | 
| `` |  | `` | 
| `` |  | `` | 

## Methods
| Method | Function | Example | 
| ------ | -------- | ------- |
| `` |  | `` |
| `` |  | `` |
| `` |  | `` |
| `` |  | `` |
| `` |  | `` |

# Hashtables

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
