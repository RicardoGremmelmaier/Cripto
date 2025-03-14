#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main (int argc, char *argv[]) {

   if (argc < 4) { 
      printf("use: %s input.txt output.txt [enc/dec] shift\n", argv[0]); 
      return 1; 
   }

   FILE *ifile = fopen (argv[1], "r"); /*input file!*/
   FILE *ofile = fopen (argv[2], "w"); /*output file!*/
   char *option = argv[3]; /*Opção: enc (cifrar) e dec (decifrar)!*/
   int shift = atoi(argv[4]); /*Deslocamento*/

   /*a = 0, b = 1, ..., z = 25.*/
   int alphabet_size = 26;

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
         /*ch - 'a' equivale a transformar {a, b, c, ..., z} para o intervalo {0, 1, ..., 25}!*/
         code = ((ch - 'a') + shift) % alphabet_size + 'a';
      }   
      else if (strcmp(option,"dec") == 0) {
         /*ch - 'a' equivale a transformar {a, b, c, ..., z} para o intervalo {0, 1, ..., 25}!*/
         code = ((ch - 'a') - shift) < 0? ((ch - 'a') - shift) + 26 % alphabet_size + 'a' : ((ch - 'a') - shift) % alphabet_size + 'a';
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

