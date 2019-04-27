# Canopy Alpha v2.0

### A software solution to viewing email search warrants

Created by Canopy Intelligence LLC

## Bugs

1. Some MIME headers are a different format than the 'typical' header and our parser misses information
2. Keyword word bank adds words on new row every time
3. Word frequency count is very slow and halts the application
4. HTML with images/color doesn't show up right
5. No robustness for if an email doesn't have HTML content

## ToDo

### GUI
~~1. Loosen rigidness of welcome window~~

~~2. Remove different window for search~~

~~3. Open emails in content window~~

~~4. Make coloring on inbox/outbox more user friendly~~

5. Be able to 'flag' emails as "important" or "do not read again"

6. Autocomplete typing in search bar

7. Fix HTML display

~~8. Vectorize all windows~~

9. Remove 'x' in upper left corner
10. Sort data by hierarchical folders - inboxes or FB data
11. More flexible sorting options
12. Number emails

~~13. Be able to add multiple warrants to one session~~

~~14. Add threading for data parsing~~

15. Be able to view facebook warrant

### Data
~~1. Speed up data analysis~~

2. Be able to save/load a session

~~3. Break input files into working .can, .ses, and .ins files~~

4. Identify spam emails

### Parser
~~1. Clean up HTML parsing~~

2. Be able to view attachments
3. Get content (string data) out of facebook HTML data

## Latest Features: Canopy Alpha v2.0

### GUI
- Loosen rigidness of welcome window
- Remove different window for search
- Vectorize all windows
- Be able to add multiple warrants to one session

### Data

### Parser
- Improved HTML parsing from MIME input files



## Past Releases

Canopy Alpha Features v1.0
3/18/2019

### GUI
- Welcome Window and Search Window interface
- Allow user to select a file as an input
- Display email headers in Search Window
- Clicking email headers opens an email viewer window displaying email contents
- All windows are centered
- Word frequency display interface for all emails
- Word bank for adding keyword filters
- Take user input for filter data
- User can search word frequencies

### Data
- Filter emails by date
- Display emails in chronological order
- Counting word frequency in all email content
- Filter emails by keyword

### Parser
- Created Email Data storage class
- Parsing MIME header information and displaying in scroll area
- Created rough parser for MBOX files
- Improved appearance of HTML content
