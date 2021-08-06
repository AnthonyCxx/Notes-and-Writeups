[Return to main folder](https://github.com/hpu-panthersec/cyber-comp-materials/tree/main/log-analysis): log analysis main folder

# What is Log Analysis?
Log analysis is the process of interpreting a collection of computer-generated log messages with the purpose of deriving useful information from it, such as how much
data passes through your server every day or which browser clients are having trouble working with a service you provide. In the case of cybersecurity, you
will often use log analysis as a form of cyber-forensics to find information about a digital crime. <br />

# Log Formats
Consistency is incredibly important in log analysis, as structural homogeneity allows us to call certain sections of a line accross all lines and know for certain that we are
calling the same information, and not an IP address on one line and an HTTP request on another. Because of this, logs often use a `-` to represent blank information, which
preserves the order of the numeric sequence of the information, meaning that all lines shared the same information for every n-th string on the line. <br />

Ther eare many different types of standard log formats (syslog, json, gelf...), but the NCL tends to give you something similar to the [NSCA Common Log Format](https://en.wikipedia.org/wiki/Common_Log_Format).

Here is an excerpt from a typical log: `127.0.0.1 - - [10/Oct/2000:13:55:36 -0700] "GET /apache_pb.gif HTTP/1.0" 200 2326` <br />
Both user identifier and user ID and both typically blank, so I left them that way.

| Identifier | Field Content Above |
| ---------- | ------------- |
| IP Address | 127.0.0.1 |
| User Identifer | - |
| User ID | - |
| Date, Time, Timezone in [strftime](https://en.wikipedia.org/wiki/C_date_and_time_functions#strftime) | \[10/Oct/2000:13:55:36 -0700\] |
| Client Request with HTTP method, content name, and HTTP method | "GET /apache_pb.gif HTTP/1.0" |
| HTTP Status Code | 200 |
| Request Size (in bytes) | 2326 |

# A General Approach to Log Analysis
1. Use `head <filename>` to get a feel for the log
2. Between the prompt and the look of the log, find a log format guide online (Example: Amazon Web Service (AWS) Server [Log Format](https://docs.aws.amazon.com/AmazonS3/latest/userguide/LogFormat.html))
3. Find the length of the log with `wc -l <filename>`

As a general tip, pay **_very_** close attention to wording. How many transactions there are in a log may not be the amount of messages in the log. <br />
Figure out what qualifies as a 'transaction'. Know what they're asking in the context of the problem.

# Linux Commands and Concepts for Log Analysis

## Piping
The `|` (pipe) character allows you to redirect the output of one command and use it as the input of another command. If you wanted to count
the amount of lines in a file, you could do `wc -l file.txt`, _or_ you could do `cat file.txt | wc -l` and it would do the same thing. I would use this
with _grep_ when I'm looking for something in a manual but don't want to parse through the whole thing manually. If I were looking for the 'recursive' flag in
the grep manual, I would just do `grep --help | grep "recursive"`. You can use pipes multiple times in a row to make multiple transformations when
doing log analysis, and I whole-heartedly encourage it.

## Grep
GREP, or _global/regular expression/print_ is a commandline utility for searching plaintext via patterns. In its simplest application, you can search for 
instances of words with something like `grep "beans" <filename>` to finds all instances of 'beans' in a file; however, in more advanced applications,
you can search for patterns using a regular expression (a series of characters which specifies a search pattern). 

Take an the NCL flag pattern for example. An NCL flag is of the format _SKY_ or _NCL_ followed by a hyphen and then 4 capital letters, 
which is then followed another hyphen and 4 digits. This pattern would be expressed in Linux as `(SKY|NCL)-[A-Za-z]{4}-[0-9]{4}`. <br />

Breaking down the regular expression, you can see that there are three primary groups: `(SKY|NCL)`, `[A-Za-z]{4}`, and `[0-9]{4}` - each with a hyphen in between.
The first group `(SKY|NCL)` will match with either the word _SKY_ or _NCL_, but not both. Furthermore, the letters _must_ be capitalized to match. The second group,
`[A-Za-z]{4}`, matches with any 4 letters (upper, lower, or mixed case). Finally, `[0-9]{4}` matches with any 4 digits. Often, it is better to search for a pattern than 
specific words, as patterns allow for a broader search.

### Notable Flags
| Flag | Action |
| ---- | ------ | 
| `-i` | case insensitive search |
| `-E` | search via [extended RegEx](https://www.gnu.org/software/sed/manual/html_node/BRE-vs-ERE.html) pattern |
| `-o` | print only the matches, not the whole line |
| `-r` | use grep recursively |
| `-v` | reverse grep: print lines that do **_not_** match |
| `-n` | list the line number for each match |
| `-c` | show the amount of matches, not the matches |
| `-w` | match only whole words |
| `-B <num>` | provide before context for matches |
| `-A <num>` | provide after context for matches |
| `-C <num>` | provide before and after context for matches |
> The extended regex pattern is not needed to use regex. Grep natively understands regular expressions, even inside quotation marks.

## Head and Tail
The _head_ and _tail_ commands show the first or last lines of a file, providing a quick look at its contents.

### Notable Flags
| Flag | Action |
| ---- | ------ |
| `-c <int>` | show the first/last `<int>` characters |
| `-n <int>` | show the first/last `<int>` lines |

### Examples
| Example | Function |
| ------- | -------- |
| `head -n 5 log.txt` | show the first 5 lines of log.txt |
| `head -10 log.txt` | show the first 10 lines of log.txt |

## Sort
The _sort_ command sorts some contents line by line in the following order: symbols, numbers, uppercase letters, lowercase letters. <br />

### Notable Flags
| Flag | Action |
| ---- | ------ |
| `-f` | fold lowercase letters (ignore case) |
| `-b` | ignore leading blanks |
| `-d`, `--dictionary-order` | consider only blanks and alphanumeric characters |
| `-i`, `--ignore-nonprinting`  | consider only printable characters |
| `-r` | sort in reverse order |
| `-R` | randomly sort (shuffle) |
| `-k <int>` | sort by key (the `<int>`th column) |

## Examples
| Example | Function |
| ------- | -------- |
| `w \| sort` | sort online users by username |
| `df \| sort -k 5` | display free disk space by amount remaining (column 5) |

## Uniq
_Uniq_ (short for _unique_) removes duplicate lines. It _only_ removes adjacent duplicates, so it is always necessary to preface _uniq_ with _sort_. <br />

### Notable Flags
| Flag | Action |
| ---- | ------ |
| `-c` | preface the line with the amount of times it occured |
| `-d` | only print duplicate lines (showed up more than once) |
| `-i` | ignore case |
| `-s <int>` | skip the first `<int>` characters |
| `-u` | only print unique lines |

### Examples
| Example | Function |
| ------- | -------- |
| `cat ipAddrs.txt \| sort \| uniq` | print all unique ip addresses |
| `cat ipAddrs.txt \| sort \| uniq -c \| sort -n` | sort ip addresses by the amount of times they appear |

## AWK
AWK is a text-processing language and an incredibly powerful tool for log analysis. Check out [A Guide to AWK](https://github.com/hpu-panthersec/cyber-comp-materials/tree/main/log-analysis/AWK). <br />
If you're looking for AWK snippets, [click here](https://github.com/hpu-panthersec/cyber-comp-materials/blob/main/log-analysis/AWK/awk-snippets.md).

## Sed
Sed, a stream editor, is another powerful tool. Refer to [A Guide to Sed](https://github.com/hpu-panthersec/cyber-comp-materials/tree/main/log-analysis/Sed.md).

## Cut
_Cut_ is a utility that allows you to edit the format of text by displaying only certain fields or editing those fields.

### Notable Flags
| Flag | Action |
| ---- | ------ |
| `-b <int>` | display certain bytes |
| `-d <char>` | specify delimiter |
| `-f <int>` | display specific fields |
| `--complement` | display all characters but the specified |
| `--output-delimiter` | change how the content is output |

### Examples
| Example | Function |
| ------- | -------- |
| `cut -b 1,2,3,7` | display specific characters (1, 2, 3, and 7) |
| `cut -b 1-10` | display a range of characters (1-10) |

## Miscellaneous
- Often, timestamps are in [Epoch Time](https://en.wikipedia.org/wiki/Unix_time): [Epoch Time Converter](https://www.epochconverter.com/).

### Readings
- [The GNU AWK Reference](https://www.gnu.org/software/gawk/manual/gawk.html)
- [RegEx Tutorial for Linux](https://likegeeks.com/regex-tutorial-linux/)
