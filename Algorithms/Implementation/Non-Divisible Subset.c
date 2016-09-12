#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, k, result=0;
    scanf("%d %d",&n, &k);
    // Special case: 1. integer num only 1 -> result = 1; 
    //               2. divisor k = 1 -> result = 1
    if(n == 1 || k == 1){
        printf("%d", 1);
    }else{    
        int s_i, num[k];
        for(int i = 0; i < k; i++) 
            num[i] = 0;
        // Store num of those whose remainder is k' at num[k'].
        for(int arr_i = 0; arr_i < n; arr_i++){
           scanf("%d",&s_i);
           s_i %= k;
           num[s_i] += 1;
        }

        for(int i = 1; i < k/2; i++){
            if(num[i] > num[k-i])
                result += num[i];
            else
                result += num[k-i];
        }
        if(num[0] > 0) result++;
        if(k % 2 == 0){ 
            if(num[k/2] > 0)
                result++;
        }else{
            if(num[k/2] > num[k/2 + 1])
                result += num[k/2];
            else
                result += num[k/2 +1];
        } 
        printf("%d", result);
    }           
    
    return 0;
}