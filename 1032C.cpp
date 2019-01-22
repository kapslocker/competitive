#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), dp(5, 1);
    vector<vector<int> > prev(n, vector<int>(5, -1));
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for(int i = 1; i < n; i++) {
        vector<int> nn(5, 0);
        if(a[i - 1] < a[i]) {
            for(int j = 0; j < 5; j++) {
                for(int k = 0; k < j; k++) {
                    if(dp[k]) {
                        nn[j] = 1;
                        prev[i][j] = k;
                    }
                }
            }
        }
        else if(a[i - 1] > a[i]) {
            for(int j = 0; j < 5; j++) {
                for(int k = j + 1; k < 5; k++) {
                    if(dp[k]) {
                        nn[j] = 1;
                        prev[i][j] = k;
                    }
                }
            }
        }
        else {
            for(int j = 0; j < 5; j++) {
                for(int k = 0; k < 5; k++) {
                    if(dp[k] && k != j) {
                        nn[j] = 1;
                        prev[i][j] = k;
                    }
                }
            }
        }
        for(int j = 0; j < 5; j++)
            dp[j] = nn[j];
    }
    vector<int> ans(n, -1);
    prev[0][1] = 1;
    prev[0][2] = 1;
    prev[0][3] = 1;
    prev[0][4] = 1;
    prev[0][0] = 1;
    for(int j = 0; j < 5; j++) {
        if(prev[n - 1][j] >= 0) {
            ans[n - 1] = j;
        }
    }
    if(ans[n - 1] == -1) {
        cout << "-1\n";
        return 0;
    }
    int p = ans[n - 1];
    while(n > 0) {
        ans[n - 1] = p;
        p = prev[n - 1][p];
        n--;
    }
    n = ans.size();
    for(int i = 0; i < n; i++)
        cout << ans[i] + 1 << " ";
    cout << endl;
    return 0;
}
