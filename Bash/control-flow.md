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
if [ ! -d someDir ]   # Normally, you would not use need the [], but here you do           
then                 
  echo directory \'someDir\' does not exist, creating directory \'someDir\'
  mkdir someDir
else
  echo directory \'someDir\' exists...
```
