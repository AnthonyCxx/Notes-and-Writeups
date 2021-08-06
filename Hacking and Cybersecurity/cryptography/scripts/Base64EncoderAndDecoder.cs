/*
Author: Ethan Cox
Date: 5/31/2021
Last Updated: 5/31/2021
Group: High Point University Cybersecurity Club
C# Compiler: Mono JIT compiler version 6.12.0.122 (on Ubuntu 20.04.2 LTS)
Companion Files: None
Purpose: This program is a tool for encoding or decoding text in Base64 made in C#.
Example of encrypted text: bG9yZW0gaXBzdW0= 
Decrypted version:         lorem ipsum
*/

using System;            //I/O Operations
using System.Text;      //Conversion methods for byte arrays to strings and such

//Main class
namespace classes 
{
    class Base64
    {
        //Main function, driver code
        static void Main(string[] args)
        {
            //Variables
            string choice;
            string text;
            var encoder = new Base64Encoder();
            var decoder = new Base64Decoder();

            //Get choice (encode/decode)
            do
            {
                Console.Write("Encode/Decode? (Enter \'e\' or \'d\'): ");
                choice = Console.ReadLine();
                Console.WriteLine("");   

                if (choice != "e" && choice != "d")
                {
                    Console.WriteLine("Enter either \'e\' or \'d\' (for encode or decode)");
                }

            } while(choice != "e" && choice != "d");
        

            //Get the text from the user
            Console.Write("Enter the text to translate: ");
            text = Console.ReadLine();
            Console.WriteLine("");

            //Decode or encode
            switch (choice)
            {
                case "d":
                    Console.WriteLine($"Decoded Text: {decoder.Decode(text)}");
                    break;
                case "e":
                    Console.WriteLine($"Encoded Text: {encoder.Encode(text)}");
                    break;
                default:
                    Console.WriteLine("Error: unknown request. Exiting...");
                    System.Environment.Exit(1);
                    break;                             //Just to make the compiler happy :/
            }
        }
    }



     //I know you're not supposed to do this, but I mean for this code to be copied and pasted,
    //so I'm gonna put all three classes in one file.
    
    //Base64 Decoder
    class Base64Decoder
    {
        //Decode
        public string Decode(string encodedText)
        {
            //Decode the text
            var decodedText = System.Convert.FromBase64String(encodedText);

            //Return the text as a string (from a byte array)
            return System.Text.Encoding.Default.GetString(decodedText);
        }
    }

    //Base64 Encoder
    class Base64Encoder
    {
        //Encode
        public string Encode(string plaintext)
        {
            //Translate the plaintext string into a byte array
            var encodedText = System.Text.Encoding.ASCII.GetBytes(plaintext);

            //Return the Base64 encoded byte array as a string
            return System.Convert.ToBase64String(encodedText);
        }
    }

}       //End of 'classes' namespace

//End of program
