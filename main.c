#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include ".\lib\words.h"
#include ".\lib\dynamic.h"


int main(void) {
    extern char *output_filename;
    extern char *word;
    char read_chr = '\0';
    char input_filename[12] = "source.txt";
    FILE *source_file;
    int lineCount = 1, columnCount = 1;

    source_file = fopen(input_filename, "r");

    // Read file loop
    do {
        read_chr = fgetc(source_file);

        // Resize string dynamically
        resize_string();

        switch (read_chr) {
            case ' ': {
                if ((int)strlen(word) > 0) {
                    int r = check_words(word, (int)strlen(word), lineCount);
                    free_string();
                }
                break;
            }

            case '\n': {
                int c = check_words(word, (int)strlen(word), lineCount);
                free_string();
                lineCount++;
                columnCount = 1;
                break;
            }

            case EOF: {
                int u = check_words(word, (int)strlen(word),lineCount);
                free_string();
                break;
            }

            default: {
                if ((int)read_chr != 13 && read_chr != EOF) {
                    word[(int)strlen(word)] = read_chr;
                }
                break;
            }
        }

        columnCount++;

    } while (read_chr != EOF);

    fclose(source_file);

    return (EXIT_SUCCESS);
}
