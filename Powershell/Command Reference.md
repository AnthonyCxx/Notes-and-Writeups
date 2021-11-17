# A Quick Reference for Powershell Commands

# Common Parameters and Risk-mitigation Options
Options that all commands support. [See the documentation](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_commonparameters?view=powershell-7.1).

| Option | Function |
| ------ | -------- | 
| `-Debug` | "displays programmer-level detail about the operation; only works if when the command generates a debugging message." |
| `-ErrorAction` | "determines how to respond to a non-terminating error; only works if the command generates a non-terminating error." |
| `-ErrorVariable` | "stores error messages about the command in the specified variable and in the `$Error` automatic variable." | 
| `-InformationAction` | "overrides the value of `$InformationPreference`, which by default is set to **SilentlyContinue**." | 
| `-InformationVariable` | "stores in a variable a string that you specify by adding the `Write-Information` command." | 
| `-OutBuffer` | "determines the number of objects to accumulate in a buffer before any objects are sent through the pipeline." | 
| `-OutVariable` | "stores output from the command in the specified variable in addition to sending the output along the pipeline." | 
| `-PipelineVariable` | "stores the value of the current pipeline element as a variable." | 
| `-Verbose` | "displays detailed information about the operation done by the command." | 
| `-WarningAction` | "determines how the cmdlet responds to a warning from the command." | 
| `-WarningVariable` | "stores warnings about the command in the specified variable" | 
| `-Confirm` | "prompts you for confirmation before executing the command." |
| `-WhatIf` | "writes a message that describes the effects of running the cmdlet without actually performing any action" | 
| `-Force` | forcibly performs a command; supresses prompts for confirmation |


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

# UNDOCUMENTED
