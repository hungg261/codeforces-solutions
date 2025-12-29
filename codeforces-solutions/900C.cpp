#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n + 1), delta(n + 1, 0), preRec(n + 1, 0), sufRec(n + 2, 0);

    arr[0] = 0;
    preRec[0] = 0, sufRec[0] = 0;
    pair<int, int> maxVal = {0, 0};
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];

        preRec[i] = preRec[i - 1];
        if(arr[i] > arr[maxVal.first]) ++delta[maxVal.first];
        if(arr[i] > arr[maxVal.first]) ++sufRec[i];

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

    if(n == 2){
        cout << "1\n";
        return 0;
    }

    for(int i = n; i >= 1; --i){
        sufRec[i] = sufRec[i + 1] + sufRec[i];
    }

    int resRec = 0, res = 1e9;
    for(int i = 1; i <= n; ++i){
        int newRec = preRec[i - 1] + sufRec[i + 1] + delta[i];
        if(newRec > resRec){
            res = arr[i];
            resRec = newRec;
        }
        else if(newRec == resRec) res = min(res, arr[i]);

        cerr << i << " " << arr[i] << ": " << preRec[i - 1] << ' ' << delta[i] << '\n';
    }

    cout << res << '\n';

    return 0;
}
