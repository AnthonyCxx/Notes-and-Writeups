# Dataclasses in Python
Dataclasses are a special type of class that are tailored for storing data. Dataclasses are imported from the [_dataclasses_](https://docs.python.org/3/library/dataclasses.html)
module as _dataclass_, which contains a decorator, `@dataclass`, that can be used to make a class a dataclass. Dataclasses can be especially convenient because they automatically 
generate a host of magic methods: \_\_init_\_\, \_\_repr_\_\, \_\_eq\_\_, all the comparison operators (\_\_lt\_\_, \_\_le\_\_, \_\_gt\_\_, \_\_ge\_\_), and possibly even
\_\_hash\_\_. This virtually eliminates all the normal boilerplate code you'd have to write in order to write a class for storing data.


Throughout the examples I will be using a class _Point_ that has two coordinates (an x- and a y-coordinate). <br />
The example is from Scott Irwin's 2018 talk: [_Dataclasses are here. Now what?_](https://www.youtube.com/watch?v=zHY1oaYxxjA) <br />
```Python

```

## _@dataclass_ Arguments
The _@dataclass_ decorator can take arguments that change how the dataclass functions. <br />
By default, only init, repr, and eq are true — order, frozen, and unsafe_hash are false by default.

### init

```Python
def __init__(self, x: int=0, y: int=0) -> None:
    self.x = x
    self.y = y
```

### repr

```Python
def __repr__(self):
    return (f'{self.__class__.__qualname__}'
            f'(x={self.x}, y={self.y})')
```

### eq

```Python
def __eq__(self, other):
    if other.__class__ is self.__class__:
        return ((self.x, self.y) == (other.x, other.y))
    return NotImplemented
```
> Reference: [_NotImplemented_](https://docs.python.org/3/library/exceptions.html#NotImplementedError) exception

### order

```Python

```

### frozen

```Python

```
### unsafe_hash

```Python

```
