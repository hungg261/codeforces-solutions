#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> arr(m + 1);
    for(int i = 1; i <= m; ++i){
        cin >> arr[i];
    }

    sort(begin(arr), end(arr));
    int ans = 0;
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= arr[i]; ++j){
            int idx = lower_bound(begin(arr) + 1, end(arr), n - j) - begin(arr);
            int delta = m - idx + 1;

//            if(i >= idx) --delta;

            ans += delta;
            cerr << i << ": " << delta << "\n";
        }
    }
    for(int i = 1; i <= m; ++i){
        ans -= max(0LL, arr[i] - (n - arr[i]) + 1);
    }

    cout << ans << '\n';
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
