//
// Created by Anshumali Karna on 29/06/22.
//

#ifndef AHATCO_NEW_PARSER_H
#define AHATCO_NEW_PARSER_H
#include "token.h"
#include "AST.h"
#include "lexer.h"

typedef struct PARSER_STRUCT {
    LEXER_T* lexer;
    TOKEN_t* current_token;
    TOKEN_t* prev_token;
} parser_T;

parser_T* init_parser(LEXER_T* lexer);

void parser_eat(parser_T* parser, int token_type);

ast_T* parser_parse(parser_T* parser);

ast_T* parser_parse_statement(parser_T* parser);

ast_T* parser_parse_statements(parser_T* parser);

ast_T* parser_parse_exp(parser_T* parser);

ast_T* parser_parse_factor(parser_T* parser);

ast_T* parser_parse_function_call(parser_T* parser);

ast_T* parser_parse_variable(parser_T* parser);

ast_T* parser_parse_string(parser_T* parser);

ast_T* parser_parse_id(parser_T* parser);

ast_T* parser_parse_variable_definition(parser_T* parser);

#endif //AHATCO_NEW_PARSER_H
