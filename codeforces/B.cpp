#include <bits/stdc++.h>
using namespace std;

#define int long long


template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template<class T> ostream &operator<<(ostream &os, multiset<T> V) {
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

bool isleaf(vector<vector<int> > &graph, int u) {
    return graph[u].size() == 1;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, temp;
    int ans = 0;
    cin >> n;
    multiset<int> nums;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        nums.insert(temp);
        ans += temp;
    }
    if(nums.size() == 1) {
        cout << temp << endl;
        return 0;
    }
    for(int x = 1; x <= 100; x++) {
        int large = -1;
        for(int num : nums) {
            if(num % x == 0) {
                large = max(num, large);
            }
        }
        if(large == -1)
            continue;
        nums.erase(nums.find(large));
        auto small = *nums.begin();
        nums.erase(nums.begin());
        nums.insert(large / x);
        nums.insert(small * x);
        int s = 0;
        for(int num : nums) {
            s = s + num;
        }
        if(s < ans)
            ans = s;
        nums.erase(nums.find(large / x));
        nums.erase(nums.find(small * x));
        nums.insert(large);
        nums.insert(small);
    }
    cout << ans << endl;
    return 0;
}
