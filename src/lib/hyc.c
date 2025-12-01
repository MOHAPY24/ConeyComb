#include "contains.h"
#include "token.h"
#include "parse.h"
#include <stdio.h>
#include <string.h>
#include "hyc.h"
#include "tokenize.h"
#include "bytecode.h"
#include "encoder.h"

char program[] = "+-+-+.";

int run(){
    encode();
    size_t bytecode_len = pc;
    write_bytecode_to_file("out.chb", bytecode_len);
    for(int i = 0; i < BYTE_SIZE; i++){
    pc = i;
    switch((unsigned char)bytecode[i]){
        case 0x00:
        case 0x01: adr(); break;
        case 0x02:
        case 0x03: mdr(); break;
        case 0x04:
        case 0x05: pvr(); break;
        case 0xEE: break;
    }
    
    }
    //print_bytecode_debug(bytecode_len);

    return 0;
}