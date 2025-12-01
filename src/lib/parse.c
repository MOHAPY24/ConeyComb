#include "tokenize.h"
#include "eat.h"
#include "parse.h"
#include <string.h>
#include "bytecode.h"
#include <stdio.h>



void adr(){
    int cmd = bytecode[pc];
    if(cmd == 0x01){
        ytape[ccomby][yptr]++;  
    }
    else if(cmd == 0x00){
        xtape[ccombx][xptr]++;  
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
}

void mdr(){
    int cmd = bytecode[pc];
    if(cmd == 0x02){
        ytape[ccomby][yptr]--;  
    }
    else if(cmd == 0x03){
        xtape[ccombx][xptr]--;  
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
}

void pvr(){
    int cmd = bytecode[pc];
    if(cmd == 0x04){
        printf("%d\n", ytape[ccomby][yptr]);  
    }
    else if(cmd == 0x05){
        printf("%d\n", xtape[ccombx][xptr]);   
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
}


void nxtc(){
    int cmd = bytecode[pc];
    if(cmd == 0x06){
        xptr++; 
    }
    else if(cmd == 0x07){
        xptr++;
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
}

void pvc(){
    int cmd = bytecode[pc];
    if(cmd == 0x08){
        xptr--; 
    }
    else if(cmd == 0x09){
        xptr--;
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
}

void cup(){
    int cmd = bytecode[pc];
    if(cmd == 0x10){
        yptr++; 
    }
    else if(cmd == 0x11){
        yptr++;
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
}

void cdown(){
    int cmd = bytecode[pc];
    if(cmd == 0x12){
        yptr--; 
    }
    else if(cmd == 0x13){
        yptr--;
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
}





