#include <stdio.h>
#include <stdlib.h>

/*
    Preciso calcular valores para a e b, onde A = q^a mod p 
    e B = q^b mod p, e depois calcular o valor de B^a mod p
    e A^b mod p, e comparar os dois resultados.
    Se forem iguais, então a e b são os valores que eu procuro.
    Se não forem iguais, então eu preciso continuar procurando.
    
*/

unsigned long square_mul(unsigned long q, unsigned long x, unsigned long n) {
    unsigned long r = 1;

    while (x > 0){
        if ((x%2) == 1){
            r = (r * q) % n;
        }
        x /= 2;
        q = (q * q) % n;
    }

    return r;
}

unsigned long find(unsigned long p, unsigned long q, unsigned long X){
    unsigned long result; 
    unsigned long key = 1;
    for (key = 1; key < p; key++) {
        result = square_mul(q, key, p);
        if (result == X) return key;
    }
    printf("Key not found\n");
    return 0;
}


int main (int argc, char *argv[]){
    if(argc != 5) {
        printf("Usage: %s <p> <q> <A> <B>\n", argv[0]);
        return 1;
    }

    unsigned long p = strtoul(argv[1], NULL, 10);
    unsigned long q = strtoul(argv[2], NULL, 10);
    unsigned long A = strtoul(argv[3], NULL, 10);
    unsigned long B = strtoul(argv[4], NULL, 10);

    printf("p = %lu\n", p);
    printf("q = %lu\n", q);
    printf("A = %lu\n", A);
    printf("B = %lu\n", B);

    
    unsigned long a = find(p, q, A);
    unsigned long b = find(p, q, B);

    printf("a = %lu\n", a);        
    printf("b = %lu\n", b);
    
    if (a == 0 || b == 0) {
        printf("Key not found\n");
        return 1;
    }   

    unsigned long chaveA = square_mul(B, a, p);
    unsigned long chaveB = square_mul(A, b, p); 

    if (chaveA == chaveB) {
        printf("Key found: %lu\n", chaveA);
    } else {
        printf("Key not found\n");
    }
    return 0;   
}

