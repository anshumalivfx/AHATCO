//
// Created by Anshumali Karna on 29/06/22.
//

#ifndef AHATCO_NEW_LEXER_H
#define AHATCO_NEW_LEXER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include <ctype.h>

typedef struct LEXER_STRUCT {
    char c;
    unsigned int i;
    char* contents;
} LEXER_T;

LEXER_T* init_lexer(char* contents);


void lexer_advance(LEXER_T* lexer);


void lexer_skip_whitespace(LEXER_T* lexer);

TOKEN_t* lexer_get_next_token(LEXER_T* lexer);

TOKEN_t* lexer_collect_string(LEXER_T* lexer);

TOKEN_t* lexer_collect_id(LEXER_T* lexer);

TOKEN_t* lexer_advance_with_token(LEXER_T* lexer, TOKEN_t* token);


char* lexer_get_current_char_as_string(LEXER_T* lexer);

#endif //AHATCO_NEW_LEXER_H
