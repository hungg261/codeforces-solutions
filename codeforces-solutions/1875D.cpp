/******************************************************************************
Link: https://codeforces.com/problemset/problem/1875/D
Code: 1875D
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-06-22.03.16
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i) cin >> arr[i];

    sort(begin(arr), end(arr));

    vector<int> cnt(n);
    for(int i = 1; i <= n; ++i){
        if(arr[i] < n) ++cnt[arr[i]];
    }

    int mex = 0;
    for(; mex < n; ++mex){
        if(cnt[mex] == 0) break;
    }

    int res = 0;
    while(mex > 0){
        fill(begin(cnt), begin(cnt) + mex, 0);
        for(int i = n; i >= 1; --i){
            if(arr[i] >= mex) continue;
            ++cnt[arr[i]];
        }

        auto it = min_element(begin(cnt), begin(cnt) + mex);
        cerr << mex << ' ' << it - begin(cnt) << ' ' << *it << '\n';

        res += (*it - 1) * mex;
        mex = it - begin(cnt);
        res += *it * mex;
    }

    cout << res << '\n';

//    sort(begin(arr), end(arr));
//    vector<bool> mark(n);
//    int mex = 0;
//    for(int i = 1; i <= n; ++i){
//        if(arr[i] >= n) break;
//        if(arr[i] > mex){
//            break;
//        }
//
//        mex = arr[i] + 1;
//    }

//    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
//
//    vector<int> delfirst(n + 1), dellast(n + 1);
//    for(int i = 1; i <= n; ++i){
//        if(i == n || arr[i + 1] > 0) delfirst[i] = 0;
//        else delfirst[i] = mex;
//    }
//    for(int i = n; i >= 1; --i){
//        if(i > 1 && arr[i - 1] > mex) dellast[i] = mex;
//        else dellast[i] = arr[i - 1] + 1;
//    }
//
//    int res = 1e9;
//    for(int i = 1; i <= n; ++i){
//        dp[i][n + 1] = delfirst[i];
//        dp[0][i] = dellast[i];
//    }
////    for(int i = 1; i <= n; ++i){
////        for(int j = n; j > i; --j){
////            dp[i][j] = min(dp[i - 1][j] + delfirst[i], dp[i][j + 1] + dellast[j]);
////            if(i + 1 == j){
////                res = min(res, dp[i][j]);
////            }
////
//////            cerr << i << ' ' << j << ": " << dp[i][j] << '\n';
////        }
////    }
////
//    for(int i = 1; i <= n; ++i) cerr << arr[i] << ' '; cerr << '\n';
//    for(int i = 0; i <= n + 1; ++i){
//        for(int j = 0; j <= n + 1; ++j){
//            cerr << i << ' ' << j << ": " << dp[i][j] << '\n';
//        }
//    }
////
//    cerr << mex << '\n';
//    for(int i = 1; i <= n; ++i) cerr << delfirst[i] << ' ' << dellast[i] << '\n';
//    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
