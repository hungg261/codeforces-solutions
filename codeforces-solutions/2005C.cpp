#include<bits/stdc++.h>
//#define int long long
using namespace std;

const string TARGET = "narek";
int encode(char c){
    return find(begin(TARGET), end(TARGET), c) - begin(TARGET);
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<string> arr(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        arr[i] = "#" + arr[i];
    }

    vector<vector<vector<int>>> nxt(n + 1, vector<vector<int>>(m + 1, vector<int>(5, 0)));
    int last[6] = {};
    for(int i = 1; i <= n; ++i){
        for(int j = n; j >= 0; --j){
            for(int c = 0; c < 5; ++c){
                nxt[i][j][c] = last[c];
            }

            if(j > 0) last[encode(arr[i][j] - 'a')] = j;
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(5, 0));
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < m; ++j){
            for(int prv_c = 0; prv_c < 5; ++prv_c){

            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
