#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void swap(char *x, char *y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
        
}

int next_permutation(char *a, size_t length){
    size_t i, j;
    if (length == 0) return 0;
    
    i = length - 1;
    while (i > 0 && a[i-1] >= a[i])
        i--;
    if (i == 0)
        return 0;
    
    // 現在保證存在一個i使得 a[i-1] < a[i], 
    // 在此之前其他的數字由左到右都是越來越小
    // 也就是本來就是排序較大的permutation,這部分換了字串不會比較大
    // 所以如果全部都是降序排列，就直接回傳0
    // 接下來再找一個j，滿足a[j]比a[i-1]大，swap過來，可以保證現在的陣列比較大
    // 且由右往回找，可以確保換的值是最小的。
    // 剩下的部分就是把原本降序排列改成升序，這樣才是比較小的排列方式。
    j = length - 1;
    while (a[j] <= a[i-1])
        j--;
    swap(&a[i-1], &a[j]);
    
    j = length - 1;
    while(i < j){
        swap(&a[i], &a[j]);
        i++;
        j--;
    }    
    return 1;
}

int main() {
    int n;    
    scanf("%d\n", &n);
    for(int i=0; i<n; i++){
        char word[100];
        scanf("%s", word);
        if (next_permutation(word, strlen(word))){
            printf("%s\n", word);
        } else {
            printf("no answer\n");
        }
    }   
    return 0;
}