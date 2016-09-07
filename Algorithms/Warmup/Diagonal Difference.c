#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n;
    int sum_d1 = 0 , sum_d2 = 0;
    scanf("%d",&n);
    int a[n][n];
    for(int a_i = 0; a_i < n; a_i++){
       for(int a_j = 0; a_j < n; a_j++){
          
          scanf("%d",&a[a_i][a_j]);
          if (a_i == a_j) sum_d1+=a[a_i][a_j];
          if (n == a_i+a_j+1) sum_d2+=a[a_i][a_j]; 
       }
    }
    if (sum_d1 > sum_d2)
        printf("%d", sum_d1-sum_d2);
    else
        printf("%d", sum_d2-sum_d1);
    
    return 0;
}