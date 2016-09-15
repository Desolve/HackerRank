#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, k, charge, actual = 0;
    scanf("%d %d\n", &n, &k);
    for(int i = 0; i < n; i++){
        int c;
        scanf("%d ", &c);
        if(i != k){
            actual += c;
        }
    }
    actual /= 2;
    scanf("%d", &charge);
    if(charge > actual)
        printf("%d", charge - actual);
    else
        printf("Bon Appetit");
    return 0;
}