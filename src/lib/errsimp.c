#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errsimp.h"

char* UnrecognizedTokenError(char got, unsigned int traceback) {
    char* buf = malloc(256);
    snprintf(buf, 256, "Unrecognized token '%c' at %u", got, traceback);
    return buf;
}

void UnexpectedToken(const char* expected, const char* got) {
    printf("Unexpected token: expected '%s', got '%s'\n", expected, got);
}
