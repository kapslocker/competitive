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

const int mod = 1e9 + 7;

vector<int> polyfromroots(vector<int> &roots) {
    int n = roots.size();
    vector<int> poly(1,1);
    for(int i = 0; i < n; i++) {
        poly.push_back(0);
        int temp = 1;
        for(int j = 1; j < poly.size(); j++) {
            int prev = poly[j];
            poly[j] -= roots[i] * temp;
            poly[j] %= mod;
            temp = prev;
        }
    }
    return poly;
}


int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, N, k;
    cin >> N >> k;
    map<int, int> counts;
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        counts[x]++;
    }
    vector<int> roots;
    for(auto &x : counts)
        roots.push_back(x.second);
    n = roots.size();
    vector<int> coeffs = polyfromroots(roots);
    int ans = 0, curr = 1;
    for(int i = 0; i <= min(n, k); i++) {
        ans += curr * coeffs[i];
        curr *= -1;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
