#include "aa.h"
std::fstream file;

bool readData(std::string& DB_rekap){
	file.open(DB_rekap);
	if(!file.is_open()){
		std::cerr << "Dashboard.cpp : File not found" << std::endl;
		return false;
	}
	return true;
}

void writeData(std::string& DB_rekap){
	if(!readData(DB_rekap)){
		return;
	}

	std::string line;
	while(std::getline(file, line)){
		std::stringstream ss(line);
		std::string semesterStr, ipsStr;

		if(std::getline(ss, semesterStr, ',') && std::getline(ss, ipsStr, ',')){
			DashBoard temp;
			temp.semester = stoi(semesterStr);
			temp.IPS = stof(ipsStr);
			DashBoardData.push_back(temp);
		}
	}
	file.close();
}