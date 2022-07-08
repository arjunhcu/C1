#include <bits/stdc++.h>

using namespace std;

vector<int> v = {
	251, 286, 420, 491, 506, 34, 716, 829, 615,
	53, 807, 837, 750, 650, 181, 140, 543, 944,
	210, 113, 551, 379, 818, 817, 227, 525, 257,
	735, 932, 172, 410, 935, 351, 347, 521, 168,
	482, 885, 612, 352};

int main() {
	
	priority_queue<int> pq;
	priority_queue<int> dq;
	
	int k = 9, N = v.size();
	
	for(int i = 0; i < k; i++) {
		pq.push(v[i]);
	}
	
	vector<int> res;
	
	res.push_back(pq.top());
	
	for(int i = k; i < N; i++) {
		
		if(v[i-k] == pq.top())
			pq.pop();
		else
			dq.push(v[i-k]);
		
		while(!dq.empty() && pq.top() == dq.top()) {
			pq.pop();
			dq.pop();
		}
		
		pq.push(v[i]);
		res.push_back(pq.top());
	}
	
	for(auto x: res)
		cout<<x<<" ";
	
	return 0;
}