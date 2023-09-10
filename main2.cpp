#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

const int MAX_LINE = 5;
const int MAX_LEN = 64;

//одномерный массив символов (каждая строка хранится друг за другом)

int main() {
    FILE *file = fopen("txt.txt", "r");
    if (file == NULL) {
        printf ("Can not open file");
        return 1;
    }

    char *text = (char *)calloc(MAX_LINE * MAX_LEN, sizeof(char));
    if (text == NULL) {
        printf ("Can not allocate memory");
        fclose(file);
        return 1;
    }

    size_t i = 0;

    while (i < MAX_LINE && fgets(&text[i * MAX_LEN], (int)MAX_LEN, file) != NULL) {
        i++;
    }

    fclose(file);

    for (size_t j = 0; j < i; j++) {
        printf("%s", &text[j * MAX_LEN]);
    }

    free(text);
    return EXIT_SUCCESS;
}
