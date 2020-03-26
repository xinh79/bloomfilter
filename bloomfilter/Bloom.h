#ifndef _BLOOM_H
#define _BLOOM_H

#include "Common.h"
#include "HashTable.h"
#include "HashList.h"

class Bloom {
  friend ostream& operator<<(ostream& output, const Bloom& bm);

 public:
  Bloom(int ID, int bloomSize, int hashNum);
  ~Bloom();

  int GetHashSize()        { return pHashSize;}
  int GetHashNum()         { return pHashNum;}

  void SetHashSize(int p)  { pHashSize = p;}
  void SetHashNum(int p)   { pHashNum = p;}

  void Write(md5_byte_t *p, int size);
  bool Check(md5_byte_t *p, int size);
  void ReadBitvector(unsigned char *vect);
  void WipeOut();

 private:
  Bloom() {;} // avoid random Bloom filter creation.
  unsigned int ReadBit(int i); // Internal function.

  int       pHashSize;
  int       pHashNum;
  HashTable pHashTable;
  HashList  pHashList;
};

#endif // _BLOOM_H
