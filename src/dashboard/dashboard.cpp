#include "aa.h"
using namespace std;
fstream file;

bool readData(string& DB_rekap){
	file.open(DB_rekap);
	if(!file.is_open()){
		cerr << "Dashboard.cpp : File not found" << endl;
		return false;
	}
	return true;
}

void writeData(string& DB_rekap){
	if(!readData(DB_rekap)){
		return;
	}

	string line;
	while(getline(file, line)){
		stringstream ss(line);
		string semesterStr, ipsStr;

		if(getline(ss, semesterStr, ',') && getline(ss, ipsStr, ',')){
			DashBoard temp;
			temp.semester = stoi(semesterStr);
			temp.IPS = stof(ipsStr);
			DashBoardData.push_back(temp);
		}
	}
	file.close();
}