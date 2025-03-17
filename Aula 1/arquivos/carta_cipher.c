#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Uso: %s input.txt output.txt bigrama_ou_trigrama substituto\n", argv[0]);
        return 1;
    }

    FILE *ifile = fopen(argv[1], "r");
    FILE *ofile = fopen(argv[2], "w");

    if (!ifile || !ofile) {
        printf("Erro ao abrir arquivos.\n");
        return 1;
    }

    char prev1 = '\0', prev2 = '\0';  // Armazena os caracteres anteriores
    char ch;
    int match_len = strlen(argv[3]); // Tamanho do padrão a ser substituído

    while (fscanf(ifile, "%c", &ch) != EOF) {
        // Verifica se os caracteres anteriores formam o bigrama/trigrama desejado
        if ((match_len == 2 && prev1 == argv[3][0] && ch == argv[3][1]) ||
            (match_len == 3 && prev2 == argv[3][0] && prev1 == argv[3][1] && ch == argv[3][2])) {
            fprintf(ofile, "%s", argv[4]); // Escreve o substituto no arquivo
            prev1 = '\0';  // Reseta o estado para evitar substituições encadeadas
            prev2 = '\0';
        } else {
            // Se um caractere antigo faz parte de um bigrama/trigrama incompleto, escrevemos ele antes
            if (prev1 != '\0') {
                fprintf(ofile, "%c", prev1);
            }
            prev2 = prev1;
            prev1 = ch;
        }
    }

    if (prev1 != '\0') fprintf(ofile, "%c", prev1);
    
    fclose(ifile);
    fclose(ofile);
    
    printf("Substituição concluída!\n");
    return 0;
}
