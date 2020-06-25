/* @file
 *
 *  preprocessor directives and codes header file
 * 
*/

#ifndef _DIRECTIVE_H
#define _DIRECTIVE_H

#include <stddef.h>

/* 
 *   directive codes
*/
enum pp_directive_code {
    DC_ARCHITECTURE, DC_INSTRUCTION, DC_DEFINE, DC_INCLUDE
};

/* 
 *  modes for processing line tokens
*/
typedef enum pp_directive_mode {
    DM_NOTHING,
    DM_ARCHITECTURE, DM_INCLUDE,       // single operand
    DM_A_DEFINE, DM_B_DEFINE,          // two operands
    DM_A_INSTRUCTIOM, DM_B_INSTRUCTION // two operands
} pp_directive_mode;


/* 
 *  raw directive struct
*/
typedef struct pp_directive {
    const char* directive;
    int code;
} pp_directive;

/*
 *  function for directive recognizing and validation
*/
const struct pp_directive* validate_directive(const char *str, size_t len);

#endif // _DIRECTIVE_H