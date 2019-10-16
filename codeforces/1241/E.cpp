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

vector<pair<int, int> > dp;
int n, k;
unordered_map<int, vector<pair<int, int> > > tree;

void dfs(int u) {
    vector<int> temp;
    for(auto &x : tree[u])
        dfs(x.first);
    for(auto &[v, w] : tree[u]) {
        // take edge, k - 1 or don't take, k
        temp.push_back(w + dp[v].second - dp[v].first);
        dp[u].first += dp[v].first;
        dp[u].second += dp[v].first;
    }
    std::sort(temp.begin(), temp.end());
    int i = 0;
    for(i = 0; i < min(k - 1, (int)temp.size()); i++) {
        if(temp[i] < 0)
            break;
        dp[u].first += temp[i];
        dp[u].second += temp[i];
    }
    if(i == k - 1 && i < temp.size() && temp[i] > 0) {
        dp[u].first += temp[i];
    }
}


int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while(q--) {
        cin >> n >> k;
        for(int i = 0; i < n - 1; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            tree[u].push_back({v, w});
            tree[v].push_back({u, w});
        }
        dfs(1);
        cout << dp[1].first << endl;
    }
    return 0;
}
