# [Automatic Variables](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_automatic_variables?view=powershell-7.2)



| Variable | Contains | Example |
| -------- | -------- | ------- |
| `$?` | true if that last command succeeded, false otherwise | `Write-Host --ThisOptionDoesNotExist; Write-Host $?` |
| `$^` | first word of the last line received | `Get-ChildItem -Attributes Hidden+Directory; Write-Host $^` |
| `$$` | last word of the last line received | `Get-ChildItem -Attributes Hidden+Directory; Write-Host $$` |
| `$_` |  | `` |
| `` |  | `` |
| `` |  | `` |
> ^ and $ represent the beginning and ends of lines <br />
> 

- True: `$true`
- False `$false`
- Null: `$null`
- Home: `$Home`

# Sources
- Microsoft Powershell Documentation: [Automatic Variables](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_automatic_variables?view=powershell-7.2)
- SS64: [Powershell Automatic Variables](https://ss64.com/ps/syntax-automatic-variables.html)
- JavaTPoint: [Powershell Automatic Variables](https://www.javatpoint.com/powershell-automatic-variables)
