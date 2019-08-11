#include <bits/stdc++.h>

using namespace std;


double distsq(const vector<double> &p1, const vector<double> &p2) {
    double ans = 0;
    for(int i = 0; i < p1.size(); i++) {
        ans += (p1[i] - p2[i]) * (p1[i] - p2[i]);
    }
    return ans;
}


bool check(vector<vector<double> > &points) {
    // for every point, 3 points at x, 3 points at 2x, 1 point at 3x
    unordered_map<double, int> hmap;
    for(int i = 1; i < 8; i++) {
        double d = distsq(points[0], points[i]);
        hmap[d]++;
        if(hmap[d] > 3)
            return false;
    }
    double mind = (*min_element(hmap.begin(), hmap.end())).first;
    for(auto &p:hmap) {
        if(fabs(p.first/mind) < 1e-6 && p.second != 3)
            return false;
        if(fabs(p.first/(2 *mind)) < 1e-6 && p.second != 3)
            return false;
        if(fabs(p.first/(3 * mind)) < 1e-6 && p.second != 1)
            return false;
    }
    return true;
}

bool backtrack(vector<vector<double> > &points) {
    
}
int main() {
    vector<vector<double> > points(8, vector<double>(3));
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 3; j++)
            cin >> points[i][j];
    }
    cout << check(points);
    return 0;
}
