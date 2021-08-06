# Author: Ethan Cox
# Date: 5/12/2021
# Last Updated: 6/13/2021
# Group: High Point University Cybersecurity Club
# Companion Files: None
# Python Version: 3.9.5
#
# Purpose: Deciphers messages enciphered with the Atbash cipher
# 
# Example of encrypted text: zgyzhs xrksvi
# Decrypted version:         atbash cipher

import string
alphabet = string.ascii_lowercase

def getText():
    # Get the enciphered text as a list               
    enciphered_text = input("Enter the enciphered message: ").strip().lower()
    return enciphered_text

def decipherText(enciphered_text):
    deciphered_text = ""

    # Decipher each char individually
    for char in enciphered_text:
        if char.isalpha():
            deciphered_text += alphabet[ (len(alphabet) - alphabet.find(char) - 1) % len(alphabet) ]
        else:
            deciphered_text += char

    return deciphered_text
    #Note: I could simplify this by just overwriting 'enciphered_text', but it makes the code more difficult to read

def main():
    # Get the enciphered text
    enciphered_text = getText()

    # Deciphered said text...
    deciphered_text = decipherText(enciphered_text)

    # Print the decrypted text
    print(f"\nDeciphered text: {deciphered_text}\n")

if __name__ == "__main__":
    main()
