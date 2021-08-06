# What is AWK?
AWK is an older, interpreted programming language oriented to one thing and one thing only: text processing. This means that AWK is fundamentally data-driven 
and is designed to search for patterns in and perform manipulations upon text. Compared to other languages, AWK is exceedingly simple and can be so short at times 
that you can write the script entirely on the commandline instead of having to write it in a file - this makes it easy to integrate with other commands via piping.
A standard AWK program looks like this: `awk '<program>' <file(s)>`. That's it. AWK is a tad dated at this point, and has newer counterparts, NAWK and GAWK 
(New AWK and GNU AWK). <br />

## A Short Summary by Julia Evans
<img src="https://user-images.githubusercontent.com/70488531/118374323-70a5e780-b589-11eb-9a3c-3c660f5275b6.png" alt="drawing" width="600"/>

Link to [her Twitter](https://twitter.com/b0rk) <br />

# A Summary of AWK
I'm going to assume that you have _AWK: [Pre-defined Variables](https://github.com/hpu-panthersec/cyber-comp-materials/blob/main/log-analysis/AWK/awk-predefined-variables.md)_
handy while you're reading this. No need to explain things twice.

### Records and Fields
AWK is primarily composed to two things: records and fields. For now, you can think of records and fields as lines and words respectively, but your understanding 
will deepen as you really come to understand how AWK works. A simple AWK program performs the exact same operation on every single line of some given text and 
relies on its understanding of the individual lines and words to do so. Naturally, what separates a line from another and a word from another is quite imporant. By default,
AWK separates lines by newline characters (_\n_) and words by spaces. You can change this manually by assigning the _RS_ and _FS_ variables (short for _record separator_ 
and _field separator_) at the beginning of the script. <br />

Assigning the field separator would look something like this: 
```AWK
# The keyword BEGIN makes the assignment of the field separator only be executed at the beginning of the script
awk 'BEGIN {FS = ":"}' <file>
```
> You may see something like this when working with MAC or IPv6 addresses when it is necessary to work with the individual sections of it (for identification and such).

### Actions
AWK is built on the idea of patterns and actions. Whenever a pattern is matched, the assigned action is taken. Any action/command in AWK will be enclosed within `{ }`.
To group commands, write multiple commands within the same set of `{ }`, separated by semicolons `;`.
```AWK
# Prints the first and second field for each line, but prints them on separate lines
awk '{print $1 ; print $2}' <file>
```
> You can nest commands by putting another set of `{ }` within another.

### Patterns
Patterns are also enclosed, but are enclosed in `/ /` instead. Putting a pattern inside `/ /` is essentialy the same as [grepping](https://www.urbandictionary.com/define.php?term=grepping) it, as it will bring up every line that matches said pattern. Note that [AWK uses extended regular expressions](https://hub.packtpub.com/regular-expressions-awk-programming/), not just regular expressions.
Have a look at the example below:
```AWK
# Matches with every line that contains the word twelve
awk '/twelve/' <file>
```
> An empty pattern, `//`, matches with all text; however, an empty set of braces, `{}`, does nothing. <br />
> Additionally, you can combine patterns with the standard C logical symbol trio: `&&` (and), `||` (or), and `!` (not). 

### Combining Actions and Patterns
Often, you will only want to take action on a subset of the input -- on the lines that match some pattern. By including a pattern before an action, AWK knows
to only perform that action on lines that match said pattern.
```AWK
# Does {action} for every line that matches /pattern/
awk '/pattern/ {action}' <file>
```

### Chaining Sets of Actions and Patterns
Taking a subset of a subset is an easy way to cut a file down to size. AWK allows you do do this by writing _/pattern/ {action}_ statements back to back.
```AWK
# Take all the people who have "a" in their name (column 1) and then match
# with any line that has "e" in it.
awk '$1 ~ /a/ {} /e/ {print}' <file>
```
> Remember, an empty `{}` does nothing. If you wrote `{print}` after the first pattern, it would print the first subset, and then the subset of that subset too.
> All you want here is the subset of the subset.

### Implying Actions and Patterns
A neat trick is implying a pattern or action by including one but not the other. <br /> 
For example, running the following line will print the entire line since no pattern is specified:
```AWK
# Prints the entire line as no pattern is specified
awk '{print}' <file>
```

Similarly, the following line will print the any line with more than five words since no action is specified:
```AWK
# Prints lines with more than 5 words (fields) since no action was specified
awk 'NF > 5' <file>
```
> Specifying just a pattern is good when you just need a quick AWK pattern in the middle of piping; it's a good shorthand.

### Keywords
AWK has two keywords that affect how the next action behaves, they are _BEGIN_ and _END_. Like _True_ and _False_ in Python, these keywords are case-sensitive.
The _BEGIN_ and _END_ keywords tell the interpreter that the next command block `{ }` should only be run at the beginning/end of the program, and not on every line.
Often, you will see these keywords used to do things like setup variables for the program or print table headers/ends. Anything not affected by the _BEGIN_ or _END_ keywords
is considered the body of the program.

#### BEGIN Keyword
```AWK 
# Prints ___ BEGINNING OF FILE ___ once and then just prints every line.
awk 'BEGIN {print "___ BEGINNING OF FILE ___"} {print}' <file>
```
#### END Keyword
```AWK 
# Prints every line and then prints **END OF PROGRAM** at the end of the program
awk '{print} END {print "**END OF PROGRAM** "}' <file>
```
> Funnily, enough, I accidentally put `END {print "**END OF PROGRAM** "}` at the beginning of the line when testing this and it didn't affect anything. Still, 
> for clarity's sake, you should probably put it after the body of the program.

### The Range Operator: ,
A `,` can be used to describe a range. For example, in the script `awk 'NR==1, NR==3 {print NR, $0}'`, the `,` indicates to print lines 1-3.
This can be further applied to match all the lines between two matches with the format `/pattern/, /pattern/`. See the script below.
```AWK
# Print the line number and line content for all lines between /Jack/ and /Jill/
`awk '/Jack/,/Jill/ {print NR, $0}' <file>`
```
> In messing around, it seems that the first pattern is not case sensitive while the second one is? Furthermore, invalid patterns are the equivalent of null patterns.
> The case sensitivity worth looking into...

### The Match Operator: ~
You can apply patterns to only certain fields with the `~` operator using the format `field ~ /pattern/`:
```AWK
# Matches with any line that has horn in the first field
# Matches with horn, horny, hornswoggle...
awk '$1 ~ /horn/ {print NR, $0}' <file>
```
> Hornswoggle, verb: "get the better of (someone) by cheating or deception."

### Expanding upon Matching: RegEx, Numeric, and String Comparisons
You can use **extended** regex to elaborate on a pattern. If you do not know RegEx yet, I highly recommend learning it because being able to describe a pattern allows you 
to search for unknowns. In addition to using RegEx, you can also use logical operators in conjunction with fixed values or even other fields or strings to specify matches.
You can even use the two together, putting a `!` before a regex to match lines that do not match the given regex.
```AWK
# If the third field is "Biology", print the line
awk '$3 == "Biology" {print NR, $0}' <file>
```
> Comparison of strings
```AWK
# If the price (column 5) is more than $1000, print it
awk '$5 > 1000 {print $0}' <file>
```
> Comparison of numbers
```AWK
# If the color is blue and there is at least 1 left, mark it "Available"
awk '$5 > "Blue" && $6 > 0 {print "Available"}' <file>
```
> Multiple comparison with logical and, `&&`

### Control Flow: If, Else, and the Ternary Operator 
#### Simple If, else if, and else statements
If statements in AWK use `( )` for their conditions and the whole if statement must be placed within the action brackets `{ }`.
```AWK
# If the last column is zero, print "zero"; otherwise, print "non-zero"
awk '{if ($NF==0) print "zero" ; else print "non-zero" }' <file>
```
> `$NF` always prints the last fields. Remember, fields are _not_ zero-indexed. <br />
> AWK also has `else if` statements, just include another condition after the `else if`.

#### The Ternary Operator
Here is an example of the ternary operator. If you are unfamiliar with the ternary operator, [click here](https://en.wikipedia.org/wiki/%3F:#C).
```AWK
# For every line, if the last row (the amount left) is non-zero, mark it as available  
awk '{ ($NF!=0) ? status="Available" : status="Not available" ; print "Status:", status}' <file>
```
### Storing Similar Variables: Associative Arrays
Arrays in AWK are associative, meaning they have key-value pairs (yes, it's literally a dictionary from Python, but here you can have multi-dimensional associative arrays).
These arrays are dynamic and you enter values with
the format `array["key"] = value`.
```AWK
# Sets an array "someArr" with the values "one" and "two" mapped to the values 1 and 2.
awk 'BEGIN {someArr["one"] = 1; someArr["two"] = 2} {} END {print "Numbers:", someArr["one"], someArr["two"]}' <file>
```
> The values of arrays (both the keys and values) can be fields. 

#### Accessing Array Element with a Range-Based For Loop:
Print items in the array using the format `for (<var> in <array name>[<var>]) <action>`.
```AWK
awk 'BEGIN {someArr["one"] = 1; someArr["two"] = 2} {} END {for (item in someArr) print someArr[item]}' <file>
```

#### Splitting a Field into an Array: split()
A field can be split into an array using the _split()_ function. The split function takes 3 parameters, the field, the array name, and a character (or regex) to 
act as a delimiter. Format: `split(field, array name, delimiter)`.
```AWK
# Split user's email addresses (column 3) by the "@" symbol and print the domain name
awk '{split($3, emailArr, "@") ; print emailArr[2]}' <file>
```
> In addition to splitting fields, you can split a custom string to quickly make an array instead of manually assigning each value.
