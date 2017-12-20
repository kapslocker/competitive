#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > getFactors(int n){
    if(n <= 0)
        return {};
    vector<pair<int, int> > ans;
    for(int i = 2; i <= (int)sqrt(n); i++){
        if(n % i == 0)
            ans.push_back({i, 0});
        while(n % i == 0){
            n = n / i;
            ans.back().second++;
        }
    }
    if(n != 1)
        ans.push_back({n, 1});
    return ans;
}
void getDivisors(vector<pair<int, int> > &factors, vector<int> &divisors, int pos = 0, int res = 1){
    if(pos == factors.size()){
        divisors.push_back(res);
        return;
    }
    for(int i = 0; i <= factors[pos].second; i++){
        getDivisors(factors, divisors, pos + 1, res);
        res = res * factors[pos].first;
    }
}
void intersection(vector<int> &a, vector<int> &b, vector<int> &ans){
    int n = a.size(), m = b.size(), i = 0, j = 0;
    while(i < n && j < m){
        if(a[i] == b[j])
            ans.push_back(a[i]);
        if(a[i] < b[j])
            i++;
        else
            j++;
    }
}
int main(){
    int a, b;
    cin >> a >> b;
    vector<pair<int, int> > fA = getFactors(a), fB = getFactors(b);
    vector<int> divA, divB;
    getDivisors(fA, divA);
    getDivisors(fB, divB);
    sort(divA.begin(), divA.end());
    sort(divB.begin(), divB.end());
    vector<int> common;
    intersection(divA, divB, common);
    for(auto x : common)
        cout << x << " ";
    cout << endl;
    int q;
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        vector<int> :: iterator it = upper_bound(common.begin(), common.end(), y);
        --it;
        int d = *it;
        if(d <= y && d >= x)
            cout << d << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
