# Dectorators in Python

```Python
import functools

def function_wrapper(function):
    @functools.wraps(function)
    def wrapper(*args, **kwargs):
        return function(*args, **kwargs)
    return wrapper
```
