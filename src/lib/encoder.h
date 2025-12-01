#ifndef ENCODER_H
#define ENCODER_H

extern void encode();
extern void print_bytecode_debug(size_t bytecode_len);
extern void write_bytecode_to_file(const char* filename, size_t bytecode_len);
extern size_t read_bytecode_from_file(const char* filename, unsigned char* buffer, size_t max_size);
extern void run_bytecode(size_t bytecode_len);
#endif