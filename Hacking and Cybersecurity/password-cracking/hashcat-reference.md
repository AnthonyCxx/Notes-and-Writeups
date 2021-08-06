# Hashcat Reference
[Hashcat Wiki](https://hashcat.net/wiki/) <br />
[Return to main folder](https://github.com/hpu-panthersec/cyber-comp-materials/tree/main/password-cracking): password cracking

## What is Hashcat?
Hashcat is a _'password recovery tool'_ that many people just use as a password cracker. <br />
Hashcat allows you to attempt to crack [hashed passwords](https://thycotic.com/company/blog/2020/05/07/how-do-passwords-work/) using a variety of attack modes (brute-force, wordlist, combination, etc.). <br />
Simply put, all Hashcat will ask you for so it can crack passwords is the attack mode, hash type, the list of passwords, and the wordlist or character set. The betters the wordlist or character set, the faster you will crack passwords. <br />


## Attack Modes
| Attack Mode | ID | Explanation |
| ----------- | -- | ----------- |
| [Straight/Dictionary](https://hashcat.net/wiki/doku.php?id=dictionary_attack) | 0 | takes each word from a file and hashes it, comparing the hash to each password to be cracked |
| [Combination](https://hashcat.net/wiki/doku.php?id=combinator_attack) | 1 | takes two wordlists. For each word in the 1st dictionary, it tries concatenating each word in the 2nd wordlist |
| [Brute-force/Mask](https://hashcat.net/wiki/doku.php?id=mask_attack) | 3 | tests all possible character combinations using a provided character set |
| [Hybrid](https://hashcat.net/wiki/doku.php?id=hybrid_attack) | 6/7 | combines a straight attack with a brute-force attack, allowing you to prepend or append characters to a word |

A tip for brute-force/mask attacks: <br />
You can test every character set up to a given character set with the `--increment` option. <br />
For example, you could test, `?l`, `?l?l`, `?l?l?d`, and `?l?l?d?a` by including `--increment` and the character set `?l?l?d?a`. <br />
If you want to specify a minimum length to start at, use `--increment-min <int>`. <br />

A note on hybrid attacks: <br />
Depending on whether you want to prepend or append the characters, you should use attack mode 6 or 7 respectively. <br />
For attack mode 6, list the character set before the dictionary. For attack mode 7, list the character set _after_ the dictionary. <br />

### Character Sets
| Representation | Meaning |
| -------------- | ------- |
| ?l | lowercase letters (abcdefghijklmnopqrstuvwxyz) |
| ?u | uppercase letters (ABCDEFGHIJKLMNOPQRSTUVWXYZ) |
| ?d | digits (0123456789) |
| ?h | lowercase hexademcimal (0123456789abcdef) |
| ?H | uppercase hexadecimal (0123456789ABCDEF) |
| ?s | symbols («space»!"#$%&'()\*+,-./:;<=>?@[\\]^\_\`{\|}~) |
| ?a | lowercase, uppercase, digits, and symbols (?l, ?u, ?d, ?s) |
| ?b  | memory? never seen/used this... (0x00 - 0xff) |

## Common Hash IDs
| Hash Type | Hash ID |
| --------- | ------- |
| MD5 | 0 |
| SHA1 | 100 |
| MD5Crypt | 500 |
| LM | 3000 |
| MD4 | 900 |

## Examples from NCL Challenges
- `hashcat -a 0 -m 0 passwords.txt rockyou.txt --force` - straight attack (-a 0) a file (passwords.txt) of MD5 (-m 0) hashes
- `hashcat -a 3 -m 0 passwords.txt SKY-LRNB-?d?d?d?d --force` - brute-foces (-a 3) a file (passwords.txt) of MD5 (-m 0) hashes of the format SKY-LRNB-?d?d?d?d where each `?d` represents some digit 0-9

## Wordlists and Rulelists

### Wordlists
Wordlists should always be tailored to what you are trying to crack. E.g., use a WPA wordlist if you are trying to break a WPA password. <br />
That being said, here are some good general rulelists: <br />
- [RockYou](https://www.kaggle.com/wjburns/common-password-list-rockyoutxt) - the go-to list of passwords to try. Covers many common passwords.
- [10k Most Common Passwords](https://github.com/danielmiessler/SecLists/blob/master/Passwords/Common-Credentials/10k-most-common.txt) - top 10,000 most common passwords
- [LinkedIn Password Dump](https://github.com/op7ic/linkedin_wordlist) - passwords from a LinkedIn breach from 2012 (there was another one as of 2021, but that list is not public)

### Rulelists
Note: some of these rule lists are capital-l _Long_. Using the first few in tandem with wordslists such as RockYou.txt can take a long time. Run your command and then solve some other challenge while you wait. Do not wait for hashcat to finish if you use a rule list with a long wordlist.
- [Dive.rule](https://github.com/hashcat/hashcat/blob/master/rules/dive.rule) - considered the most comprehensive wordlist out there --- also means this takes a _long_ ass time to run
- [One Rule to Rule them All](https://github.com/NotSoSecure/password_cracking_rules) (yes that's a LOTR reference) - a one of the most comprehensive rule lists. May succeed where dive.rule fails. OneRuleToRuleThemAll.rule includes excerpts from NSARules.rule, Hob0Rules.rule, and KoreLogic.rule.
- [NSA Rules](https://github.com/NSAKEY/nsa-rules) - no, this was not made by the NSA. NSAKEY is the guy's name. It's a comphrensive rulelist of 123,289 rules and is pretty solid.
- [Hob0Rules](https://github.com/praetorian-inc/Hob0Rules) - some rulelists based on industry patterns. Hob064.rule is solid if you only want a short list of rules.
- [KoreLogic](https://contest-2010.korelogic.com/rules-hashcat.html) - a compilation of rulelists with small mutations, such as appending numbers.
- [L33tspeak Rulelist](https://github.com/hashcat/hashcat/blob/master/rules/leetspeak.rule) - transmutes passwords into all potential forms of [leetspeak](https://en.wikipedia.org/wiki/Leet).
<br /> <br />
[Other, offical Hashcat wordlists](https://github.com/hashcat/hashcat/tree/master/rules)

### Creating Your Own Wordlists
For hard challenges, you may be asked to generate your own wordlist. <br />
Often, the hardest part is knowing what the topic of your wordlist should be. <br />
Honestly, I recommend running your hashes through a general wordlist and then deriving the subject from the commonality between what you were able to crack. <br />
Once you find the subject, search the internet for a pre-made wordlist (there probably is one) using `filetpe:txt` <br />
If you can't figure out a common point between the passwords, google what you have using [search modifiers](https://github.com/hpu-panthersec/cyber-comp-materials/blob/main/open-source-intelligence/boolean-search-methods.md); use `""` and `intext:` <br />

### Creating Your Own Rulelists
[Here](https://hashcat.net/wiki/doku.php?id=rule_based_attack)'s a list of internal Hashcat functions that allow you to make your own rulelists. <br />
Generating your own rulelists is not easy. I recommend sticking to the pre-made ones until you really understand how to use Hashcat.

### Known Wordlists from Past Challenges
- [Comprehensive List of Pokémon](https://github.com/hpu-panthersec/cyber-comp-materials/blob/main/password-cracking/wordlists/pokemon.txt) (Gen. VIII)


## Closing Notes
Remember that you can always write a bash script to try multiple attacks and then just check the [potfile](https://hashcat.net/wiki/doku.php?id=frequently_asked_questions#what_is_a_potfile) (a log file with all cracked passwords and the hashes they came from) with
`cat ~/.hashcat/hashcat.potfile`. To create a bash script, just create a new file with `#! /bin/bash` at the top and then put your commands in there. Then, just do `bash <script_name>`
