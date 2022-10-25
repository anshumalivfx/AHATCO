//
// Created by Anshumali Karna on 29/06/22.
//

#ifndef AHATCO_NEW_TOKEN_H
#define AHATCO_NEW_TOKEN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct TOKEN_STRUCT {
    enum {
        TOKEN_ID,
        TOKEN_EQUALS,
        TOKEN_STRING,
        TOKEN_SEMI,
        TOKEN_LPAREN,
        TOKEN_RPAREN,
        TOKEN_COMMA,
        TOKEN_EOF
    } type;
    char* value;
} TOKEN_t;

TOKEN_t* init_token(int type, char* value);


#endif //AHATCO_NEW_TOKEN_H
