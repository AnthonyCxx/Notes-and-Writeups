# A Basic Keystroke Reference for Vim
Replace anything that is both italicized and bolded or is in curly brackets `{ }`. <br />
Just as a note, underscores are considered letters, not characters. <br />

## Fundamental Commands
| Key | Action |
| --- | -------- |
| h | move the cursor left one character |
| j | move the cursor down one character |
| k | move the cursor up one character |
| l | move the cursor right one character |
| i | enter insert (edit) mode |
| esc | return to normal mode | 
| :w | write to (save) the file |
| :q | quit the current file |
| :q! | quit the file without saving |
| :wq | save the file and quit |

## Modes
| Mode | Key | Function | 
| ---- | --- | -------- | 
| Normal Mode | esc | the default mode, returned to with _esc_ |
| Insert Mode | i | begin insert before the cursor |
| Replace Mode | R | overwrites characters instead of inserting |
| Visual Mode | v | highlight text for group manipulation |
| Visual Line Mode | V | highlights text by line |
| Visual Block Mode | ctrl + v | highlight text by blocks (great for adjusting columns) |
| Commmand Mode | : | use native vim commands (ex. find and replace) |

## Navigation
| Key | Action |
| --- | -------- |
| :_**num**_ | move the cursor to line number _num_ | 
| 0 | move the cursor to the beginning of the line |
| ^ | move the cursor to the first non-blank character on the line |
| $ | move the cursor to the end of the line |
| w | move forward a word (stop at symbols or whitespace) |
| W | move forward a word (ignore symbols and whitespace) |
| b | move backward a word (stop at symbols or whitespace) |
| B | move backward a word (ignore symbols and whitespace) |
| f{character} | move forwards to the next instance of **_character_** |
| F{character} | move backwards to the next instance of **_character_** |
| ctrl + u | move forward a section |
| ctrl + d | move backward a section |
| ctrl + f | move forward a page |
| ctrl + b | move backward a page |
| ctrl + { | move forward a paragraph (to the next blank line) |
| ctrl + } | move backward a paragraph (to the next blank line) |
| gg | jump to the beginning of the file |
| G | jump to the end of the file |
| % | jump to matching element of a {}, (), or \[ \]  pair |

## Editing Text
| Key | Action |
| --- | ------ |
| i | open insert before the cursor |
| I | open insert at the beginning of the line | 
| a | open insert after the cursor | 
| A | open insert at the end of the line |
| dd | delete the current line |
| C | delete the rest of the line and start insert |
| D | delete the rest of the line |
| S | delete the entire line and start insert |
| o | open a new line below the cursor |
| O | open a new line above the cursor |


## Manipulating Text
| Key | Action |
| --- | ------ |
| x | delete a character |
| yy | yank (copy) text |
| p | paste text below the cursor |
| P | paste text above the cursor |
| J | join the current line and the line below |
| :s/_**old_text**_/_**new_text**_/g | gind and replace some text on the current line |
| :%s/_**old_text**_/_**new_text**_/g | find and replace some text on all lines |

## Searching
| Key | Action |
| --- | -------- |
| /_**text/pattern**_ | forward search |
| ?_**text/pattern**_  | backwards search |
| n | move cursor to next search result |
| N | move cursor to previous search result |

## Miscellaneous
| Key | Action |
| --- | ------ |
| :!_**command**_  | execute a shell command without exiting vim |
| . | repeat the previous command |
| u | undo the previous command |
| ctrl + r | redo the previous undo |
| ctrl + l | refresh the screen |
| q: | opens commandline history (escape with ctrl + c twice) |
