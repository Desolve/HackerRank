#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int compare(const void *arg1, const void *arg2){
     return  (*(int *)arg1 - *(int *)arg2);
}

int main(){
    int n; 
    scanf("%d",&n);
    int arr[n];
    for(int arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",&arr[arr_i]);
    }
    qsort((void *)arr, n, sizeof(int), compare);
    int remain_num = n, cut_num = 1;
    printf("%d\n", remain_num);
    
    for(int i = 1; i < n ; i++){
        if (arr[i] > arr[i-1]){
            remain_num -= cut_num;
            printf("%d\n", remain_num);
            cut_num = 1;
        }else {
            cut_num++;
        }
    }
    return 0;
}