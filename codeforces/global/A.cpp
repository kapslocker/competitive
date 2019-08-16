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
    int b, k;
    cin >> b >> k;
    vector<int> a(k);
    for(int i = 0; i < k; i++)
        cin >> a[i];
    int s = 0;
    if(b % 2 == 0) {
        s = s + a[k - 1];
    }
    else {
        for(int i = 0; i < k; i++) {
            s = s + a[i];
        }
    }
    if(s % 2 == 0)
        cout << "even\n";
    else
        cout << "odd\n";
    return 0;
}
