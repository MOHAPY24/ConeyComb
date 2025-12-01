#include "tokenize.h"
#include "eat.h"

void eat(char token_type[]){
    if(current_token.type == token_type){
        current_token = tokenize();
    }
    else{
        UnexpectedToken(current_token.type, current_token.value);
    }
}