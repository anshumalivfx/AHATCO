//
// Created by Anshumali Karna on 25/10/22.
//

#include "../include/io.h"

char* get_file_contents(const char* filepath){
    char* buffer = 0;
    long length;
    FILE* f = fopen(filepath, "rb");
    if (f){
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);
        buffer = malloc(length);
        if (buffer){
            fread(buffer, 1, length, f);
        }
        fclose(f);
        return buffer;
    }
    printf("Error: Could not open file %s", filepath);
    exit(2);
}