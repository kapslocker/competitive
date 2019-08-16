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
	vector<int> c(26);
	for(int i = 0; i < 26; i++) {
		cin >> c[i];
	}
	string s;
	cin >> s;
	int n = s.length(), pre = 0, ans = 0;
	vector<map<int, int> > hmap(26);
	for(int i = 0; i < n; i++) {
		int ch = s[i] - 'a';
    	ans = ans + hmap[ch][pre];
        pre = pre + c[ch];
		hmap[ch][pre]++;
	}
	cout << ans << endl;
	return 0;
}
