#include<bits/stdc++.h>
using namespace std;

#define int long long

string S, T;
bool used[20];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> S >> T;

    sort(begin(S), end(S), greater<char>());

    if(S.size() < T.size()){
        cout << S << '\n';
        return 0;
    }

    int n = S.size();

    bool smaller = false;
    vector<int> res;
    for(int j = 0; j < n; ++j){
        if(smaller) break;

        int lim = smaller ? 9 : T[j];
        int i = 0;
        for(; i < n; ++i){
            if(!used[i] && S[i] <= lim){
                break;
            }
        }

        if(i >= n){
            if(j == 0){
                cout << "-s1\n";
                return 0;
            }

            used[res.back()] = false;
            res.pop_back();

            int q = 0;
            for(; q < n; ++q){
                if(!used[q] && S[q] < T[j - 1]){
                    break;
                }
            }

//            cerr << q << '\n';
            if(q >= n){
                cout << "-1\n";
                return 0;
            }

            res.push_back(q);
            smaller = true;
            used[q] = true;
            continue;
        }

        res.push_back(i);
        smaller = S[i] < lim;
        used[i] = true;
    }

    for(int i = 0; i < n; ++i){
        if(!used[i]) res.push_back(i);
    }

    for(int i: res){
        cout << S[i];
    }

    return 0;
}
