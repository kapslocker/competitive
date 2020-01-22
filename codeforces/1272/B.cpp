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

string solve(int n) {
    if(n <= 21) {
        if(15 <= n && 20 >= n)
            return "YES";
        return "NO";
    }
    int x = n % 14;
    if(1 <= x && x <= 6) {
        cout << x << " " << n / 14;
        return "YES";
    }
    return "NO";
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t;
    // cin >> t;
    // while(t--) {
    //     int n;
    //     cin >> n;
    //     cout << solve(n) << endl;
    // }
    for(int i = 1; i < 100; i++) {
        cout << i << " " << solve(1000000000000000000) << endl;
    }
    return 0;
}
