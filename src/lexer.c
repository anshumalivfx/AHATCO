//
// Created by Anshumali Karna on 29/06/22.
//

#include "../include/lexer.h"


LEXER_T* init_lexer(char* contents){
    LEXER_T* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    lexer->contents = contents;
    lexer->i = 0;
    lexer->c = contents[lexer->i];
    return lexer;
}


void lexer_advance(LEXER_T* lexer){
    if (lexer->c != '\0' && lexer->i < strlen(lexer->contents)){
        lexer->i += 1;
        lexer->c = lexer->contents[lexer->i];
    }
}


void lexer_skip_whitespace(LEXER_T* lexer){
    while (lexer->c == ' ' || lexer->c == 10){
        lexer_advance(lexer);
    }
}

TOKEN_t* lexer_get_next_token(LEXER_T* lexer){
    while(lexer->c != '\0' && lexer->i < strlen(lexer->contents)){
        if (lexer->c == ' ' || lexer->c == 10){
            lexer_skip_whitespace(lexer);
        }

        if (isalnum(lexer->c)){
            return lexer_collect_id(lexer);
        }


        if (lexer->c == '"'){
            return lexer_collect_string(lexer);
        }

        switch (lexer->c) {
            case '=': return lexer_advance_with_token(lexer, init_token(TOKEN_EQUALS, lexer_get_current_char_as_string(lexer))); break;
            case ';': return lexer_advance_with_token(lexer, init_token(TOKEN_SEMI, lexer_get_current_char_as_string(lexer))); break;
            case '(': return lexer_advance_with_token(lexer, init_token(TOKEN_LPAREN, lexer_get_current_char_as_string(lexer))); break;
            case ')': return lexer_advance_with_token(lexer, init_token(TOKEN_RPAREN, lexer_get_current_char_as_string(lexer))); break;
            case ',': return lexer_advance_with_token(lexer, init_token(TOKEN_COMMA, lexer_get_current_char_as_string(lexer))); break;
        }
    }
    return init_token(TOKEN_EOF, "\0");
}


TOKEN_t* lexer_collect_string(LEXER_T* lexer){
    lexer_advance(lexer);
    char* value = calloc(1,sizeof(char));
    value[0] = '\0';
    while (lexer->c != '"'){
        char* s = lexer_get_current_char_as_string(lexer);
        value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
        strcat(value,s);
        lexer_advance(lexer);
    }
    lexer_advance(lexer);
    return init_token(TOKEN_STRING, value);
}

TOKEN_t* lexer_collect_id(LEXER_T* lexer){
    char* value = calloc(1,sizeof(char));
    value[0] = '\0';
    while (isalnum(lexer->c)){
        char* s = lexer_get_current_char_as_string(lexer);
        value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
        strcat(value,s);
        lexer_advance(lexer);
    }
    return init_token(TOKEN_ID, value);
}


TOKEN_t* lexer_advance_with_token(LEXER_T* lexer, TOKEN_t* token){
    lexer_advance(lexer);

    return token;
}

char* lexer_get_current_char_as_string(LEXER_T* lexer){
    char* str = calloc(2, sizeof(char));
    str[0] = lexer->c;
    str[1] = '\0';
    return str;
}