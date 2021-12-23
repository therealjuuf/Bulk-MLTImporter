// MLTImporter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Structure.h"

extern _FileMLT* ReadMLT(string filename);
_FileMLT* WriteMLT(string filename, _FileMLT* mlt);

extern int read3DCFromFolder(_FileMLT* mlt);

int main()
{
	std::cout << "write target mlt file name?!\n";
	string filename;
	getline(cin, filename);


	_FileMLT* mlt = ReadMLT(filename);

	read3DCFromFolder(mlt);

	WriteMLT(filename, mlt);
	std::cout << "new models added successfully!\n";
	getchar();

}
