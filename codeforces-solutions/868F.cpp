/******************************************************************************
Link: https://codeforces.com/problemset/problem/868/F
Code: 868F
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-31-21.40.46
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXK = 20;
int n, k, arr[MAXN + 5];
int dp[MAXK + 5][MAXN + 5];

// test dp / expected TLE (better one)
int mark[MAXN + 5];
void trau(){
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int c = 1; c <= k; ++c){
        for(int i = 1; i <= n; ++i){
            int cost = 0;
            for(int j = i; j >= 1; --j){
                cost += mark[arr[j]];
                ++mark[arr[j]];

                dp[c][i] = min(dp[c][i], dp[c - 1][j - 1] + cost);
            }
            for(int j = i; j >= 1; --j){
                --mark[arr[j]];
            }
        }
    }

    cout << dp[k][n] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    trau();

    return 0;
}
