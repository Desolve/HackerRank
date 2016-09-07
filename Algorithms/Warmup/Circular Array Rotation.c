#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, k, q;
    scanf("%d %d %d\n", &n, &k, &q);
    int a[n], b[q];
    
    for(int i = 0; i < n-1; i++) scanf("%d ", &a[i]);
    scanf("%d\n", &a[n-1]);     
    
    for(int l = 0; l < q-1; l++) scanf("%d\n", &b[l]);
    scanf("%d", &b[q-1]);
    
    k %= n;
    
    for(int i = 0; i < q-1; i++){
        if(b[i] - k >= 0) 
            printf("%d\n", a[b[i] - k]);
        else
            printf("%d\n", a[b[i] + n - k]);
    }
    if(b[q-1] - k >= 0) 
            printf("%d", a[b[q-1] - k]);
    else
            printf("%d", a[b[q-1] + n - k]);
    
    return 0;
}