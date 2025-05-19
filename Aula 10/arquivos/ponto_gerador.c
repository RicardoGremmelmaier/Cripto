#include <stdio.h>

#define PRIMO 17
#define A 2
#define B 3

typedef struct {
    int x;
    int y;
    int infinito; 
} Ponto;

int inverso_mod(int a, int p) {
    int t = 0, newt = 1;
    int r = p, newr = a;

    while (newr != 0) {
        int q = r / newr;
        int temp = newt;
        newt = t - q * newt;
        t = temp;
        temp = newr;
        newr = r - q * newr;
        r = temp;
    }

    if (r > 1) return -1;
    if (t < 0) t += p;
    return t;
}

Ponto soma(Ponto P1, Ponto P2) {
    Ponto R;

    if (P1.infinito) return P2;
    if (P2.infinito) return P1;

    if (P1.x == P2.x && P1.y == P2.y) {
        int s_num = (3 * P1.x * P1.x + A) % PRIMO;
        int s_den = inverso_mod(2 * P1.y, PRIMO);
        if (s_den == -1) {
            R.infinito = 1;
            return R;
        }
        int s = (s_num * s_den) % PRIMO;

        R.x = (s * s - 2 * P1.x + PRIMO) % PRIMO;
        R.y = (s * (P1.x - R.x) - P1.y + PRIMO) % PRIMO;
        R.x = (R.x + PRIMO) % PRIMO;
        R.y = (R.y + PRIMO) % PRIMO;
        R.infinito = 0;
        return R;
    }

    if (P1.x == P2.x) {
        R.infinito = 1;
        return R;
    }

    int s_num = (P2.y - P1.y + PRIMO) % PRIMO;
    int s_den = inverso_mod((P2.x - P1.x + PRIMO) % PRIMO, PRIMO);
    if (s_den == -1) {
        R.infinito = 1;
        return R;
    }
    int s = (s_num * s_den) % PRIMO;

    R.x = (s * s - P1.x - P2.x + PRIMO) % PRIMO;
    R.y = (s * (P1.x - R.x) - P1.y + PRIMO) % PRIMO;
    R.x = (R.x + PRIMO) % PRIMO;
    R.y = (R.y + PRIMO) % PRIMO;
    R.infinito = 0;
    return R;
}

Ponto multiplica(Ponto P0, int k) {
    Ponto R = {0, 0, 1}; 
    while (k > 0) {
        if (k % 2 == 1) {
            R = soma(R, P0);
        }
        P0 = soma(P0, P0);
        k /= 2;
    }
    return R;
}

int main() {
    Ponto G = {5, 1, 0}; 
    printf("Ponto gerador G = (%d, %d)\n\n", G.x, G.y);

    for (int k = 1; k <= PRIMO + 1; k++) {
        Ponto R = multiplica(G, k);
        if (R.infinito) {
            printf("%dG = Ponto no infinito\n", k);
        } else {
            printf("%dG = (%d, %d)\n", k, R.x, R.y);
        }
    }

    return 0;
}
