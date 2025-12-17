#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int l, r, G;
    cin >> l >> r >> G;

    int A = (l + G - 1) / G * G, B = r / G * G;
    if(A > B){
        cout << "-1 -1\n";
        return;
    }

    for(int a = A; a <= r; a += G){
        for(int b = B; b >= a; b -= G){
            if(__gcd(a, b) == G){
                cout << a << ' ' << b << '\n';
            }
        }
    }

    cout << "-1 -1\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
