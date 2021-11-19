# Basic Commandline Utilities
> [Show Directory Content](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Basic-Navigation.md#get-childitem) <br />
> [Change Directories](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Basic-Navigation.md#set-location) <br />
> [Clear Terminal](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Basic-Navigation.md#clear-host) <br />
> [Create a File, Directory...](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Basic-Navigation.md#new-item) <br />
> [Remove a File, Directory...](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Basic-Navigation.md#remove-item) <br />
> [Write File Contents to Terminal](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Basic-Navigation.md#get-content) <br />
> [Copy a File, Directory...](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Basic-Navigation.md#copy-item)

## [Get-ChildItem](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/get-childitem?view=powershell-7.2)
> Aliases: gci, dir, ls

Lists the contents of a directory (folder).

| Option | Function | Example |
| ------ | -------- | ------- |
| `-Name` | limits results to items whose name matches the pattern | `Get-ChildItem -Name *.py` |
| `-Directory` | limits results to directories | `Get-ChildItem -Directory \| Measure-Object` |
| `-File` | limits results to files | `Get-ChildItem -File` |
| `-ReadOnly` | limits results to readonly files | `Get-ChildItem -ReadOnly` | 
| `-Hidden` | limits results to hidden files | `Get-ChildItem -Hidden` |
| `-System` | limits results to system files | `Get-ChildItem -System` | 
| `-Attributes` | limits results to items with the specified [FileAttributes](https://docs.microsoft.com/en-us/dotnet/api/system.io.fileattributes?view=net-5.0). Combine attributes with `+` (and), `,` (or), and `!` (not). | `Get-ChildItem -Attributes !Directory+Hidden` |
| `-Force` | displays normally inaccessable files (e.g. hidden files, system files...) | `Get-ChildItem -Force` | 
| `-Include` | only includes results to results that match the given pattern | `Get-ChildItem -Include test??.cpp` | 
| `-Exclude` | excludes results that match the given pattern | `Get-ChildItem -Exclude *.tmp` |
| `-Path` | indicates the path to search | `...` | 
| `-LiteralPath` | indicates the path to search as a raw (verbatim) string | `...` | 
| `-Filter` | "Specifies a filter to qualify the `-Path` parameter." | `...` |
| `-Recurse` | recursively lists files | `Get-ChildItem -Recurse` | 
| `-Depth` | dictates maximum recursion depth | `Get-ChildItem -Recurse -Depth 1` |
| `-FollowSymlink` | displays (but does not follow) [symlinks](vvvhttps://blogs.windows.com/windowsdeveloper/2016/12/02/symlinks-windows-10/) | `...` |

---

## [Set-Location](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/set-location?view=powershell-7.2)
> Aliases: sl, cd

"Sets the working location to a specified location. That location could be a directory, a subdirectory, a registry location, or any provider path."

| Option | Function | Example |
| ------ | -------- | ------- |
| `-Path` | specifies the path to take | `Set-Location -Path C:\Users\ethan\Downloads\hmm` |
| `-LiteralPath` | takes the path as a raw (verbatim) string | `Set-Location -LiteralPath C:\Users\ethan\Downloads\*` |
| `-PassThru` | returns the path after executing the command | ` Write-Host (Set-Location .\Documents\ -PassThru)` |

---

## [Clear-Host](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/clear-host?view=powershell-7.2)
> Aliases: cls

Clears the screen. This command has no parameters.

---

## [New-Item](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/new-item?view=powershell-7.2)
> Aliases: ni, mkdir

Creates a new item of the specified type.

| Option | Function | Example |
| ------ | -------- | ------- |
| `-ItemType` | specifies the type of item to create | `New-Item "testdir" -ItemType Directory` |
| `-Name` | specifies the name of the new item | `New-Item -Name "testfile"` | 
| `-Force` | allows for overwriting read-only files | `ni -Name "test.cpp" -Force` | 
| `-Path` | specifies the location to create the new item | `New-Item -Type File -Path .. -Name "testfile.txt"` |
| `-Value` | specifies file content | `New-Item -Type File -Name "testfile.txt" -Value "file content here"` |
| `-Confirm` | prompts the user for confirmation before proceeding | `New-Item -Type Directory -Name yaboi -Confirm` |
| `-WhatIf` | shows what _would_ happen, but prevents the command from running | `New-Item -Type File -Name "hmmm.txt" -WhatIf` |
> File, Directory, SymbolicLink, Junction, HardLink

---

## [Remove-Item](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/remove-item?view=powershell-7.2)
> Aliases: del, erase, rd, ri, rm, rmdir

| Option | Function | Example |
| ------ | -------- | ------- |
| `-Include` |  | `` |
| `-Exclude` |  | `` |
| `-Force` |  | `` |
| `-Filter` |  | `` |
| `-Path` |  | `` |
| `-LiteralPath` |  | `` |
| `-Recurse` |  | `` |
| `-Stream` |  | `` |
| `-Confirm` | prompts the user for confirmation before proceeding | `` |
| `-WhatIf` | shows what would happen, but prevents the command from running | `Remove-Item -Include * -Path "C:\Windows\System32\" -Recurse -WhatIf` |

---

## [Get-Content](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/get-content?view=powershell-7.2)
> Aliases: gc, type, cat

| Option | Function | Example |
| ------ | -------- | ------- |
| `-TotalCount` | get first _n_ lines of the file | `Get-Content .\testdata.dat -TotalCount 3` |
| `-Tail` |  | `Get-Content .\testdata.dat -Tail 3` |
| `-Delimiter` | specifies delimiter (default: `\n`) | `Get-Content .\testdata.dat -TotalCount 3 -Delimiter ','` |
| `-Path` | path of the file to read | `Get-Content -Path .\Documents\testdata.dat` |
| `-LiteralPath` | path of the file to read as a raw (verbatim) string | `Get-Content -LiteralPath .\Documents\testdata.dat` |
| `-Include` | include matching items | `Get-Content *.dat -Include beta*` |
| `-Exclude` | exclude matching items | `Get-Content *.dat -Exclude test*` |
| `-Raw` | literally reads newlines (`\n`) and carriage returns (`\r`) | `Get-Content .\testdata.dat -Raw` |
| `-Encoding` | specifies [encoding system](https://docs.microsoft.com/en-us/dotnet/api/microsoft.powershell.commands.filesystemcmdletproviderencoding?view=powershellsdk-1.1.0) (read more [here](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_character_encoding?view=powershell-7.2)) | `Get-Content .\testdata.dat -Encoding ASCII` |
| `-Filter` | "Specifies a filter to qualify the `-Path` parameter." | `...` |
| `-Force` | "override a read-only attribute or create directories to complete a file path..." | `...` |
| ` -ReadCount` | "specifies how many lines of content are sent through the pipeline at a time" | `...` |

---

## [Copy-Item](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.management/copy-item?view=powershell-7.2)
> Aliases: copy, cp

| Option | Function | Example |
| ------ | -------- | ------- |
| `-Destination` | specifies the destination directory | `cp .\original.txt -Destination C:\Users\user\Desktop` |
| `-Recurse` | recursively copies from a directory | `cp .\OriginFolder -Destination .\CopiedData -Recurse` |
| `-Path` | path of the file to copy | `cp -Path .\Documents\original.txt -Destination copy.txt` |
| `-LiteralPath` | path of the file to read as a raw (verbatim) string | `...` |
| `-Include` | only include matching items | `cp *.cs -Destination .. -Include *final*` |
| `-Exclude` | exclude matching items | `cp *.cs -Destination .. -Exclude *test*` |
| `-Filter` | "specifies a filter to qualify the `-Path` parameter" | `...` |
| `-Confirm` | prompts the user for confirmation before proceeding | `Copy-Item .\original.txt copy.txt -Confirm` |
| `-Force` | forces a copy of normally non-copiable items | `Copy-Item .\aReadOnlyFile.txt .. -Force` |
| `-Container` | "preserves container objects during the copy operation" | `...` |
| `-PassThru` | returns the path to the copied object  | `Write-Host (cp .\original.txt copy.txt -PassThru)` |
| `-FromSession` | "specifies the PSSession object to which a remote file is being copied" | `...` |
| `-ToSession` | "specifies the PSSession object to which a remote file is being copied"  | `...` |

---

- Get-Acl
- Set-Acl
- Get-ItemProperty
- Set-ItemProperty
- Move-Item
- Rename-Item
