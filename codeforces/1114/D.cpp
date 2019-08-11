#include <bits/stdc++.h>
using namespace std;



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


int dfs(int p, vector<int> &arr) {
    
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, temp;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(arr.size() == 0 || arr[arr.size() - 1] != temp)
            arr.push_back(temp);
    }
    n = arr.size();
    int minv = INT_MAX;
    for(int i = 0; i < n; i++) {
        minv = min(minv, solve(i, arr));
    }
    cout << max(0, minv) << endl;
    return 0;
}
