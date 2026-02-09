/******************************************************************************
Link: https://codeforces.com/contest/1856/problem/C
Code: 1856C
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-09-18.03.40
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    while(k > 0){
        int idx = -1;
        for(int i = 2; i <= n; ++i){
            if(arr[i - 1] <= arr[i] && (idx == -1 || arr[idx] < arr[i]))
                idx = i;
        }

        if(idx == -1) break;
        for(int i = idx - 1; i >= 1 && k > 0; --i){
            int cost = min(k, arr[i + 1] - arr[i] + 1);

            k -= cost;
            arr[i] += cost;
        }
    }

    for(int ele: arr) cout << ele << ' '; cout << '\n';
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
