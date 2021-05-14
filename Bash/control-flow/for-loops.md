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
>> Here are the sections of the for loop:
>> | Part of Loop | Contextual Example | Purpose |
>> | ------------ | ------------------ | ------- | 
>> | Declaration | i=0 | declares the variable |
>> | Loop Condition | i < 10 | continue to loop until the condition is false |
>> | Update statement | i++ | each time a loop is completed, run this statement |
