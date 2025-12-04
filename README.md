# About the Project
This code in C++ is build to handle information about pattern calls and display it to the user.

## DESCRIPTION
The code can produce a training example of dummy data for pattern calls tuples and store it into a file for further analysis.
This version 1.0 give the following queries:
- retrieve a pattern call with a specified identifier, e.g. 42
- list all pattern calls with a specified name, e.g. “myPattern”
- list all pattern calls with a specified path, e.g. “src/patterns/Functional.pat”
- list all pattern calls which are skipped, i. e. when the “called” flag is false
- list all pattern calls which are not skipped, i. e. when the “called ” flag is true

## Directory Structure
The directory includes four main directories
```
Debug               //Specifies the debuggers to run
Header Files-----| // includes all the functions definitions and variables
                 |
                 DataBase.h       //class DataBase holds function definitions and variables related to the dummy data production.
                 DataProcessing.h //class DataProcessing holds function definitions and variables related to the analysis

Source Files-----| // includes the building structure for the run
                 |
                 DataBase.cpp       //for dummy data production , e.g. Database generation , resp.read  from a file
                 DataProcessing.cpp //for analysis, e.g. reading column by column or row by row.
                PatternCalls.cpp    //Includes the main function for user interface
src/patterns/----- // includes all the saved data files during the run.
```
##  RUN THE CODE
The code supports C++11
```
$ g++ PatternCalls.cpp
```
from user interface several options can be selected
                            Menu Options
              1 - produce dummy data for pattern calls
              2 - Retrieve a pattern call with a specified identifier
              3 - List all pattern calls with specific criterion
              4 - End program
## 🌍 Let’s Connect
Author: Ahmed Qamesh
Email: ahmed.qamesh@gmail.com
