# Password Cracking Cheatsheet
[Return to main folder](https://github.com/hpu-panthersec/cyber-comp-materials/tree/main/password-cracking): password cracking

## Identifiying Hashes
- [Online Hash Generator](https://emn178.github.io/online-tools/sha256.html) - generates a hash from a string (MD5, SHA256, etc.)
- [Online Hash Analyzer](https://www.tunnelsup.com/hash-analyzer/) - analyzes hashes, notes whether they are salted

| Common Hashes | Example for Reference |
| ------------- | ------- |
| MD5 | 6adaea58394876f63a2887c620c203da |
| SHA1 | 6475E365DC76EF8BA570A1FEB48A857B6700CF35 |
| SHA256 | 0209a48d4be6609c01f844e027733956992f9a294e5000a0baae44d17746572f |
| NTLM | E1D57B0755B30785FDCFC2AFB2D1BE34:0FF14E6830947CD1F863474AD88D198D |

For NTLM passwords, use OphCrack with the [XP Special Wordlist](https://ophcrack.sourceforge.io/tables.php) <br />
[Full List of Hash Examples](https://hashcat.net/wiki/doku.php?id=example_hashes)


## Hashcat Highlights - [Link](https://github.com/hpu-panthersec/cyber-comp-materials/blob/main/password-cracking/hashcat-reference.md)
| Attack Modes | Character Sets |
|--|--|
|<table> <tr><th>Attack Mode</th><th> ID </th></tr><tr><td>[Straight/Dictionary](https://hashcat.net/wiki/doku.php?id=dictionary_attack)</td><td>0</td></tr> <tr><td>[Combination](https://hashcat.net/wiki/doku.php?id=combinator_attack)</td><td>1</td></tr> <tr><td>[Brute-force/Mask](https://hashcat.net/wiki/doku.php?id=mask_attack)</td> <td>3</td></tr> <tr><td>[Hybrid](https://hashcat.net/wiki/doku.php?id=hybrid_attack)</td><td>6/7</td></tr> </table>| <table> <tr><th>Representation</th><th>Equivalent Expression</th></tr><tr><td>?l</td><td>lowercase letters [a-z]</td></tr> <tr> <td>?u</td> <td>uppercase letters [A-Z]</td> </tr> <tr> <td>?d</td> <td>digits [0-9]</td> </tr> <tr> <td>?s</td> <td>symbols [!"&\*...]</td> </tr>  <tr> <td>?a</td> <td>all sets [?l?u?d?s]</td> </tr> </table>|

<!-- This is the most disgusting thing I've ever seen. Here's a key for anyone who dares to brave this beast -->
<!-- <table> </table> : creates a table -->
<!-- <th> </th>       : creates a table header -->
<!-- <tr> </tr>       : creates a table row -->
<!-- <td> </td>       : creates a table element -->

<!-- Source: double-table taken from https://stackoverflow.com/questions/43232279/how-can-one-display-tables-side-by-side-in-github-markdown -->
