# A Quick Reference for Powershell Commands
> [Common Parameters and Risk-mitigation Options](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Command%20Reference.md#common-parameters-and-risk-mitigation-options) <br />
> [Getting Help](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Command%20Reference.md#getting-help) <br />
> [System Information](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Command%20Reference.md#system-information) <br />
> [Formatting Data](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Command%20Reference.md#formatting-data) <br />
> [Miscellaneous](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Command%20Reference.md#miscellaneous) <br />

Anything in quotation marks comes directly from documentation, which is avalilable with `Get-Help -Name <commandlet>` or online.

# Common Parameters and Risk-mitigation Options
Options that all commands support. [See the documentation](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_commonparameters?view=powershell-7.1).

| Option | Function |
| ------ | -------- | 
| `-Debug` | "displays programmer-level detail about the operation done by the command. This parameter works only when the command generates a debugging message." |
| `-ErrorAction` | "" |
| `-ErrorVariable` | "" | 
| `-OutBuffer` | "" | 
| `-OutVariable` | "" | 
| `-PipelineVariable` | "" | 
| `-Verbose` | "" | 
| `-WarningAction` | "" | 
| `-WarningVariable` | "" | 
| `-Confirm` | "prompts you for confirmation before executing the command." |
| `-WhatIf` | "writes a message that describes the effects of running the cmdlet without actually performing any action" | 

# Getting Help
> [Get-Help](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Command%20Reference.md#get-help) <br />
> [Get-Command](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Command%20Reference.md#get-command) <br />
> [Get-Member](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Command%20Reference.md#get-member) <br />
> [Get-Alias](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Powershell/Command%20Reference.md#get-alias) <br />

## Get-Help
> Aliases: help, man

"`Get-Help` gets the help content that it displays from help files on your computer. Without the help files, `Get-Help` displays only basic information about cmdlets."

| Option | Function | Example |
| ------ | -------- | ------- |
| `-Name <command>` | shows help files for a given command | `Get-Help -Name Get-ComputerInfo` |
| `-Full`, `-Detailed`, `-Online`, `-ShowWindow` | specify help info/format | `Get-Help -Name Get-Alias -ShowWindow` |
| `-Parameter <parameter>` | shows help for a parameter of a command | `Get-Help -Name Set-Timezone -Parameter Id` |
| `-Examples` | show examples for a command | `Get-Help Write-Output -Examples` |

---

## Get-Command
> Aliases: gcm

"The `Get-Command` cmdlet gets all commands that are installed on the computer, including cmdlets, aliases, functions, filters, scripts, and applications."

| Option | Function | Example |
| ------ | -------- | ------- |
| `-Noun <noun>` | list commands related to \<noun\> concept | `Get-Command -Noun *adapter*` |
| `-Verb <verb>` | list commands related to \<verb\> action | `Get-Command -Verb Enable*` |
| `-Type <type>` | list commands of type \<type\> (e.g. cmdlet, function...) | `Get-Command -Type Script` |
| `-Module <module>` | list commands from a specific module | `Get-Command -Module Microsoft.PowerShell.Security` |
| `(Get-Command <module>).ModuleName` | list module a command is from | `(Get-Command Get-ComputerInfo).ModuleName` |
> You can list all modules with `Get-Module -ListAvailable`.

---

## Get-Member
> Aliases: gm

"The `Get-Member` cmdlet gets the members, the properties and methods, of objects."; to use `Get-Member`, you have to pipe something into it.

| Option | Function | Example |
| ------ | -------- | ------- |
|  |  |  |
|  |  |  |
|  |  |  |

---

## Get-Alias
> Aliases: gal

"The `Get-Alias` cmdlet gets the aliases in the current session."

| Option | Function | Example |
| ------ | -------- | ------- |
| `-Name <alias>` | lists commands related to the given name (the given alias) | `Get-Alias -Name sl*` |
| `-Definition <command>` | lists aliases related to a given cmdlet | `Get-Alias -Definition Sort-Object` |
| `-Exclude <alias>` | excludes related aliases from the search results | `Get-Alias g* -Exclude gp*` |

# System Information

## Get-Service

## Get-Member

## Get-ComputerInfo

# Formatting Data

## Format-Table

## Out-GridView

## Sort-Object

# Miscellaneous

## Out-Null

## Measure-Command
