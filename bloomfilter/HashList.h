#ifndef _HASHLIST_H
#define _HASHLIST_H

#include <vector>
#include <assert.h>

#include "Common.h"
#include "md5.h"

// A brother class of Hash.

class HashFunc {
 public:
  HashFunc(int i, int s): pID(i), pSize(s) {;}

  int  GetID()   { return pID;}
  int  GetSize() { return pSize;}

  void SetID(int i)   { pID=i;}
  void SetSize(int i) { pSize=i;}

  unsigned int operator()(md5_byte_t *input, int size) {
	md5_byte_t info[256];
	md5_byte_t digest[16];
	unsigned int hashvalue;

	//其作用是如果它的条件返回错误，则终止程序执行
	assert(size < 200);
	assert(pSize > 0);

	memcpy((void *) info, (void *) &pID, sizeof(pID));
	memcpy((void *) &info[sizeof(pID)], (void *) input, size);
	md5(digest, info, size+sizeof(pID));
	hashvalue = (*(unsigned int *) &digest[4]) % pSize;

	// cout << info << " is hashed into " << hashvalue << endl;

	return (hashvalue);
  }

 private:
  HashFunc() {;} // Nobody can create HashFunc object without providing an ID.
  int pID;
  int pSize;
};

typedef vector<HashFunc*>   HashList;
typedef HashList::iterator  HashIter;

#endif // _HASHLIST_H
