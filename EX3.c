#include <stdio.h>
#include <stdlib.h>

void compactFile(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (in == NULL || out == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char ch;

    while ((ch = fgetc(in)) != EOF) {
        if (ch != ' ' && ch != '\n') {
            fputc(ch, out);
        }
    }

    fclose(in);
    fclose(out);
}

int main() {
    const char *inputFile = "input.txt";
    const char *outputFile = "output.txt";

    compactFile(inputFile, outputFile);

    printf("File compacted successfully. Result saved in %s\n", outputFile);
    return 0;
}
