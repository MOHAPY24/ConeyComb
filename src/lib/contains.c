#include "contains.h"
#include <stdlib.h>


unsigned int cpointer = 0;
char *code = NULL;
unsigned int xptr = 0;
unsigned int ccombx = 0;
unsigned int ccomby = 0;
unsigned int yptr = 0;
int xtape[5][30] = {0};
int ytape[5][30] = {0};
char outputs[3024] = {};
Token current_token = {"NONE", "NONE"};
unsigned int steps = 0;
bool comment_mode = false;
bool ymode = false;

void add_code(char pcode[6024]){
    code = pcode;
}