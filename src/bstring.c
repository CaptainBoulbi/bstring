#include "bstring.h"
#include <stdlib.h>
#include <time.h>

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

char* bstrchr(const string* s, int c){
  for (int i=0; i<s->size; i++){
    if (s->cstr[i] == c) return s->cstr + i;
  }
  return NULL;
}

int bstrcmp(const string* s1, const string* s2){
  int minlen = s1->size < s2->size ? s1->size : s2->size;
  int i;

  for (i=0; i<=minlen && s1->cstr[i] == s2->cstr[i]; i++);

  // (0 or false) * 2 - 1 = -1
  // (1 or true) * 2 - 1 = 1

  if (i < minlen)
    return ((s2->cstr[i] < s1->cstr[i]) * 2) - 1;

  if (s1->size == s2->size) return 0;

  return ((s2->size > s1->size) * 2) - 1;
}

// pas compris ce que sa fait
int bstrcoll(const char *s1, const char *s2);

char* bstrcpy(char *dest, const char *src);

size_t bstrcspn(const char *s, const char *reject);

string* bstrdup(const string* s){
  return bstrninit(s->cstr, s->size);
}

string* bstrfry(string* string){
  srand(time(NULL));
  for (int i=0; i<string->size; i++){
    int index = rand() % string->size;

    char old = string->cstr[i];
    string->cstr[i] = string->cstr[index];
    string->cstr[index] = old;
  }
  return string;
}

int bstrlen(const string* s){
  return s->size;
}

string* bstrncat(string* dest, const string* src, int n){
  int realn = src->size < n ? src->size : n;
  int oldSize = dest->size;

  dest->size += realn;
  dest->cstr = realloc(dest->cstr, (dest->size+1) * sizeof(char));

  for (int i=0; i<realn; i++){
    dest->cstr[oldSize + i] = src->cstr[i];
  }

  return dest;
}

int bstrncmp(const string* s1, const string* s2, int n){
  int minlen = s1->size < s2->size ? s1->size : s2->size;
  minlen = n < minlen ? n : minlen;
  int i;

  for (i=0; i<=minlen && s1->cstr[i] == s2->cstr[i]; i++);

  // (0 or false) * 2 - 1 = -1
  // (1 or true) * 2 - 1 = 1

  if (i < minlen)
    return ((s2->cstr[i] < s1->cstr[i]) * 2) - 1;

  if (minlen <= s1->size && minlen <= s2->size) return 0;

  return ((s2->size > s1->size) * 2) - 1;
}

char* bstrncpy(char *dest, const char *src, size_t n);

char* bstrpbrk(const char *s, const char *accept);

char* bstrrchr(const string *s, int c){
  for (int i=s->size; i>0; i--){
    if (s->cstr[i] == c) return s->cstr + i;
  }
  return NULL;
}

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
  if (str == NULL) return NULL;
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
