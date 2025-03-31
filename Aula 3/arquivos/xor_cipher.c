#include <stdio.h>
#include <string.h>
#include "aleatorio.h"


int main (int argc, char *argv[]) {
   FILE *fin  = fopen (argv[1], "r");
   FILE *fout = fopen (argv[2], "w");

   while (!feof(fin)) {
        char c, code;
        fscanf (fin, "%c", &c);
        if (c == EOF) { 
            break;
        } else if (c == '\n') {
            code = c;
        } else if (c == ' ') {
            code = c;
        } else {
            int random = aleatorio() % 26;
            code = ((c - 'a') ^ random) + 'a';
        }
      fprintf (fout, "%c", code);   
   }
   fclose(fin);
   fclose(fout);
   return 0;
}
