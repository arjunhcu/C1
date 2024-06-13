#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
	
	Node(int val):data(val), left(NULL), right(NULL){}
};

Node * find(Node *root, int target) {
	
	if(root == NULL)
		return root;
	
	if(root->data == target)
		return root;
	
	Node *l = find(root->left, target);
	if(l != NULL)
		return l;
	
	return find(root->right, target);	
}

void buildmap(Node *root, unordered_map<Node *, Node *>& m, unordered_map<int, bool>& v, Node *parent) {
	if(root == NULL)
		return;
	m[root] = parent;
	
	int p = parent != NULL ? parent->data : -1;
	
	cout<<root->data<<":"<<p<<"\n";
	
	v[root->data] = false;
	buildmap(root->left, m, v, root);
	buildmap(root->right, m, v, root);
}

int burn_tree(Node *root, int target) {
	
	cout<<"root:"<<root->data<<"\n";
	
	Node *trgt = find(root, target);
	if(trgt == NULL)
		return -1;
	
	cout<<"trgt is :"<<trgt->data<<"\n";
	
	unordered_map<Node *, Node *> m;
	unordered_map<int, bool > v;
	buildmap(root, m, v, NULL);

	queue<Node*> q;
	q.push(trgt);
	
	cout<<"Lets go on queue\n";
	
	int count = -1;
	
	while(!q.empty()) {
		
		int N = q.size();
		count++;
		
		for(int i = 0; i < N; i++) {
			Node *node = q.front();
			q.pop();
			
			Node *left = node->left;
			Node *right = node->right;
			Node *parent = m[node];
			
			if(left != NULL && !v[left->data])
				q.push(left);
			if(right != NULL  && !v[right->data])
				q.push(right);
			if(parent != NULL && !v[parent->data])
				q.push(parent);
			
			v[node->data] = true;
		}
	}
	
	return count;
}

int main() {
	
	
	Node *t1 = new Node(1);
	Node *t2 = new Node(2);
	Node *t3 = new Node(3);
	Node *t4 = new Node(4);
	Node *t5 = new Node(5);
	Node *t6 = new Node(6);
	Node *t7 = new Node(7);
	Node *t8 = new Node(8);
	Node *t9 = new Node(9);
	Node *t10 = new Node(10);
	Node *t11 = new Node(11);
	Node *t12 = new Node(12);
	Node *t13 = new Node(13);
	
	t1->left =  t2;
	t1->right = t3;
	
	t2->left = t4;
	t2->right = t5;
	
	t3->right = t6;
	
	t5->left = t7;
	t5->right = t8;
	
	t6->right = t9;
	
	t7->left = t10;
	t7->right = t11;
	
	t9->right = t12;
	
	t11->right = t13;
	
	cout<<" value is : "<<burn_tree(t1, 8)<<"\n";
	
	return 0;
}