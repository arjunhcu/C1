#include <bits/stdc++.h>

using namespace std;

struct Node {
	int v;
	int d;
	
	Node(int a, int b):v(a),d(b){}
};

bool is_valid(int x) {
	return (x <= 100);
}

void fun(vector<int> &v, unordered_map<int, int> &m) {
	
	
	queue<Node> q;
	
	Node s(0,0);
	
	q.push(s);
	Node root(0,0);
	
	while(!q.empty()) {
		
		root = q.front();
		
		if(root.v == 100) {
			cout<<"minimum steps to reach 100: "<<root.d<<"\n";
			break;
		}
		
		q.pop();
		
		if(!v[root.v]) {
			v[root.v] = 1;
			
			for(int i = 1; i <=6; i++) {
				if(is_valid(root.v + i)) {
					Node lroot(m[root.v + i], root.d + 1);
					q.push(lroot);
				}
			}
		}
		
	}
}


int main() {
	
	vector<int> v(1000,0);
	
	unordered_map<int, int> m;
	
	for(int i=0; i <=100; i++)
		m[i] = i;
	
	m[11] = 40;
	m[37] = 67;
	m[47] = 93;
	m[15] = 72;
	
	m[90] = 12;
	m[98] = 31;
	m[85] = 23;
	m[75] = 75;

	fun(v, m);
	
	
	return 0;
}

