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
    long long int height[61];
    height[0] = 1;
    for(int i = 1; i < 61; i++){
        if(i % 2 == 1){
            height[i] = height[i-1] * 2;
        }else{
            height[i] = height[i-1] + 1;
        }
    }
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        scanf("%d",&n);
        printf("%lld\n", height[n]);
    }
    return 0;
}