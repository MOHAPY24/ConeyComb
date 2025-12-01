#include "contains.h"
#include "errsimp.h"
#include <string.h>
#include "tokenize.h"

Token tokenize(){
    Token NONE = {"NONE", "NONE"};
    if(cpointer > strlen(code)){
        return NONE;
    }
    const char current_char = code[cpointer];
    cpointer++;

    if(current_char == '+' && comment_mode != true){
        Token token = {"+", ADD_CELL};
        current_token = token;
        return token;
    }
    else if(current_char == '-' && comment_mode != true){
        Token token = {"-", MINUS_CELL};
        current_token = token;
        return token;
    }
    else if(current_char == '.' && comment_mode != true){
        Token token = {".", PRINT_VALUE};
        current_token = token;
        return token;
    }
    else if(current_char == '>' && comment_mode != true){
        Token token = {">", CELL_RIGHT};
        current_token = token;
        return token;
    }
    else if(current_char == '<' && comment_mode != true){
        Token token = {"<", CELL_LEFT};
        current_token = token;
        return token;
    }
    else if(current_char == '^' && comment_mode != true){
        Token token = {"^", CELL_UP};
        current_token = token;
        return token;
    }
    else if(current_char == 'v' && comment_mode != true){
        Token token = {"v", CELL_DOWN};
        current_token = token;
        return token;
    }
    else if(current_char == 'W' && comment_mode != true){
        Token token = {"W", PREV_COMB};
        current_token = token;
        return token;
    }
    else if(current_char == '/' && comment_mode != true){
        Token token = {"/", NEXT_COMB};
        current_token = token;
        return token;
    }
    else if(current_char == ',' && comment_mode != true){
        Token token = {",", PRINT_ASCII};
        current_token = token;
        return token;
    }
    else if(current_char == ':' && comment_mode != true){
        Token token = {":", INPUT};
        current_token = token;
        return token;
    }
    else if(current_char == '(' && comment_mode != true){
        Token token = {"(", COMMENT_START};
        current_token = token;
        return token;
    }
    else if(current_char == ')'){
        Token token = {")", COMMENT_END};
        current_token = token;
        return token;
    }
    else if(current_char == '!' && comment_mode != true){
        Token token = {"!", CLEAR_CELL};
        current_token = token;
        return token;
    }
    else if(current_char == '~' && comment_mode != true){
        Token token = {"~", CLEAR_COMB};
        current_token = token;
        return token;
    }
    else if(current_char == '%' && comment_mode != true){
        Token token = {"%", CLEAR_TAPE};
        current_token = token;
        return token;
    }
    else if(current_char == 'S' && comment_mode != true){
        Token token = {"S", SQUARE_CELL};
        current_token = token;
        return token;
    }
    else if(current_char == '*' && comment_mode != true){
        Token token = {"*", SAVE_POLLEN};
        current_token = token;
        return token;
    }
    else if(current_char == '&' && comment_mode != true){
        Token token = {"&", LOAD_POLLEN};
        current_token = token;
        return token;
    }
    else if(current_char == '#' && comment_mode != true){
        Token token = {"#", IF_0};
        current_token = token;
        return token;
    }
    else if(current_char == '\n'){
        Token token = {"\n", "NEWLINE"};
        current_token = token;
        return token;
    }
    else if(current_char == ' ' && comment_mode != true){
        Token token = {" ", "SPACE"};
        current_token = token;
        return token;
    }
    else{
        if(comment_mode == true){
            Token token = {"COMMENT", "COMMENT"};
            current_token = token;
            return token;
        }
        Token error = {"ERROR", UnrecognizedTokenError(current_char, current_char)};
        current_token = error;
        return error;
    }

}