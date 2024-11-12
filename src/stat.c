#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main()
{
    int n, data[NMAX];
    if(input(data,&n) == 0){
        output(data, n);
        printf("\n");
        output_result(max(data, n),
                  min(data, n),
                  mean(data, n),
                  variance(data, n));

    }else{
        printf("n/a");
    }

    return 0;
}

int input(int *a , int *n){
    if(scanf("%d", n) != 1 || *n <= 0 || *n > 10)
        return 1;

    for(int i = 0; i < *n; i++){
        if(scanf("%d", &a[i]) != 1){
            return 1;
        }
    }
    return 0;
}

void output(int *a , int n){
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int max(int *a , int n){
    int temp_max = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] > temp_max){
            temp_max = a[i];
        }
    }
    return temp_max;
}

int min (int *a , int n){
    int temp_min = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] < temp_min){
            temp_min = a[i];
        }
    }
    return temp_min;
}

double mean(int *a , int n){
    double sum = 0.0;
    for(int i = 0; i < n; i++){
        sum += a[i];
    }
    return sum / n;
    
}

double variance (int *a , int n){
    double sum = 0, total , square_sum = 0.0;
    total = mean(a,n);

    for(int i = 0; i < n; i++){
        sum += a[i];
    }

    for(int i = 0; i < n; i++){
        square_sum += (a[i] - total) * (a[i] - total);
    }

    return square_sum / n;
}

void output_result (int max_v , int min_v , double mean_v , double variance_v ){
    printf("%d %d %.6f %.6f", max_v , min_v , mean_v , variance_v);
}