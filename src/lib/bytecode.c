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

void pcmbb(){
    char cmd = current_token.value[0];
    if(cmd == 'W'){
        if(ymode == true){
            bytecode[pc] = 0x14;
            pc++;
        }
        else{
            ymode = true;
            bytecode[pc] = 0x15;
            pc++;
        }
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
} 


void ncmbb(){
    char cmd = current_token.value[0];
    if(cmd == '/'){
        if(ymode == true){
            bytecode[pc] = 0x16;
            pc++;
        }
        else{
            ymode = true;
            bytecode[pc] = 0x17;
            pc++;
        }
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
} 

void pascib(){
    char cmd = current_token.value[0];
    if(cmd == ','){
        if(ymode == true){
            bytecode[pc] = 0x18;
            pc++;
        }
        else{
            ymode = true;
            bytecode[pc] = 0x19;
            pc++;
        }
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
} 


void inpb(){
    char cmd = current_token.value[0];
    if(cmd == ':'){
        if(ymode == true){
            bytecode[pc] = 0x20;
            pc++;
        }
        else{
            ymode = true;
            bytecode[pc] = 0x21;
            pc++;
        }
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
}

void cmtb(){
    char cmd = current_token.value[0];
    if(cmd == '('){
        if(ymode == true){
            bytecode[pc] = 0x22;
            pc++;
        }
        else{
            ymode = true;
            bytecode[pc] = 0x23;
            pc++;
        }
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
} 

void cmteb(){
    char cmd = current_token.value[0];
    if(cmd == ')'){
        if(ymode == true){
            bytecode[pc] = 0x24;
            pc++;
        }
        else{
            ymode = true;
            bytecode[pc] = 0x25;
            pc++;
        }
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
} 


void clrclb(){
    char cmd = current_token.value[0];
    if(cmd == '!'){
        if(ymode == true){
            bytecode[pc] = 0x26;
            pc++;
        }
        else{
            ymode = true;
            bytecode[pc] = 0x27;
            pc++;
        }
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
} 

void clrcmbb(){
    char cmd = current_token.value[0];
    if(cmd == '~'){
        if(ymode == true){
            bytecode[pc] = 0x28;
            pc++;
        }
        else{
            ymode = true;
            bytecode[pc] = 0x29;
            pc++;
        }
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
} 

void clrtpb(){
    char cmd = current_token.value[0];
    if(cmd == '%'){
        if(ymode == true){
            bytecode[pc] = 0x30;
            pc++;
        }
        else{
            ymode = true;
            bytecode[pc] = 0x31;
            pc++;
        }
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
} 

void svplnb(){
    char cmd = current_token.value[0];
    if(cmd == '*'){
        if(ymode == true){
            bytecode[pc] = 0x32;
            pc++;
        }
        else{
            ymode = true;
            bytecode[pc] = 0x33;
            pc++;
        }
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
} 

void ldplb(){
    char cmd = current_token.value[0];
    if(cmd == '&'){
        if(ymode == true){
            bytecode[pc] = 0x34;
            pc++;
        }
        else{
            ymode = true;
            bytecode[pc] = 0x35;
            pc++;
        }
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
} 

void sqrclb(){
    char cmd = current_token.value[0];
    if(cmd == 'S'){
        if(ymode == true){
            bytecode[pc] = 0x36;
            pc++;
        }
        else{
            ymode = true;
            bytecode[pc] = 0x37;
            pc++;
        }
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
} 

void if0b(){
    char cmd = current_token.value[0];
    if(cmd == '#'){
        if(ymode == true){
            bytecode[pc] = 0x38;
            pc++;
        }
        else{
            ymode = true;
            bytecode[pc] = 0x39;
            pc++;
        }
    }
    else{
        char expected_str[2] = {cmd, '\0'};
        UnexpectedToken(expected_str, current_token.type);
    }
} 



