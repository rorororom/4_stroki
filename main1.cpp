#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

const int MAX_LEN = 64;
const int MAX_LINE = 5;

int main() {
    const char* File = "txt.txt";
    struct stat st;

    size_t size = 0;
    if (stat(File, &st) == 0) {
        size = st.st_size;
        printf("%lu\n", size);
    }
    else
    {
        printf ("stat");
        return 1;
    }

    FILE* file = fopen(File, "r");

    if (file == NULL)
    {
        perror("fopen");
        return 1;
    }

    char text[MAX_LINE][MAX_LEN]= {};

    for (int i = 0; i < MAX_LINE; i++) {
        if (fgets(text[i], MAX_LEN, file) == NULL) {
            printf ("error file");
            break;
        }
    }

    fclose(file);

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n",text[i]);
    }
}
