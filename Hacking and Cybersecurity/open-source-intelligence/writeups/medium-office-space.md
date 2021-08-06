# Office Space - Medium

![image](https://user-images.githubusercontent.com/70488531/115806235-5e82c000-a3b4-11eb-801a-496cf5b71601.png)


## Given
For this challenge, you are given a single, bird's-eye view of an office and are tasked with finding the city the office is in. <br /> <br />
![image](https://user-images.githubusercontent.com/70488531/115806251-693d5500-a3b4-11eb-85b8-a3e66929760e.png)

## Analysis - Finding Identifiers
The first step is always to try finding the image with a [reverse image searching tool](https://tineye.com/). <br />
Unfortunately, this image turns up no results (most NCL challenges won't unless designed to). <br />

Thus, the next step is identifying unique identifiers, which will lead us to the building. <br />
A few notable identifiers would be: 
- The office has a soccer field next to it
- The office seems to be a part of a larger complex, which includes the soccer field
- The office is shaped like the [U.S.S. Enterprise NCC-1701](https://www.google.com/search?q=USS+enterprise+NCC-1701&tbm=isch&ved=2ahUKEwjrq7aUn5PwAhXHA98KHc7xCtwQ2-cCegQIABAA&oq=USS+enterprise+NCC-1701&gs_lcp=CgNpbWcQAzICCAAyAggAMgIIADICCAAyAggAMgIIADICCAAyAggAMgIIADICCAA6BAgjECc6BAgAEENQlT5Yolpgx1xoAHAAeACAAaEBiAHrCZIBBDE2LjGYAQCgAQGqAQtnd3Mtd2l6LWltZ8ABAQ&sclient=img&ei=qyaCYKuqG8eH_AbO46vgDQ&bih=722&biw=1536&rlz=1C1CHBF_enUS856US856#imgrc=DoJiMOe4c6L5qM) from Star Trek

## Pivoting
Now that we have some information, we can use it to find more. <br />
In this case, we know two key things about the image: <br />
1. The office has a soccer field
2. The office is shaped like the U.S.S Enterprise

With this information, we can perform a Google search, using quotation marks to look only for exact matches. <br />
Search: ```"star trek" "soccer field"``` <br />

Result: <br /> <br />
![image](https://user-images.githubusercontent.com/70488531/115806731-511a0580-a3b5-11eb-850e-eeb6948fa997.png)

The first result is a perfect match. [Visit the website](https://htxt.co.za/2015/05/this-spaceship-office-is-a-chinese-mans-r1-1billion-ode-to-star-trek/) hosting the image and look for more identifiers. <br />

Host Site: <br /> <br />
![image](https://user-images.githubusercontent.com/70488531/115806983-c259b880-a3b5-11eb-9a53-fb9791b1bc46.png)

In only the third paragraph, you can see that the office is located in _Changle, China_.

## Conclusion
By identifying the unique qualities of something, you have a basis to then search for it. <br />
The more specific the identifier, the easier it is to pivot and find more information on your target. <br />


<br /> <br /> <br /> <br /> 
## Extra
Often, different tools will yield different results; you ought to choose your tool based on the situation and adjust as needed. <br />
For example, since I know this office is in China, I should use the Chinese search engine [Baidu](https://www.baidu.com/) to find more information. <br />
Honestly, you don't need to speak Chinese to use Baidu at a basic level. Just pop your search into [Google Translate](https://www.google.com/search?q=google+translate&rlz=1C1CHBF_enUS856US856&oq=&sourceid=chrome&ie=UTF-8), and then use that. <br /> 
From there just click around until you get to images (图片). <br />

If you were to use Baidu, you would find many more applicable results: <br /> <br />
![image](https://user-images.githubusercontent.com/70488531/115807819-50826e80-a3b7-11eb-8745-79f8247e942c.png)

### writeup.eof()
