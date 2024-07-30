#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000
void merge(int a[], int l, int md, int r) {
    int n1 = md - l + 1, n2 = r - md;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int i = 0; i < n2; i++) R[i] = a[md + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 and j < n2) 
        a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int md = l + (r - l) / 2;
        mergeSort(a, l, md);
        mergeSort(a, md + 1, r);
        merge(a, l, md, r);
    }
}

int main() {
    int n, a[N]; 
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    srand(time(0));
    for (int i = 0; i < n; i++) {
        a[i] = rand();
        printf("%d%c", a[i], i == n - 1 ? '\n' : '\t');
    }

    clock_t start = clock();
    mergeSort(a, 0, n - 1);
    clock_t end = clock();

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d%c", a[i], i == n - 1 ? '\n' : '\t');

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
}
