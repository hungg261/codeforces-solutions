#include<bits/stdc++.h>
//#define int long long
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];

    auto calc = [&](int cost){
        int neg = 0, earn = 0;
        for(int i = 0; i < n; ++i){
            if(cost <= a[i]){
                earn += cost;
            }
            else if(cost <= b[i]){
                earn += cost;
                ++neg;
            }

            if(neg > k) return -1;
        }

        return earn;
    };


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
