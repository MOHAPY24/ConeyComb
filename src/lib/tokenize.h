#ifndef TOKENIZE_H
#define TOKENIZE_H
#include "token.h"
#include "errsimp.h"
#include "contains.h"
#include "eat.h"


extern Token tokenize();
extern unsigned char current_char;
extern Token current_token;

#endif