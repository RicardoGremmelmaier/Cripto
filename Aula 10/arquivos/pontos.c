#include <stdio.h>

int mod_exp(int base, int exp, int mod) {
    int result = 1;
    base %= mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}

int main() {
    int a = 1;       
    int b = 1;      
    int p = 7;      

    printf("Curva elíptica: y^2 ≡ x^3 + %dx + %d mod %d\n", a, b, p);
    printf("Pontos na curva:\n");

    int count = 0;

    for (int x = 0; x < p; x++) {
        int rhs = (mod_exp(x, 3, p) + a * x + b) % p;
        if (rhs < 0) rhs += p;

        for (int y = 0; y < p; y++) {
            if ((mod_exp(y, 2, p)) % p == rhs) {
                printf("(%d, %d)\n", x, y);
                count++;
            }
        }
    }

    printf("Ponto no infinito: O\n");
    count++;

    printf("\nTotal de pontos: %d\n", count);

    return 0;
}
