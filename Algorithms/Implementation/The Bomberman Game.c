/* 
	Solve by Desolve Lin, 2016/09/15
	Please help yourself take it for reference,
	but kindly have a link to my blog if you use it at other website,
	thanks a lot!
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void printAns(int r, int c, char grid[][201]){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

void printFull(int row, int column){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
                printf("O");
        }
        printf("\n");
    }
}

// t3 result
void expAndRev(int row, int column, char grid[][201]){
    // Expand to find detonate area
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            if(grid[i][j] == 'O'){
                // Those who are detonated areas are not real bomb and can't be expanded again.
                if(i - 1 >= 0)
                    if(grid[i-1][j] == '.')
                        grid[i-1][j] = 'E';
                if(j - 1 >= 0)
                    if(grid[i][j-1] == '.')
                        grid[i][j-1] = 'E';
                if(i + 1 <= row) 
                    if(grid[i+1][j] == '.')
                        grid[i+1][j] = 'E';
                if(j + 1 <= column) 
                    if(grid[i][j+1] == '.')
                        grid[i][j+1] = 'E';
            }
        }
    }
    // Reverse to find t3 bomb state        
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            if(grid[i][j] != '.'){
                grid[i][j] = '.';
            }else{
                grid[i][j] = 'O';
            }    
        }
    }   
}

int main() {
    int row, column, n;
    scanf("%d %d %d\n", &row, &column, &n);
    char grid[201][201];
    
    for(int i = 0; i < row; i++){
        char tmp;
        for(int j = 0; j < column; j++){            
            scanf("%c", &grid[i][j]);
        }
        scanf("%c", &tmp); // remove linefeed
    }
    if(n == 1)
        printAns(row, column, grid);
    else if(n % 2 == 0)
        printFull(row, column);
    else{
        // t3 state => expand and reverse once : t3, 7, 11, 15
        // t5 state => expand and reverse twice: t5, 9, 13, 17
        expAndRev(row, column, grid);
        if(n % 4 == 1)
            expAndRev(row, column, grid);
        printAns(row, column, grid);
    }    
    return 0;
}
