/******************************************************************************
Link: https://codeforces.com/contest/1628/problem/E
Code: 1628E
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-27-21.07.05
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct DSU{
    int n;
    vector<int> par, sz;

    DSU() = default;
    DSU(int _sz): n(_sz){
        par.resize(n + 1);
        sz.resize(n + 1);
    }

    void init(){
        for(int u = 0; u <= n; ++u)
            create(u);
    }

    void create(int v){
        par[v] = v;
        sz[v] = 1;
    }

    int find(int v){
        return par[v] == v ? v : par[v] = find(par[v]);
    }

    bool same(int u, int v){
        return find(u) == find(v);
    }

    bool unite(int a, int b){
        a = find(a);
        b = find(b);

        if(a != b){
            if(sz[a] < sz[b]) swap(a, b);

            par[b] = a;
            sz[a] += sz[b];

            return true;
        }

        return false;
    }
};

const int MAXN = 3e5, MAXLG = __lg(MAXN) + 1;

struct Edge{
    int u, v, w;

    bool operator < (const Edge& other) const{
        return w < other.w;
    }
};
vector<Edge> edges;
int n, q;
int h[MAXN * 2 + 1], val[MAXN * 2 + 1];
pair<int, int> lcas[MAXN * 4 + 1][MAXLG + 1];
int rangelca[MAXN * 2 + 1][MAXLG + 1];
vector<int> tree[MAXN * 2 + 1];
int head;
int tin[MAXN * 2 + 1], Timer = 0;

void dfs_krt(int u){
    tin[u] = ++Timer;
    lcas[Timer][0] = {h[u], u};

    for(int v: tree[u]){
        h[v] = h[u] + 1;

        dfs_krt(v);
        lcas[++Timer][0] = {h[u], u};
    }

}

int find_lca(int u, int v){
    int l = tin[u], r = tin[v];
    if(l > r) swap(l, r);

    int bit = __lg(r - l + 1);
    return min(lcas[l][bit], lcas[r - (1 << bit) + 1][bit]).second;
}

int range_lca(int l, int r){
    int bit = __lg(r - l + 1);
    return find_lca(rangelca[l][bit], rangelca[r - (1 << bit) + 1][bit]);
}

void compute(){
    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 1; i + (1 << j) - 1 <= Timer; ++i){
            lcas[i][j] = min(lcas[i][j - 1], lcas[i + (1 << (j - 1))][j - 1]);
        }
    }

    for(int i = 1; i <= n; ++i) rangelca[i][0] = i;
    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 1; i + (1 << j) - 1 <= head; ++i){
            rangelca[i][j] = find_lca(rangelca[i][j - 1], rangelca[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int nodes[MAXN * 8 + 1], lazy[MAXN * 8 + 1];
void update(int id, int l, int r, int u, int v){
    if(r < u || v < l) return;
    if(u <= l && r <= v){
//        nodes[id] =
    }
}

void KRT(){
    sort(begin(edges), end(edges));

    DSU dsu(n * 2);
    dsu.init();
    head = n;
    for(const Edge& e: edges){
        int fu = dsu.find(e.u),
            fv = dsu.find(e.v);

        if(fu == fv) continue;

        ++head;
        tree[head].push_back(fu);
        tree[head].push_back(fv);
        val[head] = e.w;

        dsu.par[fu] = dsu.par[fv] = head;
        dsu.sz[head] = dsu.sz[fu] + dsu.sz[fv];
    }

    h[head] = 0;
    dfs_krt(head);
    compute();
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i < n; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        edges.push_back({a, b, c});
    }

    KRT();

    return 0;
}
