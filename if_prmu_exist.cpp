#include <bits/stdc++.h>


using namespace std;

void fun(vector<int>& p, string& res, int k) {
	
	unordered_map<int, int>m;
	
	int count = INT_MAX;
	
	int l, r;
	l = p.size(), r = -1;
	
	//add base case if 1 is not found
	
	for(int i = 0; i<p.size(); i++) {
		m[p[i]] = i;
	}
	
	
	for(int i = 1; i<=k; i++) {
		
		l = min(m[i], l);
		r = max(m[i], r);
		
		cout<<"x :"<<i<<" l:"<<l<<" r:"<<r<<"\n";
		
		if(r - l + 1 == i)
			res+="1";
		else
			res+="0";
	}
	
}


int main() {
	
	vector<int> p = {5,3,2,1,6,4}; //111001;
	string res = "";
	fun(p, res, 6);
	cout<<"permutations exist : "<<res<<" \n";
	
	return 0;
}