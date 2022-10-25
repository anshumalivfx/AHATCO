//
// Created by Anshumali Karna on 21/10/22.
//

#ifndef AHATCO_VISITOR_H
#define AHATCO_VISITOR_H

#include "AST.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct VISITOR_STRUCT {
    ast_T** variable_definition;
    size_t variable_definition_size;

} visitor_T;

visitor_T* init_visitor();

ast_T* visitor_visit(visitor_T* visitor,ast_T* node);
ast_T* visitor_visit_variable_definition(visitor_T* visitor,ast_T* node);
ast_T* visitor_visit_variable(visitor_T* visitor,ast_T* node);
ast_T* visitor_visit_function_call(visitor_T* visitor,ast_T* node);
ast_T* visitor_visit_string(visitor_T* visitor,ast_T* node);
ast_T* visitor_visit_compound(visitor_T* visitor,ast_T* node);
#endif //AHATCO_VISITOR_H
