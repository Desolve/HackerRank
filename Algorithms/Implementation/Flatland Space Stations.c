#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int compare(const void *arg1, const void *arg2){
     return  (*(int *)arg1 - *(int *)arg2);
}

int main(){
    int n; 
    int m; 
    scanf("%d %d",&n,&m);
    if(n == m) 
        printf("0");
    else{        
        int *c = malloc(sizeof(int) * m);
        int max = 0, temp = 0;
        for(int i = 0; i < m; i++){
            scanf("%d",&c[i]);
        }
        qsort((void *)c, m, sizeof(int), compare);
        
        max = c[0];        
        for(int i = 1; i < m; i++){
            temp = (c[i]-c[i-1])/2;
            max = (max > temp)? max : temp;
        }
        temp = n-1 - c[m-1];
        max = (max > temp)? max : temp;
        printf("%d", max);        
    }
    return 0;
}