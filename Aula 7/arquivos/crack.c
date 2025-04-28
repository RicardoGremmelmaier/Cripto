#include <math.h>  
#include <stdio.h> 

typedef long long int ulong;

ulong trial_division_sqrt(ulong n) {
    ulong sqrt_n = (ulong)sqrt((double)n);
    ulong x;
    for(x=2; x <= sqrt_n; x++) {
        if ((n % x) == 0) {
            printf("%lld é divisível por %lld multiplicado por %lld\n", n, x, n/x);
            return x;
        }
    }
}

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

int main() {
    ulong n = 6326693;
    
    ulong e = 5;
    ulong p = trial_division_sqrt(n);
    ulong q = n / p;
    ulong y = 1632643;

    ulong phi = (p-1)*(q-1);

    ulong a, b;
    ulong mdc = euclides_estendido (phi, e, &a, &b);

    printf("MDC: %lld\n", mdc);

    while (b < 0) { b += phi; }

    ulong d = b % phi;

    long long x = square_multiply (y, d, n);

    printf("x: %lld\n", x);

    return 0;
}