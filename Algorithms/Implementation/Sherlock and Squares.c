#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int a, b, diff;
        scanf("%d %d", &a, &b);
        diff = (int)(floor(sqrt(b)) - ceil(sqrt(a))) + 1;
        if(diff < 0) diff = 0;
        printf("%d\n", diff);
    }    
    return 0;
}