#include <stdio.h>
#include <stdlib.h>

int main () {
   int i = 0, sum1 = 0, sum2 = 0;
   char *nome = (char *)malloc(256 * sizeof(char));
   printf("Digite o seu nome: ");
   scanf ("%s" , nome);
   while (nome[i] != '\0') {
      sum1 += nome[i];
      sum2 += (nome[i] * nome[i]);
      i++;
   }
   printf ("Calcula a entrada: %x%x (S-Box)\n", sum1 % 16, sum2 % 16);
   free(nome);
   return 0;
}
