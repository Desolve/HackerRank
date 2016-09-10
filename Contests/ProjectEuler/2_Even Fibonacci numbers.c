#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
/*
1 2 3 5 8 13 21 34 55 89
Fn = Fn-1 + Fn-2 = 2Fn-2 +Fn-3 = 2Fn-2 + Fn-3
Since 2Fn-2 is even, Fn will be even when Fn-3 is even.

Fn = 2[Fn-3 + Fn-4] + Fn-3 = 3Fn-3 + 2Fn-4 = 3Fn-3 + 2Fn-5 + 2Fn-6

Fn-3 = 2Fn-5 + Fn-6
2Fn-5 = Fn-3 - Fn-6

Fn = 3Fn-3 + [Fn-3 - Fn-6] + 2Fn-6  = 4Fn-3 + Fn-6

E1 = 2
E2 = 8
E3 = 34
E4 = 144

So when we only consider even numbers' series,
it follows the equation: En+2 = En + 4En+1 .
*/

/*
void eFib(){
    long long int prev = 2, now = 8, num = 34;
    int cnt = 2;
    while(num <= 40000000000000000){
        prev = now;
        now = num;
        num = prev + 4 * now;
        cnt++;
        printf("\nCnt: %d Now: %lld", cnt, now);
    }
    printf("\nCnt: %d\nLastNum: %lld", cnt, now);
}*/

void fillArray(long long int *evenF, long long int *evenS){
    evenF[0] = 2, evenF[1] = 8, evenS[0] = 2, evenS[1] = 10;
    for(int i = 2; i < 27; i++){
        evenF[i] = evenF[i-2] + 4 * evenF[i-1];
        evenS[i] = evenS[i-1] + evenF[i];
    }
    for(int j = 0; j < 27; j++)
        printf("%lld, ", evenF[j]);
        //printf("\nCnt: %2d, Num: %17lld, Sum: %17lld", j, evenF[j], evenS[j]);    
}
void solveSum(long long int n, long long int *evenF, long long int *evenS){
    int cnt;
    for(cnt = 0; cnt < 27; cnt++){
        if(evenF[cnt] > n)
            break;
    }
    printf("%lld\n", evenS[cnt-1]);
    /*for(int i = 0; i < 27; i++){
        if(evenF[i] >= n){
            if(evenF[i] > n)
                printf("%lld\n", evenS[i-1]);
            else
                printf("%lld\n", evenS[i]);
            break;
        }
    }*/
}

int main() {
    //long long int *num, long long int prev, long long int now
    int t;
    scanf("%d", &t);
    long long int evenF[27]={2, 8, 34, 144, 610, 2584, 10946, 46368, 196418, 832040, 3524578, 14930352, 63245986, 267914296, 1134903170, 4807526976, 20365011074, 86267571272, 365435296162, 1548008755920, 6557470319842, 27777890035288, 117669030460994, 498454011879264, 2111485077978050, 8944394323791464, 37889062373143906};
    long long int evenS[27]={2, 10, 44, 188, 798, 3382, 14328, 60696, 257114, 1089154, 4613732, 19544084, 82790070, 350704366, 1485607536, 6293134512, 26658145586, 112925716858, 478361013020, 2026369768940, 8583840088782, 36361730124070, 154030760585064, 652484772464328, 2763969850442378, 11708364174233842, 49597426547377748};
    //fillArray(evenF, evenS);
    for(int i = 0; i < t; i++){
        long long int n;
        scanf("%lld", &n);
        solveSum(n, evenF, evenS);        
    }
    return 0;
}
