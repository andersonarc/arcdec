/* @file
 *
 *  string utilities library source
 * 
*/
#include "ustring.h"

/*
 * copy string to memory and return pointer
 * 
 * @return new string
*/
MANUAL_FREE string_t copystr(IN string_t source) {
   OUT string_t buffer = (string_t) malloc(strlen(source)+1);
   strcpy(buffer, source);
   return buffer;
}

/*
 * split string into substrings
 * 
 * @return pointer to substrings struct
*/
MANUAL_FREE biarray_string strsplit(IN string_t string, IN const string_t delimiter) {
   size_t length = substrcount(string, *delimiter); 

   OUT biarray_string result; // split result
   result.length = length;                           // length 
   result.array = malloc(length * sizeof(string_t)); // array

   string_t token = strtok(string, delimiter);
   for (int i = 0; token != NULL; i++) {
      result.array[i] = copystr(token); // set value in @var result_buffer
      token = strtok(NULL, delimiter);  // next token (NULL is not a typo, it is required)
   }
   return result;
}

/*
 * count occurencies of @arg character in @arg string
 * 
 * @return count
*/
size_t charcount(IN const string_t string, IN const char character) {
   OUT int count = 0;
   size_t length = strlen(string);
   for (int i = 0; i < length; i++) {
      if (string[i] == character) count++;
   }
   return count;
}

/*
 * count occurencies of @arg substring in @arg string
 * 
 * @return count
 * 
 * @warn unoptimized, consider taking algorithm from @func strreplace
*/
size_t strcount(IN const string_t string, IN const string_t substring) {
   OUT int count = 0;
   size_t length = strlen(string);
   size_t sublength = strlen(substring);
   for (int i = 0; i < length; i++) {
      if (strncmp(&(string[i]), substring, sublength)) count++;
   }
   return count;
}

/*
 * count occurencies of substrings split by @arg character in @arg string
 * 
 * @return count
*/
size_t substrcount(IN const string_t string, IN const char character) {
   OUT int count = 0;
   bool inside = false;
   size_t length = strlen(string);
   for (int i = 0; i < length; i++) {
      if (string[i] == character) {
         if (inside) {
            inside = false;
            count++;
         }
      } else {
         inside = true;
      }
   }
   return count + inside;
}

/*
 * replace occurencies of @arg replace in @arg source with @arg with
 * 
 * @return the pointer to new string
*/
MANUAL_FREE string_t strreplace(IN const string_t source, IN const string_t replace, IN const string_t with) {
   OUT string_t result;  // the result string
   string_t next;    // the next insert point
   string_t tmp;     // varies
   size_t rlen;      // length of @arg replace (the string to remove)
   size_t wlen;      // length of @arg with (the string to replace @arg replace with)
   size_t flen;      // distance between @arg replace and end of last @arg replace
   int count = 0;    // number of replacements

   /*
    * error checks and initialization
   */
   if (!source || !replace) {
      return NULL;
   }
   rlen = strlen(replace);
   if (rlen == 0) {
      return NULL; // empty @arg replace causes infinite loop during count
   }
   if (!with) {
      with = "";
   }
   wlen = strlen(with);

   /* 
    * count the number of replacements needed
   */
   if (tmp = strstr(source, replace)) { // = instead of == is not a typo
      next = tmp + rlen;
      count++;
   }
   for (; tmp = strstr(next, replace); ++count) {
      next = tmp + rlen;
   }

   // allocate memory for result and also store pointer in tmp
   tmp = result = malloc(strlen(source) + (wlen - rlen) * count + 1);
   if (!result) return NULL;

   /*    
    *   first time through the loop, all the variables are set correctly
    *
    *   @var tmp points to end of previous replacement
    *   @var next points to the next occurrence of @var replace in @var source
    *   @var source points to the remainder of @var source after "end of @arg replace"
   */
   while (count--) {
      next = strstr(source, replace);           // find next occurence
      flen = next - source;                     // calculate length of source string to copy
      tmp = strncpy(tmp, source, flen) + flen;  // copy part of source string before replacing
      tmp = strcpy(tmp, with) + wlen;           // copy replacement
      source += flen + rlen;                    // move pointer to end of @arg replace
   }
   strcpy(tmp, source); // copy remaining
   return result;
}