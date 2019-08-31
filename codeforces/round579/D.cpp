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
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    vector<int> last(m), first(m);
    int idx = n - 1;
    for(int i = m - 1; i >= 0; i--) {
        while(s[idx] != t[i]) {
            idx--;
        }
        last[i] = idx;
        idx--;
    }
    idx = 0;
    for(int i = 0; i < m; i++) {
        while(s[idx] != t[i]) {
            idx++;
        }
        first[i] = idx;
        idx++;
    }
    int ans = 0;
    for(int i = 0; i < m - 1; i++) {
        int len = last[i+1] - first[i] - 1;
        ans = max(ans, len);
    }
    ans = max(ans, n - first[m-1] - 1);
    ans = max(ans, last[0]);
    cout << ans << endl;
    return 0;
}
