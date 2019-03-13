# Canopy Alpha v1.0

### A software solution to viewing email search warrants

Created by Ethan Bond, Luke Epp, Josh Rands, and Matt Wojnoski  
2/27/2019

## Bugs

1. Some MIME headers are a different format than the 'typical' header and our parser misses information
2. Keyword word bank adds words on new row every time

## ToDo

### GUI
1. Add search feature for word frequency
2. Be able to remove keyword filters

### Data
1. C++ function for word count from string/char stream

### Parser
1. Know email location in meta data
2. Create parser for .mbox file type
3. Parse html section of .eml to look normal
4. Create html string from raw html

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

### Data
- Filter emails by date
- Display emails in chronological order

### Parser
- Created Email Data storage class
- Parsing MIME header information and displaying in scroll area
