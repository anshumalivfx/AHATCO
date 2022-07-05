//
// Created by Anshumali Karna on 29/06/22.
//

#include "../include/parser.h"


parser_T* init_parser(LEXER_T* lexer){
    parser_T* parser = calloc(1, sizeof(struct PARSER_STRUCT));
    parser->lexer = lexer;
    parser->current_token = lexer_get_next_token(lexer);

    return parser;
}

void parser_eat(parser_T* parser, int token_type){
    if (parser->current_token->type == token_type){
        parser->current_token = lexer_get_next_token(parser->lexer);
    }

    else {
        printf(
                "Unexpected token `%s`, with type %d",
                    parser->current_token->value,
                    parser->current_token->type
                );
        exit(1);
    }
}

ast_T* parser_parse(parser_T* parser){
    return parser_parse_statements(parser);
}

ast_T* parser_parse_statement(parser_T* parser){
    switch (parser->current_token->type) {
        case TOKEN_ID: return parser_parse_id(parser);
    }
}


ast_T* parser_parse_statements(parser_T* parser){

    ast_T* compound = init_ast(AST_COMPOUND);
    compound->compound_value = calloc(1, sizeof(struct AST_STRUCT));
    ast_T* ast_statement = parser_parse_statement(parser);
    compound->compound_value[0] = ast_statement;
    printf("%s\n", parser->current_token->value);
    compound->compound_size += 1 ;

    while(parser->current_token->type == TOKEN_SEMI){
        parser_eat(parser, TOKEN_SEMI);
        ast_T* ast_statement = parser_parse_statement(parser);
        compound->compound_size += 1;
        compound->compound_value = realloc(compound->compound_value, compound->compound_size * sizeof(struct AST_STRUCT));
        compound->compound_value[compound->compound_size - 1] = ast_statement;
    }


    return compound;
}

ast_T* parser_parse_exp(parser_T* parser){
    switch (parser->current_token->type) {
        case TOKEN_STRING: return parser_parse_string(parser);
    }
}

ast_T* parser_parse_factor(parser_T* parser){
}

ast_T* parser_parse_function_call(parser_T* parser){

}

ast_T* parser_parse_variable_definition(parser_T* parser){

    parser_eat(parser, TOKEN_ID);
    char* variable_definition_variable_name = parser->current_token->value;
    parser_eat(parser, TOKEN_ID);
    parser_eat(parser, TOKEN_EQUALS);
    ast_T* variable_definition_value = parser_parse_exp(parser);

    ast_T* variable_definition = init_ast(AST_VARIABLE);
    variable_definition->variable_definition_variable_name = variable_definition_variable_name;
    variable_definition->variable_definition_value = variable_definition_value;

    return variable_definition;
}

ast_T* parser_parse_variable(parser_T* parser){

    char* token_value = parser->current_token->value;

    parser_eat(parser, TOKEN_ID);

    if (parser->current_token->type == TOKEN_LPAREN){
        return parser_parse_function_call(parser);
    }

    ast_T* ast_Variable = init_ast(AST_VARIABLE);
    ast_Variable->variable_name = token_value;

    return ast_Variable;
}

ast_T* parser_parse_string(parser_T* parser){
    ast_T* ast_String = init_ast(AST_STRING);
    ast_String->string_value = parser->current_token->value;

    parser_eat(parser, TOKEN_STRING);
    return ast_String;
}


ast_T* parser_parse_id(parser_T* parser){
    if (strcmp(parser->current_token->value, "var") == 0){
        return parser_parse_variable_definition(parser);
    }

    else {
        return parser_parse_variable(parser);
    }
}



