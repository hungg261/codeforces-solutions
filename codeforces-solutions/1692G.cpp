/******************************************************************************
Link: https://codeforces.com/problemset/problem/1692/G
Code: 1692G
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-13-12.58.52
*******************************************************************************/
#include<bits/stdc++.h>
//#define int long long
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }

    int res = 0;
    for(int i = 1; i < n; ++i){
        for(int j = i + 1; j <= n; ++j){
            if(arr[j - 1] >= arr[j] * 2){
                break;
            }

            if(j - i + 1 == k + 1){
                ++res;
                break;
            }
        }
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
