# Author: Ethan Cox
# Date: 5/15/2021
# Last Updated: 5/15/2021
# Group: High Point University Cybersecurity Club
# Python Version: 3.9.5
# Companion Files: None
# Dependencies: None
#
# Purpose: A NATO military alphabet decoding tool
# 
# Example of encrypted text: charlie-echo-romeo-echo-alfa-lima india-sierra november-alpha-sierra-tango-yankee
# Decrypted version:         CEREAL IS NASTY

# NATO Alphabet : Variant spellings such as 'Alpha'/'Alfa' and 'Juliett'/'Juliet' have been accounted for.
# Note: I have removed the variant spelling of 'XRAY': 'X-RAY' as the NCL uses hyphens to differentiate words
#       and will not use this variant. Also, it breaks the program...
NATO_ALPHABET = { 'ALPHA':'A', 'ALFA':'A', 'BRAVO':'B', 'CHARLIE':'C', 'DELTA':'D', 'ECHO':'E', \
                  'FOXTROT':'F', 'GOLF':'G', 'HOTEL':'H', 'INDIA':'I', 'JULIETT':'J', 'JULIET':'J', \
                  'KILO':'K', 'LIMA':'L', 'MIKE':'M', 'NOVEMBER':'N', 'OSCAR':'O', 'PAPA':'P', \
                  'QUEBEC':'Q', 'ROMEO':'R', 'SIERRA':'S', 'TANGO':'T', 'UNIFORM':'U', 'VICTOR':'V', \
                   'WHISKEY':'W', 'XRAY':'X', 'YANKEE':'Y', 'ZULU':'Z' }

# Western Union Alphabet -- gotta swap the space in 'New York' for splitting reasons...
WESTERN_UNION_ALPHABET = { 'ADAMS':'A', 'BOSTON':'B', 'CHICAGO':'C', 'DENVER':'D', 'EASY':'E', 'FRANK':'F', \
                           'GEORGE':'G', 'HENRY':'H', 'IDA':'I', 'JOHN':'J', 'KING':'K', 'LINCOLN':'L', \
                           'MARY':'M', 'NEW_YORK':'N', 'OCEAN':'O', 'PETER':'P', 'QUEEN':'Q', 'ROGER':'R', \
                           'SUGAR':'S', 'THOMAS':'T', 'UNION':'U', 'VICTOR':'V', 'WILLIAM':'W', 'XRAY':'X', \
                           'YOUNG':'Y', 'ZERO':'Z' }

# Full military alphabet (NATO + Western Union)
MILITARY_CODE = {**NATO_ALPHABET, **WESTERN_UNION_ALPHABET}

def getText():
    # Get the encrypted text as a list
    encrypted_text = input("Enter the encrypted message: ").strip().upper().split()
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
    for pos, encoded_word in enumerate(word):
        try:
            word[pos] = MILITARY_CODE[encoded_word]
        except KeyError:
            print(f"\nFATAL ERROR: The word \'{encoded_word}\' does not appear in the NATO Alphabet...")
            print("Exiting with error status code 1...\n")
            exit(1)

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
