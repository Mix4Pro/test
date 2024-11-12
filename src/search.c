#include <stdio.h>
#include <math.h>

int input(int *a , int *n);
int mean(int *a, int n);
int find_biggest_even(int *a , int n , int *num);
double variance (int *a , int n);
void show(int *a , int n , int num);

int main (void){
    int n , data[10] , biggest_even = 0;

    if(input(data,&n) == 0){
        printf("n/a");
        return 0;
    }
    find_biggest_even(data, n , &biggest_even);
    show(data, n , biggest_even);
    return 0;
}

int input(int *a , int *n){
    if(scanf("%d", n) != 1 || *n < 0 || *n > 10)
        return 0;
    for(int i = 0; i < *n; i++){
        if(scanf("%d", &a[i]) != 1)
            return 0;
    }
}

int mean(int *a, int n){
    int sum;
    for(int i = 0; i < n; i++)
        sum += a[i];
    return sum / n;
}

int find_biggest_even(int *a , int n , int *num){
    for(int i = 0 ; i < n ; i++){
        if(a[i] % 2 == 0)
            *num = a[i];
    }
}

double variance (int *a , int n){
    int square_sum;
    int total = mean(a,n);
    for(int i = 0; i < n; i++)
        square_sum += (a[i] - total) * (a[i] - total);
    return square_sum / n;

}

void show(int *a , int n , int num){
    if(num < mean( a , n ) && num > 3 * sqrt(variance( a , n )) && num == 0)
        printf("0");
    printf("%d", num );
}