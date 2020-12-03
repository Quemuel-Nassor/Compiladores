/*
    Library to manipulate dynamically strings
    
	Author: Quemuel Alves Nassor
	Date: 01/12/20 23:01
*/
#ifndef DYNAMIC_H
#define DYNAMIC_H

#include <string.h>
#include <stdlib.h>

// Global char pointer
char *word = "\0";

/*
    Function to deallocate and clear a dynamic string
        param: void
*/
void free_string(void)
{
    free(word);
    word = (char *)malloc(sizeof(char));
    word[0] = '\0';
}

/*
    Function to dynamically resize a string
        param: void
*/
void resize_string(void)
{
    int size = (int)strlen(word);
    char *old_word = (char *)malloc(size * sizeof(char));
    strcpy(old_word, word);
    word = (char *)malloc((size + 1) * sizeof(char));
    strcpy(word, old_word);
    free(old_word);
    word[(size + 1)] = '\0';
}

#endif
