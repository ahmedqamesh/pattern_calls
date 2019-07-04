#include <cstdlib>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "../Header Files/DataProcessing.h"
using namespace std;
DataProcessing::DataProcessing(const string& file_name) {
        /*
         * The function reads an existing data file and saves it into a vector of strings
         * Parameters:
           file_name [string]: name of the output file
         * return:
           datavector [vector<vector<string>>] : vector includes all the data
         */
        stream_read.open(file_name, ios::binary);
        string out_file = remove_extension(file_name) + "_OUT.csv";
        stream_write.open(out_file, ios::binary);
        stream_write << stream_read.rdbuf(); // Copy read file into output file
        bool line_is_header = true; // First line assumed to be the header
        stream_read.seekg(0); // "Rewind" infile stream
        while (stream_read) {
                // Grab whole row
                string s;
                if (!getline(stream_read, s))
                        break;

                istringstream ss (s);
                vector<string> record;
                while(ss) {
                        // Split string by comma delimiter
                        string s;
                        if (!getline(ss, s, ','))
                                break;
                        record.push_back(s);
                }

                if (line_is_header)
                        header = record;
                else
                        datavector.push_back(record);
                // First iteration clears through the header
                line_is_header = false;
        }
}

void DataProcessing::headers() {
        //read the headers
        for (auto&& i : header)
                cout << i << ", ";
}
DataProcessing::CsvVector DataProcessing::rows() {
        //return the rows
        return datavector;
}

void DataProcessing::specify_row(string col, string nam){
        /*
         * The function return a vector of indicies corresponds to a specific element.
         * Parameters:
           col [string]: name of the column
           nam [string]: name of the element
         * return:
           colIndex[i] [vector<int>] : vector of indicies
         */
        vector<string>  column = column_info(col);// get column col
        vector<int> colIndex = index_from_vector(column, nam); // get index of a row specific name nam
        for(int i=0; i <colIndex.size(); ++i) GetRow(colIndex[i]);
}

DataProcessing::CsvVector DataProcessing::GetColumn(const string& s) {
        /*
         * The function return a vector of elements in specific column s .
         * Parameters:
           s [string]: name of the column
         * return:
           columnData[i] [[vector<vector<string>>]] : vector of strings
         */
        DataProcessing::CsvVector columnData;
        columnData.push_back(column_info(s));
        return columnData;
}


vector<string> DataProcessing::get_header() {
        return header;
}
vector<string> DataProcessing::GetRow(const int& i) {
        /*
         * read a specific row with an index i
         * Parameters:
           i [int] : index of the row
         * return:
           datavector[i] [vector<vector<string>>] : vector includes the row data
         */

        for (auto idx = datavector[i].begin(); idx != datavector[i].end(); ++idx)
                cout << *idx <<',';
        cout<<"\n";
        return datavector[i];
}


vector<string> DataProcessing::column_info(const string& s) {
/* Returns all data in the passed column(s)
 * Parameters:
    s [string]: name of the column
 * return:
    columnData[i] [[vector<vector<string>>]] : vector of strings
 */
        vector<string> data;
        int index = index_from_string(s);

        for (auto&& i : datavector) {
                data.push_back(i[index]);
        }
        return data;
}

vector<int> DataProcessing::index_from_vector(vector<string> v, string key){
      /*
       * get a vector of indicies of a specific element in an array
       * parameters:
         v [vector<string>]: vector of strings
         key[string]: element under test
       * return:
         colIndex [vector<int>] : vector of indicies for the specified element
       */
        vector<int> colIndex;
        int i;
        for(i=0; i <v.size(); ++i) {
                if(v[i]!=key) {
                        continue;
                }else{
                        colIndex.push_back(i);
                }
        }
        return colIndex;
}

int DataProcessing::index_from_string(const string& s) {
        /*
         * get index of a specific element s in an array
         * parameters:
           s [string]: element name
         * return:
           pos [int] : index of the element
         */

        int pos = find(header.begin(), header.end(), s) - header.begin();
        if (pos == header.size()) {
                throw out_of_range("\nColumn: " + s + " not found in header");
        }
        return pos;
}

string DataProcessing::remove_extension(const string& s) {
        // remove extension part from a file name
        string ret = s;
        ret.erase(ret.find_last_of("."), string::npos);
        return ret;
}
