#include <stdio.h>

int main() {
    int a[5];
    int b[5];

    for(int i = 0; i<5; ++i) {
        a[i] = 1;
    }

    for(int i = 0; i<5; ++i) {
        b[i] = 1;
    }

    for(int i = 0; i<5; ++i) {
        printf("%d and %d\n", a[i], b[i]);
    }
}