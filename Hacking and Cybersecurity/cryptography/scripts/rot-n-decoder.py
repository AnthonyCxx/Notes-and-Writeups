# Author: Ethan Cox
# Date: 5/10/2021
# Last Updated: 5/13/2021
# Group: High Point University Cybersecurity Club
# Python Version: 3.9.5
# Companion Files: None
#
# Purpose: Testing every possible rotation of a Caesar/rot-n cipher online is so tedious that I wrote this out of pure annoyance.
# 
# Example of encrypted text: FXL-TGNX-0751
# Decrypted version:         SKY-GTAK-0751

import re
import string
alphabet = string.ascii_uppercase
NCL_FLAG_PATTERN = r"(SKY|NCL)-\w{4}-\d{4}"

def getCiphertext():
    cipher_text = input("Enter the ciphertext: ").strip().upper()
    return cipher_text

def decipherText(cipher_text, rot_amnt):
    deciphered_text = ""

    # Rotate every character in the ciphertext by the given amount
    for char in cipher_text:
        if char.isalpha():          # If it's a letter, rotate it
            deciphered_text += alphabet[ (alphabet.find(char) + rot_amnt) % 26 ]
        else:                       # Otherwise, leave it alone
            deciphered_text += char

    return deciphered_text

def main():
    # Get the ciphered text
    cipher_text   = getCiphertext()
    likely_answer = None
    rot_applied   = None

    # Test the ciphered text with every rotation of characters
    for rot_amnt in range(1, 26):
        deciphered_text = decipherText(cipher_text, 26 - rot_amnt)
        print(f"{str(rot_amnt).zfill(2)} : {deciphered_text}")

        # If the result contains a flag from NCL, mark it down
        if re.match(NCL_FLAG_PATTERN, deciphered_text):
            likely_answer = deciphered_text
            rot_applied   = rot_amnt

    # If there was any notable result, print it separately
    if likely_answer != None:
        print(f"\nLikely answer: {likely_answer} : rot-{rot_applied}\n")
    else:
        print("\nLikely answer: None\n")

if __name__ == "__main__":
    main()
