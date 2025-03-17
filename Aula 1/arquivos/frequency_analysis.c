#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26
#define NUMBER_SIZE 10
#define MAX_PAIRS 1000
#define MAX_TRIOS 1000

typedef struct {
    char pair[3];
    int count;
} PairFreq;

typedef struct {
    char trio[4];
    int count;
} TrioFreq;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s input.txt output.txt\n", argv[0]);
        return 1;
    }

    FILE *ifile = fopen(argv[1], "r");
    FILE *ofile = fopen(argv[2], "w");

    if (!ifile || !ofile) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    int frequency_letters[ALPHABET_SIZE] = {0};
    int frequency_numbers[NUMBER_SIZE] = {0};

    PairFreq pairs[MAX_PAIRS];
    int pair_count = 0;

    TrioFreq trios[MAX_TRIOS];
    int trio_count = 0;

    char prev = '\0', prev2 = '\0', ch;
    
    while (fscanf(ifile, "%c", &ch) != EOF) {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            if (ch >= 'A' && ch <= 'Z') {
                frequency_letters[ch - 'A']++;
            } else if (ch >= '0' && ch <= '9') {
                frequency_numbers[ch - '0']++;
            }

            /* Analisar bigramas */
            if (prev != '\0') {
                char temp[3] = {prev, ch, '\0'};
                int found = 0;
                for (int i = 0; i < pair_count; i++) {
                    if (strcmp(pairs[i].pair, temp) == 0) {
                        pairs[i].count++;
                        found = 1;
                        break;
                    }
                }
                if (!found && pair_count < MAX_PAIRS) {
                    strcpy(pairs[pair_count].pair, temp);
                    pairs[pair_count].count = 1;
                    pair_count++;
                }
            }

            /* Analisar trigramas */
            if (prev2 != '\0') {
                char temp[4] = {prev2, prev, ch, '\0'};
                int found = 0;
                for (int i = 0; i < trio_count; i++) {
                    if (strcmp(trios[i].trio, temp) == 0) {
                        trios[i].count++;
                        found = 1;
                        break;
                    }
                }
                if (!found && trio_count < MAX_TRIOS) {
                    strcpy(trios[trio_count].trio, temp);
                    trios[trio_count].count = 1;
                    trio_count++;
                }
            }

            prev2 = prev;
            prev = ch;
        }
    }

    /* Escrever frequência de letras e números */
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        fprintf(ofile, "%c: %d\n", i + 'A', frequency_letters[i]);
    }
    for (int i = 0; i < NUMBER_SIZE; i++) {
        fprintf(ofile, "%c: %d\n", i + '0', frequency_numbers[i]);
    }

    /* Escrever frequência de bigramas */
    fprintf(ofile, "\nBigramas:\n");
    for (int i = 0; i < pair_count; i++) {
        fprintf(ofile, "%s: %d\n", pairs[i].pair, pairs[i].count);
    }

    /* Escrever frequência de trigramas */
    fprintf(ofile, "\nTrigramas:\n");
    for (int i = 0; i < trio_count; i++) {
        fprintf(ofile, "%s: %d\n", trios[i].trio, trios[i].count);
    }

    fclose(ifile);
    fclose(ofile);

    return 0;
}
