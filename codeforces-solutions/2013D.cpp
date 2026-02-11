/******************************************************************************
Link: https://codeforces.com/contest/2013/problem/D
Code: 2013D
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-11-17.58.58
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    vector<int> suf(n + 2);
    suf[n + 1] = 0;
    for(int i = n; i >= 1; --i) suf[i] = suf[i + 1] + arr[i];

    int total = 0, cnt = n;
    int mn = 1e18, mx = -1e18;
    for(int i = 1; i <= n; ++i) total += arr[i];
    for(int i = 1; i + 1 <= n; ++i){
        if(arr[i] < arr[i + 1]){
            total -= arr[i];
            cnt--;
        }
        else{
            int avg = total / cnt;

            int delta = arr[i] - avg;
            if(delta < 0){
                continue;
            }

            total -= arr[i] + arr[i + 1];

            arr[i] -= delta;
            arr[i + 1] += delta;

            total += arr[i + 1];
            --cnt;
        }

        mn = min(mn, arr[i]);
        mx = max(mx, arr[i]);
    }

    mn = min(mn, arr[n]);
    mx = max(mx, arr[n]);

    cout << mx - mn << '\n';
//    for(int i = 1; i <= n; ++i) cerr << arr[i] << ' '; cerr << '\n';
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
