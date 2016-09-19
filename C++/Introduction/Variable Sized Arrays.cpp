#include <iostream>
using namespace std;

int main() {
    void solve();
    solve();
	return 0;
}
#include <vector>

void solve(){
    int N, Q;
    scanf("%d %d", &N, &Q);
    vector<vector<int> >v(N);
    for(int i = 0; i < N; i++){
        int k;
        scanf("%d", &k);
        v[i].resize(k);
        for(int j = 0; j < k; j++){
            scanf("%d", &v[i][j]);
        }
    }
    
    for(int i = 0; i < Q; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", v[a][b]);
    }
}