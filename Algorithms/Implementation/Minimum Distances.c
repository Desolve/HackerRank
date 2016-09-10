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
    int *A = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
       scanf("%d",&A[i]);
    }
    int d = -1;
    for(int i = 0; i < n-1; i++)
        for(int j = i + 1; j < n; j++){
            if(A[i] == A[j])
                if(d < 0) d = j - i;
                else if(j - i < d) d = j - i;
        }
    printf("%d", d);
    
    return 0;
}