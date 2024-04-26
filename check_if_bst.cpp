#include <bits/stdc++.h>

using namespace std;

struct Node {
	Node *left;
	Node *right;
	int val;
	
	Node(int v):left(NULL), right(NULL) {
		val = v;
	}
};


bool isbst(Node *root, int* left_max, int* right_min) {
	
	if(root == NULL) {
		*left_max = INT_MIN;
		*right_min = INT_MAX;
		return true;
	}
	
	if(root->left == NULL && root->right == NULL) {
		*left_max = *right_min = root->val;
		return true;
	}
	
	int lmax, lmin, rmax, rmin;
	
	bool islbst = isbst(root->left, &lmax, &lmin);
	bool isrbst = isbst(root->right, &rmax, &rmin);
	
	*left_max = min(root->val, min(lmin, rmin));
	*right_min = max(root->val, max(lmax, rmax));
	
	cout<<root->val<<"->("<<*left_max<<*right_min<<")\n";
	
	if(islbst && isrbst && root->val >= *left_max && root->val < *right_min )
		return true;
	return false;
}

    int fun(Node *root, int *mmin, int *mmax, bool *isbst) {
	
	if(root == NULL) {
		*isbst = true;
		*mmin = INT_MAX;
		*mmax = INT_MIN;
		return 0;
	}
	
	if(root->left == NULL && root->right == NULL) {
		*isbst = true;
		*mmin = *mmax = root->data;
		return 1;
	}
	
	bool islbst, isrbst;
	int lmax = INT_MIN, lmin = INT_MAX, rmax = INT_MIN, rmin = INT_MAX;
	
	int l = fun(root->left, &lmin, &lmax, &islbst);
	int r = fun(root->right, &rmin, &rmax, &isrbst);
	
	if(islbst && isrbst && root->data > lmax && root->data < rmin) {
		*isbst = true;
		*mmin = min(lmin, root->data);
		*mmax = max(rmax, root->data);
		return 1 + l + r;
	}
	*isbst = false;
	return max(l, r);
}


int main() {
	
	Node *t1 = new  Node(12);
	Node *t2 = new  Node(7);
	Node *t3 = new Node(16);
	Node *t4 = new Node(3);
	Node *t5 = new Node(9);
	Node *t6 = new Node(14);
	Node *t7 = new Node(19);
	Node *t8 = new Node(8);
	Node *t9 = new Node(14);
	
	t1->left= t2;
	t1->right= t3;
	
	t2->left = t4;
	t2->right = t5;
	
	t3->left = t6;
	t3->right = t7;
	
	t5->left = t8;
	t5->right = t9;
	
	bool isbst;
	int min, max;
	cout<<"size of largest bst : \n"<<fun(t1, &min, &max, &isbst)<<"\n";
	
	return 0;
}