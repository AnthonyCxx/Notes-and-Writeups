# Operator Overloading in Python
Operators are just tokens tied with a built-in function. Overloading operators in Python is done by adding a dunder method like `__add()__` to your class.

```Python
# A simple wrapper around a number for demonstrating operator overloading
class Number:
    def __init__(self, number):
        self.num = number
        
    def __add__(self, other):
        return self.num + other
        
# // DRIVER CODE // #
def main():
    num = Number(10)
    print(num + 2)    # Add '2' directly to an object

main()
```

## Overloadable Operators

P.S. _[token](https://techterms.com/definition/token)_ refers to a single, irreducible element of a programming language like the operator '+'.

### Arithmetic Operators
| Token | Arity | Dunder Method |
| ----- | ----- | ------------- | 
| + | Binary | \_\_add()\_\_ |
| - | Binary | \_\_sub()\_\_ | 
| * | Binary | \_\_mul()\_\_ | 
| / | Binary | \_\_truediv()\_\_ | 
| % | Binary | \_\_mod()\_\_ | 
| // | Binary | \_\_floordiv()\_\_ | 
| ** | Binary | \_\_pow()\_\_ | 

### Comparison Operators
| Token | Arity | Dunder Method |
| ------ | ----- | ------------- | 
|  |  |  |
|  |  |  | 
|  |  |  | 
|  |  |  | 
|  |  |  | 

### Bitwise Operators
| Token | Arity | Dunder Method |
| ----- | ----- | ------------- | 
| << | Binary | \_\_lshift()\_\_  |
| >> | Binary | \_\_rshift()\_\_ | 
| & | Binary | \_\_and()\_\_ | 
| \| | Binary | \_\_or()\_\_ | 
| ^ | Binary | \_\_xor()\_\_ | 
| ~ | Unary | \_\_invert()\_\_ | 

### Assignment Operators
| Token | Arity | Dunder Method |
| ------ | ----- | ------------- | 
|  |  |  |
|  |  |  | 
|  |  |  | 
|  |  |  | 
|  |  |  | 
