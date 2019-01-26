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
    double nn, kk;
    cin >> nn >> kk;
    if(nn < kk) {
        cout << "-1" << endl;
        return 0;
    }
    if(2 * nn < kk * (kk + 1)) {
        cout << "-1\n";
        return 0;
    }
    int n = nn, k = kk;
    vector<int> factors;
    int l = sqrt(n);
    for(int i = 1; i <= l; i++) {
        if(n % i == 0) {
            factors.push_back(i);
            if(n / i > 1)
                factors.push_back(n / i);
        }
    }
    sort(factors.begin(), factors.end());
    int lim = (2 * n) / (k * (k + 1));
    int idx = lower_bound(factors.begin(), factors.end(), lim) - factors.begin();
    int g = factors[idx];
    if(lim < g) {
        g = factors[idx - 1];
    }
    int t = g;
    for(int i = 0; i < k; i++) {
        if(i == k - 1) {
            cout << n << endl;
            return 0;
        }
        cout << t << " ";
        n -= t;
        t += g;
    }
    return 0;
}
