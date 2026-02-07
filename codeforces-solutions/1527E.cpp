/******************************************************************************
Link: https://codeforces.com/contest/1527/problem/E
Code: 1527E
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-01-00.13.14
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 35000, MAXK = 100;
int arr[MAXN + 5], n, k;
int dp[MAXK + 5][MAXN + 5];

// test dp / expected TLE
int w(int l, int r){
    map<int, pair<int, int>> mp;
    for(int i = l; i <= r; ++i){
        if(mp.count(arr[i]))
            mp[arr[i]].second = i;
        else mp[arr[i]] = {i, i};
    }

    int res = 0;
    for(const pair<int, pair<int, int>>& p: mp){
        res += p.second.second - p.second.first;
    }
    return res;
}

void trau(){
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;

    for(int c = 1; c <= k; ++c){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= i; ++j){
                dp[c][i] = min(dp[c][i], dp[c - 1][j - 1] + w(j, i));
            }
        }
    }

    cout << dp[k][n] << '\n';
}

int pre[MAXN + 5], suf[MAXN + 5];

int curCost = 0;
int L, R;

void addL(int idx){
    curCost += pre[idx];
}

void addR(int idx){
    curCost += suf[idx];
}

void popL(int idx){
    curCost -= pre[idx];
}

void popR(int idx){
    curCost -= suf[idx];
}

void move(int l, int r){
    while(L > l) addL(--L);
    while(R < r) addR(++R);
    while(L < l) popL(L++);
    while(R > r) popR(R--);
}

void computeDp(int c, int l, int r, int optL, int optR){
    if(l > r) return;

    int mid = (l + r) >> 1;
    pair<int, int> best = {LLONG_MAX, -1};
    for(int i = optL; i <= min(optR, mid); ++i){
        move(i, mid);
        best = min(best, {dp[c - 1][i - 1] + curCost, i});
    }

    dp[c][mid] = best.first;
    int opt = best.second;

    computeDp(c, l, mid - 1, optL, opt);
    computeDp(c, mid + 1, r, opt, optR);
}

void solve(){
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;

    for(int c = 1; c <= k; ++c){
        L = 1; R = 0;
        computeDp(c, 1, n, 1, n);
    }
    cout << dp[k][n] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    vector<int> last(n + 1);
    fill(begin(last) + 1, end(last), -1);

    for(int i = 1; i <= n; ++i){
        pre[i] = pre[i - 1];
        if(last[arr[i]] != -1){
            pre[i] = i - last[arr[i]];
        }

        last[arr[i]] = i;
    }

    fill(begin(last) + 1, end(last), -1);
    for(int i = n; i >= 1; --i){
        if(last[arr[i]] != -1){
            suf[i] = last[arr[i]] - i;
        }

        last[arr[i]] = i;
    }

    solve();

    return 0;
}
