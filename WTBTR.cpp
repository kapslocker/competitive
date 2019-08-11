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

void solve(vector<pair<int, int> > &points) {
    int n = points.size();
    double ans = 1e18;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++) {
        int xx = points[i].first, yy = points[i].second;
        x[i] = (xx + yy);
        y[i] = (xx - yy);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for(int i = 0; i < n - 1; i++) {
        ans = min(ans, (x[i+1] - x[i]) / 2.0);
        ans = min(ans, (y[i+1] - y[i]) / 2.0);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int, int> > points(n);
        for(int i = 0; i < n; i++) {
            cin >> points[i].first >> points[i].second;
        }
        solve(points);
    }
    return 0;
}
