#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>



using namespace std;


//	generic types

struct xString {
	long		length;		// number of characters to follow
	std::string		chars;		// characters (usually zero terminated)
};

//	.MLT
//	known structures:	1 ("ML2")

struct _RecordMLT {
	long		index3DC;	// index of a .3DC filename
	long		indexDDS;	// index of a .DDS filename
	long		alphaFlg;	// alpha channel flag (0: alpha channel defines visibility, 1: alpha defines glow)
};

struct _FileMLT {
	char		sign[3];	// signature: 'M','L','2'
	long		count3DC;	// number of .3DC filenames to follow
	std::vector<xString*>		names3DC;	// array of filenames
	long		countDDS;	// number of .DDS filenames to follow
	std::vector<xString*>		namesDDS;	// array of filenames
	long		countRec;	// number of records to follow
	std::vector<_RecordMLT*>	records;	// array of the RecordMLT
};