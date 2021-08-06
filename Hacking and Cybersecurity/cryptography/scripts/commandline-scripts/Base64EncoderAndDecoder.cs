/*
Author: Ethan Cox
Date: 5/31/2021
Last Updated: 6/2/2021
Group: High Point University Cybersecurity Club
C# Compiler: Mono JIT compiler version 6.12.0.122 (on Ubuntu 20.04.2 LTS)
Companion Files: None

Purpose: This program is a commandline tool for encoding or decoding text in Base64 made in C#.

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
            var decoder = new Base64Decoder();
            var encoder = new Base64Encoder();

            //Validate the commandline arguments
            ValidateArgs(args);

            //Decode or encode
            switch (args[0])
            {
                case "-d":
                    Console.WriteLine($"Decoded Text: {decoder.Decode(args[1])}");
                    break;
                case "-e":
                    Console.WriteLine($"Encoded Text: {encoder.Encode(args[1])}");
                    break;
                default:
                    Console.WriteLine("Error: unknown request. Exiting...");
                    System.Environment.Exit(1);
                    break;                             //Just to make the compiler happy :/
            }
        }


        //Validate commandline arguments
        static void ValidateArgs(string[] args)
        {
            if (args.Length == 0)   //If no arguments are provided
            {
                Console.WriteLine("Usage: [option] [text]");
                Console.WriteLine("Use the options \'--help\' or \'-h\' for help.");
                System.Environment.Exit(1);
            }
            else if (args[0] == "--help" || args[0] == "-h")   //If the user asks for help
            {
                Console.WriteLine("This program encodes and decodes base64 text.");
                Console.WriteLine("You need to provide two arguements: an \'-e\' or \'d\' to indicate whether to encode/decode and the text.");
                Console.WriteLine("An example: ./base64Converter.exe -d bG9yZW0gaXBzdW0=");
                System.Environment.Exit(1);
            }
            else if (args.Length < 2)   //If only a flag or only text is provided
            {
                Console.WriteLine("Fatal error: insufficent amount of arguments. Provide both a flag and text.");
                System.Environment.Exit(1);
            }
            else if (args.Length > 2)   //If the text is improperly provided
            {
                Console.WriteLine("Fatal error: text not provided as a single string. Surround the text with \" \".");
                System.Environment.Exit(1);
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
