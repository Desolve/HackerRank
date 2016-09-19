#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    uint64_t exp31 = 2147483648;
    uint64_t N, S, P, Q, last, unq = 0;
    cin >> N >> S >> P >> Q;
    vector<bool> v;
    v.resize(exp31);
    
    if(S <= exp31) 
        last = S;
    else
        last = S % exp31;
    v[last] = true;
    ++unq;
    for(size_t i = 1; i < N; ++i){
        uint64_t val = (last * P + Q);
        if(val <= exp31)
            last = val;
        else
            last = val % exp31;
        if(v[last] != true){
            v[last] = true;
            ++unq;
        }
    }
    cout << unq;    
    return 0;
}