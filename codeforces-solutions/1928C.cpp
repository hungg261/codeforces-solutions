/******************************************************************************
Link: https://codeforces.com/problemset/problem/1928/C
Code: 1928C
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-01-22.33.08
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int a, b;
    cin >> a >> b;

    --a; --b;

    if(a < b || (a + b) % 2 != 0){
        cout << "0\n";
        return;
    }

    int res = __lg((a - b) / 2) + (__lg((a + b) / 2) + 1);

    cout << res << '\n';
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
