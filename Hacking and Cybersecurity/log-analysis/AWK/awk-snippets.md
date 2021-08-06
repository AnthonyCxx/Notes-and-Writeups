[Return to main folder](https://github.com/hpu-panthersec/cyber-comp-materials/tree/main/log-analysis/AWK): AWK main folder

# A Collection of AWK Code Snippets/One-liners
These are not ordered. I'm assuming you're going to use _Ctrl_ + _F_.

### Print Line based on Length
```AWK
# If the line is longer than 100 chars, print it
awk '{if (length($0) > 100) {print}}' <file>
```

### Find the Total Amount of Bytes in a Directory
```AWK
# The amount of bytes is the 5th field when running the command ls -l
ls -l | awk '{bytes += $5} END {print "Total bytes: ", bytes}'
```

### Find the Longest Line in a File
```AWK
# Find the length of the longest line (in chars) and store said line. If you want my words, use NF
awk '{if (length($0) > max_length) {max_length = length; longest_line = $0}} END {print max_length, " : ", longest_line}' <file>
```
> _length_ is a keyword, equal to `length($0)`

### Skip the First __ Lines
```AWK
# If more than five lines have been read, print the line (skips the first 5 lines)
awk '{if (NR > 5) {print}}' <file>
```
> Shorthand: `cat <file> | awk 'NR > 5'`

### Strip Path to File/Directory
```AWk
# Replace "pwd" with something actually useful
pwd | awk 'BEGIN {FS="/"} {print $NF}'
```
> `$NF` is always the last field in a line

### Print Final Line of File
```AWK
# At the end, print the last registered line
awk 'END {print}' <file>
```

### List Active TCP Connections and Status
```AWK
netstat -tn | awk '/tcp/{print $6}' | sort | uniq -c
```

### Find System IP Address
```AWK
ifconfig | awk '/inet / {print $2}'
```

### Create Backups a Every \*.x File in a Directory
```AWK
# AWK prints the commands, which are run when piped into Bash
ls *.<extension> | awk '{print "cp "$0" "$0".bak"}' | bash
```

### Display 10 Most Used Commands
```AWK
history | awk '{print $2}' | sort | uniq -c | sort -rn | awk "NR<11"
```
