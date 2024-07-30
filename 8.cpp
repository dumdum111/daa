#include<stdio.h>
int prims(int n, int a[10][10], int src) {
    int d[100], vis[10], sum = 0;
    for(int i = 1; i <= n; i++) 
        vis[i] = 0, d[i] = a[src][i];
    vis[src] = 1;
    for(int i = 1, u, min = 999; i <= n - 1; i++) {
        for(int j = 1; j <= n; j++) {
            if(vis[j] == 0) {
                if(d[j] < min) {
                    min = d[j];
                    u = j;
                }
            }
        }
        vis[u] = 1;
        sum += d[u];
        for(int v = 1; v <= n; v++)
            if(vis[v] == 0 and d[v] > a[u][v])
                d[v] = a[u][v];
    }
    return sum;
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
    int cost = prims(n, a, src);
    printf("The cost of MST is %d\n", cost);
}