#include<stdio.h>
#include<limits.h>

int mcm (int p[], int i, int j) {
    if(i == j) return 0;
    int cnt, mn = INT_MAX;
    for(int k = i; k < j; k++) {
        cnt = mcm(p, i, k) + mcm(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        if(cnt < mn)
            mn = cnt;
    }
    return mn;
}

int main() {
    int a[] = {30, 35, 15, 5, 10, 20, 25};
    int n = sizeof(a)/sizeof(a[0]);
    printf("Minimum number of multiplications is %d\n", mcm(a, 1, n - 1));
}