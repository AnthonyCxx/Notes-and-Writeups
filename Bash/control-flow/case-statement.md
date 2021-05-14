# Case Statements
Case statements are the Bash equivalent of the C/Java [switch statement](https://www.geeksforgeeks.org/switch-statement-cc/). <br />
By default, case statements will match with one statement. For [fallthrough behavior](https://unix.stackexchange.com/questions/75354/can-bash-case-statements-cascade), use `;&` in place of `;;`.

### Basic Format
```bash
case <var> in

   <option>)
       <statements>
       ;;
   <option>)
       <statements>
       ;;
esac
```

### Example
```bash
 read -r -p "Input: " INPUT

case $INPUT in

    [Yy]es)   #If Yes or yes, 
         echo "Understood, proceeding..."
        ;;
     [Nn]o)   #If No or no,
         echo "Understood, abandoning..."
        ;;
     [M]maybe | *)       #If 'Maybe', 'maybe', or anything else
         echo "Misunderstood, dying..."
        ;;
esac
```
