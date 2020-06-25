/* @file
 *
 *  preprocessor main header file
 * 
*/
#ifndef _PREPROCESSOR_H
#define _PREPROCESSOR_H

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "ufile.h"
#include "ustring.h"
#include "directive.h"

/*
 * preprocess @arg input and save the result in @arg output 
*/
void preprocess(FILE* input, FILE* output);

#endif // _PREPROCESSOR_H