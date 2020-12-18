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
extern char * word;

int main(void) {
    setlocale(LC_ALL, "");

    char read_chr = '\0';
    char input_filename[120] = "D:\\OneDrive\\ESCOLA\\FACULDADE\\UNAERP\\Stage_07-2020-2\\Compiladores\\Aulas\\prova02_final\\Compiladores\\source.txt";

    FILE * source_file;

    source_file = fopen(input_filename, "r");

    // Read file loop
    do {
        read_chr = fgetc(source_file);

        // Resize string dynamically
        resize_string();
        resize_string_special_word();

        is_special_chars(read_chr, lineCount);

        switch (read_chr) {
            case ' ': {
                check_words(word, (int)strlen(word), lineCount);
                free_string_word();
                break;
            }

            case '\n': {
                check_words(word, (int)strlen(word), lineCount);
                free_string_word();
                lineCount++;
                break;
            }

            case EOF: {
                check_words(word, (int)strlen(word), lineCount);
                free_string_word();
                break;
            }

//            case '<': {
//                if (strlen(special_word) == 0) {
//                    check_words(word, (int) strlen(word), lineCount);
//                    save_special_chars(read_chr, SEMICOLON, lineCount);
//                    free_string_word();
//                }
//                break;
//            }
//
//            case '>': {
//                if (strlen(special_word) == 0) {
//                    check_words(word, (int) strlen(word), lineCount);
//                    save_special_chars(read_chr, POINTER, lineCount);
//                    free_string_word();
//                }
//                break;
//            }
//
//            case '=': {
//                if (strlen(special_word) == 0) {
//                    check_words(word, (int) strlen(word), lineCount);
//                    save_special_chars(read_chr, COMMA, lineCount);
//                    free_string_word();
//                }
//                break;
//            }

            case ';': {
                check_words(word, (int) strlen(word), lineCount);
                save_special_chars(read_chr, SEMICOLON, lineCount);
                free_string_word();
                break;
            }

            case '.': {
                check_words(word, (int) strlen(word), lineCount);
                save_special_chars(read_chr, POINTER, lineCount);
                free_string_word();
                break;
            }

            case ',': {
                check_words(word, (int) strlen(word), lineCount);
                save_special_chars(read_chr, COMMA, lineCount);
                free_string_word();
                break;
            }

            case '-': {
                check_words(word, (int) strlen(word), lineCount);
                save_special_chars(read_chr, MINUS, lineCount);
                free_string_word();
                break;
            }

            case '+': {
                check_words(word, (int) strlen(word), lineCount);
                save_special_chars(read_chr, MORE, lineCount);
                free_string_word();
                break;
            }

            case '*': {
                check_words(word, (int) strlen(word), lineCount);
                save_special_chars(read_chr, MULTIPLICATION, lineCount);
                free_string_word();
                break;
            }

            case '(': {
                check_words(word, (int) strlen(word), lineCount);
                save_special_chars(read_chr, OPEN_PARENTHESIS, lineCount);
                free_string_word();
                break;
            }

            case ')': {
                check_words(word, (int) strlen(word), lineCount);
                save_special_chars(read_chr, CLOSE_PARENTHESIS, lineCount);
                free_string_word();
                break;
            }

            case '[': {
                check_words(word, (int) strlen(word), lineCount);
                save_special_chars(read_chr, OPEN_BRACKETS, lineCount);
                free_string_word();
                break;
            }

            case ']': {
                check_words(word, (int) strlen(word), lineCount);
                save_special_chars(read_chr, CLOSE_BRACKETS, lineCount);
                free_string_word();
                break;
            }

            default: {
                if (strlen(special_word) == 0) {
                    is_eof_or_new_line(read_chr);
                }
                break;
            }
        }
    } while (read_chr != EOF);

    fclose(source_file);

    return (EXIT_SUCCESS);
}