## What is Steganography?
"Steganography is the practice of hiding a secret message inside of (or even on top of) something that is not secret. These days, many examples of steganography 
involve embedding a secret piece of text inside of a picture. Or hiding a secret message or script inside of a Word or Excel document. It is a form of covert communication and can involve the use of any medium to hide messages. It’s not a form of cryptography, because it doesn’t involve scrambling data or using a key. Instead, it is a form of data hiding and can be executed in clever ways. Where cryptography is a science that largely enables privacy, steganography is a practice that enables secrecy – and deceit." <br />
\- an excerpt from [CompTIA](https://www.comptia.org/blog/what-is-steganography)

## General Stegonography
1. The message could be hidden in the file as plain text. <br />
1A. Use the `strings` command in conjunction with `grep` to parse the file for hidden information (flags, such as SKY-ABCD-1234). The command for that would be `strings <file> | grep -iE "(SKY|NCL)-[A-Za-z]{4}-[0-9]{4}"`<br />
2. The file could contain hidden files embedded within it. <br />
2A. Use `binwalk` to parse the image for hidden files. Use the `-z` flag to search for hidden files without extracting. Extract with `-e`. <br />

## Image Stegonography
3. The message could be emedded within the image itself using stegonography tools.  <br />
3A. Check for hidden, embedded information using both steghide and [the digital invisible ink toolkit](http://diit.sourceforge.net/download.php) (DIIT). This is a must have.
Go under 'decode' and then create a blank text file to use as the output. Anything uncovered will end up there as text. You may need a password, which can usually be found in 
the plaintext, in the file itself, or by doing something as simple as scanning the a QR code. <br />

## Wave (Audio) Steganography
- Right click the file and go to `properties` and then `details`. Here are things like file length and bit rate. <br /> Alternatively, you can use software such as 
  SoX ([Sound Exchange](https://www.unixmen.com/how-to-play-music-from-command-line-terminal/)) or Exiftool.
- Use [this](https://morsecode.world/international/decoder/audio-decoder-expert.html) tool to visualize messages in the audio. Yes, it's for Morse code, but it works.


## Miscellaneous, but Important Information
- The people behind the NCL are a bit cheeky when it comes to steganography.
They'll give you an image to decode that requires a password, and put that password as plaintext in 
the data of the image without ever telling you that it's the password. Which, to be fair, is at least 
a little obvious considering that it's quite out of place when surrounded by a ton of nonsense. 
- If the first bit of text is a different image extension, rename the original image with that extension and re-open it for the flag. <br />
Some extension names may not align with what you are familiar with (e.g. a file starting with `JFIF` is a `.jpeg` file). <br />
- If there's a QR code, scan it. It might just have the password.

### Sources
- CompTIA: [The Ancient Practice of Steganography](https://www.comptia.org/blog/what-is-steganography)
- HackTricks: [Stego Tricks](https://book.hacktricks.xyz/stego/stego-tricks)
- 0xRick: [Stego Tools and Resources](https://0xrick.github.io/lists/stego/)
