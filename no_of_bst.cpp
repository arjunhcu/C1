
#include <bits/stdc++.h>

using namespace std;


struct info {
	int min;
	int max;
	bool is_bst;
};

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode(int v):val(v),left(NULL),right(NULL){}
};

int fun(TreeNode *root, int *mmin, int *mmax, bool *isBST) {
	
	if(root == NULL) {
		*mmin = 1000;
		*mmax = 1000;
		*isBST = true;
		return 0;
	}
	
	if(root->left == NULL && root->right == NULL) {
		*mmin = root->val;
		*mmax = root->val;
		*isBST = true;
		return 1;
	}
	
	int lmin=0, lmax=0, rmin=0, rmax=0;
	bool lisBST, risBST;
	
	int l = fun(root->left, &lmin, &lmax, &lisBST);
	int r = fun(root->right, &rmin, &rmax, &risBST);
	
	*mmin = min(root->val, min(lmin, rmin));
	*mmax = max(root->val, max(lmax, rmax));
	
	if(lisBST && risBST && root->val >= lmax && root->val < rmin) {
		*isBST = true;
		return 1 + l + r;
	} else {
		*isBST = false;
		return l + r;
	}
}

int main() {
	
	
	TreeNode *t1 = new TreeNode(11);
	TreeNode *t2 = new TreeNode(8);
	TreeNode *t3 = new TreeNode(10);
	TreeNode *t4 = new TreeNode(5);
	TreeNode *t5 = new TreeNode(9);
	TreeNode *t6 = new TreeNode(8);
	TreeNode *t7 = new TreeNode(4);
	TreeNode *t8 = new TreeNode(6);
	
	
	t1->left = t2;
	t1->right = t3;
	
	t2->left = t4;
	
	
	t3->left = t5;
	t3->right = t6;
	
	
	t4->left = t7;
	t4->right = t8;
	
	
	int min,max;
	bool isBST;
	
	cout<<"no of bst : "<<fun(t1, &min, &max, &isBST)<<"\n";
	
	
	return 0;
}