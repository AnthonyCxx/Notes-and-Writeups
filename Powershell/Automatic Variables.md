# [Automatic Variables](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_automatic_variables?view=powershell-7.2)

This is not a comprehensive list, just a short list of ones I use often.

| Variable | Contains | Example |
| -------- | -------- | ------- |
| `$_` | represents the current object in the pipeline | `Get-Process \| ForEach-Object {$_.CPU}` |
| `$true` | contains _true_ | `$condition = $true` |
| `$false` | contains _false_ | `$condition = $false` |
| `$null` | contains _null_ | `if ($DoesNotExist -eq $null) {Write-Host "bad var"}` |
| `$?` | true if that last command succeeded, false otherwise | `Write-Host --ThisOptionDoesNotExist; Write-Host $?` |
| `$^` | first word of the last line received | `Get-ChildItem -Attributes Hidden+Directory; Write-Host $^` |
| `$$` | last word of the last line received | `Get-ChildItem -Attributes Hidden+Directory; Write-Host $$` |
| `$LastExitCode` | contains exit status of last program | `if ($LastExitCode -eq 0) {Write-Host "EXIT_SUCCESS"}` |
| `$HOME` | full path of the user's home directory | `Get-ChildItem -Path $HOME` |
| `$Host` | the current host applications | `$Host.UI.RawUI.CursorPosition.ToString()` |
| `$Matches` | contains matches from `-match` and `-notmatch` | `` |
| `` |  | `` |
| `` |  | `` |
> ^ and $ represent the beginning and ends of lines <br />

# Sources
- Microsoft Powershell Documentation: [Automatic Variables](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_automatic_variables?view=powershell-7.2)
- SS64: [Powershell Automatic Variables](https://ss64.com/ps/syntax-automatic-variables.html)
- JavaTPoint: [Powershell Automatic Variables](https://www.javatpoint.com/powershell-automatic-variables)
