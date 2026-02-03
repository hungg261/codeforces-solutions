/******************************************************************************
Link: https://codeforces.com/problemset/problem/12/D
Code: 12D
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-03-15.01.55
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5;
vector<int> ys[MAXN + 5];
vector<int> BIT[MAXN + 5];
struct FenwickTree2D{
    int N;

    FenwickTree2D() = default;
    FenwickTree2D(int n): N(n){}

    void fake_point(int x, int y){
        for(int i = x; i <= N; i += i & -i){
            ys[i].push_back(y);
        }
    }

    void fake_rect(int x1, int y1, int x2, int y2){
        fake_point(x2, y2);
        fake_point(x1 - 1, y2);
        fake_point(x2, y1 - 1);
        fake_point(x1 - 1, y1 - 1);
    }

    void build(){
        for(int i = 1; i <= N; ++i){
            sort(begin(ys[i]), end(ys[i]));
            ys[i].erase(unique(begin(ys[i]), end(ys[i])), end(ys[i]));

            BIT[i].resize(ys[i].size() + 1, 0);
        }
    }

    void update(int x, int y, int val){
        for(int i = x; i <= N; i += i & -i){
            int j = lower_bound(begin(ys[i]), end(ys[i]), y) - begin(ys[i]) + 1;
            for(; j < (int)BIT[i].size(); j += j & -j){
                BIT[i][j] += val;
            }
        }
    }

    int get(int x, int y){
        int res = 0;
        for(int i = x; i > 0; i -= i & -i){
            int j = upper_bound(begin(ys[i]), end(ys[i]), y) - begin(ys[i]);
            for(; j > 0; j -= j & -j){
                res += BIT[i][j];
            }
        }
        return res;
    }

    int get(int x1, int y1, int x2, int y2){
        return get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1);
    }
};

struct Lady{
    int B, I, R, id;

    void input(int i){
        cin >> B >> I >> R;
        id = i;
    }

    bool operator < (const Lady& other) const{
        if(B == other.B){
            if(I == other.I) return R > other.R;
            return I > other.I;
        }
        return B < other.B;
    }
};

void solve(){
    int n;
    cin >> n;

    vector<Lady> Ladies(n);
    vector<int> Xvalues;
    vector<int> Yvalues;

    for(int i = 0; i < n; ++i) cin >> Ladies[i].B;
    for(int i = 0; i < n; ++i){
        cin >> Ladies[i].I;
        Xvalues.push_back(Ladies[i].I);
    }
    for(int i = 0; i < n; ++i){
        cin >> Ladies[i].R;
        Yvalues.push_back(Ladies[i].R);
    }

    sort(begin(Xvalues), end(Xvalues));
    Xvalues.erase(unique(begin(Xvalues), end(Xvalues)), end(Xvalues));

    sort(begin(Yvalues), end(Yvalues));
    Yvalues.erase(unique(begin(Yvalues), end(Yvalues)), end(Yvalues));

    const int MAX = Xvalues.size() + 5;
    FenwickTree2D fwt(MAX);
    for(Lady& ld: Ladies){
        ld.I = lower_bound(begin(Xvalues), end(Xvalues), ld.I) - begin(Xvalues) + 1;
        ld.R = lower_bound(begin(Yvalues), end(Yvalues), ld.R) - begin(Yvalues) + 1;
        fwt.fake_point(ld.I, ld.R);
    }

    sort(begin(Ladies), end(Ladies));
    fwt.build();

    int res = 0;
    for(int i = n - 1; i >= 0; --i){
        int cur = fwt.get(Ladies[i].I + 1, Ladies[i].R + 1, MAX, MAX);
        if(cur > 0){
            ++res;
        }

        fwt.update(Ladies[i].I, Ladies[i].R, 1);
    }

    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    return 0;
}
