#include<stdio.h>
#include<string.h>
int horspool(char T[100], char P[100], int n, int m) {
    char mp[256];
    for(int i = 0; i < 256; i++) mp[i] = m;
    for(int i = 0; i < m - 1; i++) mp[(unsigned char)P[i]] = m - 1 - i;
    int i = m - 1;
    while(i < n) {
        int j = 0;
        while(j < m && (P[m - 1 - j] == T[i - j])) j++;
        if(j == m) return (i - m + 1);
        else i += mp[(unsigned char)T[i]];
    }
    return -1;
}

int main() {
    char T[100], P[100];
    printf("Enter the text string:\n");
    fgets(T, sizeof(T), stdin);
    printf("Enter the pattern string:\n");
    fgets(P, sizeof(P), stdin);
    int n = strlen(T), m = strlen(P);
    if(T[n - 1] == '\n') T[n - 1] = '\0';
    if(P[m - 1] == '\n') P[m - 1] = '\0';
    int flag = horspool(T, P, n, m);
    if(flag == -1) printf("String not found!\n");
    else printf("String found from index %d.", flag);
}
