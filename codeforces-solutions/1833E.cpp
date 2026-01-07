/******************************************************************************
Link: https://codeforces.com/problemset/problem/1833/E
Code: 1833E
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-08-00.27.24
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> p(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> p[i];
    }

    vector<bool> mark(n + 1, false);
    int mn = 0, mx = 0;
    for(int i = 1; i <= n; ++i){
        if(!mark[i]){
            ++mx;
            bool loop = false;
            int u = i;
            while(!mark[u]){
                mark[u] = true;

                if(p[p[u]] == u) loop = true;
                u = p[u];
            }

            if(loop){
                ++mn;
            }
        }
    }


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
