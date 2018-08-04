#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int N, cnt_odds = 0; 
    scanf("%d",&N);
    int *B = malloc(sizeof(int) * N);
    for(int B_i = 0; B_i < N; B_i++){
        scanf("%d",&B[B_i]);
        B[B_i] = B[B_i] & 1;
        cnt_odds += B[B_i];
    }
    if(cnt_odds % 2 == 1)
        printf("NO");
    else{
        int giveTime = 0;
        for(int i = 0; i < N-1; i++){
            if(B[i] == 1){
                if(B[i+1] == 1){
                    B[i] = B[i+1] = 0;                    
                }else{
                    B[i] = 0;
                    B[i+1] = 1;                    
                }
                giveTime++;
            }
        }
        printf("%d", giveTime * 2);
    }
        
    return 0;
}