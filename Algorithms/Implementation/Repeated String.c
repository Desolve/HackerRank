#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s",s);
    long n; 
    scanf("%ld",&n);
    if(strlen(s) == 1)
    {
        if(s[0] == 'a')
            printf("%ld", n);
        else
            printf("0");
    }else {
        int leng = strlen(s);
        long quotient = n / leng, remainder = n % leng;
        int a_total = 0, a_remain = 0, i = 0;
        while(i < remainder){
            if(s[i] == 'a'){
                a_total++;
                a_remain++;
            }
            i++;
        }
        while(i < leng){
            if(s[i] == 'a'){
                a_total++;
            }
            i++;
        }
        printf("%ld", quotient * a_total + a_remain);        
    }    
    return 0;
}