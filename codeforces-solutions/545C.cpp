#include<bits/stdc++.h>
using namespace std;

#define int long long

struct Tree{
    int x, h;

    bool operator < (const Tree& other){
        return this->x < other.x;
    }

    bool collapse(const Tree& other){
        return this->x + this->h < other.x - other.h;
    }

    bool contain(const Tree& other){
        return this->x <= other.x && other.x <= this->x + this->h;
    }

    void input(){
        cin >> x >> h;
    }
};

const int MAXN = 1e5;
int dp[MAXN + 5][3], maxDp[MAXN + 5][3], n;
Tree T[MAXN + 5];

int bound_less(int target){
    int l = 1, r = n, res = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(T[mid].x <= target){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    return res;
}

void solve(){
    dp[1][0] = 1;
    dp[1][1] = 0;
    if(n >= 2 && T[1].collapse(T[2])) dp[1][2] = 1;

    for(int i = 2; i <= n; ++i){
        if(T[i - 1].collapse(T[i])){
            dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1;
            dp[i][1] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
            dp[i][2] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
            if(i < n && T[i].collapse(T[i + 1])) ++dp[i][2];
        }
        else if(T[i - 1].contain(T[i])){
            dp[i][0];
        }
        else{
            dp[i][0] = max({dp[i - 1][0], dp[i - 1][1]}) + 1;
            dp[i][1] = max({dp[i - 1][0], dp[i - 1][1]})
        }
    }

//    dp[1][0] = 1;
//    for(int i = 2; i <= n; ++i){
//        if(T[i - 1].x + T[i - 1].h < T[i].x - T[i].h){
//            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
//
//            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
//            if(i < n && T[i].x + T[i].h < T[i + 1].x - T[i].h){
//                dp[i][1]++;
//            }
//
////            int idx = bound_less(T[i].x - T[i].h - 1);
////            dp[i][0] = max(maxDp[idx][0], maxDp[idx][1]) + 1;
//        }
//        else{
//            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0] + 1);
//        }
//    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        T[i].input();
    }
    sort(T + 1, T + n + 1);

    solve();

    return 0;
}
