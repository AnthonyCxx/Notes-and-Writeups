# Pickling in Python
Picking is a form of [data persistance](https://c3.ai/glossary/features/data-persistence/) that works by storing a [serialized](https://towardsdatascience.com/what-why-and-how-of-de-serialization-in-python-2d4c3b622f6b) version of data so it can be stored in a file and used later. Unlike formats like CSV, XML, and JSON, pickling is specific to Python,
so you should not use it to transfer data between programs in different languages.

A wide array of data in Python can be pickled, see the Python Documentation, [_What can be pickled and unpickled?_](https://docs.python.org/3/library/pickle.html#what-can-be-pickled-and-unpickled) for a full list.

## Saving Data with _pickle.dump()_

```Python

```

## Reading Data with _pickle.load()_

```Python

```

## Temporary Conversion with _pickle.dumps()_ and _pickle.loads()_
_pickle.dumps()_ and _pickle.loads()_ are just like _pickle.dump()_ and _pickle.load()_ except they return the pickled object as a string of bytes. Use _pickle.dumps()_ and 
_pickle.loads()_ when you need to pickle an object that you aren't going to write to a file. For example, you may pickle and object temporarily so it can be transferred over a 
network. In that case, why write to the pickled object to a file and then trasfer the file when you can directly transfer the byte string?

> Reference: [_What is the difference between 'dump' and 'dumps' from the Pickle module in Python?_](https://itqna.net/questions/18582/what-difference-between-dump-and-dumps-pickle-module-python) <br />
