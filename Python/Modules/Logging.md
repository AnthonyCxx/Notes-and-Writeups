# Logging in Python
Python has a native module, _logging_, for logging utilities. <br />
One of the best parts of the logging module is the 5 logging levels it provides: _debug_, _info_, _warning_, _error_, and _critical_.

## Usage
The simplest use of logging is the _.log()_ function, which is used like `logging.log(level, message)`.
By default, messages that aren't related to warnings or errors aren't shown. To change this, edit the lowest viewable level with `logging.basicConfig(level=level)`.

```Python
logging.basicConfig(level=logging.DEBUG)

logging.log(logging.INFO, "Start of program...")

print("Working!")

logging.log(logging.INFO, "End of program...")
```
