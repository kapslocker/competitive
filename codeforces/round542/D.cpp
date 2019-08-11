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
    int n, m;
    cin >> n >> m;
    vector<int> count(n + 1);
    vector<int> station(n + 1, INT_MAX);
    for(int i = 1; i <= m; i++) {
        int src, dest;
        cin >> src >> dest;
        count[src]++;
        if(dest < src) {
            dest = n + (dest - src);
        }
        else {
            dest = dest - src;
        }
        if(dest < station[src]) {
            station[src] = dest;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(station[i] == INT_MAX)
            station[i] = 0;
    }
    int num_rounds = 0;
    for(int i = 1; i <= n; i++) {
        num_rounds = max(num_rounds, count[i] - 1);
    }
    int ans = num_rounds * n, last_station = 1;
    for(int s = 1; s <= n; s++) {
        int t = s, dist = ans, maxstation = s, maxdist = 0;
        while(t != s + n) {
            int st = t % n;
            if(st == 0)
                st = n;
            if(count[st] == num_rounds + 1) {
                if(maxdist < t + station[st]) {
                    maxdist = t + station[st];
                    maxstation = t;
                }
            }
            t++;
        }
        dist = dist + maxdist - s;
        cout << dist << " ";
    }
    return 0;
}
