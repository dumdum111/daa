#include<stdio.h>
void dijkstra(int n, int a[10][10], int src) {
    int d[100], s[10], sum = 0;
    for(int i = 1; i <= n; i++) 
        s[i] = 0, d[i] = a[src][i];
    s[src] = 1;
    for(int i = 1, u; i <= n; i++) {
        int mn = 999;
        for(int j = 1; j <= n; j++)
            if(s[j] == 0 and mn > d[j]) 
                mn = d[j], u = j;
        s[u] = 1;
        sum += d[u];
        for(int v = 1; v <= n; v++)
            if(s[v] == 0 and d[v] > d[u] + a[u][v])
                d[v] = d[u] + a[u][v];
    }
    for(int i = 1; i <= n; i++)
        printf("The shortest distance from %d to %d is %d\n", src, i, d[i]);
}

int main() {
    int n, a[10][10], src;
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d",&a[i][j]);
    printf("Enter the src node:\n");
    scanf("%d",&src);
    dijkstra(n, a, src);
}