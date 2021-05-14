# Case Statements
Case statements are the Bash equivalent of the C/Java [switch statement](https://www.geeksforgeeks.org/switch-statement-cc/). <br />
By default, case statements will match with one statement. If you want to match a case and continue matching, use `;&` in place of `;;`.
```bash

 read -r -p "Input: " INPUT

case $INPUT in

    [Yy]es)   #If yes, 
         echo "Understood, proceeding..."
        ;;
     [Nn]o)   #If no,
         echo "Understood, abandoning..."
        ;;
     *)       #Otherwise...
         echo "Misunderstood, dying..."
         ;;
esac
```
> Basic Format
```bash
case <var> in

   <option>)
       <statements>
       ;;
   <option>)
       <statements>
       ;;
```
