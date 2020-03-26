#include <iostream>
#include "Bloom.h"

int
main()
{
  int num = 0;
  Bloom oneB(13, 32, 3);

  for (int i=0; i<7; i++) {
    oneB.Write((md5_byte_t *) &i, sizeof(i));
    cout << i << " inserted.... ";
    cout << oneB << endl;
  }

  oneB.ReadBitvector((unsigned char *)&num);

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
