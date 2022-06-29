//
// Created by Anshumali Karna on 29/06/22.
//

#ifndef AHATCO_NEW_AST_H
#define AHATCO_NEW_AST_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct AST_STRUCT {
    enum {
        AST_VARIABLE_DEFINITION,
        AST_VARIABLE,
        AST_FUNCTION_CALL,
        AST_STRING
    } type;

    // VARIABLE DEFINITION NAME
    char* variable_definition_variable_name;
    struct AST_STRUCT* variable_definition_value;

    // AST VARIABLE
    char* variable_name;

    // AST Function Call
    char* function_name;
    struct AST_STRUCT** function_call_arguments;
    size_t function_call_arguments_size;

    // AST_STRING
    char* string_value;
} ast_T;

ast_T* init_ast(int type);

#endif //AHATCO_NEW_AST_H
