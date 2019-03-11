# Canopy Alpha v1.0

### A software solution to viewing email search warrants

Created by Ethan Bond, Luke Epp, Josh Rands, and Matt Wojnoski  
2/27/2019

## Bugs

1. No bugs right now :)

## ToDo

### GUI
1. Take user input for keywords and date range
2. Add word bank to search window
3. Add search feature for word frequency

### Data
1. C++ function for word count from string/char stream
2. Organize emails by date

### Parser
1. Create parser for .eml file type
	- take file name as input
2. Know email location in meta data
3. Create parser for .mbox file type
4. Parse html section of .eml to look normal
5. Create html string from raw html

## Latest Features: Canopy Alpha v1.0

### GUI
- Welcome Window and Search Window interface
- Allow user to select a file as an input
- Display email headers in Search Window
- Clicking email headers opens an email viewer window displaying email contents
- All windows are centered
- Word frequency display for all emails

### Data
- 

### Parser
- Created Email Data storage class
- Parsing MIME header information and displaying in scroll area
