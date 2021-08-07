# Common Functions in Python

## _print()_
Python's generic print function; Equal to _Console.WriteLine()_ in C# or _System.out.println()_ in Java. <br />
If you want to prevent the implicit newline, add `, end=''` as the last argument.

```Python
print("Hello, World!", end='')
print("Hello, World!")
```

## _len()_
_len_ takes the length of any sequence: strings, lists — anything.

```Python
name = "Mitzelplik"

print(f"Your name is {len(name)} characters long")
```

## _type()_
_type()_ returns the datatype of an object. Don't underestimate how useful this function is in a weak-typed system. It's great for finding bugs.

```Python

```

## _sorted()_

## _sum()_
_sum()_ calculates the sum of a collection.

```Python
nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

print(f"The sum of the numbers is: {sum(nums)}")
print(f"The average of the numbers is: {sum(nums) / len(nums)}")
```

## _min()_

## _max()_

## _round()_

## _abs()_
