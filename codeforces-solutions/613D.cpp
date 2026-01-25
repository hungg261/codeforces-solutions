/******************************************************************************
Link: https://codeforces.com/problemset/problem/613/D
Code: 613D
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-24-23.01.08
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

namespace Subsolve{

vector<pair<int, int>> subgraph[MAXN + 5];
int n;
bool important[MAXN + 5];

int dfs(int u, int prv){
    int res = 0;
    int important_cnt = 0;
    for(const pair<int, int>& e: subgraph[u]){
        int v, w; tie(v, w) = e;
        if(v == prv) continue;

        if(important[v]){
            ++important_cnt;
            if(important[u]){
                ++res;
            }
        }
        res += dfs(v, u);
    }

    if(!important[u] && important_cnt >= 2) ++res;
    return res;
}

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    using namespace Subsolve;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> important[i];
    for(int i = 1; i < n; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        subgraph[a].emplace_back(b, c);
        subgraph[b].emplace_back(a, c);
    }

    cout << dfs(1, 0);

    return 0;
}
