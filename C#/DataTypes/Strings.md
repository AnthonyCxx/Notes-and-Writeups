# Strings

## Quotations
### @"String"
Prefixing a string with a _@_ will make the string raw (disables escape characters). <br />
This comes in extremely handy with Windows as Windows uses backslashes as a delimiter to separate files and folders.
```C#
string filepath = @"C:\Program Files";
```

### $"{String}"
