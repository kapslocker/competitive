#include <bits/stdc++.h>
using namespace std;

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


bool isdone = false;

void print(vector<int> &arr) {
    cout << "YES\n";
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

void dfs(vector<int> &choices, int prev, int &lsum, int &rsum, int &curr, vector<int> &ans, int total) {
    if(curr == total) {
        isdone = true;
        print(ans);
        return;
    }
    for(int choice : choices) {
        if(choice == prev)
            continue;
        if(curr % 2 == 0) {
            // insert left
            if(lsum + choice <= rsum) {
                continue;
            }
            lsum += choice;
            curr++;
            ans.push_back(choice);
            dfs(choices, choice, lsum, rsum, curr, ans, total);
            lsum -= choice;
            curr--;
            ans.pop_back();
        }
        else {
            // insert right
            if(rsum + choice <= lsum)
                continue;
            rsum += choice;
            curr++;
            ans.push_back(choice);
            dfs(choices, choice, lsum, rsum, curr, ans, total);
            rsum -= choice;
            curr--;
            ans.pop_back();
        }
        if(isdone) {
            return;
        }
    }
}


int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector<int> choices;
    for(int i = 1; i <= 10; i++)
        if(s[i - 1] == '1')
            choices.push_back(i);

    int lsum = 0, rsum = 0, curr = 0;
    vector<int> ans;
    dfs(choices, -1, lsum, rsum, curr, ans, m);
    if(!isdone) {
        cout << "NO\n";
    }
    return 0;
}
