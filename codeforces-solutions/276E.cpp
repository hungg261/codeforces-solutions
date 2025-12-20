#include<bits/stdc++.h>
using namespace std;

struct FenwickTree{
    int n;
    vector<int> BIT;

    FenwickTree() = default;
    FenwickTree(int sz){ n = sz; BIT.resize(sz + 1, 0); }

    void update(int idx, int val){
        ++idx;

        for(int i = idx; i <= n; i += i & -i){
            BIT[i] += val;
        }
    }

    int get(int idx){
        ++idx;

        int res = 0;
        for(int i = idx; i > 0; i -= i & -i){
            res += BIT[i];
        }
        return res;
    }

    int get(int l, int r){ return get(r) - get(l - 1); }

    void update(int l, int r, int val){
        r = min(r, n);
        l = max(l, 0);
        if(l > r) return;

        update(r + 1, -val);
        update(l, val);
    }
};

const int MAXN = 1e5;
int n, q;
vector<int> adj[MAXN + 5];

int h[MAXN + 5];
int ChainID[MAXN + 5], curChain = 0,
    Pos[MAXN + 5], ChainSz[MAXN + 5];

void dfs(int u, int prv){
    ChainID[u] = curChain;
    Pos[u] = ++ChainSz[curChain];

    for(int v: adj[u]){
        if(v == prv) continue;

        h[v] = h[u] + 1;
        dfs(v, u);
    }
}

FenwickTree global, sub[MAXN + 5];
void solve(){
    global = FenwickTree(n + 5);
    for(int i = 1; i <= curChain; ++i){
        sub[i] = FenwickTree(ChainSz[i] + 5);
    }

    for(int u = 1; u <= n; ++u){
        cerr << "dbg: " << ChainID[u] << ' ' << Pos[u] << '\n';
    }
    for(int u = 1; u <= curChain; ++u){
        cerr << "dbg2: " << ChainSz[u] << '\n';
    }

    while(q--){
        int type;
        cin >> type;

        if(type == 0){
            int u, x, d;
            cin >> u >> x >> d;

            if(u == 1){
                global.update(0, d, x);
                continue;
            }

            int curID = ChainID[u];
            sub[curID].update(Pos[u], Pos[u] + d, x);

            if(d > h[u]){
                global.update(0, d - h[u])
            }
        }
        else{
            int u;
            cin >> u;

        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i < n; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int v: adj[1]){
        ++curChain;
        h[v] = 1;
        dfs(v, 1);
    }

    solve();

    return 0;
}
