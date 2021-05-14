# Case Statements
Case statements are the Bash equivalent of the C/Java [switch statement](https://www.geeksforgeeks.org/switch-statement-cc/). <br />
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
> Format: <br />
> case \<var\> in <br />

> \<option\>) <br />
>   \<statements\> <br />
>      ;; <br />
> \<option\>) <br />
>  \<statements\> <br />
>   ;; <br />
> esac <br />
