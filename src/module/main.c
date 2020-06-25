/* @file
 *
 * preprocessor main function
*/
#include "ustring.h"

int main() {
    char a[] = "define AAA BBB xxx YYY";
    char b[] = " ";
    int i;
    bdarray_string result = split(a, b);
    printf("[");
    for (i = 0; i < result.length; i++) {
        printf("%s, ", result.array[i]);
        free(result.array[i]);
    }
    printf("]\n");
    return 0;
}