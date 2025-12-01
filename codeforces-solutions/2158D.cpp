#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    string S, T;
    cin >> S >> T;

    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for(int i = 0; i < n; ++i){
        dp[i][i] = true;
        if(i > 0) dp[i][i - 1] = true;
    }

    for(int len = 2; len <= n; ++len){
        for(int i = 0; i + len - 1 < n; ++i){
            int j = i + len - 1;

            if(S[i] == S[j]) dp[i][j] = dp[i + 1][j - 1];
        }
    }

    for(int i = 0; i < n; ++i){
        if(S[i] != T[i]){
            int j = n - 1;
            for(; j >= i; --j) if(dp[i][j]) break;

            for(int k = i; k <= j; ++k) S[k] = S[k] == '0' ? '1' : '0';
            cout << i + 1 << ' ' << j + 1 << '\n';
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
