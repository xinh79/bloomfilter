#include "HashList.h"
unsigned int GetHashValue(md5_byte_t *input, int size, HashList list) {
	md5_byte_t info[256];
	md5_byte_t digest[16];
	unsigned int hashvalue;

	//��pID���Ƶ�info����
	memcpy((void *) info, (void *) &(list.pID), sizeof(list.pID));
	//��input���Ƶ�info����
	memcpy((void *) &info[sizeof(list.pID)], (void *) input, size);
	//��ϣ����md5�����ϣֵ
	md5(digest, info, size+sizeof(list.pID));
	//(unsigned int*)ǿ��ת�����ָ������γ�unsigned int*�� *�õ��õ�ַָ����ڴ档
	hashvalue = (*(unsigned int *) &digest[4]) % (list.pSize);

	return (hashvalue);
}
void concatention(unsigned char *pkt_id,unsigned char *pkt_trans,unsigned char *pkt_recv,unsigned char *input)//�ֱ�Ϊ���ݰ�id��ת���ߺͽ����ߵ�ip ,������������ŵ�input 
{
	//��pkt_id ���Ƶ�input
	memcpy((void *)input,(void *)pkt_id, sizeof(pkt_id));
	//��pkt_trans������input
	memcpy((void *)&input[1], (void *)pkt_trans , 1);
	//��pkt_recv������input
	memcpy((void *)&input[2] , (void *)pkt_recv , 1);
}
