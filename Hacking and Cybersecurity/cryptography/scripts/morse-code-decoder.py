# Author: Ethan Cox
# Date: 5/12/2021
# Last Updated: 6/13/2021
# Group: High Point University Cybersecurity Club
# Python Version: 3.9.5
# Companion Files: None
#
# Purpose: Deciphers messages encoded in Morse code
# 
# Example of encrypted text: ... -.- -.-- -....- . .. -.- .-.. -....- ..... --... -.... ----.
# Decrypted version:         SKY-EIKL-5769

MORSE_LETTERS = {'.-':'A', '-...':'B', '-.-.':'C', '-..':'D', '.':'E', '..-.':'F', '--.':'G', \
                 '....':'H', '..':'I', '.---':'J', '-.-':'K', '.-..':'L', '--':'M', '-.':'N', \
                 '---':'O', '.--.':'P', '--.-':'Q', '.-.':'R', '...':'S', '-':'T', '..-':'U', \
                 '...-':'V', '.--':'W', '-..-':'X', '-.--':'Y', '--..':'Z'}

MORSE_DIGITS = {'-----':'0', '.----':'1', '..---':'2', '...--':'3', '....-':'4', \
                '.....':'5', '-....':'6', '--...':'7', '---..':'8', '----.':'9'}

MORSE_SYMBOLS = {'.-.-.-':'.', '--..--':',', '..--..':'?', '-....-':'-', '-...-':'=', \
                 '---...':':', '-.-.-.':';', '-.--.':'(', '-.--.-':')', '-..-.':'/',  \
                 '.-..-.':'\"', '...-..-':'$', '.----.':'\'', '.-.-..':'¶', '..--.-':'_', \
                 '.--.-.':'@', '---.':'!', '-.-.--':'!', '.-.-.':'+', '.-...':'~', '...-.-':'#', \
                 '. ...':'&', '-..-.':'⁄' }

# Full morse code dictionary
MORSE_CODE = { **MORSE_LETTERS,  **MORSE_DIGITS,  **MORSE_SYMBOLS }

def getText():
    # Get the enciphered text as a list               
    enciphered_text = input("Enter the enciphered message: ").strip().split()
    return enciphered_text

def decipherText(enciphered_text):
    deciphered_text = ""

    # Decipher each char individually
    for char in enciphered_text:
        if char in MORSE_CODE.keys():
            deciphered_text += MORSE_CODE[char]
        else:
            deciphered_text += enciphered_text[pos]

    return deciphered_text

def main():
    # Get the enciphered text
    enciphered_text = getText()

    # Deciphered said text...
    deciphered_text = decipherText(enciphered_text)

    # Print the decrypted text
    print(f"\nDeciphered text: {deciphered_text}\n")

if __name__ == "__main__":
    main()
