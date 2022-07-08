#include <bits/stdc++.h>

using namespace std;

#define pd pair<int,int>

vector<pd> v = {{1,3},{2,4},{6,8},{9,10}};

struct compare {
	bool operator()(pd p1, pd p2) {
		return p1.first > p2.first;
	}
};

int main(){
	
	int N = v.size();
	
	priority_queue<pd, vector<pd>, compare> pq;

	for(int i = 0; i < N; i++)
		pq.push(v[i]);
	
	vector<pd> res;
	
	while(!pq.empty()) {
		pd p = pq.top();
		pq.pop();
		if(!pq.empty() && pq.top().first <= p.second){
			p.second = max(p.second, pq.top().second);
			pq.pop();
			pq.push(p);
		} else {
			res.push_back(p);
		}
	}
	
	for(auto p : res)
		cout<<p.first<<"-"<<p.second<<"\n";
	return 0;
}