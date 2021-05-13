# Control Flow

### Operators
|  |  |
| -- | -- |
| Run second command if first succeeds | `&&` |
| Run second command if first fails | `\|\|` |


### Redirect/dispose of native error messages
`2>/dev/null` - what is [/dev/null](https://en.wikipedia.org/wiki/Null_device)?

### Control Operators
|  |  |
| -- | -- |
| group commands in main shell | `{ command1 ; command2 ; }` |
| run commands in subshell | `( command1 ; command2 ; )` |

### Control Syntax
- If statement
```bash
if cal         
then                 
  echo calander successfully displayed
else
  echo date cannot be shown. Exiting...                                                                            
  exit 1
fi
```
