# Lambda Expression in Python
Lambda is a one-time function that are often used so you don't have to define a whole function for a one-time use of something like the [_filter()_](https://www.geeksforgeeks.org/filter-in-python/) function. Lambdas as composed of two sections: the _lambda_ keyword and parameters (everything before the colon) and the 
body that is implicitly returned (everything after the colon). A simple lambda expression that squares and returns a number given to it would look like `lambda x: x**2`.

If you want to keep a lambda for later use, just assign it to a variable. Remeber, functions in python are [first-class objects](https://www.geeksforgeeks.org/first-class-functions-python/).
```Python
# Somehow this list got some strings in it. Wonder how that happened.
corrupt_list = corrupt_list = ['12', 15, 72, 3, '93', '1589', 720]

# Filter out anything that isn't an int
numbers = filter(lambda elem: isinstance(elem, int), corrupt_list)

# Cast the filter object into a list
print(list(numbers))
```
