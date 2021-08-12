# Exception Classes in Python
Custom exception classes allow programmers to define their own errors. To define your own exception class, write a new class that inherits from the base exception class 
_Exception_, has an \_\_init\_\_ method to define the error message, and has a \_\_str\_\_ method to return the message.

Here's a simple example of a custom _DivisionByZero_ exception (yes, I am aware Python has a built-in [_ZeroDivisionError_](https://docs.python.org/3/library/exceptions.html#ZeroDivisionError) exception).
```Python
# Custom exception class
class DivisionByZero(Exception):
    def __init__(self, message: str="Error: division by zero"):
        self.msg = message
        
    def __str__(self):
        return self.msg
        
# // DRIVER CODE // #
def main():
    numerator = 10
    denominator = 0
    
    try:
        if denominator == 0:
            raise DivisionByZero("Error: you cannot divide by zero...")
        
        print(f"10 / 10 = {numerator/denominator}")
    except DivisionByZero as err:  # Using custom 'DivsionByZero' exception
        print(err)

main()
```
