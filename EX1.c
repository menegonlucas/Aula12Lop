#include <stdio.h>
#include <stdlib.h>

void mergeFiles(const char *file1, const char *file2, const char *mergedFile) {
    FILE *fp1 = fopen(file1, "r");
    FILE *fp2 = fopen(file2, "r");
    FILE *fp3 = fopen(mergedFile, "w");

    if (fp1 == NULL || fp2 == NULL || fp3 == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line1[256];
    char line2[256];

    while (fgets(line1, sizeof(line1), fp1) != NULL && fgets(line2, sizeof(line2), fp2) != NULL) {
        fputs(line1, fp3);
        fputs(line2, fp3);
    }

    // If one file is longer than the other, continue copying the remaining lines
    while (fgets(line1, sizeof(line1), fp1) != NULL) {
        fputs(line1, fp3);
    }
    while (fgets(line2, sizeof(line2), fp2) != NULL) {
        fputs(line2, fp3);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}

int main() {
    const char *file1 = "file1.txt";
    const char *file2 = "file2.txt";
    const char *mergedFile = "merged.txt";

    mergeFiles(file1, file2, mergedFile);

    printf("Files merged successfully into %s\n", mergedFile);
    return 0;
}
