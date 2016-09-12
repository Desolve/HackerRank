#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    scanf("%d",&n);
    int *c = malloc(sizeof(int) * n);
    for(int c_i = 0; c_i < n; c_i++){
       scanf("%d",&c[c_i]);
    }
    int cnt = 0;
    for(int i = 0; i+1 < n; i++){        
        cnt++;    
        if((i+2) < n)
            if(c[i+2] == 0)
                i++;
    }
    printf("%d", cnt);
    return 0;
}