
#include "Structure.h"



_FileMLT* WriteMLT(string filename, _FileMLT* mlt) {


	if (remove(("./mlt/" + filename).c_str()) != 0)
		perror((""+ filename+"doesn't exist, it will be created automatically.").c_str());
	else
		puts(("./mlt/" + filename + " deleted, remaking the new one.").c_str());

	ofstream of;
	of.open("./mlt/"+filename, ios::out | ios::binary);

	of.write((char*)&mlt->sign, sizeof(mlt->sign));


	of.write((char*)&mlt->count3DC, sizeof(mlt->count3DC));

	for (int i = 0; i < mlt->count3DC; i++) {
		of.write((char*)&mlt->names3DC[i]->length, sizeof(mlt->names3DC[i]->length));
		of.write((char*)mlt->names3DC[i]->chars.c_str(), mlt->names3DC[i]->length);
	}

	of.write((char*)&mlt->countDDS, sizeof(mlt->countDDS));

	for (int i = 0; i < mlt->countDDS; i++) {
		of.write((char*)&mlt->namesDDS[i]->length, sizeof(mlt->namesDDS[i]->length));
		of.write((char*)mlt->namesDDS[i]->chars.c_str(), mlt->namesDDS[i]->length);
	}


	of.write((char*)&mlt->countRec, sizeof(mlt->countRec));

	for (int i = 0; i < mlt->countRec; i++) {
		of.write((char*)&mlt->records[i]->index3DC, sizeof(mlt->records[i]->index3DC));
		of.write((char*)&mlt->records[i]->indexDDS, sizeof(mlt->records[i]->indexDDS));
		of.write((char*)&mlt->records[i]->alphaFlg, sizeof(mlt->records[i]->alphaFlg));
	}

	return mlt;
}