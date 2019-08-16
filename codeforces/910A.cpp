#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;
    vector<int> dp(n + 1, -1);
    dp[n] = 0;
    for(int i = n - 1; i > 0; i--){
        int x = INT_MAX;
        if(s[i-1] == '0')
            continue;
        for(int j = i + 1; j <= min(i + d, n); j++){
            if(dp[j] > -1 && dp[j] < x){
                x = dp[j];
            }
        }
        if(x < INT_MAX && x > -1){
            dp[i] = 1 + x;
        }
    }
    cout << dp[1] << endl;
    return 0;
}
