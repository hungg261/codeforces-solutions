#include<bits/stdc++.h>
using namespace std;

const double pi = acos(-1);
double to_rad(double value){ return value * pi / 180.0; }
double to_deg(double value){ return value * 180.0 / pi; }

struct Point{
    int x, y;

    void input(){
        cin >> x >> y;
    }

    double dist(const Point& other){
        return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
};

struct Circle{
    Point O;
    int r;

    void input(){
        O.input();
        cin >> r;
    }
};

Circle A, B;
double L;

void solve(){
    double gocA = to_deg(acos((L * L + A.r * A.r - B.r * B.r) / (2 * L * A.r))) * 2,
            gocB = to_deg(acos((L * L + B.r * B.r - A.r * A.r) / (2 * L * B.r))) * 2;

    double quatA = gocA / 360 * (A.r * A.r * pi) - 0.5 * A.r * A.r * sin(to_rad(gocA)),
            quatB = gocB / 360 * (B.r * B.r * pi) - 0.5 * B.r * B.r * sin(to_rad(gocB));

    double ans = quatA + quatB;
    cout << fixed << setprecision(20) << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    A.input();
    B.input();

    L = A.O.dist(B.O);
    if(A.r + B.r <= L){
        cout << "0\n";
        return 0;
    }

    solve();

    return 0;
}
