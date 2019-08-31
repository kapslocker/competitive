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


int cost(int a, int b) {
    int ans = 0;
    while(a > b) {
        ans++;
        a >>=1;
    }
    if(a != b)
        return INT_MAX;
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, minv = INT_MAX, ans = INT_MAX;
    cin >> n >> k;
    vector<int> arr(n);
    unordered_map<int, vector<int> > dp;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        int ctr = 0;
        while(arr[i] >= 0) {
            dp[arr[i]].push_back(ctr);
            if(arr[i] == 0)
                break;
            arr[i] >>=1;
            ctr++;
        }
    }
    for(auto &x: dp) {
        int sum = 0;
        if(x.second.size() < k)
            continue;
        sort(x.second.begin(), x.second.end());
        for(int i = 0; i < k; i++)
            sum += x.second[i];
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
