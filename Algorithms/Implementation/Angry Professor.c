#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int t; 
    scanf("%d",&t);
    bool result[t];
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        int k; 
        scanf("%d %d",&n,&k);
        int a[n], cnt = 0;
        for(int a_i = 0; a_i < n; a_i++){
           scanf("%d",&a[a_i]);
           if(a[a_i] <= 0) cnt++; 
        }
        if (k > cnt)
            result[a0] = true;
        else
            result[a0] = false;
    }
    
    for(int a0 = 0; a0 < t; a0++){
        if(result[a0])
            printf("YES\n");
        else
            printf("NO\n");
    }    
    return 0;
}