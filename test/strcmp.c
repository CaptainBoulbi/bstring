#include <stdio.h>
#include "../bstring.h"

int main(){

  string* str1 = bstrninit("Hamood ?", 8);
  string* str2 = bstrinit("atoz!");

  printf("cmp %s - %s : %d\n", str1->cstr, str2->cstr, bstrcmp(str2, str2));

  return 0;
}
