//
// Created by Anshumali Karna on 29/06/22.
//

#include "../include/main.h"
#include "../include/lexer.h"
#include "../include/parser.h"
#include "../include/visitor.h"
#include "../include/io.h"


int main(int argc, const char* argv[]){

    LEXER_T* lexer = init_lexer(get_file_contents(argv[1]));
    parser_T* parser = init_parser(lexer);
    ast_T* root = parser_parse(parser);
    visitor_T* visitor = init_visitor();
    visitor_visit(visitor,root);
    return 0;
}