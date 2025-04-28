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

   /*Key generation*/

   /*Choosing two primes:*/
   printf("Completar parte de geração de chaves!\n");

   ulong p = 17;
   ulong q = 11;
   ulong e = 7;
   ulong x = 88;

   ulong n = p * q;
   ulong phi = (p-1)*(q-1);

   ulong a, b;
   ulong mdc = euclides_estendido (phi, e, &a, &b);

   printf("MDC: %lld\n", mdc);

   while (b < 0) { b += phi; }

   ulong d = b % phi;

   /*End key-generation*/

   printf ("Chave pública: (%lld,%lld)\n", e, n);
   printf ("Chave privada: (%lld,%lld)\n", d, n);
   long long y = square_multiply (x, e, n);
   printf ("O dado %lld cifrado com RSA é: %lld\n", x, square_multiply (x, e, n));
   printf ("O dado %lld decifrado com RSA é: %lld\n", y, square_multiply (y, d, n));
   return 0;
}
