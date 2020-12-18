/*
    Library to identify reserved words, manipulate strings
    and other tasks as showing the code of reserved words

    Authores:
        Quemuel Alves Nassor
        Wesley de Oliveira Mendes
    Date: 01/12/20
*/
#ifndef WORDS_H
#define WORDS_H

/*
    Dependencies
*/
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include ".\lib\dynamic.h"

/*
    Responses codes
*/
enum RESPONSE_CODES {
    OK = 200, INVALID
};

/*
    Reserved words codes
*/
enum RESERVED_WORDS {
    AND = 0x200, BEGIN, CHAR, DIV, DO, ELSE, END, FUNCTION,
    IF, INT, NOT, OR, PROCEDURE, PROGRAM, READD, READC, REPEAT,
    THEN, UNTIL, VAR, WHILE, WRITED, WRITEC, ATTRIBUTION, DISTINCTION,
    GTE, LTE, POINTER, SEMICOLON, COMMA, MINUS, MORE, MULTIPLICATION,
    OPEN_PARENTHESIS, CLOSE_PARENTHESIS, OPEN_BRACKETS, CLOSE_BRACKETS,
    GREAT, LESS, EQUAL
};

/*
    Output filename
*/
char * output_filename = "D:\\OneDrive\\ESCOLA\\FACULDADE\\UNAERP\\Stage_07-2020-2\\Compiladores\\Aulas\\prova02_final\\Compiladores\\output.csv";
extern char * word;
extern char * special_word;
extern int lineCount;

/*
    Function to validate reserved word AND
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_and(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is char or number
        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'A': {
                if (state == 0) {
                    word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'N': {
                if (state == 1) {
                    word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'D': {
                if (state == 2) {
                    word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 3) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", AND);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word BEGIN
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_begin(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is char or number
        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'B': {
                if (state == 0) {
                    word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'E': {
                if (state == 1) {
                    word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'G': {
                if (state == 2) {
                    word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'I': {
                if (state == 3) {
                    word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'N': {
                if (state == 4) {
                    word[i] = toupper(chr);
                    state = 5;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 5) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", BEGIN);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word CHAR
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_char(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is char or number
        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'C': {
                if (state == 0) {
                    word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'H': {
                if (state == 1) {
                    word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'A': {
                if (state == 2) {
                    word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'R': {
                if (state == 3) {
                    word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 4) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", CHAR);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word DIV
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_div(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is char or number
        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'D': {
                if (state == 0) {
                    word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'I': {
                if (state == 1) {
                    word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'V': {
                if (state == 2) {
                    word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 3) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", DIV);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word DO
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_do(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is char or number
        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'D': {
                if (state == 0) {
                    word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'O': {
                if (state == 1) {
                    word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 2) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", DO);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word ELSE
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_else(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is char or number
        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'E': {
                if (state == 0) {
                    word[i] = toupper(chr);
                    state = 1;
                } else if (state == 3) {
                    word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'L': {
                if (state == 1) {
                    word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'S': {
                if (state == 2) {
                    word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 4) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", ELSE);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word END
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_end(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is char or number
        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'E': {
                if (state == 0) {
                    word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'N': {
                if (state == 1) {
                    word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'D': {
                if (state == 2) {
                    word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 3) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", END);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word FUNCTION
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_function(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is char or number
        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'F': {
                if (state == 0) {
                    word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'U': {
                if (state == 1) {
                    word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'N': {
                if (state == 2) {
                    word[i] = toupper(chr);
                    state = 3;
                } else if (state == 7) {
                    word[i] = toupper(chr);
                    state = 8;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'C': {
                if (state == 3) {
                    word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'T': {
                if (state == 4) {
                    word[i] = toupper(chr);
                    state = 5;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'I': {
                if (state == 5) {
                    word[i] = toupper(chr);
                    state = 6;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'O': {
                if (state == 6) {
                    word[i] = toupper(chr);
                    state = 7;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 8) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", FUNCTION);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word IF
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_if(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is char or number
        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'I': {
                if (state == 0) {
                    word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'F': {
                if (state == 1) {
                    word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 2) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", IF);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word INT
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_int(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is char or number
        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'I': {
                if (state == 0) {
                    word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'N': {
                if (state == 1) {
                    word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'T': {
                if (state == 2) {
                    word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 3) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", INT);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word NOT
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_not(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is char or number
        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'N': {
                if (state == 0) {
                    word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'O': {
                if (state == 1) {
                    word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'T': {
                if (state == 2) {
                    word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 3) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", NOT);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word OR
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_or(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is char or number
        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'O': {
                if (state == 0) {
                    word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'R': {
                if (state == 1) {
                    word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 2) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", OR);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word PROCEDURE
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_procedure(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is char or number
        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'P': {
                if (state == 0) {
                    word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'R': {
                if (state == 1) {
                    word[i] = toupper(chr);
                    state = 2;
                } else if (state == 7) {
                    word[i] = toupper(chr);
                    state = 8;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'O': {
                if (state == 2) {
                    word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'C': {
                if (state == 3) {
                    word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'E': {
                if (state == 4) {
                    word[i] = toupper(chr);
                    state = 5;
                } else if (state == 8) {
                    word[i] = toupper(chr);
                    state = 9;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'D': {
                if (state == 5) {
                    word[i] = toupper(chr);
                    state = 6;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'U': {
                if (state == 6) {
                    word[i] = toupper(chr);
                    state = 7;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 9) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", PROCEDURE);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word PROGRAM
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_program(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is char or number
        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'P': {
                if (state == 0) {
                    word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'R': {
                if (state == 1) {
                    word[i] = toupper(chr);
                    state = 2;
                } else if (state == 4) {
                    word[i] = toupper(chr);
                    state = 5;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'O': {
                if (state == 2) {
                    word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'G': {
                if (state == 3) {
                    word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'A': {
                if (state == 5) {
                    word[i] = toupper(chr);
                    state = 6;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'M': {
                if (state == 6) {
                    word[i] = toupper(chr);
                    state = 7;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 7) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", PROGRAM);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word READD
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_readd(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is char or number
        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'R': {
                if (state == 0) {
                    word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'E': {
                if (state == 1) {
                    word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'A': {
                if (state == 2) {
                    word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'D': {
                if (state == 3) {
                    word[i] = toupper(chr);
                    state = 4;
                } else if (state == 4) {
                    word[i] = toupper(chr);
                    state = 5;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 5) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", READD);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word READC
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_readc(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is char or number
        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'R': {
                if (state == 0) {
                    word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'E': {
                if (state == 1) {
                    word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'A': {
                if (state == 2) {
                    word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'D': {
                if (state == 3) {
                    word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'C': {
                if (state == 4) {
                    word[i] = toupper(chr);
                    state = 5;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 5) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", READC);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word REPEAT
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_repeat(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is char or number
        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'R': {
                if (state == 0) {
                    word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'E': {
                if (state == 1) {
                    word[i] = toupper(chr);
                    state = 2;
                } else if (state == 3) {
                    word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'P': {
                if (state == 2) {
                    word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'A': {
                if (state == 4) {
                    word[i] = toupper(chr);
                    state = 5;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'T': {
                if (state == 5) {
                    word[i] = toupper(chr);
                    state = 6;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 6) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", REPEAT);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word THEN
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_then(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is char or number
        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'T': {
                if (state == 0) {
                    word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'H': {
                if (state == 1) {
                    word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'E': {
                if (state == 2) {
                    word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'N': {
                if (state == 3) {
                    word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 4) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", THEN);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word UNTIL
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_until(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is char or number
        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'U': {
                if (state == 0) {
                    word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'N': {
                if (state == 1) {
                    word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'T': {
                if (state == 2) {
                    word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'I': {
                if (state == 3) {
                    word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'L': {
                if (state == 4) {
                    word[i] = toupper(chr);
                    state = 5;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 5) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", UNTIL);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word VAR
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_var(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is char or number
        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'V': {
                if (state == 0) {
                    word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'A': {
                if (state == 1) {
                    word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'R': {
                if (state == 2) {
                    word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 3) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", VAR);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word WHILE
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_while(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is char or number
        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'W': {
                if (state == 0) {
                    word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'H': {
                if (state == 1) {
                    word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'I': {
                if (state == 2) {
                    word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'L': {
                if (state == 3) {
                    word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'E': {
                if (state == 4) {
                    word[i] = toupper(chr);
                    state = 5;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 5) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", WHILE);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word WRITED
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_writed(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is char or number
        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'W': {
                if (state == 0) {
                    word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'R': {
                if (state == 1) {
                    word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'I': {
                if (state == 2) {
                    word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'T': {
                if (state == 3) {
                    word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'E': {
                if (state == 4) {
                    word[i] = toupper(chr);
                    state = 5;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'D': {
                if (state == 5) {
                    word[i] = toupper(chr);
                    state = 6;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 6) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", WRITED);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word WRITEC
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_writec(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is char or number
        if (isalpha(chr)) {
            chr = toupper(chr);
        } else {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case 'W': {
                if (state == 0) {
                    word[i] = toupper(chr);
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'R': {
                if (state == 1) {
                    word[i] = toupper(chr);
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'I': {
                if (state == 2) {
                    word[i] = toupper(chr);
                    state = 3;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'T': {
                if (state == 3) {
                    word[i] = toupper(chr);
                    state = 4;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'E': {
                if (state == 4) {
                    word[i] = toupper(chr);
                    state = 5;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case 'C': {
                if (state == 5) {
                    word[i] = toupper(chr);
                    state = 6;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 6) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", WRITEC);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}


// ----------------------------------------------------------------------------------------------

/*
    Function to validate reserved word :=
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_attribution(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is not special char
        if ((int)chr != 58 && (int)chr != 61) {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case ':': {
                if (state == 0) {
                    word[i] = chr;
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case '=': {
                if (state == 1) {
                    word[i] = chr;
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 2) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", ATTRIBUTION);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word <>
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_distinction(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is not special char
        if ((int)chr != 60 && (int)chr != 62) {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case '<': {
                if (state == 0) {
                    word[i] = chr;
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case '>': {
                if (state == 1) {
                    word[i] = chr;
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 2) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", DISTINCTION);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word >=
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_great_than_equal(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is not special char
        if ((int)chr != 62 && (int)chr != 61) {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case '>': {
                if (state == 0) {
                    word[i] = chr;
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case '=': {
                if (state == 1) {
                    word[i] = chr;
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 2) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", GTE);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word <=
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_less_than_equal(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is not special char
        if ((int)chr != 60 && (int)chr != 61) {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case '<': {
                if (state == 0) {
                    word[i] = chr;
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            case '=': {
                if (state == 1) {
                    word[i] = chr;
                    state = 2;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 2) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", LTE);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word =
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_great(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is not special char
        if ((int)chr != 62) {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case '>': {
                if (state == 0) {
                    word[i] = chr;
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 1) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", GREAT);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word =
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_less(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is not special char
        if ((int)chr != 60) {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case '<': {
                if (state == 0) {
                    word[i] = chr;
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 1) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", LESS);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to validate reserved word =
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int is_equal(char * input_word, int size_word, int line_count) {
    int i, state = 0;
    FILE * file;
    char chr, word[size_word + 1];
    word[0] = '\0';

    // Validating reserved word
    for (i = 0; i < size_word; i++) {
        word[i + 1] = '\0';
        chr = input_word[i];

        // Validate if is not special char
        if ((int)chr != 61) {
            i = size_word;
            return INVALID;
        }

        switch (chr) {
            case '=': {
                if (state == 0) {
                    word[i] = chr;
                    state = 1;
                } else {
                    i = size_word;
                    return INVALID;
                }
                break;
            }

            default: {
                i = size_word;
                return INVALID;
                break;
            }
        }
    }

    // Writing reserved word
    if (state == 1) {
        file = fopen(output_filename, "a");
        fprintf(file, "%s", word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", EQUAL);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}


// ----------------------------------------------------------------------------------------------

/*
    Function to validate reserved word <=
        param: output_filename => output file to write symbol of reserved word
        param: input_word => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int save_special_chars(char input_word, int code, int line_count) {
    FILE * file;

    switch (input_word) {
        case '.': {
            code = POINTER;
            break;
        }
        case ';': {
            code = SEMICOLON;
            break;
        }
        case ',': {
            code = COMMA;
            break;
        }
        case '-': {
            code = MINUS;
            break;
        }
        case '+': {
            code = MORE;
            break;
        }
        case '*': {
            code = MULTIPLICATION;
            break;
        }
        case '(': {
            code = OPEN_PARENTHESIS;
            break;
        }
        case ')': {
            code = CLOSE_PARENTHESIS;
            break;
        }
        case '[': {
            code = OPEN_BRACKETS;
            break;
        }
        case ']': {
            code = CLOSE_BRACKETS;
            break;
        }

        default: {
            code = INVALID;
            break;
        }
    }

    // Writing reserved input_word
    if (code != INVALID) {
        file = fopen(output_filename, "a");
        fprintf(file, "%c", input_word);
        fprintf(file, "%c", ';');
        fprintf(file, "%i", code);
        fprintf(file, "%c", ';');
        fprintf(file, "%i\n", line_count);
        fclose(file);
        return OK;
    } else {
        fclose(file);
        return INVALID;
    }
}

/*
    Function to list reserved words
        param: void
*/
void reserved_words(void) {
	printf("INVALID: { %i } \n", INVALID);
	printf("OK: { %i } \n", OK);
	printf("AND: { 	0x%X } | { %i } \n", AND, AND);
	printf("BEGIN: { 	0x%X } | { %i } \n", BEGIN, BEGIN);
	printf("CHAR: { 	0x%X } | { %i } \n", CHAR, CHAR);
	printf("DIV: { 	0x%X } | { %i } \n", DIV, DIV);
	printf("DO: { 	0x%X } | { %i } \n", DO, DO);
	printf("ELSE: { 	0x%X } | { %i } \n", ELSE, ELSE);
	printf("END: { 	0x%X } | { %i } \n", END, END);
	printf("FUNCTION: { 	0x%X } | { %i } \n", FUNCTION, FUNCTION);
	printf("IF: { 	0x%X } | { %i } \n", IF, IF);
	printf("INT: { 	0x%X } | { %i } \n", INT, INT);
	printf("NOT: { 	0x%X } | { %i } \n", NOT, NOT);
	printf("OR: { 	0x%X } | { %i } \n", OR, OR);
	printf("PROCEDURE: { 	0x%X } | { %i } \n", PROCEDURE, PROCEDURE);
	printf("PROGRAM: { 	0x%X } | { %i } \n", PROGRAM, PROGRAM);
	printf("READD: { 	0x%X } | { %i } \n", READD, READD);
	printf("READC: { 	0x%X } | { %i } \n", READC, READC);
	printf("REPEAT: { 	0x%X } | { %i } \n", REPEAT, REPEAT);
	printf("THEN: { 	0x%X } | { %i } \n", THEN, THEN);
	printf("UNTIL: { 	0x%X } | { %i } \n", UNTIL, UNTIL);
	printf("VAR: { 	0x%X } | { %i } \n", VAR, VAR);
	printf("WHILE: { 	0x%X } | { %i } \n", WHILE, WHILE);
	printf("WRITED: { 	0x%X } | { %i } \n", WRITED, WRITED);
	printf("WRITEC: { 	0x%X } | { %i } \n", WRITEC, WRITEC);
    printf("ATTRIBUTION: { 	0x%X } | { %i } \n", ATTRIBUTION, ATTRIBUTION);
    printf("DISTINCTION: { 	0x%X } | { %i } \n", DISTINCTION, DISTINCTION);
    printf("GTE: { 	0x%X } | { %i } \n", GTE, GTE);
    printf("LTE: { 	0x%X } | { %i } \n", LTE, LTE);
}

/*
    Function check and create output file
        param: void
*/
void check_out_file(void) {
    FILE * file;

    if ((file = fopen(output_filename, "r")) == NULL) {
        file = fopen(output_filename, "w");
        fprintf(file, "%s", "WORD");
        fprintf(file, "%c", ';');
        fprintf(file, "%s", "CODE");
        fprintf(file, "%c", ';');
        fprintf(file, "%s", "LINE\n");
        fclose(file);
    }
}

/*
    Function to check and validate identified words
        param: input => identified word
        param: size_word => size of identified word
        param: line_count => line where the word was identified
*/
int check_words(char * input, int size_word, int line_count) {
    int response;

    check_out_file();

    if (size_word > 0) {
        if ((response = is_and(input, size_word, line_count)) == OK);
        if ((response = is_begin(input, size_word, line_count)) == OK);
        if ((response = is_char(input, size_word, line_count)) == OK);
        if ((response = is_div(input, size_word, line_count)) == OK);
        if ((response = is_do(input, size_word, line_count)) == OK);
        if ((response = is_else(input, size_word, line_count)) == OK);
        if ((response = is_end(input, size_word, line_count)) == OK);
        if ((response = is_function(input, size_word, line_count)) == OK);
        if ((response = is_if(input, size_word, line_count)) == OK);
        if ((response = is_int(input, size_word, line_count)) == OK);
        if ((response = is_not(input, size_word, line_count)) == OK);
        if ((response = is_or(input, size_word, line_count)) == OK);
        if ((response = is_procedure(input, size_word, line_count)) == OK);
        if ((response = is_program(input, size_word, line_count)) == OK);
        if ((response = is_readd(input, size_word, line_count)) == OK);
        if ((response = is_readc(input, size_word, line_count)) == OK);
        if ((response = is_repeat(input, size_word, line_count)) == OK);
        if ((response = is_then(input, size_word, line_count)) == OK);
        if ((response = is_until(input, size_word, line_count)) == OK);
        if ((response = is_var(input, size_word, line_count)) == OK);
        if ((response = is_while(input, size_word, line_count)) == OK);
        if ((response = is_writed(input, size_word, line_count)) == OK);
        if ((response = is_writec(input, size_word, line_count)) == OK);
        if ((response = is_attribution(input, size_word, line_count)) == OK);
        if ((response = is_distinction(input, size_word, line_count)) == OK);
        if ((response = is_great_than_equal(input, size_word, line_count)) == OK);
        if ((response = is_less_than_equal(input, size_word, line_count)) == OK);
        if ((response = is_great(input, size_word, line_count)) == OK);
        if ((response = is_less(input, size_word, line_count)) == OK);
        if ((response = is_equal(input, size_word, line_count)) == OK);
    } else {
        response = INVALID;
    }

    return response;
}

void validate_end_of_word(char read_chr, int lineCount) {
    switch (read_chr) {
        case ' ': {
            check_words(special_word, (int)strlen(special_word), lineCount);
            free_string_special_word();
            break;
        }

        case '\n': {
            check_words(special_word, (int)strlen(special_word), lineCount);
            free_string_special_word();
            lineCount++;
            break;
        }

        case EOF: {
            check_words(special_word, (int)strlen(special_word), lineCount);
            free_string_special_word();
            break;
        }
    }
}

void is_eof_or_new_line(int read_chr) {
    if ((int)read_chr != 13 && read_chr != EOF) {
        word[(int) strlen(word)] = read_chr;
    }
}

void is_special_chars(char input_word, int lineCount) {
    switch (input_word) {
        case ':': {
            special_word[(int) strlen(special_word)] = input_word;
            break;
        }

        case '>': {
            special_word[(int) strlen(special_word)] = input_word;
            break;
        }

        case '<': {
            special_word[(int) strlen(special_word)] = input_word;
            break;
        }

        case '=': {
            special_word[(int) strlen(special_word)] = input_word;
            break;
        }

        default:
            if (strlen(special_word) == 2) {
                validate_end_of_word(input_word, lineCount);
            } else if (strlen(special_word) == 1) {
                validate_end_of_word(input_word, lineCount);
            }
    }
}

# endif