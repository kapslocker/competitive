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
    int q;
    cin >> q;
    while(q--) {
        int n, h;
        cin >> h >> n;
        vector<int> p(n);
        for(int i = 0; i < n; i++) {
            cin >> p[i];
        }
        p.push_back(0);
        for(int i = 0; i < n; i++) {
            if(p[i] - p[i+1] > 1) {
                p[i] = p[i+1] + 1;
                i++;
            }
        }
        debug(p);
        int ans = 0;
        int currh = p[0], i = 0;
        while(i < n - 2) {
            if(p[i] - p[i+2])
        }
    }
    return 0;
}
