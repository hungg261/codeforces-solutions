/******************************************************************************
Link: https://codeforces.com/problemset/problem/1603/B
Code: 1603B
Time (YYYY-MM-DD-hh.mm.ss): 2026-01-04-19.27.07
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l, int r){
    return uniform_int_distribution<int>(l, r)(rng);
}

bool check(int n, int x, int y){
    return n % x == y % n;
}

void solve(){
    int x, y;
    x = Rand(2, 20) / 2 * 2;
    y = Rand(2, 20) / 2 * 2;
//    cin >> x >> y;

    int n;
    if(x > y){
        n = x + y;
    }
    else{
        if(y % x == 0) n = x;
        else{
            n = (x + y) / ((x + y) / x & (~1));
        }
    }

    if(!check(n, x, y)){
        cout << n << ' ' << x << ' ' << y << '\n';
        exit(0);
    }
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t = 1e9;
//	cin >> t;

	while(t--){
		solve();
	}

	return 0;
}
