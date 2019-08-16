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

const int mod = 1000000007;
int32_t main() {
    int n, seven = 0, sodd = 0, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        if(i % 2 == 0) {
            seven = (seven + sodd + 1) % mod;
            ans = (ans + seven) % mod;
        }
        else {
            sodd = (sodd + seven + 1) % mod;
            ans = (ans + sodd) % mod;
        }
    }
    cout << (seven + sodd) % mod << endl;
    return 0;
}
