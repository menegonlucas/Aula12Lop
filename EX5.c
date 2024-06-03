#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void encryptFile(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (in == NULL || out == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int key = 3; // Chave de criptografia (shift de 3 posições)

    char ch;

    while ((ch = fgetc(in)) != EOF) {
        if (isalpha(ch)) {
            if (islower(ch)) {
                ch = 'a' + (ch - 'a' + key) % 26;
            } else if (isupper(ch)) {
                ch = 'A' + (ch - 'A' + key) % 26;
            }
        }
        fputc(ch, out);
    }

    fclose(in);
    fclose(out);
}

int main() {
    const char *inputFile = "input.txt";
    const char *outputFile = "encrypted.txt";

    encryptFile(inputFile, outputFile);

    printf("File encrypted successfully. Result saved in %s\n", outputFile);
    return 0;
}

