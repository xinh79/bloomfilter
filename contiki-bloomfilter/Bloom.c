#include "Bloom.h"

// Input: ID -- is the initial ID of the hash function. Therefore, the
// IDs of different BFs should spread out by the number of hash
// functions to make these hash functions different.
// size -- is the bit vector size.
// num -- is the number of hash functions.

//初始化一个Bloom过滤器
void InitiBloom(int ID, int size, int num, Bloom *bloom)
{
	//制定哈希表的大小
  (*bloom).pHashSize = size;
  (*bloom).pHashNum = num;
  int i;
  for (i=0; i<(*bloom).pHashSize; i++) {
	(*bloom).pHashTable[i] = 0;
  }

  // Create different hash functions. 创建哈希函数
  for (i=0; i<(*bloom).pHashNum; i++) {
	(*bloom).pHashList[i].pID = ID + i;
	(*bloom).pHashList[i].pSize = (*bloom).pHashSize;
  }
}


/*
//消除Bloom对象内存
DeleteBloom()
{
  for (int i=0; i<pHashNum; i++) {
	//delete pHashList[i];
  }

  //pHashTable.clear();
}
*/



// return: true: Bloom filter is cleared.
//         false: Bloom filter is not cleared.
//将元素存储到bloom过滤器的hashTable中

void BloomWrite(md5_byte_t *p, int size, Bloom *bloom)
{
  // Write-in multiple bits.
  int i;
  for (i=0; i<(*bloom).pHashNum; i++) {
	unsigned int Hashvalue =  GetHashValue(p, size,(*bloom).pHashList[i]);
    (*bloom).pHashTable[Hashvalue] = 1;
  }
}

// Return whether there is a hit in the Bloom filter.
//检测元素是否在bloom过滤器的hashTable中
int BloomCheck(md5_byte_t *p, int size, Bloom bloom)
{
	int i;
  for (i=0; i<bloom.pHashNum; i++) {
	unsigned int Hashvalue =  GetHashValue(p, size,bloom.pHashList[i]);
    if (bloom.pHashTable[Hashvalue] == 0) {
      // Not in the set.
      return 0;
    }
  }

  // It is a hit.
  return 1;
}

// Return a hit in the Bloom filter.
/*
unsigned int BloomReadBit(int pos)
{
	//断言
  assert(pos < pHashSize);

  return (pHashTable[pos]);
}

// Return a hit in the Bloom filter.


//不清楚有什么功能
void BloomReadBitvector(unsigned char *vect)
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
*/
void BloomWipeOut(Bloom *bloom)
{
  // Clear the table again.
  int i;
  for (i=0; i<(*bloom).pHashSize; i++) {
    (*bloom).pHashTable[i] = 0;
  }
}
