#include <stdio.h>
#include <string.h>

void KSA (unsigned char *K, int M, unsigned char S[], int N) {
}

unsigned char PRGA (int *i, int *j, unsigned char S[], int N) {
}

int main (int argc, char *argv[]) {
   FILE *fin  = fopen (argv[1], "r");
   char *chave = argv[2];
   FILE *fout = fopen (argv[3], "w");
   int N = 256;
   unsigned char S[N];
   /*????*/ 
   int k = 0;
   int i = 0, j = 0;
   while (!feof(fin)) {
      char c;
      fscanf (fin, "%c", &c);
      /*Nao modifique o intervalo do caractere em c, nem trate espacos ou nova linha!*/ 
      /*????*/ 
   }
   fclose(fin);
   fclose(fout);
   return 0;
}
