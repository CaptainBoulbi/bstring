#include <stdio.h>
#include "bstring.h"

int main(){

  string str;
  bstrinit(&str, "Hamood ?");

  printf("str : %s, size : %ld\n", str.cstr, str.size);

	return 0;
}
