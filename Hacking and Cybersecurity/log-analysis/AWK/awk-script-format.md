[Return to main folder](https://github.com/hpu-panthersec/cyber-comp-materials/tree/main/log-analysis/AWK): AWK main folder

## AWK Script Format
```awk
#! /bin/awk -f

# Note: commands should be separated by lines.
# this is a comment...
<script>
```
> If needed, you can extend lines with a reverse solidus, `\`.

After writing the script, run `awk -f <.awk file> <.txt file>`

## Example Script
```AWK
#! /bin/awk -f

# Beginning: print the header
BEGIN {print "__________ HEADER __________"}

# Body: print every line of the text file
{print}

# Ending: print the ending
END {print "__________  END   __________"}
```

As a note, _**never**_ put single nor double quotation marks in your comments - the AWK interpreter will read it as an EoS (end of script) marker.
