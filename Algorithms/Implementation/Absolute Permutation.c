#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

// swap: make element i, j of the array arr[] swap with each other.
void swap(int *arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
/* permute: calculate absolute permutation of k, if NOT possible then return -1.
/  case: k==0
        Array itself is the answer, no need to swap anything.
  case: other
        Suppose there's an absolute permutation of the array, then element i must swap with element i+k,
        then the difference will be -k, +k.
        Since then, a section will be 2*k. 
        Ex: 0, 1, ..., k-1 -> k+0, k+1, ... k+k-1, and next round should start from 0+2k.
        We could start from i=0, each time adding 2*k to find if there's a pair to swap,
        that is, from 0, k -> 2k, 3k -> 4k, 5k ...(if still < n)
        (Notice that if we find a single num that can't be paired, we have to return -1.)
        
        Then i=1, i=2, i=3 ... ...
        And we could get the array done with absolute permutation of k.
*/
int permute(int *arr, int k, int n){
    for(int i = 0; i < k; i++){
        for(int j = i; j < n; j += k*2){
            if(j + k >= n)                        
                return -1;
            else
                swap(arr, j, j+k);        
        }         
    }
    return 0;
}
int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n, k;
        scanf("%d %d",&n,&k);
        int arr[n];
        
        for(int i = 0; i < n; i++)
            arr[i] = i + 1;
        
        if(k == 0){
            for(int i = 0; i < n; i++)
                printf("%d ", arr[i]);
        }else{
            if(permute(arr, k, n) == -1)
                printf("-1");
            else
                for(int i = 0; i < n; i++)
                    printf("%d ", arr[i]);            
        }
        printf("\n");
    }
    return 0;
}