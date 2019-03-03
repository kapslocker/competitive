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
    int n, sum = 0;
    cin >> n;
    vector<string> arr(n);
    char sep;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += (int) arr[i].length();
    }
    sum += n / 2;
    sum /= n / 2;
    cin >> sep;
    for(int i = 0; i < n; i++)
        arr[i] += sep;
    set<string> st(arr.begin(), arr.end());
    while(!st.empty()) {
        string s1 = *st.begin(), s2;
        int rem = sum - s1.length() + 1;
        st.erase(st.begin());
        for(auto &str : st) {
            if(str.length() == rem) {
                s2 = str;
                break;
            }
        }
        cout << s1 << s2.substr(0, s2.length() - 1) << endl;
        st.erase(s2);
    }
    return 0;
}
