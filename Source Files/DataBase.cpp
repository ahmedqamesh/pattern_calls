/*
 * DataBase.cc
 *
 *  Created on: 3 Jul 2019
 *      Author: ahmedqamesh
 */
#include "../Header Files/DataBase.h"
#include <string.h>
#include <time.h>
#include <ctime>
void DataBase::initialize(int idx, string nam, string pat, bool fla){
								/*
								 * The function intialise all the set function needed for data generation
								 * Parameters:
								   idx [integer]: index of the caller.
								   nam [string]: caller's name.
								   pat [string]: project relative path to the so called pattern file
								   fla [bool]: flag states whether the pattern should be called or not (“called”).
								 */
								SetId(idx);
								SetName(nam);
								SetpatternFile(pat);
								SetcalledFlag(fla);
};
tuple <int, string, string, bool> DataBase::FindCallInfo(int i, int rand){
								/*
								 * The function provide call information for the dummy data based on some pre-defined data
								 * Parameters:
								   i [integer]: index of the caller.
								   rand [integer]: random number to select data randomly
								 * return:
								   return a tuple of the pattern call with id, name, patternFile, calledFlag.
								 */

								vector<string> names = {"Yannick", "Qamesh", "George", "Martin","Hans","Laura","Edward"};
								vector<bool> status={true,false,false, true,true,false,false };
								string PatFile = string("src/patterns/Functional_")+ string(names[rand])+string(".pat");
								dummyData.open(string("../")+PatFile, ios::out);
								dummyData << "Dummy data for"<<":"<<PatFile<<endl;
								dummyData.close();

								initialize(i,names[rand],PatFile, status[rand]);
								return make_tuple(id, name, patternFile, calledFlag);
};

void DataBase::GenerateDatabase(string file, int ncalls){
								/*
								 * The function  print the call information and save it to a csv file.
								 * Parameters:
								   file [string]: the file name in csv format
								   ncalls [integer]: number of required calls
								 */

								data.open(file, ios::out);
								data << "id" << ","<< "name" <<","<< "patternFile" << ","<< "called"<<endl;
								cout << left<< setw(6) << setfill('-') << left << '+'
													<< setw(16) << setfill('-') << left << '+'
													<< setw(36) << setfill('-') << left << '+' << setw(11)
													<< setfill('-')<< '+' << '+' << endl;

								cout << setfill(' ') << '|' << left << setw(5)
													<< "id"
													<< setfill(' ') << '|' << setw(15) << "name"
													<< setfill(' ') << '|' << setw(35) << "patternFile"
													<< setfill(' ') << '|' << right << setw(10)
													<< "called" << '|' << endl;

								cout << left << setw(6) << setfill('-') << left
													<< '+' << setw(16) << setfill('-') << left << '+'
													<< setw(36)
													<< setfill('-') << left << '+' << setw(11) << setfill('-')
													<< '+' << '+' << endl;

								for (int count=0; count <= ncalls; ++count) {
																int range = 6 - 0 + 1;
																int num = rand() % range + 0;
																auto GenerateCall =  FindCallInfo(count, num);
																string flag = "true";
																if (get< 3>(GenerateCall) == 0) flag = "false";
																cout << setfill(' ') << '|' << left << setw(5) << get<0>(GenerateCall)
																					<< setfill(' ') << '|' << setw(15) << get<1>(GenerateCall)
																					<< setfill(' ') << '|' << setw(35) << get<2>(GenerateCall)
																					<< setfill(' ') << '|' << setw(10)<< flag<<right <<  '|'  <<endl;
																data<< get< 0>(GenerateCall) << ","<< get< 1>(GenerateCall)<<","<< get<2>(GenerateCall)<< "," << flag<< endl;
								};

								cout << left << setw(6) << setfill('-') << left
													<< '+' << setw(16) << setfill('-') << left << '+'
													<< setw(36)<< setfill('-') << left << '+' << setw(11)
													<< setfill('-')<< '+' << '+' << endl;
								data.close();
};

void DataBase::LoadData(string DataProcessing){
								/*
								 * The function  loads the data into C++ program
								 * Parameters:
								   file [string]: the file name in csv format
								 */
								inFile.open(DataProcessing, ios::in);
								// check if opening a file failed
								if (inFile.fail()) {
																cerr << "Error opeing a file" << endl;
																inFile.close();
																exit(1);
								}
								while (getline(inFile, line)) {
																cout << line << endl;
								}
								inFile.close();
};

// Set functions
void DataBase::SetId( int callno ) {
								id = callno;
};

void DataBase::SetName(string fname ) {
								name = fname;
};

void DataBase::SetpatternFile(string file) {
								patternFile = file;
};
void DataBase::SetcalledFlag( bool flag) {
								calledFlag = flag;
};
