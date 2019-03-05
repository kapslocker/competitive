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
    vector<int> arr(3);
    cin >> arr[0] >> arr[1] >> arr[2];
    int ans = 0;
    sort(arr.begin(), arr.end());
    ans += arr[0];
    arr[1] -= arr[0];
    arr[2] -= arr[0];
    arr[0] = 0;
    while(arr[1] + arr[2] >= 3) {
        int selected = min(arr[1], arr[2]/2);
        ans += selected;
        arr[1] -= selected;
        arr[2] -= 2 * selected;
        if(arr[2] < arr[1])
            swap(arr[1], arr[2]);
        if(arr[1] == 0)
            break;
    }
    cout << ans << endl;
    return 0;
}
