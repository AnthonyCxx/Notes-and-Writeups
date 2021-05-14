```bash
arr=()	         #Create an empty array
arr=(1 2 3)	     #Initialize array
${arr[2]}	       #Retrieve third element
${arr[@]}	       #Retrieve all elements
${!arr[@]}	     #Retrieve array indices
${#arr[@]}	     #Calculate array size
arr[0]=3	       #Overwrite 1st element
arr+=(4)	       #Append value(s)
str=$(ls)	       #Save ls output as a string
arr=( $(ls) )	   #Save ls output as an array of files
${arr[@]:s:n}	   #Retrieve n elements starting at index s
```
> Shamelessly stolen from [Intro to Bash Arrays](https://opensource.com/article/18/5/you-dont-know-bash-intro-bash-arrays)
