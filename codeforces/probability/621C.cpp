#include <bits/stdc++.h>
using namespace std;

#define int long long


template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class T> ostream &operator<<(ostream &os, set<T> V) {
    os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class T> ostream &operator<<(ostream& os, vector<T> V) {
    os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class K, class X> ostream &operator<<(ostream& os, map<K,X> V) {
    os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail...T) { cerr << " " << H; debug_out(T...); }

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int p;

int mults(int l, int r) {
    return (int)(r) / p - (int)(l-1) / p;
}
double contrib(int a, int b, int c, int d) {
    double num = mults(a, b) * (d - c + 1) + mults(c, d) * (b - a + 1) - mults(a,b) * mults(c, d);
    return (1000.0 * num) / (d - c + 1) / (b - a + 1);
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; double ans = 0.0;
    cin >> n >> p;
    vector<int> l(n), r(n);
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }
    for(int i = 0; i < n-1; i++) {
        ans += contrib(l[i], r[i], l[i+1], r[i+1]);
    }
    ans += contrib(l[n-1], r[n-1], l[0], r[0]);
    cout << fixed << setprecision(10) << 2.0 * ans << endl;
    return 0;
}
