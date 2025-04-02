#ifndef AA_H
#define AA_H

#include "write.h"
#include <fstream>
#include <sstream>

struct DashBoard{
	int semester;
	float IPS;
};

extern std::vector<DashBoard> DashBoardData;

void readData();
void writeData();

#endif // AA_H