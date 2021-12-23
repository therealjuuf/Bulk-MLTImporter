#include <fstream>
#include <iostream>
#include <filesystem>
#include "Structure.h"
namespace fs = std::filesystem;


int read3DCFromFolder(_FileMLT* mlt){
	std::string path("./data/");
	std::string ext(".3DC");
	std::string ext2(".3dc");
	for (auto &p : fs::recursive_directory_iterator(path))
	{
		if (p.path().extension() == ext || p.path().extension() == ext2) {
			std::string asd = p.path().stem().string();
			xString * _3dcName = new xString();
			_3dcName->chars = asd + ".3DC";
			_3dcName->length = (asd + ".3DC").size();
			xString * _DDSName = new xString();
			
			_DDSName->chars = asd + ".dds";
			_DDSName->length = (asd + ".dds").size();

			_RecordMLT* record = new _RecordMLT();
			record->index3DC = mlt->count3DC;
			record->indexDDS = mlt->countDDS;
			record->alphaFlg = 1;


			mlt->names3DC.push_back(_3dcName);
			mlt->namesDDS.push_back(_DDSName);

			mlt->count3DC += 1;
			mlt->countDDS += 1;
			mlt->countRec += 1;



			mlt->records.push_back(record);

		}		
	}
	return 0;
}
