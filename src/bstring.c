#include "bstring.h"
#include <stdlib.h>

// for debug
#include <stdio.h>

// from string.h

char* bstpcpy(char *dest, const char *src);

string* bstrcat(string* dest, const string* src){
  int oldSize = dest->size;
  dest->size += src->size;
  dest->cstr = realloc(dest->cstr, (dest->size+1) * sizeof(char));

  for (int i=0; i<src->size+1; i++){
    dest->cstr[oldSize + i] = src->cstr[i];
  }

  return dest;
}

char* bstrchr(const char *s, int c);

int bstrcmp(const char *s1, const char *s2);

int bstrcoll(const char *s1, const char *s2);

char* bstrcpy(char *dest, const char *src);

size_t bstrcspn(const char *s, const char *reject);

char* bstrdup(const char *s);

char* bstrfry(char *string);

int bstrlen(const string* s){
  return s->size;
}

char* bstrncat(char *dest, const char *src, size_t n);

int bstrncmp(const char *s1, const char *s2, size_t n);

char* bstrncpy(char *dest, const char *src, size_t n);

char* bstrpbrk(const char *s, const char *accept);

char* bstrrchr(const char *s, int c);

char* bstrsep(char **stringp, const char *delim);

size_t bstrspn(const char *s, const char *accept);

char* bstrstr(const char *haystack, const char *needle);

char* bstrtok(char *s, const char *delim);

size_t strxfrm(char *dest, const char *src, size_t n);

// from strings.h


int bstrcasecmp(const char *s1, const char *s2);

int bstrncasecmp(const char *s1, const char *s2, size_t n);

char* bindex(const char *s, int c);

char* brindex(const char *s, int c);

// custom string operations

string* bstrinit(const char* lit){
  int n;
  for (n=0; lit[n] != '\0'; n++);

  return bstrninit(lit, n);
}

string* bstrninit(const char* lit, int n){
  string* str = malloc(sizeof(string));
  str->cstr = malloc((n+1) * sizeof(char));
  str->size = n;
  for (int i=0; i<n+1; i++){
    str->cstr[i] = lit[i];
  }
  return str;
}

char* bcstr(string* str){
 return str->cstr;
}
