#include<bits/stdc++.h>
using namespace std;

#define int long long

string S, T;
bool used[20];

string Try(int idx, int smaller){
    if(idx < 0){
        return "";
    }

    int lim = smaller ? 9 : T[idx];
    string best = string(20, (char)200);
    for(int i = 0; i < (int)S.size(); ++i){
        if(S[i] <= lim) best = min(best, S[i] + Try(idx - 1, smaller || (S[i] < lim)));
    }

    return best;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> S >> T;

    sort(begin(S), end(S), greater<char>());

    if(S.size() < T.size()){
        cout << S << '\n';
        return 0;
    }

    reverse(begin(S), end(S));
    reverse(begin(T), end(T));

    int len = S.size();
    cout << Try(len - 1, 0) << '\n';

    return 0;
}
