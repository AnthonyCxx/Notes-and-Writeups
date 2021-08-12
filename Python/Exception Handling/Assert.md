# Asserts in Python
The _assert_ keyword allows you to catch errors that should never occur if all of your code is correct. The _assert_ keyword will stop the program with a message
if the expression following the _assert_ is false.

Here, the _assert_ statement catches that the index is less than 0, which is impossible.
```Python
def main():
    index = -1
    assert index > 0, "index cannot be less than 0"

main()
```
