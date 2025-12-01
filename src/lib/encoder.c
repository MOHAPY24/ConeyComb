#include "contains.h"
#include "token.h"
#include "parse.h"
#include <stdio.h>
#include <string.h>
#include "tokenize.h"
#include "hyc.h"
#include <stdlib.h>
#include "bytecode.h"

void print_bytecode_debug(size_t bytecode_len) {
    printf("Encoded opcodes (non-NOP):\n");
    for (size_t i = 0; i < bytecode_len; i++) {
        if (bytecode[i] != 0xEE) {
            printf("bytecode[%zu] = 0x%02X\n", i, bytecode[i]);
        }
    }
}


void write_bytecode_to_file(const char* filename, size_t bytecode_len) {
    FILE* f = fopen(filename, "wb");
    if (!f) {
        perror("Failed to open file");
        return;
    }

    size_t written = fwrite(bytecode, sizeof(unsigned char), bytecode_len, f);
    if (written != bytecode_len) {
        printf("Warning: only wrote %zu of %zu bytes\n", written, bytecode_len);
    }

    fclose(f);
}

size_t read_bytecode_from_file(const char* filename, unsigned char* buffer, size_t max_size) {
    FILE* f = fopen(filename, "rb");
    if (!f) {
        perror("Failed to open file for reading");
        return 0;
    }

    size_t bytes_read = fread(buffer, sizeof(unsigned char), max_size, f);
    fclose(f);

    printf("Read %zu bytes from '%s'\n", bytes_read, filename);
    return bytes_read;
}


void encode(){
    add_code(program);
    for(int i = 0; i <= strlen(program)-1; i++){
        Token recived = tokenize();
        //printf("%s,%s\n", recived.type, recived.value); 
        if(strcmp(recived.type, "NONE") == 0){
            continue;
        }
        if(strcmp(recived.value, "+") == 0){
            adrb();
        }
        else if(strcmp(recived.value, "-") == 0){
            mdrb();

        }
        else if(strcmp(recived.value, ".") == 0){
            prvb();
        }

        else{
            continue;
        }
        
    }
}