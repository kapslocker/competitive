#include <bits/stdc++.h>
using namespace std;

string ans;

vector<int> suf(10), pre(10);
void precomp(string &s) {
    for(int i = 0; i < 10; i++) {
        suf[i] = -1;
        pre[i] = INT_MAX;
    }
    for(int i = s.length() - 1; i >= 0; i--) {
        suf[s[i]-'0'] = max(suf[s[i]-'0'], i);
    }
    for(int i = 0; i < s.length(); i++) {
        pre[s[i]-'0'] = min(pre[s[i]-'0'], i);
    }
}

bool solve(string &s) {
    int n = s.length();
    precomp(s);
    for(int i = 0; i < n; i++) {
        int val = s[i] - '0';
        // eight cases.
        // smaller on left with 1 => anything.
        // smaller on right with 1=> mark 2.
        // larger on left with 1  => impossible
        // larger on right with 1 => mark 1.
        // smaller on left with 2 => mark 1.
        // smaller on right with 2=> impossible
        // larger on left with 2  => mark 1.
        // larger on right with 2 => anything.
        bool issmallright = false, islargeleft = false;
        for(int dd = val + 1; dd < 10; dd++) {
            if(pre[dd] < i) {
                islargeleft = true;
                break;
            }
        }
        for(int dd = 0; dd < val; dd++) {
            if(suf[dd] > i) {
                issmallright = true;
                break;
            }
        }
        if(issmallright && islargeleft)
            return false;
        if(issmallright)
            ans[i] = '2';
        else if(islargeleft)
            ans[i] = '1';
        else {
            ans[i] = '0';
        }
    }
    // unconstrained
    // mark 1 when:
    // 1. smaller element on left with 2.
    // 2. larger element on right with 1.
    for
    return true;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        ans.resize(n);
        bool x = solve(s);
        if(x)
            cout << ans << endl;
        else
            cout << "-" << endl;
    }
    return 0;
}
