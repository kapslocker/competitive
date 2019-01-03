#include <bits/stdc++.h>
using namespace std;

std::vector<pair<int,int> > v,edg;

bool collinear(int i, int j, int k){
	int dx1 = v[j].first-v[i].first;
	int dx2 = v[k].first-v[i].first;
	int dy1 = v[j].second-v[i].second;
	int dy2 = v[k].second-v[i].second;
	return (dx1*1ll*dy2==dy1*1ll*dx2);
}

int main(){
	int k;
	cin >> k;
	int vn = (k-1)/3+1;
	v.push_back(make_pair(1,0));
	v.push_back(make_pair(100000000,0));
	edg.push_back(make_pair(1,2));
	int x=1,y=0;
	int dx = 100000, dy= 1000;
	for(int i=0;i<vn;i++){
		x+=dx;
		y+=dy;
		v.push_back(make_pair(x,y));
		edg.push_back(make_pair(1,i+3));
		edg.push_back(make_pair(2,i+3));
		if(i)
			edg.push_back(make_pair(i+2,i+3));
		dy+=1000;
	}
	if(k%3!=1){
		v.push_back(make_pair(0,1));
		v.push_back(make_pair(0,2));
		edg.push_back(make_pair(1,vn+3));
		edg.push_back(make_pair(1,vn+4));
		edg.push_back(make_pair(vn+3,vn+4));
	}
	if(k%3==0){
		v.push_back(make_pair(100000001,1));
		v.push_back(make_pair(100000001,2));
		edg.push_back(make_pair(2,vn+5));
		edg.push_back(make_pair(2,vn+6));
		edg.push_back(make_pair(vn+5,vn+6));
	}
	cout << v.size()<<" "<<edg.size()<<"\n";
	for(int i=0;i<v.size();i++)
		printf("%d %d\n",v[i].first,v[i].second);
	for(int i=0;i<edg.size();i++)
		printf("%d %d\n",edg[i].first,edg[i].second);
	for(int i=0;i<v.size();i++)
		for(int j=i+1;j<v.size();j++)
			for(int k=j+1;k<v.size();k++)
				if(collinear(i,j,k))
				{
					assert(0);
					// cout<<i<<" "<<j<<" "<<k<<"\n";
					// cout<<v[i].first<<" "<<v[i].second<<"\n";
					// cout<<v[j].first<<" "<<v[j].second<<"\n";
					// cout<<v[k].first<<" "<<v[k].second<<"\n";
				}
}
