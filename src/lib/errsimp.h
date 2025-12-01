#ifndef ERRSIMP_H
#define ERRSIMP_H


char* UnrecognizedTokenError(char got, unsigned int traceback);


void UnexpectedToken(const char* expected, const char* got);

#endif
