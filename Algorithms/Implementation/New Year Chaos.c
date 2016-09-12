#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int T; 
    scanf("%d",&T);
    for(int a0 = 0; a0 < T; a0++){
        int n, bribe_total = 0, chao = 0; 
        scanf("%d",&n);
        int *q = malloc(sizeof(int) * n);
        int q_now[n], pos_now[n];
        for(int q_i = 0; q_i < n; q_i++){
            scanf("%d",&q[q_i]);
            q_now[q_i] = q_i + 1;
            pos_now[q_i] = q_i;
        }
        for(int i = 0; i < n; i++){
            if(pos_now[q[i]-1] - i > 2)
            {
                chao = 1;
                break;
            }
        }
        if(chao){
            printf("Too chaotic\n");
        }else{
            for(int i = 0; i < n-1; i++)
            {
                int temp = q[i], diff = pos_now[q[i]-1] - i;
                if( diff == 2 )
                {
                    bribe_total +=2;
                    pos_now[q_now[i+1]-1]++;
                    pos_now[q_now[i]-1]++;
                    pos_now[q_now[i+2]-1] -= 2;
                    q_now[i+2] = q_now[i+1];
                    q_now[i+1] = q_now[i];
                    q_now[i] = temp;
                } else if( diff == 1 ){
                    bribe_total++;
                    pos_now[q_now[i]-1]++;
                    pos_now[q_now[i+1]-1]--;
                    q_now[i+1] = q_now[i];
                    q_now[i] = temp;                    
                }                    
            }    
            printf("%d\n", bribe_total);
        }
    }
    return 0;
}