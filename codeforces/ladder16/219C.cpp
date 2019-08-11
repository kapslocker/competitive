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

int diff(string &a, string &b) {
    int ans = 0;
    for(int i = 0; i < a.length(); i++) {
        if(a[i] != b[i])
            ans++;
    }
    return ans;
}

void solve2(int n, string arr) {
    string str1(n, 'A'), str2(n, 'A');
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            str1[i] = 'A'; str2[i] = 'B';
        }
        else {
            str1[i] = 'B'; str2[i] = 'A';
        }
    }
    int a = diff(str1, arr), b = diff(str2, arr);
    if(a < b) {
        cout << a << endl << str1 << endl;
    }
    else {
        cout << b << endl << str2 << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    string arr;
    cin >> arr;
    if(k == 2) {
        solve2(n, arr);
        return 0;
    }
    int ans = 0;
    for(int i = 1; i < n - 1; i++) {
        if(arr[i] != arr[i - 1])
            continue;
        ans++;
        for(char ch = 'A'; ch < 'A' + k; ch++) {
            if(ch != arr[i - 1] && ch != arr[i + 1]) {
                arr[i] = ch;
                break;
            }
        }
    }
    if(arr[n - 1] == arr[n - 2]) {
        ans++;
        int temp = arr[n - 1] - 'A';
        temp = (temp + 1) % k;
        arr[n - 1] = 'A' + temp;
    }
    cout << ans << endl << arr << endl;
    return 0;
}
