/******************************************************************************
Link: https://codeforces.com/contest/1423/problem/K
Code: 1423K
Time (YYYY-MM-DD-hh.mm.ss): 2025-12-30-22.52.56
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

bool triangle(int a, int b, int c){
    return a + b > c && b + c > a && c + a > b;
}

int trau(int n, bool output = true){
    int res = 0;
    for(int a = 1; a <= n; ++a){
        bool found = false;
        for(int b = 1; b <= n; ++b){
            if(a == b) continue;

            int g = __gcd(a, b);
            if(triangle(a / g, b / g, g)){
                found = true;
                break;
            }
        }

        if(!found){
            if(output){
                cerr << "lonely: " << a << '\n';
            }
            ++res;
        }
    }

    return res;
}

void solve(){
    for(int n = 8; n <= 8; ++n){
        cout << n << ": " << trau(n) << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
