#include <bits/stdc++.h>

using namespace std;

#define pd pair<int,int>

vector<int> in = {5, 9, 6, 8, 6, 4, 6, 9, 5, 4, 9};

struct compare {
	bool operator()(pd p1, pd p2) {
		return p1.first > p2.first;
	}
};

int main() {
	
	int N = in.size();
	
	vector<int> lmax(N, 0);
	vector<int> rmax(N, 0);
	
	priority_queue<pd, vector<pd>, compare> pq;
	
	
	pq.push({in[0], 0});
	
	for(int i = 1; i < N; i++) {
		while(!pq.empty() && pq.top().first <= in[i])
			pq.pop();
		lmax[i] = pq.empty() ? 0 : pq.top().second;
		pq.push({in[i], i});
	}
	
	pq = priority_queue<pd, vector<pd>, compare>();
	pq.push({in[N-1], N-1});
	
	
	for(int i = N-2; i >= 0; i--) {
		while(!pq.empty() && pq.top().first <= in[i])
			pq.pop();
		rmax[i] = pq.empty() ? 0 : pq.top().second;
		pq.push({in[i], i});
	}
	
	int r = 0;
	
	for(int i = 0 ; i < N; i++) {
		cout<<lmax[i]<<" "<<rmax[i]<<" "<<lmax[i]*rmax[i]<<"\n";
		r = max(r, lmax[i]*rmax[i]);
	}
	
	cout<<"res "<<r<<"\n";
	return 0;
}