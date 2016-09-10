#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long long int cal(int t) {
    if(t==1) 
        return 0;
    int up = t-1;
    long long int q_3  = up / 3;
    long long int q_5  = up / 5;
    long long int q_15 = up / 15;
    return ((long long int)(q_3*(q_3+1)/2*3+q_5*(q_5+1)/2*5-q_15*(q_15+1)/2*15));
    
}

int main() {
    int n;
    scanf("%d\n", &n);
    int t[n];
    for(int i=0; i<n; i++)
       scanf("%d\n", &t[i]); 
    for(int i=0; i<n; i++)
        printf("%lld\n", cal(t[i]));
    
    return 0;
}
