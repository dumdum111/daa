#include<stdio.h>
int a[10], vis[10], target, found = 0;

void sumofsub(int m, int idx, int r) {
    vis[idx] = 1;
    if((m + a[idx]) == target) {
        printf("{");
        for(int i = 1; i <= idx; i++) {
            if(vis[i] == 1) {
                printf(" %d ",a[i]);
                found = 1;
            }
        }
        printf("}\n");
    }
    else {
        if(m + a[idx] + a[idx + 1] <= target) sumofsub(m + a[idx], idx + 1, r - a[idx]);
        if((m + r - a[idx] >= target) && (m + a[idx + 1] <= target)) {
            vis[idx] = 0;
            sumofsub(m, idx + 1, r - a[idx]);
        }
    }
}

int main() {
    int n, sum = 0;
    printf("Enter maximum number:\n");
    scanf("%d",&n);
    printf("Enter the set in increasing order:\n");
    for(int i = 1; i <= n; i++)
        scanf("%d",&a[i]), sum += a[i];
    printf("Enter the target value:\n");
    scanf("%d",&target);
    if(sum < target or a[1] > target) 
        printf("No subset possible.\n");
    else { 
        sumofsub(0, 1, sum);
        if(found == 0)
            printf("No subset possible.\n");
    }
}
