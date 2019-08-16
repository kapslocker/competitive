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

int removeleading(string &s) {
    int i = 0;
    while(i < s.length() - 1 && s[i] == '0')
        i++;
    s = s.substr(i);
    return i;
}


int solve(string s, int rem, vector<int> c) {
    int ca = c[rem], cb = c[3 - rem];
    int n = s.length();
    if(ca >= 1) {
        for(int i = n - 1; i > 0; i--) {
            if((s[i] - '0') % 3 == rem) {
                string ans = s.substr(0, i) + s.substr(i + 1);
                cout << ans << endl;
                return 0;
            }
        }
//        either 2 twos or this 1.
        if(s.length() > 1 && s[1] != '0') {
            string ans = s.substr(1);
            cout << ans << endl;
            return 0;
        }
        if(cb >= 2) {
            int i1 = -1, i2 = -1;
            for(int i = n - 1; i >= 0; i--) {
                if((s[i] - '0') % 3 == 3 - rem) {
                    if(i2 < 0)
                        i2 = i;
                    else {
                        i1 = i;
                        break;
                    }
                }
            }
            string ans = s.substr(0, i1) + s.substr(i1 + 1, i2 - i1 - 1) + s.substr(i2 + 1);
            removeleading(ans);
            cout << ans << endl;
            return 0;
        }
        // need to remove this 1
        s = s.substr(1);
        removeleading(s);
        if(s.length() == 0) {
            cout << -1 << endl;
            return 0;
        }
        cout << s << endl;
        return 0;
    }
    if(cb >= 2) {
        int i1 = -1, i2 = -1;
        for(int i = n - 1; i >= 0; i--) {
            if((s[i] - '0') % 3 == 3 - rem) {
                if(i2 < 0)
                    i2 = i;
                else {
                    i1 = i;
                    break;
                }
            }
        }
        string ans = s.substr(0, i1) + s.substr(i1 + 1, i2 - i1 - 1) + s.substr(i2 + 1);
        removeleading(ans);
        if(ans.length() == 0)
            cout << -1 << endl;
        else
            cout << ans << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    removeleading(s);
    int n = s.length();
    int sum = 0;
    vector<int> c = {0, 0, 0};
    for(int i = 0; i < n; i++) {
        sum += s[i] - '0';
        c[1] += (s[i] - '0') % 3 == 1;
        c[2] += (s[i] - '0') % 3 == 2;
    }
    if(sum % 3 == 0) {
        cout << s << endl;
        return 0;
    }
    solve(s, sum % 3, c);
    return 0;
}
