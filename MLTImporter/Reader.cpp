
#include "Structure.h"



_FileMLT* ReadMLT(string filename) {
	

	ifstream rf("./mlt/"+filename, ios::binary);
	if (!rf) {
		cout << "file cannot be opened" << endl;
		//getchar();
		//return -1;
		//return 1;
	}
	cout << "mlt loaded" << endl;

	char temp[500];

	_FileMLT* mlt = new _FileMLT();
	rf.read((char*)&mlt->sign, sizeof(mlt->sign));


	// read 3dc count
	rf.read((char*)&mlt->count3DC, sizeof(mlt->count3DC));

	// read 3dc names
	for (int i = 0; i < mlt->count3DC; i++) {
		xString * _3dcName = new xString();
		rf.read((char*)&_3dcName->length, sizeof(_3dcName->length));

		rf.read((char*)&temp, _3dcName->length);

		_3dcName->chars = temp;

		mlt->names3DC.push_back(_3dcName);

	}


	// read 3dc count
	rf.read((char*)&mlt->countDDS, sizeof(mlt->countDDS));

	// read 3dc names
	for (int i = 0; i < mlt->countDDS; i++) {
		xString * _ddsName = new xString();
		rf.read((char*)&_ddsName->length, sizeof(_ddsName->length));

		rf.read((char*)&temp, _ddsName->length);

		_ddsName->chars = temp;

		mlt->namesDDS.push_back(_ddsName);

	}

	// read 3dc count
	rf.read((char*)&mlt->countRec, sizeof(mlt->countRec));

	// read 3dc names
	for (int i = 0; i < mlt->countRec; i++) {
		_RecordMLT * mltrecord = new _RecordMLT();
		
		rf.read((char*)&mltrecord->index3DC, sizeof(mltrecord->index3DC));
		rf.read((char*)&mltrecord->indexDDS, sizeof(mltrecord->indexDDS));
		rf.read((char*)&mltrecord->alphaFlg, sizeof(mltrecord->alphaFlg));


		mlt->records.push_back(mltrecord);

	}




	rf.close();

	return mlt;
}