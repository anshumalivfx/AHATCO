//
// Created by Anshumali Karna on 29/06/22.
//

#include "../include/AST.h"

ast_T* init_ast(int type){
    ast_T* ast = calloc(1, sizeof(struct AST_STRUCT));
    ast->type = type;

    // VARIABLE DEFINITION NAME
    ast->variable_definition_variable_name = (void*)0;
    ast->variable_definition_value = (void*)0;

    // AST VARIABLE
    ast->variable_name = (void*)0;

    // AST Function Call
    ast->function_name = (void*)0;
    ast->function_call_arguments = (void*)0;
    ast->function_call_arguments_size = 0;

    // AST_STRING
    ast->string_value = (void*)0;

    // AST_COMPOUND
    ast->compound_value = (void*)0;
    ast->compound_size = 0;
    return ast;
}