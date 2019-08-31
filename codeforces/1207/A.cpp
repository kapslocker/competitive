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

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int b, p, f, h, c;
        cin >>b >> p >> f >> h >> c;
        int ans = 0;
        if(h >= c) {
            int num_burg = min(b / 2, p);
            ans = ans + num_burg * h;
            int rem = b - 2 * num_burg;
            ans = ans + min(rem / 2, f) * c;
            cout << ans << endl;
        }
        else {
            int num_burg = min(b / 2, f);
            ans = ans + num_burg * c;
            int rem = b - 2 * num_burg;
            ans = ans + min(rem / 2, p) * h;
            cout << ans << endl;
        }
    }
    return 0;
}
