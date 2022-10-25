//
// Created by Anshumali Karna on 21/10/22.
//

#include "../include/visitor.h"


static ast_T* builtin_function_alog(visitor_T* visitor, ast_T** args, int args_size){
    for(int i = 0; i < args_size; i++){
        ast_T* visited_ast = visitor_visit(visitor,args[i]);
        switch (visited_ast->type){
            case AST_STRING:
                printf("%s",visited_ast->string_value);
                break;
            default:
                printf("Unknown type");
                break;
        }
    }

    return init_ast(AST_NOOP);
}

visitor_T* init_visitor() {
    visitor_T* visitor = calloc(1, sizeof(struct VISITOR_STRUCT));
    visitor->variable_definition = calloc(1, sizeof(struct AST_STRUCT));
    visitor->variable_definition_size = 0;
    return visitor;
}

ast_T* visitor_visit(visitor_T* visitor,ast_T* node){
    switch (node->type) {
        case AST_VARIABLE_DEFINITION:
            return visitor_visit_variable_definition(visitor,node); break;
        case AST_VARIABLE:
            return visitor_visit_variable(visitor,node); break;
        case AST_FUNCTION_CALL:
            return visitor_visit_function_call(visitor,node); break;
        case AST_STRING:
            return visitor_visit_string(visitor,node); break;
        case AST_COMPOUND:
            return visitor_visit_compound(visitor,node); break;
        case AST_NOOP:
            return node; break;
    }
    printf("Uncaught Statement of type %d \n", node->type);

    exit(1);
    return init_ast(AST_NOOP);
}
ast_T* visitor_visit_variable_definition(visitor_T* visitor,ast_T* node){
    if (visitor->variable_definition == (void*)0){
        visitor->variable_definition = calloc(1, sizeof(struct AST_STRUCT*));
        visitor->variable_definition[0] = node;
        visitor->variable_definition_size += 1;
    }
    else {
        visitor->variable_definition_size += 1;
        visitor->variable_definition = realloc(
                visitor->variable_definition,
                visitor->variable_definition_size * sizeof(struct AST_STRUCT*)
                );
        visitor->variable_definition[visitor->variable_definition_size - 1] = node;
    }

    return node;
}

ast_T* visitor_visit_variable(visitor_T* visitor,ast_T* node){
    for(int i = 0; i < visitor->variable_definition_size; i++){
        ast_T* variable_def = visitor->variable_definition[i];
        if (strcmp(variable_def->variable_definition_variable_name,node->variable_name) == 0){
            return visitor_visit(visitor,variable_def->variable_definition_value);
        }
    }
    return node;
}

ast_T* visitor_visit_function_call(visitor_T* visitor,ast_T* node){
    if (strcmp(node->function_name, "ALog") == 0){
        return builtin_function_alog(visitor,node->function_call_arguments, node->function_call_arguments_size);
    }
    else {
        printf("Uncaught Function Call of type `%s` \n", node->function_name);
        exit(1);
    }
}

ast_T* visitor_visit_string(visitor_T* visitor,ast_T* node){
    return node;
}

ast_T* visitor_visit_compound(visitor_T* visitor,ast_T* node){
    for (int i = 0; i < node->compound_size; i++) {
        visitor_visit(visitor,node->compound_value[i]);
    }
    return init_ast(AST_NOOP);
}
