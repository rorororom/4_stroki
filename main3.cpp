#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

const int MAX_LINE = 5;
const int MAX_LEN = 64;

//двумерный массив указателей, элементы являются указателями на строки

int main(void) {
    FILE *file = fopen ("txt.txt", "r");
    if (file == NULL) {
        printf ("Can not open file");
        return 1;
    }

    char **text = (char **)calloc(MAX_LINE, sizeof(char *));
    if (text == NULL) {
        printf ("Can not allocate memory");
        fclose (file);
        return 1;
    }

    char buffer[MAX_LEN * MAX_LINE] = {};

    size_t i = 0;

    while (i < MAX_LINE*MAX_LEN && fgets(buffer, sizeof(buffer), file) != NULL) {
        text[i] = (char *)malloc(MAX_LINE * sizeof(char));
        if (text[i] == NULL) {
            printf ("Can not allocate memory");
            break;
        }

        strcpy(text[i], buffer);
        i++;
    }

    fclose(file);

    for (size_t j = 0; j < i; j++) {
        printf("%s", text[j]);
        free(text[j]);
    }

    free(text);
}
