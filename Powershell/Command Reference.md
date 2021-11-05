# A Quick Reference for Powershell Commands

# Getting Help

## Get-Command
> Aliases: gcm

| Option | Function | Example |
| ------ | -------- | ------- |
|  |  |  |
|  |  |  |
|  |  |  |

## Get-Member
> Aliases: gm

| Option | Function | Example |
| ------ | -------- | ------- |
|  |  |  |
|  |  |  |
|  |  |  |

## Get-Help
> Aliases: man

| Option | Function | Example |
| ------ | -------- | ------- |
| `-Name <command>` | shows help files for a given command | `Get-Help -Name Get-ComputerInfo` |
| `-Full`, `-Detailed`, `-Examples`, <br /> `-Online`, `-Parameter <parameter>`, `-ShowWindow` | change the level of detail/presentation format | `Get-Help -Name Get-Alias -ShowWindow` |
|  |  |  |

## Get-Alias
> Aliases: gal

| Option | Function | Example |
| ------ | -------- | ------- |
| `-Name <alias>` | lists commands related to the given name (the given alias) | `Get-Alias -Name sl*` |
| `-Definition <command>` | lists aliases related to a given cmdlet | `Get-Alias -Definition Sort-Object` |
| `-Exclude <alias>` | excludes related aliases from the search results | `Get-Alias g* -Exclude gp*` |

# Information

## Get-Service

## Get-Member

## Get-ComputerInfo

# Manipulating Information

## Sort-Object
> Aliases: 

## 
