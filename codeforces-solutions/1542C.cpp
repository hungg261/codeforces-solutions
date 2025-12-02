#include<bits/stdc++.h>
using namespace std;

int smallest[50];
void compute(){
    for(int i = 1; i <= 1000; ++i){
        for(int j = 2; j < 50; ++j){
            if(smallest[j] == 0 && i % j != 0){
                smallest[j] = i;
            }
        }
    }

    for(int i = 1; i <= 49; ++i){
        cout << i << ": " << smallest[i] << '\n';
    }
}

void solve(){
    int n;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    compute();

    return 0;
}
