#ifndef CONTAINS_H
#define CONTAINS_H
#include "token.h"
#include <stdbool.h>

extern unsigned int cpointer;
extern char* code;
extern unsigned int xptr;
extern unsigned int ccombx;
extern unsigned int ccomby;
extern unsigned int yptr;
extern int xtape[5][30];
extern int ytape[5][30];
extern char outputs[3024];
extern Token current_token;
extern unsigned int steps;
extern bool comment_mode;
extern bool ymode;

extern void add_code(char pcode[6024]);

#endif