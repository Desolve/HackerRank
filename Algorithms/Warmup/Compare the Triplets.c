#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void caculate(int sca, int scb, int *scoreA, int *scoreB){
    if(sca > scb){
        *scoreA = *scoreA + 1;
    }else if (sca < scb){
        *scoreB = *scoreB + 1;
    }
    return;
}
int main(){

    int a0; 
    int a1; 
    int a2; 
    scanf("%d %d %d",&a0,&a1,&a2);
    int b0; 
    int b1; 
    int b2; 
    scanf("%d %d %d",&b0,&b1,&b2);
    int scoreA = 0, scoreB = 0;
    caculate(a0, b0, &scoreA, &scoreB);
    caculate(a1, b1, &scoreA, &scoreB);
    caculate(a2, b2, &scoreA, &scoreB);
    printf("%d %d", scoreA, scoreB);
    return 0;
}