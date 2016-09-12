#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d\n", &t);
    for(int i=0; i<t; i++)
    {
        int n, m, s, result;
        scanf("%d %d %d\n", &n, &m, &s);
        result = (m % n) + (s-1) % n;
        if (result > n) result %= n;
        if (result == 0) result = n;
        printf("%d\n", result);
    }
    return 0;
}