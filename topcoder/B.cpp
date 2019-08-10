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

string getLiteral(string candidate) {
    int n = candidate.length();
    bool isend = false;
    string ans = "";
    vector<string> suffixes = {"L", "LL", "U", "UL", "ULL", "LU", "LLU"};
    for(int i = 0; i < n; i++) {
        if(candidate[i] >= '0' && candidate[i] <= '9') {
            ans.push_back(candidate[i]);
        }
        else if(candidate[i] >= 'A' && candidate[i] <= 'F') {
            ans.push_back(candidate[i]);        }
        else if(candidate[i] == 'O') {
            ans.push_back('0');
        }
        else if(candidate[i] == 'I') {
            ans.push_back('1');
        }
        else if(candidate[i] == 'Z') {
            ans.push_back('2');
        }
        else if(candidate[i] == 'S') {
            ans.push_back('5');
        }
        else if(candidate[i] == 'T') {
            ans.push_back('7');
        }
        else {
            // has to match suffix
            string temp = candidate.substr(i);
            bool found = false;
            for(int j = 0; j < suffixes.size(); j++) {
                if(temp == suffixes[j]) {
                    ans = ans + temp;
                    found = true;
                    break;
                }
            }
            if(!found)
                return "";
            else
                break;
        }
    }
    return "0x" + ans ;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string a;
    cin >> a;
    cout << getLiteral(a) << endl;
    return 0;
}
