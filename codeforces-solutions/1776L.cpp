/******************************************************************************
Link: https://codeforces.com/problemset/problem/1776/L
Code: 1776L
Time (YYYY-MM-DD-hh.mm.ss): 2026-02-02-22.27.40
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long

string s;
int n, alpha, beta;

int ext_gcd(int a, int b, int& x, int& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int g = ext_gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

void solve(){
    int pa, pb;
    cin >> pa >> pb;

    int a = alpha * (pa - pb), b = beta * (pb - pa);
    int x, y;

    int c = b * (beta * beta - alpha * alpha);

    cerr << a << ' ' << b << ' ' << c << '\n';

    int g = ext_gcd(a, b, x, y);
    if(c % g != 0){
        cout << "NO\n";
        return;
    }

    x *= c / g;
    y *= c / g;

    int tlow = llround(ceil(1.0 * -x * g / b)), thigh = llround(floor(1.0 * y * g / a));
    if(tlow <= thigh) cout << "YES\n";
    else cout << "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s;
    for(int i = 0; i < n; ++i){
        if(s[i] == '+') ++alpha;
        else ++beta;
    }

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
