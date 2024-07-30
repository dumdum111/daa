#include <stdio.h>
#include <stdlib.h>

void dfs(int n, int a[10][10], int src, int vis[]) {
    printf("%d\t", src);
    vis[src] = 1;
    for (int i = 0; i < n; i++) 
        if (!vis[i] && a[src][i] == 1) 
            dfs(n, a, i, vis);
}

void bfs(int n, int a[10][10], int src, int vis[]) {
    int que[10], f = 0, r = 0;
    printf("%d\t", src);
    vis[src] = 1;
    que[r++] = src;
    while (f < r) {
        int u = que[f++];
        for (int i = 0; i < n; i++) {
            if (!vis[i] && a[u][i] == 1) {
                printf("%d\t", i);
                vis[i] = 1;
                que[r++] = i;
            }
        }
    }
}

int main() {
    int n, a[10][10], src, vis[10], ch;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    printf("Enter the src node: ");
    scanf("%d", &src);
    for (int i = 0; i < n; i++) vis[i] = 0;

    printf("1: Depth First Traversal \n2: Breadth First Traversal\n");
    scanf("%d", &ch);

    switch (ch) {
        case 1:
            printf("The DFS order is:\n");
            dfs(n, a, src, vis);
            break;
        case 2:
            printf("The BFS order is:\n");
            bfs(n, a, src, vis);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }
}
