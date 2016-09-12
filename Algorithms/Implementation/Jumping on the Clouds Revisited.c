#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    int k; 
    scanf("%d %d",&n,&k);
    int *c = malloc(sizeof(int) * n);
    for(int c_i = 0; c_i < n; c_i++){
       scanf("%d",&c[c_i]);
    }
    int energy = 100, jumptime = n / k;
    energy -= jumptime;

    for(int i = 0; i < n; i += k)
        energy -= c[i]*2;
    printf("%d", energy);

    return 0;
}