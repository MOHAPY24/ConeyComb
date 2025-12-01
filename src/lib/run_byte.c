#include "tokenize.h"
#include "eat.h"
#include "parse.h"
#include <string.h>
#include "bytecode.h"
#include "run_byte.h"

int run_compiled(){
    size_t bytecode_le = read_bytecode_from_file("out.chb",bytecode, BYTE_SIZE);
    run_bytecode(bytecode_le);
    return 0;
}
