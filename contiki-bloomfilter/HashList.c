#include "HashList.h"
unsigned int GetHashValue(md5_byte_t *input, int size, HashList list) {
	md5_byte_t info[256];
	md5_byte_t digest[16];
	unsigned int hashvalue;

	//将pID复制到info数组
	memcpy((void *) info, (void *) &(list.pID), sizeof(list.pID));
	//将input复制到info数组
	memcpy((void *) &info[sizeof(list.pID)], (void *) input, size);
	//哈希函数md5计算哈希值
	md5(digest, info, size+sizeof(list.pID));
	//(unsigned int*)强制转化这个指针的类形成unsigned int*， *得到该地址指向的内存。
	hashvalue = (*(unsigned int *) &digest[4]) % (list.pSize);

	return (hashvalue);
}
void concatention(unsigned char *pkt_id,unsigned char *pkt_trans,unsigned char *pkt_recv,unsigned char *input)//分别为数据包id，转发者和接收者的ip ,并将级联结果放到input 
{
	//将pkt_id 复制到input
	memcpy((void *)input,(void *)pkt_id, sizeof(pkt_id));
	//将pkt_trans级联到input
	memcpy((void *)&input[1], (void *)pkt_trans , 1);
	//将pkt_recv级联到input
	memcpy((void *)&input[2] , (void *)pkt_recv , 1);
}
