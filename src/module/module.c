/* @file
 *
 *  preprocessor main source file
 * 
*/
#include "preprocessor.h"

//todo
typedef struct {
    const char* /* //todo restrict? */ src;
    const char* dst;
} pp_define_t;

/*
 * preprocess single line, by tokens
*/
void analyze(char* line) {
    char* token = strtok(line, " ");
    const pp_directive* directive = NULL;
    pp_directive_mode mode = DM_NOTHING;

    char* architecture;

    while (token != NULL) {
        switch (mode) {
            case DM_ARCHITECTURE: {
                architecture = malloc(strlen(token)); //todo free?
                strcpy(architecture, token);
                break;
            }
            case DM_A_INSTRUCTIOM: {
                puts(token);
                break;
            }
            case DM_B_INSTRUCTION: {
                puts(token);
                break;
            }
            case DM_INCLUDE: {
                break;
            }
            case DM_A_DEFINE: {
                break;
            }
            case DM_B_DEFINE: {
                break;
            }
            case DM_NOTHING:
            default: {
                directive = validate_directive(token, strlen(token));
                if (directive != NULL) {
                    switch (directive->code) {
                        case DC_ARCHITECTURE: {
                            puts("architecture");
                            mode = DM_ARCHITECTURE;
                            break;
                        }
                        case DC_INSTRUCTION: {
                            puts("instruction");
                            mode = DM_A_INSTRUCTIOM;
                            break;
                        }
                        case DC_DEFINE: {
                            puts("define");
                            mode = DM_A_DEFINE;
                            break;
                        }
                        case DC_INCLUDE: {
                            puts("include");
                            mode = DM_INCLUDE;
                            break;
                        }
                        default: {
                            printf("else \"%s\"\n", token);
                            mode = DM_NOTHING;
                            break;
                        }
                    }
                }
            }
        }
        token = strtok(NULL, " ");
    }
}

/*
 * preprocess @arg input and save the result in @arg output 
*/
void preprocess(FILE* input, FILE* output) {
    size_t size;
    char* line;
    do {
        size = lsize(input);
        size += 1;
        line = (char*) malloc(size);
        fgets(line, size, input);
        puts(line);
        fgetc(input);
        //todo replace line by define tables
        analyze(line);
        size -= 1;
        free(line);
    } while (size != EOF);
}