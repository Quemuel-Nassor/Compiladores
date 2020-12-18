/*
    Library to manipulate dynamically strings

	Authores:
        Quemuel Alves Nassor
        Wesley de Oliveira Mendes
	Date: 01/12/20
*/
#ifndef DYNAMIC_H
#define DYNAMIC_H

#include <string.h>
#include <stdlib.h>

// Global char pointers
char *word = "\0";
char *special_word = "\0";

/*
    Function to deallocate and clear a dynamic string WORD
        param: void
*/
void free_string_word(void) {
    free(word);
    word = (char * ) malloc(sizeof(char));
    word[0] = '\0';
}

/*
    Function to deallocate and clear a dynamic string SPECIAL_WORD
        param: void
*/
void free_string_special_word(void) {
    free(special_word);
    special_word = (char * ) malloc(sizeof(char));
    special_word[0] = '\0';
}

/*
    Function to dynamically resize a string WORD
        param: void
*/
void resize_string(void) {
    int size = (int) strlen(word);
    char * old_word = (char * ) malloc(size * sizeof(char));

    strcpy(old_word, word);
    word = (char * ) malloc((size + 1) * sizeof(char));

    strcpy(word, old_word);
    free(old_word);

    word[(size + 1)] = '\0';
}

/*
    Function to dynamically resize a string SPECIAL_WORD
        param: void
*/
void resize_string_special_word(void) {
    int size = (int) strlen(special_word);
    char * old_word = (char * ) malloc(size * sizeof(char));

    strcpy(old_word, special_word);
    special_word = (char * ) malloc((size + 1) * sizeof(char));

    strcpy(special_word, old_word);
    free(old_word);

    special_word[(size + 1)] = '\0';
}

#endif