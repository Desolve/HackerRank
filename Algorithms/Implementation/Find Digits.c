#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void setDivisible(int num, int divisible[]){
   for(int i = 2; i <= 9; i++){
       if(num % i == 0)
           divisible[i] = 1;
       else
           divisible[i] = 0;
   }
}
void countNum(int num, int divisible[]){
    int lsb, cnt = 0;
    while(num != 0){
        lsb = num % 10;
        cnt += divisible[lsb];
        num /= 10;
    }
    printf("%d\n", cnt);
}

int main(){
    int t; 
    scanf("%d",&t);
    int divisible[10];
    divisible[0] = 0;
    divisible[1] = 1;
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        scanf("%d",&n);
        setDivisible(n, divisible);
        countNum(n, divisible);
    }
    
    
    return 0;
}