# Logging in Python
Python has a native module, _logging_, for logging utilities. <br />
One of the best parts of the logging module is the 5 logging levels it provides: _debug_, _info_, _warning_, _error_, and _critical_.

Python Logging Documentation: [_logging — Logging facility for Python_](https://docs.python.org/3/library/logging.html).

## Basic Usage
The simplest use of logging is the _.log()_ function, which is used like `logging.log(level, message)`.
By default, messages that aren't related to warnings or errors aren't shown. To change this, edit the lowest viewable level with `logging.basicConfig(level=level)`.

```Python
# Show all logging messages, down to the debug level
logging.basicConfig(level=logging.DEBUG) # 'level=' is mandatory.

# Basic log message
logging.log(logging.INFO, "Start of program...")

# //Program goes here...

# Basic log message
logging.log(logging.INFO, "End of program...")
```

## Directly Calling a Logging Level
The 5 logging levels can be directly called by doing _logging.\<level\>_. <br />
For example, I could directly call the _error_ level with `logging.error(message)`.

```Python
import logging

# Display an error
logging.error("stuff")
```

## Creating a Logging Object
If you want to use a logger, use `logging.getLogger(logger_name)`.

```Python
import logging

# Create a custom logger
logger = logging.getLogger("CustomLogger")

logger.error("stuff")
```
