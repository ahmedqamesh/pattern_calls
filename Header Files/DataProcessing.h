/*
 * DataProcessing.h
 *
 *  Created on: 1 Jul 2019
 *      Author: ahmedqamesh
 */
#ifndef DATAPROCESSING_H_
#define DATAPROCESSING_H_
#include <string>
#include <tuple>
#include <string>
#include <cstdlib>
; class DataProcessing {
								typedef vector<vector<string>> CsvVector;

public:
								DataProcessing() = default;
								DataProcessing(const string&);
								inline void headers();
								inline vector<string> GetHeader();

								vector<string> GetRow(const int&);
								inline CsvVector rows();
								CsvVector GetColumn(const string&);
								void SpecifyRow(string col, string nam);
								vector<int> IndexFromVector(vector<string>  v, string key);
								vector<string> ColumnInfo(const string&);
private:
								vector<string> header;
								CsvVector datavector;
								ifstream streamRead;
								ofstream streamWrite;
								inline string RemoveExtension(const string&);
								int IndexFromString(const string&);
};
#endif /* DATAPROCESSING_H_ */
