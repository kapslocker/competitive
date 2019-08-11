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

int mods(string n, int mod) {
    int ans = 0, N = n.length();
    for(int i = 0; i < N; i++) {
        ans = (ans * 10 + (n[i] - '0')) % mod;
    }
    return ans;
}
int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    int t, n;
    string k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        int a = mods(k, n), b = n - a;
        cout << 2 * min(a, b) - (a == b) << endl;
    }
    return 0;
}