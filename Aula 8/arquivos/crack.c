#include <stdio.h>
#include <math.h>

typedef long long int ulong;

ulong square_multiply (ulong q, ulong x, ulong n){
   ulong r = 1;
   while (x > 0) {
      if ((x % 2) == 1) {
         r = (r * q) % n; /*Multiply (MUL)*/
         if (r < 0) { printf("overflow"); }
      }
      x /= 2;
      q = (q * q) % n; /*Square (SQ)*/
      if (q < 0) { printf("overflow"); }
   }
   return r;
}

ulong euclides_estendido (ulong m, ulong n, ulong *a, ulong *b) {
  ulong d;
  if (n == 0) {
    *a = 1;
    *b = 0;
    return m;
  }
  else {
    d = euclides_estendido (n, m % n, a, b);
    ulong e = *a, f = *b;
    *a = f;
    *b = e - f*(m/n);
    return d;
  }
}

int main () {

   ulong e = 131;
   ulong s_x1 = 6292;
   ulong s_x2 = 4768;
   ulong s_x3 = 1424;
   ulong n = 9797;
   

   /*End key-generation*/

   long long x1 = square_multiply (s_x1, e, n);
   long long x2 = square_multiply (s_x2, e, n);
   long long x3 = square_multiply (s_x3, e, n);
   printf("x1 = %lld\n", x1);
   printf("x2 = %lld\n", x2);
   printf("x3 = %lld\n", x3);
   return 0;
}
