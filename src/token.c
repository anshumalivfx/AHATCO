//
// Created by Anshumali Karna on 29/06/22.
//

#include "../include/token.h"


TOKEN_t* init_token(int type, char* value){
    TOKEN_t* token = calloc(1, sizeof(struct TOKEN_STRUCT));
    token->type = type;
    token->value = value;
    return token;
}
