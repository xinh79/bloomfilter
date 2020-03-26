#include "Bloom.h"

// Input: ID -- is the initial ID of the hash function. Therefore, the
// IDs of different BFs should spread out by the number of hash
// functions to make these hash functions different.
// size -- is the bit vector size.
// num -- is the number of hash functions.
Bloom::Bloom(int ID, int size, int num):
  pHashSize(size), pHashNum(num)
{
  pHashTable.reserve(pHashSize);
  for (int i=0; i<pHashSize; i++) {
	pHashTable[i] = false;
  }

  pHashList.reserve(pHashNum);

  // Create different hash functions.
  for (int i=0; i<pHashNum; i++) {
	pHashList[i] = new HashFunc(ID+i, pHashSize);
  }
}

Bloom::~Bloom()
{
  for (int i=0; i<pHashNum; i++) {
	delete pHashList[i];
  }

  pHashTable.clear();
}


// return: true: Bloom filter is cleared.
//         false: Bloom filter is not cleared.
void
Bloom::Write(md5_byte_t *p, int size)
{
  // Write-in multiple bits.
  for (int i=0; i<pHashNum; i++) {
    pHashTable[(*pHashList[i])(p, size)] = true;
  }
}

// Return whether there is a hit in the Bloom filter.
bool
Bloom::Check(md5_byte_t *p, int size)
{
  for (int i=0; i<pHashNum; i++) {
    if (pHashTable[(*pHashList[i])(p, size)] == false) {
      // Not in the set.
      return false;
    }
  }

  // It is a hit.
  return true;
}

// Return a hit in the Bloom filter.
unsigned int
Bloom::ReadBit(int pos)
{
  assert(pos < pHashSize);

  if (pHashTable[pos]) {
      return 1;
  }
  else {
    return 0;
  }
}

// Return a hit in the Bloom filter.
void
Bloom::ReadBitvector(unsigned char *vect)
{
  int i, j;

  // Go through every byte of the bitvector.
  for (j=0; j<pHashSize/8; j++) {
    for (i=0; i<7; i++) {
      vect[j] |= (pHashTable[j*8+i])? 1: 0;
      vect[j] <<= 1;
    }
    vect[j] |= (pHashTable[j*8+i])? 1: 0; // last bit needs no shifting.
  }
}

void
Bloom::WipeOut()
{
  // Clear the table again.
  for (int i=0; i<pHashSize; i++) {
    pHashTable[i] = false;
  }
}

ostream&
operator<<(ostream& output, const Bloom& bm) {
  for (int i=0; i<bm.pHashSize; i++) {
    if (i%8 == 0) {
      output << ' ';
    }

    output << (bm.pHashTable[i]? 1: 0);
  }

  return output;  // for multiple << operators.
}
