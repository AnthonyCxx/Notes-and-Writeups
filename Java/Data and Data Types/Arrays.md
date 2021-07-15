# Arrays in Java
Arrays are a data structure that store a collection of elements of the same type; these elements can be primitive types like ints or they can be objects.
Arrays have a fixed size which is set when the array is declared. To access the individual elements, you must know the index; otherwise, you have to iterate over 
the array manually.

## Declaring an Array
```Java
import java.util.Arrays;

public class arrays
{
    public static void main(String[] args)
    {
        // A collection of 10 names as an array (uninitialized)
        String[] names = new String[10];

        // An array of 5 integers, 1-5
        int[] arr = {1, 2, 3, 4, 5};

    }
}
```
