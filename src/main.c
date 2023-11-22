#include <stdio.h>
#include "bstring.h"

void print(string* str){
  printf("str : %s, size : %d\n", bcstr(str), bstrlen(str));
}

int main(){

  string* str1 = bstrninit("Hamood ?", 8);

  string* str2 = bstrinit("atoz!");

  print(str1);
  print(str2);

  bstrcat(str2, str1);

  print(str2);

  bstrcat(bstrcat(str1, bstrinit(" aime son caca~")), bstrinit(" noice."));

  print(str1);

	return 0;
}
