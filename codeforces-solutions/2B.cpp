#include<bits/stdc++.h>
using namespace std;

#define int long long

int cnt(int x, int base){
    int res = 0;
    while(x % base == 0){
        ++res;
        x /= base;
    }
    return res;
}

struct State{
    int cnt2 = 0, cnt5 = 0;

    int get() const{ return min(cnt2, cnt5); }

    bool operator < (const State& other) const{
        return this->get() < other.get();
    }
};

const int dx[2] = {0, 1}, dy[2] = {1, 0};
const int MAXN = 1000, INF = 1e9;
int n, arr[MAXN + 5][MAXN + 5];
int par[MAXN + 5][MAXN + 5];
State dp[MAXN + 5][MAXN + 5];

void solve(){
    for(int i = 1; i <= n; ++i) dp[i][0] = dp[0][i] = {INF, INF};
    dp[1][1] = {cnt(arr[1][1], 2), cnt(arr[1][1], 5)};

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i == 1 && j == 1) continue;

            dp[i][j] = {INF, INF};

            for(int d = 0; d < 2; ++d){
                int nx = i - dx[d], ny = j - dy[d];
                if(1 <= nx && nx <= n && 1 <= ny && ny <= n){
                    int c2 = cnt(arr[i][j], 2), c5 = cnt(arr[i][j], 5);
                    State cur = dp[nx][ny];

                    cur.cnt2 += c2;
                    cur.cnt5 += c5;

                    if(cur < dp[i][j]){
                        par[i][j] = d;
                        dp[i][j] = cur;
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cerr << dp[i][j].cnt2 << "/" << dp[i][j].cnt5 << "\t";
        }
        cerr << '\n';
    }

    cout << dp[n][n].get() << '\n';

    int cx = n, cy = n;
    string res;

    while(cx * cy != -1){
        int d = par[cx][cy];
        res += d == 0 ? 'R' : 'D';

        cx -= dx[d];
        cy -= dy[d];
    }

//    while(cx * cy != 1){
//        for(int d = 0; d < 2; ++d){
//            int nx = cx - dx[d], ny = cy - dy[d];
//            if(1 <= nx && nx <= n && 1 <= ny && ny <= n){
//                int c2 = cnt(arr[cx][cy], 2), c5 = cnt(arr[cx][cy], 5);
//                State cur = dp[nx][ny];
//
//                cur.cnt2 += c2;
//                cur.cnt5 += c5;
//
//                if(cur.get() == dp[cx][cy].get()){
//                    res += (d == 0 ? 'R' : 'D');
//                    cx = nx;
//                    cy = ny;
//                    goto passed;
//                }
//            }
//        }
//
//        passed: NULL;
//    }

    reverse(begin(res), end(res));
    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> arr[i][j];
        }
    }

    solve();

    return 0;
}
