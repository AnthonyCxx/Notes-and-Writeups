# Refining Search Results with Boolean Search Methods
[Return to main folder](https://github.com/hpu-panthersec/cyber-comp-materials/tree/main/open-source-intelligence): open-source-intelligence

## These methods are meant for Google, but may work with other engines
## Always use as few words as possible. <br /> Do not use unnecessary words such as "the" or "a" unless necessary.

| Operator | Purpose | Example |
| -------- | ------- | ------- | 
| site | Search specific site | site:wikipedia.org | 
| related	| Search for related sites | related:wikipedia.org |			
| cache	| Search with Google's cached version of a site | cache:wikipedia.org	|			
| intitle | Search page Title | intitle:wikipedia |
| allintitle | Search page title | intitle:wikipedia |
| subject	| Group subject search	|  |
| inurl	| Search URL | inurl:wikipedia | 
| allinurl | Search URL | allinurl:wikipedia | 
| filetype | specific files | filetype:pdf	|
| intext | Search text of page only | intext:wiki |
| allintext	| Search text of page only | allintext:wiki |
| "" | Search for exact word match | "Wikipedia" |			
| +	| Search for more than one specific key | jaguar + car |  				
| -	| Exclude words from your search | jaguar speed -car |
| OR | Combines two searches | jaguar OR car |	
| * |	Wildcard operator	| how to * to Wikipedia	|			
| link | Search for links to pages | link:wikipedia | 
| inanchor | Search link anchor text | |
| numrange | Locate number | do not use. |
| daterange	| Search in date range | daterange:2444239-2458849 |
| author | Group author search | author:John author:Green | 
| group	| Group name search	| |
| msgid	| Group msgid search | |
| imagesize | Advanced Image Search | imagesize:320x320 |					
| @	| Search Social Media | @wikipedia | 			
| # |	Search for hashtags	| #wiki |			
| $	| Search for a price | camera $400	|				
| .. | Search within a range of numbers | camera $50..$100 |
| ~ | search for a term and its synonyms | it security ~tools |

### An explanation on 'daterange'
The _daterange_ keyword takes two dates, a start date and an end date, which are separated by a hyphen. <br />
These dates _must_ be provided as integer Julian dates (the amount of days since the beginning of the [Julian period](https://www.britannica.com/science/Julian-period). <br />
The example used in the chart above searches for the dates January 1st, 1980 - January 1st, 2020 (daterange:2444239-2458849).

#### Master Lists of File Formats and Extensions
[Extensions 0-9](https://en.wikipedia.org/wiki/List_of_filename_extensions) <br />
[Extensions A-E](https://en.wikipedia.org/wiki/List_of_filename_extensions_(A%E2%80%93E)) <br />
[Extensions F-L](https://en.wikipedia.org/wiki/List_of_filename_extensions_(F%E2%80%93L)) <br />
[Extensions M-R](https://en.wikipedia.org/wiki/List_of_filename_extensions_(M%E2%80%93R)) <br />
[Extensions S-Z](https://en.wikipedia.org/wiki/List_of_filename_extensions_(S%E2%80%93Z)) <br />
[Master List of File Formats](https://en.wikipedia.org/wiki/List_of_file_formats) <br />

### Some real-world examples:
| Purpose | Text |
| ------- | ---- |
| Finding usernames | allintext:username filetype:log |
| Finding SSNs | +ssn "486..500-01..99-0001..9999" (all social security numbers from Missouri) |
| Finding emails (with some passwords) | allintext:email OR mail +\*gmail.com filetype:txt |

### Sources:
[Infosec Institute](https://resources.infosecinstitute.com/topic/google-hacking-the-hidden-face-of-google-2/) <br />
[Wikipedia - Google Dorks/Hacking](https://en.wikipedia.org/wiki/Google_hacking) <br />
[Google Hacking](http://index-of.co.uk/Google/Google%20Hacking.pdf) <br />
[Google Dorking with Examples](https://gist.github.com/stevenswafford/393c6ec7b5375d5e8cdc)
