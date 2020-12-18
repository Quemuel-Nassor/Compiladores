/*
  	Authores:
        Quemuel Alves Nassor
        Wesley de Oliveira Mendes
	Date: 01/12/20
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include ".\lib\dynamic.h"
#include ".\lib\words.h"

int lineCount = 1;
extern char *word;
extern long int stack_parenthesis;
extern long int stack_brackets;
char * BASE_PATH = "";

int main(void) {
    setlocale(LC_ALL, "");

    char read_chr = '\0';
    
    char input_filename[200];

    strcpy(output_filename,BASE_PATH);
    strcpy(input_filename,BASE_PATH);
    strcat(input_filename,"source.txt");
    strcat(output_filename,"output.csv");

    FILE * source_file;

    source_file = fopen(input_filename, "r");

    // Read file loop
    do {
        read_chr = fgetc(source_file);

        // Resize strings dynamically
        resize_string();
        resize_string_special_word();

        is_special_chars(read_chr, lineCount);

        switch (read_chr) {
            case ' ': {
                if(check_words(word, (int)strlen(word), lineCount) != OK) {
                    return error_found(' ',INVALID,lineCount);
                }
                free_string_word();
                break;
            }

            case '\n': {
                if(check_words(word, (int)strlen(word), lineCount) != OK) {
                    return error_found('\n',INVALID,lineCount);
                }
                free_string_word();
                lineCount++;
                break;
            }

            case EOF: {
                if(check_words(word, (int)strlen(word), lineCount) != OK) {
                    return error_found(EOF,INVALID,lineCount);
                }
                free_string_word();
                break;
            }

            case ';': {
                if(check_words(word, (int) strlen(word), lineCount) != OK) {
                    return error_found(';',INVALID,lineCount);
                }
                save_special_chars(read_chr, SEMICOLON, lineCount);
                free_string_word();
                break;
            }

            case '.': {
                if(check_words(word, (int) strlen(word), lineCount) != OK) {
                    return error_found('.',INVALID,lineCount);
                }
                save_special_chars(read_chr, POINTER, lineCount);
                free_string_word();
                break;
            }

            case ',': {
                if(check_words(word, (int) strlen(word), lineCount) != OK) {
                    return error_found(',',INVALID,lineCount);
                }
                save_special_chars(read_chr, COMMA, lineCount);
                free_string_word();
                break;
            }

            case '-': {
                if(check_words(word, (int) strlen(word), lineCount) != OK) {
                    return error_found('-',INVALID,lineCount);
                }
                save_special_chars(read_chr, MINUS, lineCount);
                free_string_word();
                break;
            }

            case '+': {
                if(check_words(word, (int) strlen(word), lineCount) != OK) {
                    return error_found('+',INVALID,lineCount);;
                }
                save_special_chars(read_chr, MORE, lineCount);
                free_string_word();
                break;
            }

            case '*': {
                if(check_words(word, (int) strlen(word), lineCount) != OK) {
                    return error_found('*',INVALID,lineCount);
                }
                save_special_chars(read_chr, MULTIPLICATION, lineCount);
                free_string_word();
                break;
            }

            case '(': {
                if(check_words(word, (int) strlen(word), lineCount) != OK) {
                    return error_found('(',INVALID,lineCount);
                }
                save_special_chars(read_chr, OPEN_PARENTHESIS, lineCount);
                free_string_word();
                stack_parenthesis++;
                break;
            }

            case ')': {
                if(check_words(word, (int) strlen(word), lineCount) != OK) {
                    return error_found(')',INVALID,lineCount);
                }
                save_special_chars(read_chr, CLOSE_PARENTHESIS, lineCount);
                free_string_word();
                stack_parenthesis--;
                break;
            }

            case '[': {
                if(check_words(word, (int) strlen(word), lineCount) != OK) {
                    return error_found('[',INVALID,lineCount);
                }
                save_special_chars(read_chr, OPEN_BRACKETS, lineCount);
                free_string_word();
                stack_brackets++;
                break;
            }

            case ']': {
                if(check_words(word, (int) strlen(word), lineCount) != OK) {
                    return error_found(']',INVALID,lineCount);
                }
                save_special_chars(read_chr, CLOSE_BRACKETS, lineCount);
                free_string_word();
                stack_brackets--;
                break;
            }

            default: {
                if (strlen(special_word) == 0) {
                    is_not_eof_or_new_line(read_chr);
                }
                break;
            }
        }
    } while (read_chr != EOF);

    fclose(source_file);

    if(stack_brackets != 0 || stack_parenthesis != 0) {
        return error_found(' ',INVALID,lineCount);
    }

    return (EXIT_SUCCESS);
}