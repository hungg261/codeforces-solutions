#include<bits/stdc++.h>
using namespace std;

struct FenwickTree{
    int n;
    vector<int> BIT;

    FenwickTree() = default;
    FenwickTree(int sz){ n = sz; BIT.resize(sz + 1, 0); }

    void update(int idx, int val){
        if(idx <= 0) return;

        for(int i = idx; i <= n; i += i & -i){
            BIT[i] += val;
        }
    }

    int get(int idx){
        if(idx <= 0) return 0;

        int res = 0;
        for(int i = idx; i > 0; i -= i & -i){
            res += BIT[i];
        }
        return res;
    }

    int get(int l, int r){ if(l > r) return 0; return get(r) - get(l - 1); }
};

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n + 1), delta(n + 1, 0), preRec(n + 1, 0);

    arr[0] = 0;
    preRec[0] = 0;
    pair<int, int> maxVal = {0, 0};
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];

        preRec[i] = preRec[i - 1];
        if(arr[i] > arr[maxVal.first]) ++preRec[i];

        if(arr[i] > arr[maxVal.first]){
            maxVal.second = maxVal.first;
            maxVal.first = i;
        }
        else if(arr[i] > arr[maxVal.second]){
            maxVal.second = i;
        }


        if(arr[maxVal.second] > arr[i]) continue;
        else if(arr[maxVal.first] > arr[i]){
            ++delta[maxVal.first];
        }

    }

    int resRec = 0, res = 1e9;
    for(int i = 1; i <= n; ++i){
        int newRec = preRec[i - 1] + delta[i];
        if(newRec > resRec){
            res = arr[i];
            resRec = newRec;
        }
        else if(newRec == resRec) res = min(res, arr[i]);

        cerr << preRec[i - 1] << ' ' << delta[i] << '\n';
    }

    cout << res << '\n';

    return 0;
}
