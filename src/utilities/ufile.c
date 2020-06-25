/* @file
 *
 *  file utilities library source
 * 
*/
#include "ufile.h"

/*
 * measure file size
 * does not modify position on stream (backups previous)
*/
size_t fsize(FILE* file) {
   size_t prev = ftell(file);
   fseek(file, 0L, SEEK_END);
   size_t size = ftell(file);
   fseek(file, prev, SEEK_SET);
   return size;
}

/*
 * count file size from current position until @arg delimiter
 * does not modify position on stream (backups previous)
*/
int dsize(FILE* file, const char delimiter) {
   size_t prev = ftell(file);
   int c = fgetc(file);
   int count = 0;
   while (c != delimiter) {
      if (c == EOF) return EOF;
      c = fgetc(file);
      count++;
   }
   fseek(file, prev, SEEK_SET);
   return count;
}