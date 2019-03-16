# Canopy Alpha v1.0

### A software solution to viewing email search warrants

Created by Ethan Bond, Luke Epp, Josh Rands, and Matt Wojnoski  
2/27/2019

## Bugs

1. Some MIME headers are a different format than the 'typical' header and our parser misses information
2. Keyword word bank adds words on new row every time
3. Word frequency count is very slow and halts the application
4. HTML with images/color doesn't show up right
5. No robustness for if an email doesn't have HTML content

## ToDo

### GUI

### Data
1. Speed up data analysis

### Parser
1. Know email location in meta data

## Latest Features: Canopy Alpha v1.0

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
