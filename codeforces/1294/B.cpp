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

string solve() {
    int n;
    cin >> n;
    vector<pair<int, int> > pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].first >> pts[i].second;
    }
    sort(pts.begin(), pts.end());
    string ans = "";
    int cx = 0, cy = 0;
    for(int i = 0; i < n; i++) {
        int nx = pts[i].first, ny = pts[i].second;
        if(nx >= cx && ny >= cy) {
            ans += string(nx - cx, 'R') + string(ny - cy, 'U');
        }
        else {
            return "";
        }
        cx = nx;
        cy = ny;
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string ans = solve();
        if(ans.length()) {
            cout << "YES" << endl;
            cout << ans << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
