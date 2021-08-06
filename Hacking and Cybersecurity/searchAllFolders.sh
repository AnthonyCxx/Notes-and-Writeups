#! /bin./bash

# This is a work in progress since I have no idea what the fuck I'm doing lmao #
# This is a short script designed to automatically parse this repo for content using grep and keywords from stdin.

grep --color -ri $* .


# NCL Flag RegEx :
# Bash: grep -iE "(SKY|NCL)-[A-Za-z]{4}-[0-9]{4}"
# Python: r"(SKY|NCL)-\w{4}-\d{4}"

# Can replace '-' with '.' to search for elusive flags...
