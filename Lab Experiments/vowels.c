#include <stdio.h>

int main() {
    char sentence[1000];
    int i, count = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    for (i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == 'a' || sentence[i] == 'e' ||
            sentence[i] == 'i' || sentence[i] == 'o' ||
            sentence[i] == 'u' || sentence[i] == 'A' ||
            sentence[i] == 'E' || sentence[i] == 'I' ||
            sentence[i] == 'O' || sentence[i] == 'U') {
            count++;
        }
    }

    printf("Number of vowels: %d\n", count);

    return 0;
}