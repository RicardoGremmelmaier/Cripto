#include <stdio.h>
#include <string.h>

void KSA (unsigned char *K, int M, unsigned char S[], int N) {
   int i, j = 0;
   for (i = 0; i < N; i++){
      S[i] = i;
   }

   for (i = 0; i < N; i++){
      j = (j + S[i] + K[i % M]) % N;
      unsigned char temp = S[i];
      S[i] = S[j];
      S[j] = temp;
   }
}

unsigned char PRGA (int *i, int *j, unsigned char S[], int N) {
   *i = (*i + 1) % N;
   *j = (*j + S[*i]) % N;
   unsigned char temp = S[*i]; 
   S[*i] = S[*j];   
   S[*j] = temp;
   return S[(S[*i] + S[*j]) % N];
}

int main (int argc, char *argv[]) {
   FILE *fin  = fopen (argv[1], "r");
   char *chave = argv[2];
   FILE *fout = fopen (argv[3], "w");
   int N = 256;
   unsigned char S[N];

   int key_size = strlen(chave);
   /* Inicializa o KSA */
   KSA(chave, key_size, S, N);

   int k = 0;
   int i = 0, j = 0;
   while (!feof(fin)) {
      char c, code;
      fscanf (fin, "%c", &c);
      /*Nao modifique o intervalo do caractere em c, nem trate espacos ou nova linha!*/ 
      /* pegar cada char do file in e realizar o xor com o valor retornado do PRGA*/
      if (c == EOF) { 
         break;  
      } else {
         code = c ^ PRGA(&i, &j, S, N);
      }
      fprintf (fout, "%c", code);   
   }
   fclose(fin);
   fclose(fout);
   return 0;
}
