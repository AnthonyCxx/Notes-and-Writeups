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

P.S. '[token](https://techterms.com/definition/token)' refers to a single, irreducible element of a programming language.

### Arithmetic Operators
| Token | Arity | Dunder Method |
| ----- | ----- | ------------- | 
| + |  | \_\_add()\_\_ |
| - |  |  | 
| * |  |  | 
| / |  |  | 
| % |  |  | 
| // |  |  | 
| ** |  |  | 

### Comparison Operators
| Token | Arity | Dunder Method |
| ----- | ----- | ------------- | 
|  |  |  |
|  |  |  | 
|  |  |  | 
|  |  |  | 
|  |  |  | 

### Bitwise Operators
| Token | Arity | Dunder Method |
| ------ | ----- | ------------- | 
|  |  |  |
|  |  |  | 
|  |  |  | 
|  |  |  | 
|  |  |  | 

### Assignment Operators
| Token | Arity | Dunder Method |
| ------ | ----- | ------------- | 
|  |  |  |
|  |  |  | 
|  |  |  | 
|  |  |  | 
|  |  |  | 
