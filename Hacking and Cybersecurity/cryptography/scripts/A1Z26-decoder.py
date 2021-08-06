# Author: Ethan Cox
# Date: 5/10/2021
# Last Update: 5/12/2021
# Group: High Point University Cybersecurity Club
# Python Version: 3.9.5
# Companion Files: None
#
# Purpose: This script decrypts a message that have been encrypted with a simple A1Z26 cipher.
#          Honestly, I wrote this whole thing this morning and then found out it's an actual thing 
#          with pre-built tools about two hours later...
# 
#
# Example of encrypted text: 9 12-5-6-20 9-20 9-14 20-8-5 19-15-21-20-8-19-9-4-5 4-5-1-4 4-18-15-16 9-14 20-8-5 16-1-18-11
# Decrypted version: i left it in the southside dead drop in the park 

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
        word[pos] = chr( int(num) + 96 ) # 'a' starts at 97 in ASCII

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
