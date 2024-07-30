#include<stdio.h>
#include<string.h>
int max(int a, int b) { return a > b ? a : b;}

void lcs(char x[], char y[], int m, int n) {
    int DP[100][100];
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 or j == 0)
                DP[i][j] = 0;
            else 
                DP[i][j] = x[i - 1] == y[j - 1] ? 1 + DP[i - 1][j - 1] : max(DP[i - 1][j], DP[i][j - 1]);
        }
    }
    int len = DP[m][n];
    printf("LCS length is %d\n", DP[m][n]);
    char LCS[100];
    LCS[len] = '\0';
    int i = m, j = n;
    while(i and j) {
        if(x[i - 1] == y[j - 1]) {
            LCS[--len] = x[--i];
            j--;
        }
        else 
            DP[i - 1][j] > DP[i][j - 1] ? i-- : j--;
    }
    printf("The LCS is %s\n", LCS);
}

int main() {
    char x[100], y[100];
    printf("Enter the first string:\n");
    fgets(x, sizeof(x), stdin);
    printf("Enter the second string:\n");
    fgets(y, sizeof(y), stdin);
    int m = strlen(x), n = strlen(y);
    if(x[m - 1] == '\n') x[m - 1] = '\0';
    if(y[n - 1] == '\n') y[n - 1] = '\0';
    lcs(x, y, m, n);
}
