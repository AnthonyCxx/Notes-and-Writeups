# T9 Decoder
# Author: Ethan Cox
# Date: 5/10/2021
# Last Update: 5/13/2021
# Group: High Point University Cybersecurity Club
# Python Version: 3.9.5
# Companion Files: None
#
# Purpose: This script decrypts a message that has been encrypyed with a standard T9 (telephone keypad) cipher.
#
# Example of encrypted text: 333-444-66-33 66-33-9-7777
# Decrypted version: fine news

# A dictionary of all the number codes and their letter equivalent
KEYPAD = { '2':'a', '22':'b', '222':'c', \
            '3':'d', '33':'e', '333':'f', \
            '4':'g', '44':'h', '444':'i', \
            '5':'j', '55':'k', '555':'l', \
            '6':'m', '66':'n', '666':'o', \
            '7':'p', '77':'q', '777':'r', '7777':'s', \
            '8':'t', '88':'u', '888':'v', \
            '9':'w', '99':'x', '999':'y', '9999':'z'}

def getText():
    # Get the encrypted text as a list
    encrypted_text = input("Enter the encrypted message: ").strip().lower().split()
    return encrypted_text

def decryptText(encrypted_text):
    # Use list comprehension to apply function decrypt() to each element of the list
    decrypted_text = [decrypt(word) for word in encrypted_text]     

    # Return the list of decrypted words as a single, spaced string
    return ' '.join(decrypted_text)  

# Decrypt a string
def decrypt(word):
    # Transform the string into a list to evaluate each number individually
    word = word.split('-')
    
    # Replace each element in the list with its ASCII equivalent
    for pos, num in enumerate(word):
        word[pos] = KEYPAD[num]

    # Return list as a string
    return ''.join(word)

# Main Function
def main():
    # Get the text to be deciphered
    encrypted_text = getText()

    # Decrypt said text...
    decrypted_text = decryptText(encrypted_text)

    # Print the decrypted text
    print(f"\nDecrypted text: {decrypted_text}\n")


## Driver Code ##
if __name__ == '__main__':
    main()
