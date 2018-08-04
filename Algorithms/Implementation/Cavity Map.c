#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    scanf("%d",&n);
    char* grid[n];
    for(int grid_i = 0; grid_i < n; grid_i++){
       grid[grid_i] = (char *)malloc(1024 * sizeof(char));
       scanf("%s",grid[grid_i]);
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i == 0 || j == 0 || i == n-1 || j == n-1)
                printf("%c", grid[i][j]);
            else{
                char tmp = grid[i][j];
                if(tmp > grid[i-1][j] && tmp > grid[i+1][j] && tmp > grid[i][j-1] && tmp > grid[i][j+1])
                    printf("X");
                else
                    printf("%c", tmp);
            }                
        }
        printf("\n");
    }    
    return 0;
}