#include <bits/stdc++.h>

using namespace std;

#define pd pair<int,int>

vector<pd> v = {{1,3},{2,4},{6,8},{7,10}};

struct compare{
	bool operator()(pd p1, pd p2){
		return p1.second < p2.second ;
	}
};

bool compare1(pd p1, pd p2) {
	return p1.second < p2.second;
}

int fun(vector<pd>& v) {
	
	sort(v.begin(), v.end(), compare1);
	
	int N = v.size();
	int ending = v[0].second, res  = 1;
	
	for(int i = 1; i<N; i++) {
		pd p = v[i];
		if(p.first >= ending) {
			res++;
			ending = p.second;
		}
	}
	
	return res;
}

int main() {
	cout<<"max meetings :"<<fun(v)<<"\n";
	return 0;
}