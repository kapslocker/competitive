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

void print(int x, int l, int n) {
    cout << l << endl;
    for(int i = 0; i < l - 2; i++) {
        cout << 0 << " ";
    }
    cout << -n << " " << x << endl;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k;
    cin >> k;
    int maxval = 1000000;
    if(k <= maxval) {
        cout << 1 << endl << -k << endl;
        return 0;
    }
    for(int l = 2; l <= 2000; l++) {
        for(int j = 1; j <= 2000; j++) {
            int h = k + j * l;
            if(h % (l - 1) == 0) {
                int x = h / (l - 1);
                if(x <= maxval) {
                    print(x, l, j);
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
