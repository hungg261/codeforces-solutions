/******************************************************************************
Link: https://codeforces.com/problemset/problem/1987/C
Code: 1987C
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-15-19.24.42
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i) cin >> arr[i];

    int res = 0;
    for(int i = 1; i <= n;){
        int j = i + 1;
        while(j <= n && arr[j - 1] > arr[j]) ++j;

        res += arr[i];
        i = j;
    }

    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
