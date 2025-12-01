#ifndef TOKEN_H
#define TOKEN_H


#define ADD_CELL "ADD_CELL"
#define MINUS_CELL "MINUS_CELL"
#define CELL_LEFT "CELL_LEFT"
#define CELL_RIGHT "CELL_RIGHT"
#define CELL_UP "CELL_UP"
#define CELL_DOWN "CELL_DOWN"
#define NEXT_COMB "NEXT_COMB"
#define PREV_COMB "PREV_COMB"
#define SAVE_POLLEN "SAVE_POLLEN"
#define LOAD_POLLEN "LOAD_POLLEN"
#define SQUARE_CELL "SQUARE_CELL"
#define CLEAR_CELL "CLEAR_CELL"
#define CLEAR_COMB "CLEAR_COMB"
#define CLEAR_TAPE "CLEAR_TAPE"
#define PRINT_VALUE "PRINT_VALUE"
#define PRINT_ASCII "PRINT_ASCII"
#define INPUT "INPUT"
#define COMMENT_START "COMMENT_START"
#define COMMENT_END "COMMENT_END"
#define LOOP_END "LOOP_END"
#define IF_0 "IF_0"


typedef struct {
    char* value;
    char* type;
} Token;


#endif