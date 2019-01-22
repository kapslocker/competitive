#include <bits/stdc++.h>
using namespace std;

#define int long long


template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template<class T> ostream &operator<<(ostream &os, set<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
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

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, temp;
    cin >> n;
    multiset<int> g;
    for(int i = 0; i < n * n; i++) {
        cin >> temp;
        g.insert(temp);
    }
    vector<int> nums;
    for(int i = 0; i < n; i++) {
        nums.push_back(*g.rbegin());
        auto it = g.find(nums.back());
        g.erase(it);
        for(int j = 0; j < nums.size() - 1; j++) {
            int a = gcd(nums[j], nums.back());
            it = g.find(a);
            g.erase(it);
            it = g.find(a);
            g.erase(it);
        }
    }
    for(int i = 0; i < n; i++)
        cout << nums[i] << " ";
    cout << endl;
    return 0;
}
