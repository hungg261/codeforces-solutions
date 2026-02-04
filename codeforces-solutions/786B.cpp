/******************************************************************************
Link: https://codeforces.com/problemset/problem/786/B
Code: 786B
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-04-08.01.09
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;
const int MAXN = 1e5;
int n, q, s;

struct Node{
    vector<pair<Node*, int>> edges;
    Node *l, *r;
    int dist = INF;

    Node(): l(nullptr), r(nullptr){}
    Node(Node *_l, Node *_r): l(_l), r(_r){}
};

Node *leaf[MAXN + 5];
Node *uproot, *downroot;

Node *build(int l, int r){
    if(l == r){
        return leaf[l];
    }

    int mid = (l + r) >> 1;
    return new Node(build(l, mid),
                    build(mid + 1, r));
}

void dfs(Node *node){
    if(!node) return;
    if(node->l) cerr << (node) << ' ' << (node->l) << '\n';
    if(node->r) cerr << (node) << ' ' << (node->r) << '\n';

    dfs(node->l);
    dfs(node->r);
}

void add1(Node *node, int l, int r, int u, int x, int y, int w){
    if(y < l || r < x) return;
    if(x <= l && r <= y){
        leaf[u]->edges.emplace_back(node, w);
        return;
    }

    int mid = (l + r) >> 1;
    add1(node->l, l, mid, u, x, y, w);
    add1(node->r, mid + 1, r, u, x, y, w);
}

void add2(Node *node, int l, int r, int x, int y, int v, int w){
    if(y < l || r < x) return;
    if(x <= l && r <= y){
        node->edges.emplace_back(leaf[v], w);
        return;
    }

    int mid = (l + r) >> 1;
    add2(node->l, l, mid, x, y, v, w);
    add2(node->r, mid + 1, r, x, y, v, w);
}

void dijkstra(int s){
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<>> pq;

    leaf[s]->dist = 0;
    pq.push({0, leaf[s]});

    while(!pq.empty()){
        int cost;
        Node *u;
        tie(cost, u) = pq.top();
        pq.pop();

        if(cost != u->dist) continue;

        for(const pair<Node*, int>& e: u->edges){
            Node *v; int w;
            tie(v, w) = e;

            if(cost + w < v->dist){
                v->dist = cost + w;
                pq.push({cost + w, v});
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q >> s;
    for(int i = 1; i <= n; ++i){
        leaf[i] = new Node();
    }
    uproot = build(1, n);
    downroot = build(1, n);

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int u, v, w;
            cin >> u >> v >> w;

            add1(uproot, 1, n, u, v, v, w);
        }
        else if(type == 2){
            int u, l, r, w;
            cin >> u >> l >> r >> w;

            add1(uproot, 1, n, u, l, r, w);
        }
        else{
            int v, l, r, w;
            cin >> v >> l >> r >> w;

            add2(downroot, 1, n, l, r, v, w);
        }
    }

    dijkstra(s);
    for(int i = 1; i <= n; ++i){
        cout << leaf[i]->dist << ' ';
    }

    return 0;
}
/*
4 3 1
3 4 1 3 12
2 2 3 4 10
1 2 4 16

3 5 1
2 3 2 3 17
2 3 2 2 16
2 2 2 3 3
3 3 1 1 12
1 3 3 17
*/
