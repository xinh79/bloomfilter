#ifndef _HASHLIST_H
#define _HASHLIST_H

#include "md5.h"
#include "string.h"

 typedef struct hashlist{
	 int pID;
	 int pSize; 
 } HashList;
/*
int  GetID(HashList list)   { return list.pID;}
int  GetSize(HashList list) { return list.pSize;}

void SetID(int i, HashList list)   { list.pID=i;}
void SetSize(int i, HashList list) { list.pSize=i;}
*/
unsigned int GetHashValue(md5_byte_t *, int, HashList);
void concatention(unsigned char *pkt_id,unsigned char *pkt_trans,unsigned char *pkt_recv,unsigned char *input);//分别为数据包id，转发者和接收者的ip    


#endif // _HASHLIST_H
