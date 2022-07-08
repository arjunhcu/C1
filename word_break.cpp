#include <bits/stdc++.h>

using namespace std;

vector<string> d = { "i", "like", "sam", "sung", "samsung", "mobile", "ice", 
  "and", "cream", "icecream", "man", "go", "mango", "su"};

unordered_map<string, int> m;


bool fun(string s, string& res) {
	
	int N = s.length();
	
	for(int l = 1; l <=N; l++) {
		string temp = s.substr(0,l);
		if(m[temp]) {
			//cout<<"substr : "<<temp<<"\n";
			res = res + " " + temp;
			if (l == N)
				return true;
			return fun(s.substr(l, N-l), res);
		}
	}
	return false;
}

int main() {
	
	for(auto s: d)
		m[s] = 1;
	
	string res = " ";
	
	string in = "likesamsu";
	
	if(fun(in, res))
		cout<<"fpund as : "<<res<<"\n";
	
	return 0;
}