/******************************************************************************
Link: https://codeforces.com/contest/1527/problem/E
Code: 1527E
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-01-00.13.14
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 35000, MAXK = 100;
int arr[MAXN + 5], n, k;
int dp[MAXK + 5][MAXN + 5];

vector<vector<int>> pos[MAXN + 5];

// test dp / expected TLE
void trau(){
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;

    for(int c = 1; c <= k; ++c){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= i; ++j){
                dp[c][i] = min(dp[c][i], dp[c - 1][j - 1] + cost(j, i));
            }
        }
    }

    cout << dp[k][n] << '\n';
}

int curCost = 0;
int L, R;

void add(int x){
    int lo = lower_bound(pos[x].begin(), pos[x].end(), L) - pos[x].begin();
    int hi = upper_bound(pos[x].begin(), pos[x].end(), R) - pos[x].begin() - 1;
    if(lo <= hi) curCost += hi - lo;
}

void move(int l, int r){
    while(L > l) add(arr[--L]);
    while(R < r) add(arr[++R]);
}

void compute(){

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        pos[arr[i]].push_back(i);
    }

    return 0;
}
