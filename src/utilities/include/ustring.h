/* @file
 *
 *  string utilities library header file
 * 
*/
#ifndef _USTRING_H
#define _USTRING_H

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

#include "udefines.h"

/*
 * count occurencies of @arg character in @arg string
*/
#define lsize(file) dsize(file, '\n')


/*
 * bidirectional array for storing strings
*/
typedef struct {
    int length;
    string_t* array;
} biarray_string;

/*
 * copy string to memory and return pointer
 * 
 * @return new string
*/
MANUAL_FREE string_t copystr(IN string_t source);

/*
 * split string into substrings
 * 
 * @return pointer to substrings struct
*/
MANUAL_FREE biarray_string strsplit(IN string_t string, IN const string_t delimiter);

/*
 * count occurencies of @arg character in @arg string
 * 
 * @return count
*/
size_t charcount(IN const string_t string, IN const char character);

/*
 * count occurencies of @arg substring in @arg string
 * 
 * @return count
 * 
 * @warn unoptimized, consider taking algorithm from @func strreplace
*/
size_t strcount(IN const string_t string, IN const string_t substring);

/*
 * count occurencies of substrings split by @arg character in @arg string
 * 
 * @return count
*/
size_t substrcount(IN const string_t string, IN const char character);
/*
 * replace occurencies of @arg replace in @arg source with @arg with
 * 
 * @return the pointer to new string
*/
MANUAL_FREE string_t strreplace(IN const string_t source, IN const string_t replace, IN const string_t with);

#endif /* _USTRING_H */