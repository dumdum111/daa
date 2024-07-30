#include <stdio.h>
#include <stdlib.h>
int vis[100], count, res[100];
void dfs(int n, int a[100][100], int src) {
    vis[src] = 1;
    for (int i = 1; i <= n; i++) 
        if (a[src][i] == 1 and vis[i] == 0) 
            dfs(n, a, i);
    res[++count] = src;
}

void topologicalDFS(int n, int a[100][100]) {
    for (int i = 1; i <= n; i++) vis[i] = 0;
    count = 0;
    for (int j = 1; j <= n; j++) 
        if (vis[j] == 0) 
            dfs(n, a, j);
    for (int i = n; i >= 1; i--) 
        printf("--> %d%c", res[i], i == 1 ? '\n' : '\t');
}

void topologicalSourceRemoval(int n, int a[100][100], int sc[100]) {
    for (int i = 1; i <= n; i++) {
        if (sc[i] == 0) {
            printf("%d\t", i);
            sc[i] = -1;
            for (int j = 1; j <= n; j++) 
                sc[j] -= (a[i][j] == 1);
            i = 0;
        }
    }
    printf("\n");
}

int main() {
    int a[100][100], n, sc[100], ch;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("1: Topological order using DFS\n2: Source Removal method\n");
    scanf("%d", &ch);

    switch (ch) {
        case 1:
            printf("Topological order using DFS:\n");
            topologicalDFS(n, a);
            break;
        case 2:
            for (int i = 1; i <= n; i++) {
                sc[i] = 0;
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (a[i][j] == 1) {
                        sc[j]++;
                    }
                }
            }
            printf("Topological order using Source Removal:\n");
            topologicalSourceRemoval(n, a, sc);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
}
