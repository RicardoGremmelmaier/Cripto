#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main (int argc, char *argv[]) {

    if (argc < 4) { 
       printf("use: %s input.txt output.txt [enc/dec] key\n", argv[0]); 
       return 1; 
    }
 
    FILE *ifile = fopen (argv[1], "r"); /*input file!*/
    FILE *ofile = fopen (argv[2], "w"); /*output file!*/
    char *option = argv[3]; /*Opção: enc (cifrar) e dec (decifrar)!*/
    char *key = argv[4]; /*a chave a ser utilizada para cifrar ou decifrar*/
 
    /*a = 0, b = 1, ..., z = 25.*/
    int alphabet_size = 26;
    int key_size = strlen(key);
    int key_index = 0;

    // Criação do quadrado de Vigènere (DESCOMENTAR se for utilizar o quadrado para cifrar e decifrar)
    // char vigenere_square[alphabet_size][alphabet_size];
    // for (int i = 0; i < alphabet_size; i++) {
    //     for (int j = 0; j < alphabet_size; j++) {
    //         vigenere_square[i][j] = ((i + j) % alphabet_size) + 'a';
    //     }
    // }

    while (!feof(ifile)) {
        char ch, code;
        fscanf(ifile,"%c",&ch);
        if (ch == EOF) { 
            break; 
        }
        else if (ch == ' ') { 
            code = ' '; 
        }   
        else if (ch == '\n') { 
            code ='\n'; 
        }
        else if (strcmp(option,"enc") == 0) {
            /* Usando o quadrado de Vigènere para cifrar */

            // code = vigenere_square[ch - 'a'][key[key_index] - 'a'];
            // key_index = (key_index + 1) % key_size;

            /*Sem utilizar o quadrado para cifrar */

            /*O quadrado funciona como variadas cifras de César, ou seja, basta somar o valor da letra da mensagem com o valor da letra da chave
              e ai não faz necessário o uso da tabela, para esse alfabeto.
            */ 
           
            code = (((ch - 'a' + alphabet_size)% alphabet_size + (key[key_index] - 'a' + alphabet_size) % alphabet_size) + alphabet_size) % alphabet_size + 'a';
            key_index = (key_index + 1) % key_size;
        }   
        else if (strcmp(option,"dec") == 0) {
            /* Usando o quadrado de Vigènere para decifrar */
            //Percorro a linha da letra da chave buscando encontrar o char criptografado, assim pego o valor inicial atraves de um contador

            // for (int i = 0; i < alphabet_size; i++) {
            //     if (vigenere_square[key[key_index] - 'a'][i] == ch) {
            //         code = i + 'a';
            //         key_index = (key_index + 1) % key_size;
            //         break;
            //     }
            // }

            /* Sem utilizar o quadrado para decifrar */

            /* De forma similar, basta subtrair o valor da letra da mensagem com o valor da letra da chave
               e ai não faz necessário o uso da tabela, para esse alfabeto.
            */

            code = (((ch - 'a' + alphabet_size) % alphabet_size - (key[key_index] - 'a' + alphabet_size) % alphabet_size) + alphabet_size) % alphabet_size + 'a';
            key_index = (key_index + 1) % key_size;

        }
        else {
            printf("error: function \"%s\" does not exist!\n", option);
            return 1;  
        }
        fprintf(ofile,"%c",code);
    }
  
    fclose(ifile);
    fclose(ofile);
 
    return 0;
 }