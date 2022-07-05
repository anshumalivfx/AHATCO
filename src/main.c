//
// Created by Anshumali Karna on 29/06/22.
//

#include "../include/main.h"
#include "../include/lexer.h"
#include "../include/parser.h"


int main(int argc, const char* argv[]){
    LEXER_T* lexer = init_lexer(
            "var a = \"Hello World\";\n"
            "ALog(a);\n"
            );
    parser_T* parser = init_parser(lexer);
    ast_T* root = parser_parse(parser);

    printf("%d\n",root->type);
    printf("%zu\n", root->compound_size);
    return 0;
}