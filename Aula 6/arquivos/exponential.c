#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long naive(unsigned long q, unsigned long x, unsigned long n) {
    unsigned long r = 1;
    int i;

    for (i = 0; i < x; i++){r = (r * q);}
    
    return r % n;
}

unsigned long improved(unsigned long q, unsigned long x, unsigned long n) {
    unsigned long r = 1;
    int i;

    for (i = 0; i < x; i++){r = (r * q) % n;}
    
    return r;

}

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


int main (int argc, char *argv[]) {
    if(argc != 4) {
        printf("Usage: %s <q> <x> <n>\n", argv[0]);
        return 1;
    } 
    
    unsigned long q = strtoul(argv[1], NULL, 10);
    unsigned long x = strtoul(argv[2], NULL, 10);
    unsigned long n = strtoul(argv[3], NULL, 10);

    clock_t start, end;
    
    start = clock();
    printf("naive(%lu, %lu, %lu) = %lu\n", q, x, n, naive(q, x, n));
    end = clock();
    double time_spent_naive = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", time_spent_naive);

    start = clock();
    printf("improved(%lu, %lu, %lu) = %lu\n", q, x, n, improved(q, x, n));
    end = clock();
    double time_spent_improved = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", time_spent_improved);

    start = clock();
    printf("square_mul(%lu, %lu, %lu) = %lu\n", q, x, n, square_mul(q, x, n));
    end = clock();
    double time_spent_square_mul = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", time_spent_square_mul);

    return 0;
}

