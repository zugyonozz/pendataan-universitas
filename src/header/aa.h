#ifndef AA_H
#define AA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

struct DashBoard{
	int semester;
	float IPS;
};

extern vector<DashBoard> DashBoardData;

void readData();
void writeData();

#endif // AA_H