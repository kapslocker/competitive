#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<double> x(n);
    double r;
    cin >> r;
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    set<pair<pair<double, double>, int> > centres;
    for(int i = 0; i < n; i++){
        bool coll = false;
        for(auto it = centres.rbegin(); it != centres.rend(); it++){
            double xc = (*it).first.second, yc = (*it).first.first, d = fabs(xc - x[i]);
            if(fabs(xc - x[i]) <= 2.0 * r){
                coll = true;
                centres.insert({{yc + sqrt(4 * r * r - d * d), x[i]}, i});
                break;
            }
        }
        if(!coll){
            centres.insert({{r, x[i]}, i});
        }
    }
    double arr[n];
    for(auto c : centres){
        arr[c.second] = c.first.first;
    }
    for(auto c : arr){
        cout << fixed << setprecision(10) << c << " ";
    }
    return 0;
}
