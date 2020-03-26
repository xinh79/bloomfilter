
#include <stdio.h>
#include "Bloom.h"


//运行代码
int main()
{
	unsigned char id =97;
	unsigned char trans = 98;
	unsigned char recv = 99;
	unsigned char input[3];
	concatention(&id,&trans,&recv,input);
	printf("%s\n",input); // 验证是否连接 
	int num = 0;
	//声明一个bloom过滤器
	Bloom bloom;
	//初始化bloom过滤器
	InitiBloom(13, 32, 3, &bloom);
	int i,j;
	for (i=0; i<7; i++) {
		BloomWrite((md5_byte_t *) &i, sizeof(i), &bloom);
		for(j = 0;j < 32;j++)
		{
			printf("%d ",bloom.pHashTable[j]);
		}
		printf("\n");
	}
	i = 6;
	printf("%d\n",BloomCheck((md5_byte_t *) &i, sizeof(i), bloom));

	printf("%02x ", ((unsigned char *) &num)[0]);
	printf("%02x ", ((unsigned char *) &num)[1]);
	printf("%02x ", ((unsigned char *) &num)[2]);
	printf("%02x\n", ((unsigned char *) &num)[3]);

  /* Test scene 1.
  for (int i=0; i<100; i++) {
    if (oneB.Check((md5_byte_t *) &i, sizeof(i))) {
      cout << i << " is a hit." << endl;
    }
    else {
      cout << i << " is a miss." << endl;
    }
  }
  Test scene 1. */
}
