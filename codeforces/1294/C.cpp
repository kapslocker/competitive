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
 
const int MAX = 100001;
vector<int> s(MAX, 1);
vector<int> primes;
 
void sieve() {
    s[0] = 0;
    s[1] = 0;
    for(int i = 2; i < MAX; i++) {
        if(!s[i])
            continue;
        for(int j = i * i; j < MAX; j += i) {
            s[j] = 0;
        }
    }
    for(int i = 2; i < MAX; i++) {
        if(s[i])
            primes.push_back(i);
    }
}
 
vector<int> solve() {
    int n;
    cin >> n;
    int m = sqrt(n);
    set<int> divs;
    vector<int> pfacts;
    // either two primes < rootN divide n
    for(int p: primes) {
        if(n % p == 0) {
            pfacts.push_back(p);
        }
        if(pfacts.size() == 2) {
            int c = n / (pfacts[0] * pfacts[1]);
            if (c == pfacts[0] || c == pfacts[1] || c == 1) {
                return {};
            }
            return {pfacts[0], pfacts[1], n / (pfacts[0] * pfacts[1])}; 
        }
    }
 
    if (pfacts.size() == 0) {
        return {};
    }
    int p = pfacts[0];
    int k = p * p * p;
    if (n % k == 0 && n != k) {
        int c = n / k;
        if(c == p || c == p * p)
            return {};
        return {p, p * p, n / k};
    }
    return {};
}
 
int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sieve();
    int t;
    cin >> t;
    while(t--) {
        vector<int> ans = solve();
        if (ans.size()) {
            cout << "YES\n";
            cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
        }
        else {
            cout << "NO\n";
        }
    }
    
    return 0;
}