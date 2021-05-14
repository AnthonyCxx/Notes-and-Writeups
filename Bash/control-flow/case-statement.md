# Case Statements
Case statemnts are the Bash equivalent of the C/Java [switch statement](https://www.geeksforgeeks.org/switch-statement-cc/). <br />
```bash

 read -r -p "Input: " INPUT

case $INPUT in

    [Yy]es)
         echo "Understood, proceeding..."
        ;;
     [Nn]o)
         echo "Understood, abandoning..."
        ;;
     *)
         echo "Misunderstood, dying..."
         ;;
esac
```
> Format: 
> case \<var\> in <br />

> \<option\>) <br />
>     \<statements\> <br />
>      ;; <br />
> \<option\>) <br />
>     \<statements\> <br />
>        ;; <br />
> esac <br />
