#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int L, int R) {
    int i = L - 1;
    for (int j = L; j < R; j++) 
        if (a[j] <= a[R]) 
            swap(&a[++i], &a[j]);
    swap(&a[i + 1], &a[R]);
    return i + 1;
}

void quicksort(int a[], int L, int R) {
    if (L < R) {
        int j = partition(a, L, R);
        quicksort(a, L, j - 1);
        quicksort(a, j + 1, R);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[100000];
    srand(time(0));
    for (int i = 0; i < n; i++) {
        a[i] = rand();
        printf("%d%c", a[i], i == n - 1 ? '\n' : '\t');
    }

    clock_t start = clock();
    quicksort(a, 0, n - 1);
    clock_t end = clock();

    printf("The sorted array is: \n");
    for (int i = 0; i < n; i++) 
        printf("%d%c", a[i], i == n - 1 ? '\n' : '\t');

    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken is %f seconds\n", time_taken);
}

