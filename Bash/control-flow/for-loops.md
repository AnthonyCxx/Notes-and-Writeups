# For Loops

## Integer Progression For Loop
Bash uses C-like for loops, with three sections and double parentheses. <br />
Here is a short program that echos {0..10}:
```bash
for ((i=0 ; i < 10 ; i++))
do
  echo $i
done
```
> The double parentheses are needed, as they indicate an arithmetic operation. <br />
Here are the sections of the for loop:
1. Declaration - declares the variable
2. Loop condition - continue to loop until this requirement is false
3. Update statement - each time a loop is completed, run this statement
