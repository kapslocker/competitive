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

int query(int val, char type) {
    cout << type << " " << val << endl;
    fflush(stdout);
    int ans;
    cin >> ans;
    return ans;
}

int findmax() {
    int low = 2, mid, high = 1000000;
    while(low < high) {
        mid = (low + high) / 2;
        int ans = query(mid, '>');
        if(ans) {
            low = mid + 1;
        }
        else if(low == mid) {
            return low;
        }
        else {
            high = mid;
        }
    }
    return low;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    return 0;
}
