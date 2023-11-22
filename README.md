# Bstring : Better String

Bstring is a C library whose purpose is to rewrite the C standard string library by removing null terminators and replacing them with size-terminated strings.

The functions have the same name and the same definition as those in the standard library with a b at the beginning of the name (e.g. strcpy() -> bstrcpy()), so they work in the same way as the standard library with some extra functions (look at the include/bstring.h file to see what they do).
