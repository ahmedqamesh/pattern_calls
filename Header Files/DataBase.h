/*
 * DataBase.h
 *
 *  Created on: 3 Jul 2019
 *      Author: ahmedqamesh
 */
#ifndef DATABASE_H_
#define DATABASE_H_
#include<tuple>
#include <string>
#include <cstdlib>

class DataBase{
	public:
		// Set functions
		void SetId( int idx);
		void SetName(string nam);
		void SetpatternFile(string pat);
		void SetcalledFlag(bool fla);
		void initialize(int idx, string nam, string pat, bool fla);

		// Get functions
		int 	GetId() const {return id; };
		string 	GetName() const{return name;};
		string 	GetpatternFile() const{return patternFile;};
		bool GetcalledFlag() const {return calledFlag;};

		tuple <int, string, string , bool> FindCallInfo(int count , int rand);
		void GenerateDatabase(string file, int ncalls);
		void LoadData(string DataProcessing);

	private:
		int id;
		bool calledFlag;
		string name, patternFile,line;
		ofstream data, dummyData;
		ifstream inFile;
};




#endif /* DATABASE_H_ */
