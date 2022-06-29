//
// Created by Anshumali Karna on 29/06/22.
//

#include "../include/main.h"
#include "../include/lexer.h"


int main(int argc, const char* argv[]){
    LEXER_T* lexer = init_lexer(
            "var a = \"Hello World\";\n"
            "ALog(a);\n"
            );

    TOKEN_t* token = (void*)0;

    while((token = lexer_get_next_token(lexer)) != (void*)0){
        printf("TOK(%d, %s) \n", token->type, token->value);
    }
    return 0;
}