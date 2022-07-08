#include <bits/stdc++.h>

using namespace std;

vector<int> v = {1,2,3,4};
int N = 4;

void fun(vector<int>&vl, int sum, int indx) {
	
	if(sum == 0) {
		for(auto x: vl)
			cout<<" "<<x;
		cout<<"\n";
		return;
	}
	
	if(sum < 0)
		return;
	
	
	for(int i = indx; i < N;i++) {
		vl.push_back(v[i]);
		fun(vl, sum - v[i], i + 1);
		vl.pop_back();
	}
}

int main() {
	
	vector<int> vl;
	int sum = 7;
	fun(vl, sum, 0);
	return 0;
}

