/* @file
 *
 *  various defines for utilities
 * 
*/
#ifndef _UDEFINES_H
#define _UDEFINES_H

/*
 * the parameter is modified (pointer) or returned from function
*/
#define OUT

/*
 * the parameter is an argument for function 
*/
#define IN

/*
 * for better code readability
*/
#define string_t char*

/*
 * marks caller's responsibility to free the function result (pointer)
*/
#define MANUAL_FREE

#endif /* _UDEFINES_H */