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
    int l, r;

    Node() = default;
    Node(int _l, int _r): l(_l), r(_r) {};
};

Node *leaf[MAXN + 5];

Node *build1(int l, int r){
    if(l == r){
        return leaf[l] = new Node(l, r);
    }

    int mid = (l + r) >> 1;
    Node *res = new Node(l, r);
    res->edges.emplace_back(build1(l, mid), 0);
    res->edges.emplace_back(build1(mid + 1, r), 0);
    return res;
}

Node *build2(int l, int r){
    if(l == r){
        return leaf[l];
    }

    int mid = (l + r) >> 1;
    Node *res = new Node(r, l);
//    cerr << "L: " << l << ' ' << mid << " | " << l << ' ' << r << '\n';
    build2(l, mid)->edges.emplace_back(res, 0);
//    cerr << "R: " << mid + 1 << ' ' << r << " | " << l << ' ' << r << '\n';
    build2(mid + 1, r)->edges.emplace_back(res, 0);

    return res;
}

void dfs(Node *node){
    if(!node) return;

    for(const auto& e: node->edges){
        cout << (node->l) << (node->r) << ' ' << (e.first->l) << (e.first->r) << '\n';
        dfs(e.first);
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    Node *uproot = build1(1, n);
    Node *downroot = build2(1, n);

    dfs(uproot);

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
