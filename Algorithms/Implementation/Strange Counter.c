#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    long long int t; 
    scanf("%lli",&t);
    long long int n = 1;
    long long int cycle = 3;
    while(t > cycle){
        t -= cycle;
        n++;
        cycle *= (long long int) 2;        
    }
    printf("%lli", (long long int)cycle - t + 1);    
    
    return 0;
}