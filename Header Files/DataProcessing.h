/*
 * DataProcessing.h
 *
 *  Created on: 1 Jul 2019
 *      Author: ahmedqamesh
 */
#ifndef DATAPROCESSING_H_
#define DATAPROCESSING_H_
#include <string>
#include<tuple>
#include <string>
#include <cstdlib>
;class DataProcessing {
	typedef vector<vector<string>> CsvVector;

	public:
		DataProcessing() = default;
		DataProcessing(const string&);
	    inline void headers();
	    inline vector<string> get_header();

	    vector<string> GetRow(const int&);
	    inline CsvVector rows();
	    CsvVector GetColumn(const string&);
	    void specify_row(string col, string nam);
	    vector<int> index_from_vector(vector<string>  v, string key);
			vector<string> column_info(const string&);
	private:
	    vector<string> header;
	    CsvVector datavector;
	    ifstream stream_read;
	    ofstream stream_write;
	    inline string remove_extension(const string&);
	    int index_from_string(const string&);
};
#endif /* DATAPROCESSING_H_ */
