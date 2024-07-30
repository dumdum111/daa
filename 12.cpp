#include<stdio.h>
#include<math.h>

int place(int x[10], int idx) {
    for(int i = 1; i <= idx - 1; i++) 
        if(x[idx] == x[i] or abs(x[i] - x[idx]) == abs(i - idx)) 
            return 0;
    return 1;
}

void nqueen(int n) {
    int x[10], k = 1, cnt = 0;
    x[k] = 0;
    while(k) {
        x[k]++;
        while(x[k] <= n and !place(x, k)) x[k]++;
        if(x[k] <= n) {
            if(k == n) {
                printf(" \nSolution %d is \n", ++cnt);
                for(int i = 1; i <= n; i++)
                    printf("%d \t", x[i]);
            }
            else  x[++k] = 0;
        }
        else --k;
    }
}

int main() {
    int n;
    printf("Enter the number of queens:\n");
    scanf("%d", &n);
    if(n == 1 or n == 2 or n == 3) printf("Solution is not posible.\n");
    else nqueen(n);
}