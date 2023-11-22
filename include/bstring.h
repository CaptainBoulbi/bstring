#include <stddef.h>

// from string.h

char* bstpcpy(char *dest, const char *src);
// Copy a string from src to dest, returning a pointer to the end of the resulting string at dest.

char* bstrcat(char *dest, const char *src);
// Append the string src to the string dest, returning a pointer dest.

char* bstrchr(const char *s, int c);
// Return a pointer to the first occurrence of the character c in the string s.

int bstrcmp(const char *s1, const char *s2);
// Compare the strings s1 with s2.

int bstrcoll(const char *s1, const char *s2);
// Compare the strings s1 with s2 using the current locale.

char* bstrcpy(char *dest, const char *src);
// Copy the string src to dest, returning a pointer to the start of dest.

size_t bstrcspn(const char *s, const char *reject);
// Calculate the length of the initial segment of the string s which does not contain any of bytes in the string reject,

char* bstrdup(const char *s);
// Return a duplicate of the string s in memory allocated using malloc(3).

char* bstrfry(char *string);
// Randomly swap the characters in string.

size_t bstrlen(const char *s);
// Return the length of the string s.

char* bstrncat(char *dest, const char *src, size_t n);
// Append at most n bytes from the string src to the string dest, returning a pointer to dest.

int bstrncmp(const char *s1, const char *s2, size_t n);
// Compare at most n bytes of the strings s1 and s2.

char* bstrncpy(char *dest, const char *src, size_t n);
// Copy at most n bytes from string src to dest, returning a pointer to the start of dest.

char* bstrpbrk(const char *s, const char *accept);
// Return a pointer to the first occurrence in the string s of one of the bytes in the string accept.

char* bstrrchr(const char *s, int c);
// Return a pointer to the last occurrence of the character c in the string s.

char* bstrsep(char **stringp, const char *delim);
// Extract the initial token in stringp that is delimited by one of the bytes in delim.

size_t bstrspn(const char *s, const char *accept);
// Calculate the length of the starting segment in the string s that consists entirely of bytes in accept.

char* bstrstr(const char *haystack, const char *needle);
// Find the first occurrence of the substring needle in the string haystack, returning a pointer to the found substring.

char* bstrtok(char *s, const char *delim);
// Extract tokens from the string s that are delimited by one of the bytes in delim.

size_t strxfrm(char *dest, const char *src, size_t n);
// Transforms src to the current locale and copies the first n bytes to dest.

// from strings.h


int bstrcasecmp(const char *s1, const char *s2);
// Compare the strings s1 and s2 ignoring case.

int bstrncasecmp(const char *s1, const char *s2, size_t n);
// Compare the first n bytes of the strings s1 and s2 ignoring case.

char* bindex(const char *s, int c);
// Return a pointer to the first occurrence of the character c in the string s.

char* brindex(const char *s, int c);
// Return a pointer to the last occurrence of the character c in the string s.

// custom string operations

// TODO
