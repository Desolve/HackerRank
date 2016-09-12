#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n, k;
    scanf("%d %d\n", &n, &k);
    int t[n];
    for(int i=0; i<n; i++)
        scanf("%d ", &t[i]);
    int special_num = 0, page = 1;
    
    for(int chap=1; chap<=n; chap++)
    {
        for(int pb_cnt=1; pb_cnt<=t[chap-1]; pb_cnt++)
        {
            if(pb_cnt == page) special_num++;
            if(pb_cnt % k == 0 && pb_cnt < t[chap-1]) page++;
        }
        page++;
    }    
    printf("%d", special_num);
    
    return 0;
}