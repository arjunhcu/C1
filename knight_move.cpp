#include <bits/stdc++.h>

using namespace std;

#define pd pair<int, int>

int fun(vector<int>&v, vector<int>&p) {
	q.push({v[0], v[1]});
	
	int steps = -1;
	
	vector<vector<bool>> visit(N+1, vector<bool>(N+1, false));
	
	
	while(!q.empty()) {
		
		steps++;
		
		int n = q.size();
		
		for(int i =0; i < n; i++) {
			pd loc = q.front();
			q.pop();
			
			if(loc.first == p[0] && loc.second == p[1])
				return steps;
			
			
			int r = loc.first;
			int c = loc.second;
			
			if(r >= 0 && r <=N && c >=0 && c <=N && !visit[r][c]) {
				q.push({r-2, c+1});
				q.push({r-2, c-1});
				q.push({r+2, c+1});
				q.push({r+2, c-1});
				
				q.push({r+1, c+2});
				q.push({r+1, c-2});
				q.push({r-1, c+2});
				q.push({r-1, c-2});
				
				visit[r][c] = true;
			}
		}
		
	}
	
	return -1;
	
} 

int main() {
	
	vector<int> v = {4,5};
	vector<int> p = {1,1};
	
	cout<<"moves : "<<fun(v,p)<<"\n";
	
	return 0;
}