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

string ordered(int k, int len) {
    vector<int> ans(len, 0), temp;
    while(k > 0) {
        temp.push_back(k % 26);
        k = k / 26;
    }
    int j = temp.size();
    for(int i = len - 1; i >= len - j; i--) {
        ans[i] = temp[len - 1 - i];
    }
    string ret(ans.size(), 'a');
    for(int i = 0; i < ans.size(); i++) {
        ret[i] = 'a' + ans[i];
    }
    return ret;
}


vector<int> subtract(vector<int> &a, vector<int> &b, int base) {
    vector<int> ans;
    int n = a.size(), carry = 0;
    for(int i = n - 1; i > 0; i--) {
        if(a[i] > b[i]) {
            ans[i] = a[i] - b[i];
        }
        else {
            a[i] = a[i] + base;
            int j = i - 1;
            while(j >= 0 && a[j] < 1) {
                a[j] = base - 1;
                j--;
            }
            a[j]--;
            ans[i] = a[i] - b[i];
        }
    }
    return ans;
}

vector<int> getidx(string &str, int len) {
    vector<int> ans(len);
    for(int i = 0; i < n; i++) {
        ans[i] = str[i] - 'a';
    }
}

int32_t main() {
    int k;
    cin >> k;
    string s, t;
    cin >> s >> t;
    vector<int> low = getidx(s, k), high = getidx(t, k);
    
    cout << ans << endl;
    return 0;
}
