#include "tokenize.h"
#include "eat.h"
#include "parse.h"
#include "bytecode.h"
#include <string.h>
#include <stdio.h>

unsigned char bytecode[BYTE_SIZE] = {0xEE};
int pc = 0;



void adrb(){
    char cmd = current_token.value[0];
    if(cmd == '+'){
        if(ymode == true){
            bytecode[pc] = 0x01;
            pc++;
        }
        else{
            bytecode[pc] = 0x00;
            pc++;
        }
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
}

void mdrb(){
    char cmd = current_token.value[0];
    if(cmd == '-'){
        if(ymode == true){
            bytecode[pc] = 0x02;
            pc++;
        }
        else{
            bytecode[pc] = 0x03;
            pc++;
        }
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
} 

void prvb(){
    char cmd = current_token.value[0];
    if(cmd == '.'){
        if(ymode == true){
            bytecode[pc] = 0x04;
            pc++;
        }
        else{
            bytecode[pc] = 0x05;
            pc++;
        }
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
} 

void nxtcb(){
    char cmd = current_token.value[0];
    if(cmd == '>'){
        if(ymode == true){
            ymode = false;
            bytecode[pc] = 0x06;
            pc++;
        }
        else{
            bytecode[pc] = 0x07;
            pc++;
        }
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
} 

void pvcb(){
    char cmd = current_token.value[0];
    if(cmd == '<'){
        if(ymode == true){
            ymode = false;
            bytecode[pc] = 0x08;
            pc++;
        }
        else{
            bytecode[pc] = 0x09;
            pc++;
        }
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
} 

void cupb(){
    char cmd = current_token.value[0];
    if(cmd == '^'){
        if(ymode == true){
            bytecode[pc] = 0x10;
            pc++;
        }
        else{
            ymode = true;
            bytecode[pc] = 0x11;
            pc++;
        }
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
} 


void cdowb(){
    char cmd = current_token.value[0];
    if(cmd == 'v'){
        if(ymode == true){
            bytecode[pc] = 0x12;
            pc++;
        }
        else{
            ymode = true;
            bytecode[pc] = 0x13;
            pc++;
        }
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
} 

