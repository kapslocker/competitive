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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> C(n + 1), H(n + 1), capacity(n + 2, 0);
        for(int i = 1; i <= n; i++) {
            cin >> C[i];
        }
        for(int i = 1; i <= n; i++) {
            cin >> H[i];
        }
        int pre = 0;
        for(int i = 1; i <= n; i++) {
            int lo = max(1ll, i - C[i]), hi = min(n, i + C[i]);
            capacity[lo]++;
            capacity[hi + 1]--;
        }
        for(int i = 1; i <= n; i++) {
            pre = pre + capacity[i];
            capacity[i] = pre;
        }
        sort(capacity.begin() + 1, capacity.begin() + n + 1);
        sort(H.begin(), H.end());
        bool found = false;
        for(int i = 1; i <= n; i++) {
            if(capacity[i] != H[i]) {
                found = true;
                break;
            }
        }
        if(!found) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}