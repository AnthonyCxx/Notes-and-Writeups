# C# Data Types

## Primitive Data Types
| Data Type | Base Class Library Name | Bytes | Minimum Value | Maximum Value | Default Value | Literal Suffix | 
| --------- | ----------------------- | ----- | ------------- | ------------- | ------------- | -------------- |
| bool | - | 1 | true | false | false | - |
| char | - | 2 | 0 | 65,535 | \0 | - |
| string | System.String | N/A | 0 / null | 2,048 bytes | null | - |
| sbyte | System.SByte | 1 | -128 | 127 | 0 | - |
| byte | System.Byte | 1 | 0 | 255 | 0 | - |
| short | System.Int16 | 2 | -32,768 | 32,767 | 0 | - |
| ushort | System.UInt16 | 2 | 	0 | 65,535 | 0 | - |
| int | System.Int32 | 4 | -2,147,483,648 | 2,147,483,647 | 0 | - |
| uint | System.UInt32 | 4 | 0 | 4,294,967,295 | 0 | - |
| long | System.Int64 | 8 | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,807 | 0 | - |
| ulong | System.UInt64 | 8 | 0 | 18,446,744,073,709,551,615 | 0 | - |
| float | System.Single | 4 | -3.402823 x 10^38 | 3.402823 x 10^38 | 0 | - |
| double | System.Double | 8 | -1.79769313486232 x 10^308 | 1.79769313486232 x 10^308 | 0 | - |
| decimal | System.Decimal | 16 | ±1.0 × 10^−28 | ±7.9 × 10^28 | 0 | - |
> Note: private variables should have a `_` prepended (per industry standard, not my opinion)
