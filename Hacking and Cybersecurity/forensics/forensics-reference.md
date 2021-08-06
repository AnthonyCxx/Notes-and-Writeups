# What is Cyber Forensics?

## General Forensics


## Git Forensics
- Article: [Git File Structure](https://git-scm.com/docs/gitrepository-layout)
- Article: [10 Essential Git Log Commands](https://www.thegeekstuff.com/2014/04/git-log/#:~:text=The%20Git%20Log%20tool%20allows,the%20most%20recent%20commits%20first)

### Useful commmands
| Command | Purpose |
| ------- | ------- |
| `git log <filename>` | show history of a file | 
| `git log --all` | full log history |
| `git log -p` | show file changes in log history |
| `git log --grep=”<pattern>”` | search commits by pattern |

### Cheats
| Command | Purpose |
| ------- | ------- |
| `git log --graph --full-history --all --pretty=format:"%h%x09%d%x20%s"` | a quick summary of the full commit history | 
| `git log \| grep -iE ^commit \| wc -l` | finds total amount of commits |
- [Git Cheatsheet](https://github.com/yuanqing/git-cheatsheet)
