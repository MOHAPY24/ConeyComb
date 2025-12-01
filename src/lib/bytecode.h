#ifndef BYTECODE_H
#define BYTECODE_H

#define BYTE_SIZE 1024


extern unsigned char bytecode[BYTE_SIZE];
extern int pc;


extern void adrb();
extern void mdrb();
extern void prvb();
extern void nxtcb();
extern void pvcb();
extern void cupb();
extern void cdowb();

#endif