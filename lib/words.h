/*
    Library to identify reserverd words, manipulate strings
    and otherwwise tasks how show reserved words code
    
	Author: Quemuel Alves Nassor
	Date: 01/12/20 23:01
*/
#ifndef WORDS_H
#define WORDS_H

/*
    Dependencies
*/
#include <ctype.h>
#include <stdio.h>
#include <string.h>

/*
    Responses codes
*/
enum RESPONSE_CODES
{
    OK = 200,
    INVALID
};

/*
    Reserved words codes
*/
enum RESERVED_WORDS
{
    AND = 0x200,
    BEGIN,
    CHAR,
    DIV,
    DO,
    ELSE,
    END,
    FUNCTION,
    IF,
    INT,
    NOT,
    OR,
    PROCEDURE,
    PROGRAM,
    READD,
    READC,
    REPEAT,
    THEN,
    UNTIL,
    VAR,
    WHILE,
    WRITED,
    WRITEC
};

/*
    Output filename
*/
// char output_filename[12] = "output.csv";
char *output_filename = "output.txt";

/*
    Function to validate reserved word AND
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_and(char *input_word, int size_word, int line_count)
{
    int i, state = 0;
    FILE *file;
    char chr, word[size_word];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++)
    {
        word[i+1]='\0';
        chr = input_word[i];

        // Validate if is char or number
        if (isalpha(chr)){
            chr = toupper(chr);
        }else{
            i = size_word;
            return INVALID;
        }

        switch (chr)
        {
        case 'A':
        {
            if (state == 0 && strlen(word) == 0)
            {
                word[i] = toupper(chr);
                state = 1;
            }
            else
            {
                i = size_word;
                return INVALID;
            }

            break;
        }

        case 'N':
        {
            if (state == 1 && strlen(word) == 1)
            {
                word[i] = toupper(chr);
                state = 2;
            }
            else
            {
                i = size_word;
                return INVALID;
            }

            break;
        }

        case 'D':
        {
            if (state == 2 && strlen(word) == 2)
            {
                word[i] = toupper(chr);
                state = 3;
            }
            else
            {
                i = size_word;
                return INVALID;
            }
            break;
        }

        default:
        {
            i = size_word;
            return INVALID;
            break;
        }
        }
    }

    // Writing reserved word
    if (state == 3)
    {
        file = fopen(output_filename, "a");
        fprintf(file, "AND\t%i\t%i\n", AND, line_count);
        fclose(file);
        return OK;
    }
    else
    {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to check and validate identified words
        param: input => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int check_words(char *input, int size_word, int line_count)
{
    
    int response = NULL;

    if ((response = is_and(input, size_word, line_count)) == OK);
    
    return response;
}

/*
    Function to list reserved words
        param: void
*/
void reserved_words(void)
{
    printf("INVALID: { %i } \n", INVALID);
    printf("OK: { %i } \n", OK);
    printf("AND: { 0x%X } | { %i } \n", AND, AND);
    printf("BEGIN: { 0x%X } | { %i } \n", BEGIN, BEGIN);
    printf("CHAR: { 0x%X } | { %i } \n", CHAR, CHAR);
    printf("DIV: { 0x%X } | { %i } \n", DIV, DIV);
    printf("DO: { 0x%X } | { %i } \n", DO, DO);
    printf("ELSE: { 0x%X } | { %i } \n", ELSE, ELSE);
    printf("END: { 0x%X } | { %i } \n", END, END);
    printf("FUNCTION: { 0x%X } | { %i } \n", FUNCTION, FUNCTION);
    printf("IF: { 0x%X } | { %i } \n", IF, IF);
    printf("INT: { 0x%X } | { %i } \n", INT, INT);
    printf("NOT: { 0x%X } | { %i } \n", NOT, NOT);
    printf("OR: { 0x%X } | { %i } \n", OR, OR);
    printf("PROCEDURE: { 0x%X } | { %i } \n", PROCEDURE, PROCEDURE);
    printf("PROGRAM: { 0x%X } | { %i } \n", PROGRAM, PROGRAM);
    printf("READD: { 0x%X } | { %i } \n", READD, READD);
    printf("READC: { 0x%X } | { %i } \n", READC, READC);
    printf("REPEAT: { 0x%X } | { %i } \n", REPEAT, REPEAT);
    printf("THEN: { 0x%X } | { %i } \n", THEN, THEN);
    printf("UNTIL: { 0x%X } | { %i } \n", UNTIL, UNTIL);
    printf("VAR: { 0x%X } | { %i } \n", VAR, VAR);
    printf("WHILE: { 0x%X } | { %i } \n", WHILE, WHILE);
    printf("WRITED: { 0x%X } | { %i } \n", WRITED, WRITED);
    printf("WRITEC: { 0x%X } | { %i } \n", WRITEC, WRITEC);
}

#endif
