#include<bits/stdc++.h>
using namespace std;

const int PCNT = 35;
int primes[PCNT] = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
    101, 103, 107, 109, 113, 127, 131, 137, 139, 149
};

const int MAXN = 5e4;
int powmod(int a, int b, int mod){
    int res = 1;
    a %= mod;

    while(b > 0){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

struct Node{
    int cnt[PCNT];
    int lazy[PCNT];

    Node(){
        memset(cnt, 0, sizeof cnt);
        memset(lazy, 0, sizeof lazy);
    }

    Node operator | (const Node& other){
        Node res = *this + other;
        memset(res.lazy, 0, sizeof res.lazy);
        return res;
    }

    Node operator + (const Node& other){
        Node res;
        for(int i = 0; i < PCNT; ++i){
            res.cnt[i] = cnt[i] + other.cnt[i];
            res.lazy[i] = lazy[i] + other.lazy[i];
        }

        return res;
    }

    Node operator * (const int k){
        Node res;
        for(int i = 0; i < PCNT; ++i){
            res.cnt[i] = cnt[i] * k;
            res.lazy[i] = lazy[i] * k;
        }
        return res;
    }

    static Node pfactor(int X, int mul = 1){
        Node res;
        for(int i = 0; i < PCNT; ++i){
            int p = primes[i];
            while(X % p == 0){
                res.cnt[i] += mul;
                res.lazy[i] += mul;
                X /= p;
            }
        }
        return res;
    }

    int calc(int mod){
        int res = 1;
        for(int i = 0; i < PCNT; ++i)
            res = res * powmod(primes[i], cnt[i], mod) % mod;
        return res;
    }

    void debug(){
        for(int i = 0; i < PCNT; ++i){
            cerr << cnt[i] << ' ';
        }
        cerr << '\n';
    }
};

Node nodes[MAXN * 4 + 5];

void down(int id){
    for(int c = 0; c < PCNT; ++c){
        int& lz = nodes[id].lazy[c];

        nodes[id << 1].cnt[c] += lz;
        nodes[id << 1].lazy[c] += lz;

        nodes[id << 1 | 1].cnt[c] += lz;
        nodes[id << 1 | 1].lazy[c] += lz;

        lz = 0;
    }
}

void update(int id, int l, int r, int u, int v, int X, int mul){
    if(r < u || v < l) return;
    if(u <= l && r <= v){
        nodes[id] = nodes[id] + Node::pfactor(X, mul) * (r - l + 1);
        return;
    }

    down(id);

    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, X, mul);
    update(id << 1 | 1, mid + 1, r, u, v, X, mul);
    nodes[id] = nodes[id << 1] | nodes[id << 1 | 1];
}

Node get(int id, int l, int r, int u, int v){
    if(r < u || v < l) return Node();
    if(u <= l && r <= v) return nodes[id];

    down(id);

    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v) | get(id << 1 | 1, mid + 1, r, u, v);
}

int n, q;

void update(int l, int r, int X, int mul){
    if(l > r){
        update(1, 1, n, r, n, X, mul);
        update(1, 1, n, 1, l, X, mul);
    }
    else{
        update(1, 1, n, l, r, X, mul);
    }
}

int get(int l, int r, int M){
    if(l > r){
        Node res = get(1, 1, n, r, n) | get(1, 1, n, 1, l);
        return res.calc(M);
    }
    else{
        return get(1, 1, n, l, r).calc(M);
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    update(1, 1, 6, 1, 4, 20, 1);
    update(1, 1, 6, 2, 6, 15, 1);
    get(1, 1, 6, 1, 6).debug();

//    cin >> n >> q;
//    while(q--){
//        int type, l, r, V;
//        cin >> type >> l >> r >> V;
//
//        if(type == 0){
//            cout << get(l, r, V) << '\n';
//        }
//        else if(type == 1){
//            update(l, r, V, 1);
//        }
//        else{
//            update(l, r, V, -1);
//        }
//    }

    return 0;
}
