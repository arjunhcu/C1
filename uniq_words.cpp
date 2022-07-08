#include <bits/stdc++.h>

using namespace std;

int main() {
	
	vector<string> r;
	unordered_map<string, int> m;
	
	string in = "geeks for geeks";
	
	stringstream ss(in);
	string token;
	
	while(getline(ss, token, ' ')) {
		if(!m[token])
			r.push_back(token);
		m[token] = 1;
	}
	
	for(auto s: r){
		cout<<s<<"\n";
	}
	return 0;
}