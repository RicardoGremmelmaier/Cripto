#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s <a> <n>\n", argv[0]);
        return 1;
    } 

    int a = atoi(argv[1]);
    int n = atoi(argv[2]);

    if (a >= 0){
        printf("%d mod %d = %d\n", a, n, a % n);
        return 0;
    } 

    int positive = -a;
    int tmp = n;
    
    while(tmp <= positive){
        tmp += n;
    }

    int result = tmp - positive;

    printf("%d mod %d = %d\n", a, n, result);
    return 0;
}

