#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

typedef struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void updateFrequency(WordFrequency *words, int *numWords, const char *word) {
    for (int i = 0; i < *numWords; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].frequency++;
            return;
        }
    }
    strcpy(words[*numWords].word, word);
    words[*numWords].frequency = 1;
    (*numWords)++;
}

void countWordFrequency(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (in == NULL || out == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    WordFrequency words[1000];
    int numWords = 0;

    char word[MAX_WORD_LENGTH];

    while (fscanf(in, "%s", word) == 1) {
        // Convertendo a palavra para minúsculas
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }
        updateFrequency(words, &numWords, word);
    }

    for (int i = 0; i < numWords; i++) {
        fprintf(out, "%s: %d\n", words[i].word, words[i].frequency);
    }

    fclose(in);
    fclose(out);
}

int main() {
    const char *inputFile = "input.txt";
    const char *outputFile = "output.txt";

    countWordFrequency(inputFile, outputFile);

    printf("Word frequency counted successfully. Result saved in %s\n", outputFile);
    return 0;
}
