/******************************************************************************
Link: https://codeforces.com/contest/1279/problem/F
Code: 1279F
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-14-21.16.03
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>> dp;
int n, k, l;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> l;
    dp.resize(k + 1, vector<int>(n + 1, 1e18));

    dp[0][0] = 0;
    for(int c = 1; c <= k; ++c){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= i; ++j){
                dp[c][i] = min(dp[c][i], dp[c - 1][j - 1] + (i - j + 1));
            }
        }
    }

    cout << dp[k][n] << '\n';

    return 0;
}
