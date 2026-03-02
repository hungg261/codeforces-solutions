/******************************************************************************
Link: https://codeforces.com/contest/1628/problem/E
Code: 1628E
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-28-12.14.21
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
const int MAXHEAD = MAXN * 2;
struct Edge{
    int u, v, w;

    bool operator < (const Edge& other) const{
        return w < other.w;
    }
};

vector<Edge> edges;
int n, q;

int head, val[MAXHEAD + 5];
int h[MAXHEAD + 5], table[MAXHEAD + 5][MAXLG + 5];
vector<int> tree[MAXHEAD + 5];

void dfs(int u){
    for(int v: tree[u]){
        h[v] = h[u] + 1;
        table[v][0] = u;

        dfs(v);
    }
}

void compute(){
    for(int j = 1; j <= MAXLG; ++j){
        for(int i = 1; i <= n; ++i){
            table[i][j] = table[table[i][j - 1]][j - 1];
        }
    }
}

int find_lca(int u, int v){
    if(h[u] > h[v]) swap(u, v);

    {
        int diff = h[v] - h[u];
        for(int b = MAXLG; b >= 0; --b){
            if(diff >> b & 1) v = table[v][b];
        }
    }

    if(u == v) return u;

    for(int b = MAXLG; b >= 0; --b){
        if(table[u][b] != table[v][b]){
            u = table[u][b];
            v = table[v][b];
        }
    }

    return table[u][0];
}

namespace Segg{

struct Node{
    int mn = INT_MAX, mx = INT_MIN, lazy = -1;

    Node operator + (const Node& other) const{
        Node res;
        res.mn = min(mn, other.mn);
        res.mx = max(mx, other.mx);
        res.lazy = 0;
        return res;
    }

    void apply(int _mn, int _mx, int lz){
        mn = min(mn, _mn);
        mx = max(mx, _mx);
        lazy = lz;
    }
};

Node nodes[MAXHEAD * 4 + 5];

void down(int id, int l, int r){
    int &lz = nodes[id].lazy;
    if(lz == -1) return;

    int mid = (l + r) >> 1;

}

void update(int id, int l, int r, int u, int v){
    if(r < u || v < l) return;
    if(l <= u && v <= r){
        nodes[id].mn = INT_MAX;
        nodes[id].mx = INT_MIN;
        nodes[id].lazy = 0;
        return;
    }

    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v);
    update(id << 1 | 1, mid + 1, r, u, v);
    nodes[id] = nodes[id << 1] + nodes[id << 1 | 1];
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

    dfs(head);
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
