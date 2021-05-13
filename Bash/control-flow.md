# Control Flow

### Operators
|  |  |
| -- | -- |
| Run second command if first succeeds | `&&` |
| Run second command if first fails | `\|\|` |

### Control Operators
|  |  |
| -- | -- |
| group commands in main shell | `{ command1 ; command2 ; }` |
| run commands in subshell | `( command1 ; command2 ; )` |

### Control Syntax
- If statement
```bash
if ls        
then                 
  echo files displayed succesfully
else
  echo Error: files cannot be displayed. Exiting...                                                                            
  exit 1
fi
```
