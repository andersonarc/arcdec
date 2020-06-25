/* @file
 *
 *  file utilities library header file
 * 
*/
#ifndef _UFILE_H
#define _UFILE_H

#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
 * measure file size
 * does not modify position on stream (backups previous)
*/
size_t fsize(FILE* file);

/*
 * count file size from current position until @arg delimiter
 * does not modify position on stream (backups previous)
*/
int dsize(FILE* file, const char delimiter);

#endif // _UFILE_H