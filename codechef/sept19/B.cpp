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

void fill(vector<vector<int> > &choose) {
    int N = 50;
    choose[1][0] = 1;
    choose[1][1] = 1;
    for(int n = 2; n <= N; n++) {
        choose[n][0] = 1;
        for(int k = 1; k <= n; k++) {
            choose[n][k] = choose[n-1][k-1] + choose[n-1][k];
        }
    }
}
int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, n, k;
    cin >> t;
    vector<vector<int> > choose(101, vector<int>(101, 0));
    fill(choose);
    while(t--) {
        cin >> n >> k;
        vector<int> arr(n);
        map<int, int> count, req;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            count[arr[i]]++;
        }
        sort(arr.begin(), arr.end());
        int sum = 0, ans = 1;
        for(int i = 0; i < k; i++) {
            sum += arr[i];
            req[arr[i]]++;
        }
        for(auto &x : req) {
            ans = ans * choose[count[x.first]][x.second];
        }
        cout << ans << endl;
    }
    return 0;
}
