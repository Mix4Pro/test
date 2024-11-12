#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int isError = 0;

int main() {
    int n, data[NMAX];
    if (input(data, &n) != 0) {
        printf("n/a");
        return 0;
    }
    squaring(data, n);
    output(data, n);

    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 || *n > 10 || *n <= 0) {
        return 1;
    }
    for (int p = 0; p < *n; p++) {
        if (scanf("%d", &a[p]) != 1 || *n > 10) {
            return 1;
        }
    }

    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] *= a[i];
    }
}