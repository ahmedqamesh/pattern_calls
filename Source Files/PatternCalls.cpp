/*
 * PatternCalls.cpp
 *
 *  Created on: 30 Jun 2019
 *      Author: ahmedqamesh
 */
#include <iostream>
#include "../Source Files/DataBase.cpp"
#include "../Source Files/DataProcessing.cpp"
using namespace std;
enum Options { GET = 1, RETRIEVE, LIST, END};
int mainMenu()
{
								cout << "\n Menu Options" << endl
													<< "1 - produce dummy data for pattern calls"<< endl
													<< "2 - Retrieve a pattern call with a specified identifier" << endl
													<< "3 - List all pattern calls with specific criterion" << endl
													<< "4 - End program" << endl;
								int ch;
								cin >> ch;
								return ch;
};

int PatternCalls(){
								int choice;
								DataBase call;
								string file_name = "../src/patterns/dataFile.csv";
								int dataSize = 100000;
								int idx;
								string name, col;
								vector<string> columns = {"id","name","patternFile","called"};

								// handle information about pattern calls
								DataProcessing csv_obj("../src/patterns/dataFile.csv");
								typedef vector<vector<string> > CsvVector;
								vector<string> headers = csv_obj.get_header();
								while(1) {
																choice = mainMenu();
																if(choice == END)
																								break;
																switch(choice) {
																case GET: {
																		cout << "\n Enter the sample size" << endl << "? ";
																	cin >> dataSize;
																								//Genenrate a hypothetical data base for pattern calls
																								call.GenerateDatabase(file_name, dataSize);
																								break;
																}
																case RETRIEVE: {
																								cout << "\n Enter the identifier" << endl << "? ";
																								cin >> idx;
																								if(idx < 1 || idx > dataSize) {
																																cout << "Invalid identifier." << endl;
																																break;
																								}
																								//1-retrieve a pattern call with a specified identifier, e.g. 42
																								cout<<"Pattern call with identifier "<<setw(3)<<setfill(' ')<<idx<<":"<<"\n"<< left <<setw(35)<< setfill('-') << '+' << '+' << "\n";
																								vector<string> row_id = csv_obj.GetRow(idx); // Get rows by index
																								cout<<"\n"<<"*******************************************************"<<"\n";
																								break;
																}

																case LIST: {  cout << "\n Recommended Columns: [id, name,patternFile,called]" << endl;
																														cout << "\n Enter the column name" << endl << "? ";
																														cin >> col;
																														vector<string>::iterator it = std::find(columns.begin(), columns.end(), col);
																														if (it != columns.end()) {
																																						cout << "\n Enter the specified criterion" << endl << "? ";
																																						cin >> name;
																																						vector<string>  colData = csv_obj.column_info(col);

																																						vector<string>::iterator colit = std::find(colData.begin(), colData.end(), name);
																																						if (colit != colData.end()) {
																																														cout << "Analysing column:"<<setw(3)<<setfill(' ')<<col<<"\n";
																																														cout<<"pattern calls under the name"<<setw(3)<<setfill(' ')<<name<<
																																																						":"<<"\n"<<left <<setw(35)<< setfill('-') << '+' << '+' << "\n";
																																														//2-list all pattern calls with a specified name, e.g. “myPattern”
																																														csv_obj.specify_row(col, name);
																																														cout<<"\n"<<"*******************************************************"<<"\n";
																																						}else{
																																														cout <<  "Invalid identifier" << endl;
																																														break;
																																						}
																														}else{
																																						cout <<  "Invalid column name" << endl;
																																						break;
																														}
																														break;}      default: {
																								cerr << "Invalid choice!" << endl;
																								break;
																}

																}
								}
								return 0;
};
