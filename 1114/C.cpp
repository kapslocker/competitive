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

map<int, int> factors;
void fillb(int b) {
    int k = sqrt(b);
    for(int i = 2; i <= k; i++) {
        if(b % i == 0) {
            while(b % i == 0) {
                b = b / i;
                factors[i]++;
            }
        }
    }
    if(b > 1) {
        factors[b]++;
    }
}

int times(int n, int p) {
    int ans = 0,  k = p;
    while(n / p > 0) {
        ans += (n / p);
        n /= p;
    }
    return ans;
}

int solve(int n, int b) {
    fillb(b);
    int minv = -1;
    for(auto &s : factors) {
        int f = s.first, freq = s.second;
        if(minv == -1)
            minv = times(n , f) / freq;
        else
            minv = min(minv, times(n, f) / freq);
    }
    return minv;
}
int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, b;
    cin >> n >> b;
    int minv = solve(n, b);
    cout << minv << endl;
    return 0;
}
