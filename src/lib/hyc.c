#include "contains.h"
#include "token.h"
#include "parse.h"
#include <stdio.h>
#include <string.h>
#include "hyc.h"
#include "tokenize.h"
#include "bytecode.h"
#include "encoder.h"

char program[] = "+++-.>.++.^.++.v.++.<.";

int run(){
    encode();
    size_t bytecode_len = pc;
    write_bytecode_to_file("out.chb", bytecode_len);
    for(int i = 0; i < BYTE_SIZE; i++){
    pc = i;
    switch((unsigned char)bytecode[i]){
        case 0x00: adr(); break;
        case 0x01: adr(); break;
        case 0x02: mdr(); break;
        case 0x03: mdr(); break;
        case 0x04: pvr(); break;
        case 0x05: pvr(); break;
        case 0x06: nxtc(); break;
        case 0x07: nxtc(); break;
        case 0x08: pvc(); break;
        case 0x09: pvc(); break;
        case 0x10: cup(); break;
        case 0x11: cup(); break;
        case 0x12: cdown(); break;
        case 0x13: cdown(); break;
        case 0xEE: break; // NOP
        default:
            char expected_str[4] = {'0','x',0,0};
            UnexpectedToken(expected_str, "unknown opcode");
            break;
    }
    
    }
    //print_bytecode_debug(bytecode_len);

    return 0;
}