[Return to main folder](https://github.com/hpu-panthersec/cyber-comp-materials/tree/main/log-analysis): log analysis main folder

# Installing SQLite on Linux
1. `sudo apt-get upgrade && sudo apt-get update`
2. `sudo apt install sqlite3`

# SQLite Navigation
SQL is an old language. All commands must end with a `;` unless they start with a `.`. <br />

## Standard procedure
First list all the tables with `.tables` <br />
Then do `PRAGMA table_info(<table_name>)` followed by `SELECT * FROM <table_name>` to get a feel for a table. <br />

### Basic Commands
| Command | Description |
| ------- | ----------- | 
| .tables | lists the database tables |
| PRAGMA table_info(_**table_name**_); | lists selectable headers |
| SELECT _**header**_ FROM _**table**_; | display all data of a table -- use _**\***_ for all headers |

### Example
| Example | Explanation |
| ------- | ----------- | 
| SELECT title, last_visit_date FROM moz_places; | grab the title of the site and last visit date for each website |
| SELECT title, url FROM moz_places; | grab the title and URL -- do title first, the urls aren't cut short, at all. |
| SELECT * FROM moz_annos; | dump all info from table moz_annos |

## Hotspots
### Mozilla Firebox
- moz_places : browser history
- moz_annos  : download history
