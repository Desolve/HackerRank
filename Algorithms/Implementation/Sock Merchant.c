#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n, pairs = 0; 
    scanf("%d",&n);
    int *soc = calloc(100, sizeof(int));
    for(int i = 0; i < n; i++){
       int tmp;
       scanf("%d", &tmp);
       soc[tmp-1]++; 
    }
    for(int j = 0; j < 100; j++){
        pairs += soc[j] / 2;
    }
    printf("%d", pairs);
    return 0;
}