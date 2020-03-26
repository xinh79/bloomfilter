#ifndef _BLOOM_H
#define _BLOOM_H

#include "HashTable.h"
#include "HashList.h"

	typedef struct{

		int pHashSize;
		int pHashNum;
		HashTable pHashTable;
		HashList pHashList[3];

	}Bloom;

/*	int GetHashSize()        { return pHashSize;}
	int GetHashNum()         { return pHashNum;}

	void SetHashSize(int p)  { pHashSize = p;}
	void SetHashNum(int p)   { pHashNum = p;}
	
*/
    void InitiBloom(int ID, int size, int num, Bloom *bloom);
    void BloomWrite(md5_byte_t *p, int size, Bloom *bloom);
    int BloomCheck(md5_byte_t *p, int size, Bloom bloom);
	void BloomWipeOut();
	

/*	int       pHashSize;
	int       pHashNum;
	HashTable pHashTable;
	HashList  pHashList;
*/

#endif // _BLOOM_H
