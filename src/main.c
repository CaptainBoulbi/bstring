#include <stdio.h>
#include "bstring.h"

void print(string* str){
  printf("str : %s, size : %d\n", bcstr(str), bstrlen(str));
}

int main(){

  string* str1 = bstrninit("Hamood ?", 8);
  string* str2 = bstrinit("atoz!");
  string str3 = { .cstr = "caca~", .size = 5 };

  print(str1);
  print(str2);
  print(&str3);

  bstrcat(str2, str1);

  print(str2);

  bstrcat(bstrcat(str1, bstrinit(" aime son caca~")), bstrinit(" noice."));

  print(str1);

  printf("search str : %s\n", bstrchr(str2, 'o'));

  printf("cmp %s - %s : %d\n", str1->cstr, str3.cstr, bstrcmp(str1, &str3));

  string* c1 = bstrinit("abcd");
  string* c2 = bstrinit("abcd");
  print(c1);
  print(c2);
  printf("cmp : %d\n", bstrcmp(c1, c2));

  string* str4 = bstrdup(str2);
  print(str4);

  bstrncat(str4, c1, 2);
  print(str4);

	return 0;
}
