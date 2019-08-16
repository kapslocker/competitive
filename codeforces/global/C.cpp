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

int power(int a) {
    int k = 1;
    while(k <= a) {
        k = k * 2;
    }
    return k;
}

int largefact(int n) {
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return n / i;
        }
    }
    return 1;
}
int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q, a;
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> a;
        if(a & (a + 1)) {
            cout << power(a) - 1 << endl;
        }
        else {
            cout << largefact(a) << endl;
        }
    }
    return 0;
}
